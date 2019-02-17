/*********************************************************************************
 *
 *  Selection_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional selection sort code
 *
 ********************************************************************************/
#include <stdio.h>
#include "Selection_Sort.h"


void selectionSort(int arr[], int arr_size)
{
	/* Your code goes here */
	int i,j;
	int smallest_index; /* hold the index of the smallest value */
	for(i=0; i<arr_size; i++)
	{
		smallest_index = i;
		for(j=i+1; j<arr_size; j++)
		{
			if(arr[smallest_index] > arr[j])
			{
				smallest_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[smallest_index];
		arr[smallest_index] = temp;
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

