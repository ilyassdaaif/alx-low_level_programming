#include <stdio.h>

/**
 * print_array - Prints the portion of the array being searched
 * @array: The array where the search is being performed
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, int left, int right)
{
	printf("Searching in array: ");
	for (int i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively search for value in the array
 * @array: The array to search in
 * @left: The left index of the subarray to search in
 * @right: The right index of the subarray to search in
 * @value: The value to search for
 * Return: The index of the first occurrence of value or -1 if not found
 */
int recursive_search(int *array, int left, int right, int value)
{
	if (left > right)
		return (-1); /* Element is not found */

	print_array(array, left, right);
	int mid = left + (right - left) / 2;

	/* Check if the middle element is the target and also if it is the first occurrence */
	if (array[mid] == value && (mid == left || array[mid - 1] < value))
		return (mid);

	/* Continue searching to the left or right */
	if (array[mid] >= value)
		return (recursive_search(array, left, mid - 1, value));
	else
		return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 * Return: The index where the value is located or -1 if value is not present or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (recursive_search(array, 0, size - 1, value));
}

/**
 * main - Entry point for testing advanced binary search
 * Return: Always 0
 */
int main(void)
{
	int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
	printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
	printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
	return (0);
}

