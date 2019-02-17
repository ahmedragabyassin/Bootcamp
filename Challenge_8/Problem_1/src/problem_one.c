/*********************************************************************************
 *
 *  problem_one.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_one.h"

/****************************[Problem Description]*********************************
 *
 * Given an array that is circularly rotated and sorted in an ascending order and
 * the rotation is clock wise, find the number of rotations in the array.
 *
 * Sample Input:  arr = [8, 9, 10, 2, 5, 6]
 * Sample Output: The Array is rotated 3 times
 *
 * Sample Input:  arr = [2, 5, 6, 8, 9, 10]
 * Sample Output: The array is rotated 0 times
 *
 ********************************************************************************/

/*********************************************************************************
 *
 * Function: findRotationCount
 * @param: arr[], Array that the function should find the number of rotations in.
 * @param: arr_size, Size of the array
 * Description: Function to find the number of times the array is rotated
 *
 ********************************************************************************/
int findRotationCount(int arr[], int arr_size) {
	/* Your code goes here  */
	int max = arr[0];
	int max_index;
	int shifts=0;
	int i,j;
	/* search for the max number in array  */
	for(i=0; i<arr_size; i++)
	{
		if(max <= arr[i])
		{
			max = arr[i];
			max_index = i;
		}
	}
	/* check the number of shifts */
	for(j=(max_index+1); j<arr_size; j++)
	{
		shifts++;
	}
	return shifts;
}


/*********************************************************************************
 *
 * findRotationCount_Test function to test your code
 *
 ********************************************************************************/
void findRotationCount_Test(void)
{
	int arr[] = { 8, 9, 10, 2, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int count = findRotationCount(arr, n);
	printf("The array is rotated %d times\n", count);
}
