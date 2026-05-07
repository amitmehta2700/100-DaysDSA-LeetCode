#include <stdbool.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[1000] = {false};
    int queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = 0;
    visited[0] = true;

    while (front < rear) {
        int room = queue[front++];

        for (int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];

            if (!visited[key]) {
                visited[key] = true;
                queue[rear++] = key;
            }
        }
    }

    // Check all visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }

    return true;
}