
#include<iostream>
using namespace std;

int main(){
	long a = -1L;
	unsigned int b = 100;
	cout << sizeof(long) << "|" << sizeof(unsigned int) << "|"<<sizeof(float)<<"|"<<sizeof(double)<< endl;
	cout << "a vs b: " << (a > b ? a : b) << endl;
	system("pause");
	return 0;
}

// ���Ϊ:  4294967295
/*ԭ�����
	����long�ȼ���unsigned int�� ������32/64λϵͳ�ж���32λ����
	��long ������������unsigned int������ֵ����˱������Ὣ��������������ת��Ϊunsigned long
	��� ��unsigned long)a �Ľ���ͱ����һ���ܴ����
	-1 ���޷����еı���Ϊ FFFF FFFF = 2^32 - 1 = 4294967296 -1 = 4294967295
*/