/*
 ============================================================================
 Name        : challenge_9_1.c
 Author      : Yassin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * Team Members: Yassin and Elgazzar
 */

int main(void) {

	    int arr[] = {64, 25, 12, 22, 11};
	    int n = sizeof(arr)/sizeof(arr[0]);
	    selectionSort(arr, n);
	    printf("Sorted array: \n");
	    printArray(arr, n);
	    return 0;
	}
