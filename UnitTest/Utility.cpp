#include "Utility.h"

/*
	ð�������㷨���������£����Ӻ���ǰ��
	�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
	��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
	������е�Ԫ���ظ����ϵĲ��裬�������һ����
	����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚ�
*/

void BubbleSort(int a[], int n)
{
	int i,j,temp;
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-1-j;i++)
		{
			if(a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
}

/*
	һ�˿���������㷨�ǣ�
	1��������������i��j������ʼ��ʱ��i=0��j=N-1��
	2���Ե�һ������Ԫ����Ϊ�ؼ����ݣ���ֵ��key����key=A[0]��
	3����j��ʼ��ǰ���������ɺ�ʼ��ǰ����(j--)���ҵ���һ��С��key��ֵA[j]����A[j]��A[i]������
	4����i��ʼ�������������ǰ��ʼ�������(i++)���ҵ���һ������key��A[i]����A[i]��A[j]������
	5���ظ���3��4����ֱ��i=j�� (	3,4���У�û�ҵ�����������ֵ����3��A[j]��С��key,4��A[i]������key��ʱ��ı�j��i��ֵ��ʹ��j=j-1��i=i+1��ֱ���ҵ�Ϊֹ��
								�ҵ�����������ֵ�����н�����ʱ��i�� jָ��λ�ò��䡣���⣬i==j��һ����һ��������i+��j-��ɵ�ʱ�򣬴�ʱ��ѭ����������
*/

void QuickSort(int a[], int low, int high)
{
	if(low >= high)
	{
		return;
	}

	int first = low;
	int last = high;
	int key = a[first];
	while(first < last)
	{
		while(first < last && a[last] >= key)
		{
			--last;
		}
		a[first] = a[last];

		while((first < last && a[first] <= key))
		{
			++first;
		}
		a[last] = a[first];
	}

	a[first] = key;

	QuickSort(a, low, first-1);
	QuickSort(a, last+1, high);
}

//��ѭ���ܽ���ľͲ�Ҫ�õݹ�

double Factorial(int n)
{
	double result = 1;
	for(int i=1; i<=n; i++)
	{
		result *= i;
	}

	return result;
}

int Fibonacci(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;

	if(n > 2)
	{
		for(int i=0;i<n-2;i++)
		{
			f3 =f1+f2;
			f1 =f2;
			f2 =f3;
		}
		return f3;
	}
	else if(n==2)
	{
		return 1;	
	}
	else if(n ==1)
	{
		return 1;
	}

	return 1;
}

/*
��δ�������廹��do-whileѭ���������ѭ������ڵ㲢��һ������do������������switch������n����ѭ������ڶ����˼���case������
�����ִ�������ǣ�����һ��ʼ˳��ִ�У�����ִ�е���switch��ʱ�򣬾ͻ����n��ֵ��ֱ����ת�� case n����Ӵˣ����swicth������Ҳû�����ˣ���
�������˳��ִ�У��ٵ���ִ�е�while����ʱ���ͻ��ж�ѭ��������
��Ϊ�棬��whileѭ����ʼ��������ת��do���￪ʼִ��ѭ��
����ʱ�������Ѿ�û����switch�����Ժ���ı�žͱ����ͨ����ˣ�����û��goto��������¾Ϳ��Ժ��Ե���Щ�����,��ִ��8��*to++ = *from++����
Ϊ�٣����˳�ѭ������������ֹ��

����˼·�������ģ���ԭ������8��intΪ��λ�ֳ����ɸ�С�飬���Ƶ�ʱ����С��Ϊ��λ���ƣ���һ�θ���8�� int��
�ڴ���豸�У���һ�αȽ�����Ĵ��ۻ���8��int�ĸ��ơ�
��switch������������������ʱʣ�µĲ���8����int����Щʣ��Ĳ����������ģ����������ʼ�ģ��������
*/

void DuffDevice( int * to, int * from, int count)
{ 
	int n = (count+7)/8; 
	switch (count%8)
	{
	case 0 :    do { * to ++ = * from ++ ; 
	case 7 :         * to ++ = * from ++ ; 
	case 6 :         * to ++ = * from ++ ; 
	case 5 :         * to ++ = * from ++ ; 
	case 4 :         * to ++ = * from ++ ; 
	case 3 :         * to ++ = * from ++ ; 
	case 2 :         * to ++ = * from ++ ; 
	case 1 :         * to ++ = * from ++ ; 
					} while (--n >0);
	}  
}

//�Ӻ���ǰ�ϲ������ȼ�����ܳ��ȣ�����һ��ָ���arr1���������ǰ�ƶ���
void sort2arr(int *arr1, int len1, int *arr2, int len2)
{
	int pos = 0;   
	int pos1 = len1 - 1;  
	int pos2 = len2 - 1;  
	pos = len1 + len2 -1;   

	while(pos1 >= 0 && pos2 >= 0){  
		if(arr1[pos1] > arr2[pos2]){  
			arr1[pos--] = arr1[pos1--];
		} else {
			arr1[pos--] = arr2[pos2--];
		}
	}

	//��������arr1�ж�����Ĳ��� ֱ�Ӹ�ֵ
	while(pos1 >= 0){
		arr1[pos--] = arr1[pos1--];
	}
	
	//��������arr2�ж�����Ĳ��� ֱ�Ӹ�ֵ
	while(pos2 >= 0){  
		arr1[pos--] = arr2[pos2--];
	}
	
	return;
}