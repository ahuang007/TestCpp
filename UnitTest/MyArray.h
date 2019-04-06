#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

// �Զ��嶯̬���� ʵ��vector�Ļ�������
class Array{
public:
	/*
		@brief ���캯��
	*/
	Array(int sz = 8);
	/*
		@brief ��������
	*/
	~Array();

	/*
		@brief ��ȡ�����±��ֵ
		@param[in] idx �����±� ��0��ʼ
		@param[out] v ����ֵ
		@retval ture:���ڣ� false:������
	*/
	bool at(int idx, int &v);

	/*
		@brief ������β�������Ԫ��
		@param v ��Ԫ�ص�ֵ
	*/
	void push_back(int v);

	/*
		@brief ɾ�����е���ָ����ֵ
		@param v Ҫɾ����Ԫ��
		@retval �ܹ�ɾ���˼���
	*/
	int remove_all(int v);

	/*
		@brief ����Ԫ��
		@param v Ҫ���ҵ�Ԫ��
		@retval -1: �����ڣ���֮Ϊ��Ӧ���±� �±��0��ʼ
	*/
	int find(int v);

	int getSize(){
		return m_iSize;
	}

	int getValue(int idx){
		if (idx < m_iSize){
			return m_pData[idx];
		}
		else {
			cerr << "idx error" << idx << endl;
			return 0;
		}
	}

private:
	// ����Ԫ�ظ���
	int m_iSize;
	// �����С
	int m_iMaxSize;
	// ����
	int * m_pData;
};

#endif // _ARRAY_H_