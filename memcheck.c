#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep
#include <string.h>

void printMemorySize(size_t size) {
    double sizeInMB = (double)size / (1024 * 1024);
    printf("%.2f MB", sizeInMB);
}

int main() {
    size_t max_memory = 10000000000;  // Maximum memory to allocate in bytes (10GB)
    size_t allocated_memory = 0;
    size_t chunk_size = 200000000;  // Allocate memory in chunks of 200MB
    size_t max_blocks = max_memory / chunk_size;  // Maximum number of blocks

    // Array to store pointers to allocated memory blocks
    char* memory_blocks[max_blocks];

    size_t block_count = 0;

    while (allocated_memory < max_memory && block_count < max_blocks) {
        // Check if remaining memory is less than chunk size
        if (allocated_memory + chunk_size > max_memory) {
            chunk_size = max_memory - allocated_memory;
        }

        // Allocate memory
        char* memory_block = (char*)malloc(chunk_size);
        if (memory_block == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        memset(memory_block, 0, chunk_size);


        // Store the pointer in the array
        memory_blocks[block_count] = memory_block;
        block_count++;

        // Increment allocated memory
        allocated_memory += chunk_size;

        printf("Successfully allocated ");
        printMemorySize(allocated_memory);
        printf(" of memory.\n");

        // Wait for 1 second (adjust as needed)
        sleep(1);
    }

    // Free all allocated memory at the end
    printf("Freeing all allocated memory...\n");
    for (size_t i = 0; i < block_count; ++i) {
        free(memory_blocks[i]);
    }

    // Wait for user input before exiting
    printf("Press Enter to exit...");
    getchar();

    return 0;

}
