#include<iostream>

using namespace std;

/*
在const成员函数中 不能修改普通成员变量 
但是可以修改被mutable修饰的变量
*/

class ClxTest{
public:
	ClxTest();
	~ClxTest();
	void Output() const; //常量成员函数
	int GetOutputTimes() const;

private:
	mutable int m_iTimes;
	int m_count;
};

ClxTest::ClxTest(){
	m_iTimes = 0;
	m_count = 0;
}

ClxTest::~ClxTest(){
}

void ClxTest::Output() const{
	cout << "Output for test!" << endl;
	//m_count++; // 编译报错：由于正在通过常量对象访问m_count, 因此无法对其进行修改
	m_iTimes++;
}

int ClxTest::GetOutputTimes() const{
	return m_iTimes;
}

int main(){

	ClxTest lx;
	cout << lx.GetOutputTimes() << endl;
	lx.Output();
	cout << lx.GetOutputTimes() << endl;
	return 0;
}