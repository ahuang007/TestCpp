#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

// 自定义动态数组 实现vector的基本功能
class Array{
public:
	/*
		@brief 构造函数
	*/
	Array(int sz = 8);
	/*
		@brief 析构函数
	*/
	~Array();

	/*
		@brief 获取数组下标的值
		@param[in] idx 数组下标 从0开始
		@param[out] v 返回值
		@retval ture:存在， false:不存在
	*/
	bool at(int idx, int &v);

	/*
		@brief 在数组尾部添加新元素
		@param v 新元素的值
	*/
	void push_back(int v);

	/*
		@brief 删除所有等于指定的值
		@param v 要删除的元素
		@retval 总共删除了几个
	*/
	int remove_all(int v);

	/*
		@brief 查找元素
		@param v 要查找的元素
		@retval -1: 不存在；反之为相应的下标 下标从0开始
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
	// 数组元素个数
	int m_iSize;
	// 数组大小
	int m_iMaxSize;
	// 数组
	int * m_pData;
};

#endif // _ARRAY_H_