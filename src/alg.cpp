#include<iostream>
using namespace std;
int countPairs1(int* arr, int len, int value)
{
	int count = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == value)
				count++;
		}
	}
	return count;
}
int countPairs2(int* arr, int len, int value)
{
	int count = 0;
	for (int i = 0; i <= len/2; i++)
	{
		for (int j = len; j > len/2; j--)
		{
			if (arr[i] + arr[j] == value)
				count++;
		}
	}
	return count;
}
int countPairs3(int* arr, int len, int value)
{
	int count = 0;
	int mid = 0;
	for (int i = 0; i <= len; i++)
	{
		int lx = len, rx = len;
		int left = i + 1, right = len - 1;
		bool k = 0;
		while (left <= right) 
		{
			mid = (left + right) / 2;
			if (arr[mid] == value - arr[i]) 
				k = 1;
			if (arr[mid] > value - arr[i]) 
			{
				lx = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		left = i + 1; right = len - 1;
		while (left <= right) 
		{
			mid = (left + right) / 2;
			if (arr[mid] == value - arr[i]) 
				k = 1;
			if (arr[mid] >= value - arr[i]) 
			{
				rx = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		if (k) 
			count += (lx - rx);
	}
	return count;
}
