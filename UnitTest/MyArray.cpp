#include "MyArray.h"

Array::Array(int sz){
	cout << "Array Construct ----" << endl;
	if (sz > 0){
		m_iSize = 0;
		m_iMaxSize = sz;
		m_pData = new int[sz];
		cout << "Array::Array(int sz) new ------" << endl;
	} else {
		cerr << "sz error" << sz << endl;
	}
}

Array::~Array(){
	cout << "Array DeConstruct ----" << endl;
	m_iSize = 0;
	m_iMaxSize = 0;
	if (m_pData != NULL){
		delete[] m_pData;
		cout << "Array::~Array(int sz) delete ------" << endl;
	}
}

void Array::push_back(int v){
	if (m_iSize >= m_iMaxSize){
		m_iMaxSize *= 2;
		int* pNewData = new int[m_iMaxSize]; // todo: 如果申请不到内存 则报错
		for (int i = 0; i < m_iSize; i++){
			pNewData[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = pNewData;
		cout << "expand| " << m_iSize << "|" << m_iMaxSize << endl;
	}
	m_pData[m_iSize] = v;
	m_iSize++;
}