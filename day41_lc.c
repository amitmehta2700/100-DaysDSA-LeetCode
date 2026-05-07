#include <stdlib.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Step 2: Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // Step 3: Count how many have max frequency
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            maxCount++;
        }
    }

    // Step 4: Apply formula
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minTime = partCount * partLength + maxCount;

    // Step 5: Return max of total tasks or calculated time
    return (tasksSize > minTime) ? tasksSize : minTime;
}