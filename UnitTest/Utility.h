#ifndef _UTILITY_H
#define _UTILITY_H

#include <string>
#include <vector>

/*
	��������
*/

//ð�ݷ�����
void BubbleSort(int a[], int n);

//����
void QuickSort(int a[], int low, int high);

//�׳�
double Factorial(int n);

//쳲���������
int Fibonacci(int n);

//Duff�豸
void DuffDevice(int *to, int *from, int count);

//��������������ϲ���һ����������(�����һ������ռ��㹻������������)
void sort2arr(int *arr1, int len1, int *arr2, int len2); 

#endif //_UTILITY_H
