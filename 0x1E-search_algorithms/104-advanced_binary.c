#include <stdio.h>

void print_array(int *array, int left, int right) {
    printf("Searching in array: ");
    for (int i = left; i <= right; i++) {
	printf("%d", array[i]);
	if (i < right) printf(", ");
    }
    printf("\n");
}

int recursive_search(int *array, int left, int right, int value) {
    if (right >= left) {
	int mid = left + (right - left) / 2;
	print_array(array, left, right);

	// Check if the found value is the first occurrence
	if ((mid == left || value > array[mid - 1]) && array[mid] == value) {
	    return mid;
	} else if (value > array[mid]) {
	    return recursive_search(array, mid + 1, right, value);
	} else {
	    return recursive_search(array, left, mid - 1, value);
	}
    }

    return -1; // Value not found
}

int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
	return -1;
    }
    return recursive_search(array, 0, size - 1, value);
}

// Test the function
int main(void) {
    int array[] = {
	0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n\n", 999, advanced_biary(array, size, 999));
    return 0;
}
