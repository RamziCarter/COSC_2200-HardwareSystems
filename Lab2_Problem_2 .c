#include <stdio.h>
#include <stdlib.h>


int main()


	{
		int m; // user input for memory allocation of integer array
		int i, k;  // index for looping
		int ints; // integers 
		int* ptr;  // pointer
		printf("Number of integers? ");
		scanf("%d", &m);	//scanner

	
		ptr = (int*)malloc(m *  sizeof(int));  // dynamic memory allocation
		
		if (ptr == NULL)
			{
				printf("Memory allocation error \n");
				exit (0);  // terminate program 
			}

		for(i = 0; i < m; i++)
			scanf("%d", &ptr[i]);	
		 
	
		for(i = 0; i < m/2; i++) 	//reverse integer locations in array
			{
			int temp = ptr[i];
			ptr[i] = ptr[m-1-i];
			ptr[m-1-i] = temp;
			}
			
		
		for(i = 0; i < m ; i++)
			printf("Integer %d? %d \n", i, ptr[i]);

		
		findMax(&ptr[i], m);	
	}

int findMax(int *arr, int size )
	{
		int i;
		int largest = arr[0];
		for( i = 0; i < size; i++)
			{
				if(largest < arr[1])
					{
						arr[1] = largest;
					}
			}
		return largest;
	}




//
