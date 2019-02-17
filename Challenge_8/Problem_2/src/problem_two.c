/*********************************************************************************
 *
 *  problem_two.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Modify the Binary Search algorithm to find an element in a circularly sorted
 * array.
 * The array is sorted in an ascending order and rotated in clockwise
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * 				 target = 10
 * Sample Output: The number is found at index 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_two.h"

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/


int circularArraySearch(int arr[], int arr_size, int element_to_be_found)
{
	/* Your code goes here */
	int l = 0;
	int h = arr_size-1;
	if (l > h) return -1;
	while(l<h)
	{
	    int mid = (l+h)/2;
	    if (arr[mid] == element_to_be_found) return mid;

	    /* If left arr is sorted */
	    if (arr[l] <= arr[mid])
	    {
	        if (element_to_be_found >= arr[l] && element_to_be_found <= arr[mid])
	        {
	        	h = mid -1;
	        }
	        else
	        {
	        	l = mid +1;
	        }
	    }

	    if (element_to_be_found >= arr[mid] && element_to_be_found <= arr[h])
	    {
	        l = mid+1;
	        mid = l + (h - l)/2;
	    }else
	    {
	    	h = mid-1;
	    }
	}
}

/* circularArraySearch_test */
void circularArraySearch_test(void)
{
	int A[] = {9, 10, 2, 5, 6, 8};
	int target = 10;
	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);
	if(index != -1){
		printf("Element found at index %d", index);
	}
	else{
		printf("Element not found in the array");
	}

}
