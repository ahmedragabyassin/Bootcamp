/*********************************************************************************
 *
 *  problem_five.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Given an array of sorted distinct and non-negative elements, find the smallest
 * number missing in the array. The elements would be sorted and increasing in a regular way until
 * a missing number is faced then the rest of numbers would be random but sorted.
 *
 * Sample Input: arr = [0,1,2,6,9,15, 19]
 * Sample Output: the missing number is 3
 *
 * Sample Input: arr = [1,2,3,4,5]
 * Sample output: the missing number is 0
 *
 * Sample Input: arr= [0,1,2,3,4,5,6]
 * Sample Output: the missing number is 7
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_five.h"
/*********************************************************************************
 *
 * Function: smallestMissing
 *
 * @param: arr[], Array that the function should find the missing number in.
 * @param: low, the index of the first element in array
 * @param: high, the index of the last elment in the array
 * @return: int, the missing element
 *
 * Description: function to get the smallest missing number in an array.
 *
 *
 ********************************************************************************/
int smallestMissing(int arr[], int low, int high)
{
	/* Your code goes here */
	int i;
	for(i=0; i<high; i++)
	{
		if((arr[i+1] - arr[i]!=1) && (arr[i+3] - arr[i+2] == 1))
		{
			return arr[i+1]-1;
		}
		else if((arr[i+1] - arr[i]!=1) && (arr[i+3] - arr[i+2] != 1))
		{
			return arr[i+1]/arr[i];
		}
		else if((arr[i+1] - arr[i]==1) && (i==high-1))
		{
			return 0;
		}
	}
	return arr[high];

}

/* smallestMissing_test function */
void smallestMissing_test(void)
{
	int arr[] = {0,1,2,3,4,5,6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int low = 0, high = n - 1;

	printf("The smallest missing element is %d",
			smallestMissing(arr, low, high));

}
