#include "Utility.h"

/*
	冒泡排序算法的运作如下：（从后往前）
	比较相邻的元素。如果第一个比第二个大，就交换他们两个。
	对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
	针对所有的元素重复以上的步骤，除了最后一个。
	持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较
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
	一趟快速排序的算法是：
	1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
	2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
	3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]互换；
	4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]互换；
	5）重复第3、4步，直到i=j； (	3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。
								找到符合条件的值，进行交换的时候i， j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。
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

//用循环能解决的就不要用递归

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
这段代码的主体还是do-while循环，但这个循环的入口点并不一定是在do那里，而是由这个switch语句根据n，把循环的入口定在了几个case标号那里。
程序的执行流程是：程序一开始顺序执行，当它执行到了switch的时候，就会根据n的值，直接跳转到 case n那里（从此，这个swicth语句就再也没有用了）。
程序继续顺序执行，再当它执行到while那里时，就会判断循环条件。
若为真，则while循环开始，程序跳转到do那里开始执行循环
（这时候由于已经没有了switch，所以后面的标号就变成普通标号了，即在没有goto语句的情况下就可以忽略掉这些标号了,即执行8遍*to++ = *from++）；
为假，则退出循环，即程序中止。

它的思路是这样的：把原数组以8个int为单位分成若干个小组，复制的时候以小组为单位复制，即一次复制8个 int。
在达夫设备中，以一次比较运算的代价换来8个int的复制。
而switch语句则是用来处理分组时剩下的不到8个的int（这些剩余的不是数组最后的，而是数组最开始的），很巧妙。
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

//从后往前合并，首先计算出总长度，设置一个指针从arr1数组最后往前移动。
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

	//假设数组arr1有多出来的部分 直接赋值
	while(pos1 >= 0){
		arr1[pos--] = arr1[pos1--];
	}
	
	//假设数组arr2有多出来的部分 直接赋值
	while(pos2 >= 0){  
		arr1[pos--] = arr2[pos2--];
	}
	
	return;
}