#include <stdio.h>
#include <stdlib.h>
//Warren Daniel 

// Function to perform binary search on a sorted array
int search(int numbers[], int low, int high, int value) 
{
	if (high >= low)
	{
		// calculate the midpoint
	    int m = low + (high - low)/2;
	    
	    // check if the specified value is at the midpoint
	    if (numbers[m] == value) 
        	return m;
	    
	    // If the value is less than the midpoint, search in the lower half
	    if (numbers[m] > value) 
	    	return search(numbers, low, m-1, value);
	    
        // If the value is greater than the midpoint, search in the upper half
        if (numbers[m] < value) 
	    	return search(numbers, m+1, high, value);
	}
	
	//  return -1 if the value is not found,
	return -1;
}

// Function to print the elements of an array
void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array: ");
	
	// We use a loop through the array and print each element
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", numbers[i]);
	}
	
	printf("\n");
}

int main(void)
{
	// Variables Declared 
	int i, numInputs;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt", "r");

	// Read the number of test cases from the input file
	fscanf(inFile, " %d\n", &numInputs);
	
	// Process each test case
	while (numInputs-- > 0)
	{
		// Read the number of elements in the array
		fscanf(inFile, " %d\n", &countOfNums);
		
		// Dynamically allocate memory for the array
		numArray = (int *)malloc(countOfNums * sizeof(int));
		
		// Initialize average to zero
		average = 0;
		
		// Read the elements of the array and calculate the average
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile, " %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		//  Array elements Printed
		printArray(numArray, countOfNums);
		
		//  Average value Calculated 
		value = average / countOfNums;
		
		// Perform binary search to find the index of the average value
		index = search(numArray, 0, countOfNums - 1, value);
		
		// Output whether the average value exists in the array
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n", value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		// Free the allocated memory
		free(numArray);
	}

	// Close
	fclose(inFile);
}
