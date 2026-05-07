#include <stdlib.h>

// Map original node pointer → cloned node pointer
struct Node* visited[100];
struct Node* original[100];
int size = 0;

// Find if node already cloned
struct Node* getCloned(struct Node* node) {
    for (int i = 0; i < size; i++) {
        if (original[i] == node) {
            return visited[i];
        }
    }
    return NULL;
}

// Store mapping
void addMapping(struct Node* orig, struct Node* clone) {
    original[size] = orig;
    visited[size] = clone;
    size++;
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) return NULL;

    struct Node* existing = getCloned(node);
    if (existing != NULL) return existing;

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    // Store mapping
    addMapping(node, clone);

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}