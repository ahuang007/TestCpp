#ifndef _UTILITY_H
#define _UTILITY_H

#include <string>
#include <vector>

/*
	帮助函数
*/

//冒泡法排序
void BubbleSort(int a[], int n);

//快排
void QuickSort(int a[], int low, int high);

//阶乘
double Factorial(int n);

//斐波那契数列
int Fibonacci(int n);

//Duff设备
void DuffDevice(int *to, int *from, int count);

//将两个有序数组合并成一个有序数组(假设第一个数组空间足够容纳两个数组)
void sort2arr(int *arr1, int len1, int *arr2, int len2); 

#endif //_UTILITY_H
