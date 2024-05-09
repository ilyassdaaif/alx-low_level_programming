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
    if (left > right) {
	return (-1); // Element is not found
    }
	
    print_array(array, left, right);
    int mid = left + (right - left) / 2;

    // Check if the middle element is the target and also if it is the first occurrence
    if ((array[mid] == value) {
	 // Additional check if it is the the first occurrence
	 if (mid == left || array[mid - 1] < value) {
	    return mid;
	 }
    }

    // Continue searching to the left or right
    if (array[mid] >= value) {
    	return recursive_search(array, left, mid - 1, value);
    } else {
        return recursive_search(array, mid + 1, right, value);
    }
}

/**
 * advanced_binary - Searches for a value in a sorted
 * array of integers.
 * @array: A  pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: If value is not present in the array or if array is NULL, -1,
 * Otherwise, the index where value is located.
 */
int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
	return -1;
    }
    return recursive_search(array, 0, size - 1, value);
}

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
