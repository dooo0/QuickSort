#include "QuickSort.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int nWay = 0;
	
	printf("퀵 정렬을 시작합니다. 함수 10개의 숫자의 방식을 입력해주세요.\n");
	printf("1 : 랜덤   2: 수기 입력\n");

	while (nWay != 1 && nWay != 2)
	{
		scanf_s("%d", &nWay);
		if (nWay != 1 && nWay != 2)
		{
			printf("잘못 입력 하셨습니다. 다시 입력해주세요\n");
		}
	}

	if (nWay == 1)
	{
		for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
		{
			nArray[i] = rand();
		}
	}
	else if (nWay == 2)
	{
		for (int i = 0; i < sizeof(nArray) / sizeof(int); i++)
		{
			int nNum = 0;
			printf("%d번째 숫자를 입력하세요 :", i + 1);
			scanf_s("%d", &nNum);
			printf("\n");
			nArray[i] = nNum;
		}
	}
	else
	{
		printf("오류입니다. 프로그램을 종료합니다.\n");
		return 0;
	}


	PrintArray(nArray, sizeof(nArray) / sizeof(nArray[0])); //Sort 전

	Sort(nArray, 0, sizeof(nArray) / sizeof(nArray[0]));

	PrintArray(nArray, sizeof(nArray) / sizeof(nArray[0])); //Sort 후

	return 0;
}

void PrintArray(int arr[], int count)	
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

void Sort(int arr[], int start, int end)	
{
	int left = start;
	int right = end - 1;
	int pivot = start;

	if (start >= end)
		return;

	while (left < right)
	{
		if (left == pivot) {	
			if (arr[pivot] > arr[right])	
			{
				int temp = arr[right];
				arr[right] = arr[pivot];
				arr[pivot] = temp;
				pivot = right;
				left++;	
			}
			else {
				right--;
			}
		}
		else if (pivot == right) 
		{
			if (arr[pivot] < arr[left])
			{
				int temp = arr[left];
				arr[left] = arr[pivot];
				arr[pivot] = temp;
				pivot = left;
				right--;
			}
			else {
				left++;
			}
		}
	}

	PrintArray(nArray, sizeof(nArray) / sizeof(nArray[0])); 
	Sort(arr, start, pivot);	
	Sort(arr, pivot + 1, end);	
}
