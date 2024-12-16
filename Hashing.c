#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

// Function to display the hash table
void displayHashTable(int HT[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (HT[i] != -1) {
            printf("Index %d: %d\n", i, HT[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

// Hash function using the remainder method (H(K) = K mod m)
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert an employee record (key) into the hash table using linear probing
void insert(int HT[], int key, int m) {
    int hash = hashFunction(key, m);

    // Linear probing to handle collisions
    int i = 0;
    while (HT[(hash + i) % m] != -1) {
        i++;
        if (i == m) {  // Table is full
            printf("Hash table is full. Unable to insert key %d\n", key);
            return;
        }
    }

    // Insert the key into the available location
    HT[(hash + i) % m] = key;
    printf("Inserted key %d at index %d\n", key, (hash + i) % m);
}

int main() {
    int m, n;
    int HT[MAX_RECORDS];

    // Initialize hash table to -1 (representing empty slots)
    for (int i = 0; i < MAX_RECORDS; i++) {
        HT[i] = -1;
    }

    // Input number of memory locations (size of hash table)
    printf("Enter the number of memory locations in the hash table (m): ");
    scanf("%d", &m);

    // Input number of employee records (keys)
    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    // Input the keys (4-digit numbers) of the employee records
    for (int i = 0; i < n; i++) {
        int key;
        printf("Enter the 4-digit key for employee record %d: ", i + 1);
        scanf("%d", &key);

        // Ensure the key is a 4-digit number
        if (key < 1000 || key > 9999) {
            printf("Invalid key! Please enter a 4-digit number.\n");
            i--; // Retry the input
        } else {
            // Insert the key into the hash table
            insert(HT, key, m);
        }
    }

    // Display the final hash table
    displayHashTable(HT, m);

    return 0;
}
