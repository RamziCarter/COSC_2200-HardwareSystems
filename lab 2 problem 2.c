/* 

2)  Write a program that reads an arbitrary amount of integers from the user, and prints the entered integers in reverse order. The first input is the amount of numbers to be entered. 

Hint: Use dynamic memory allocation.

Example 1:

Number of integers? 5

Integer 0? 1

Integer 1? 2

Integer 2? 3

Integer 3? 4

Integer 4? 5

5

4

3

2

1

Done

Example 2:

Number of integers? 16

Integer 0? 33

Integer 1? 44

Integer 2? 55

Integer 3? 345

Integer 4? 23

Integer 5? 43

Integer 6? 654

Integer 7? 76

Integer 8? 87

Integer 9? 999

Integer 10? 88

Integer 11? 777

Integer 12? 45

Integer 13? 3332

Integer 14? 23

Integer 15? 12

12

23

3332

45

777

88

999

87

76

654

43

23

345

55

44

33

Done

 

3. Implement the following function findMax and test it by passing an array through main function.

int findMax(int *arr, int size)

// The first argument is for an array and size is the number of elements in the 
*\

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





