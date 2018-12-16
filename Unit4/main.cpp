#include<iostream>

using namespace std;

/*
��const��Ա������ �����޸���ͨ��Ա���� 
���ǿ����޸ı�mutable���εı���
*/

class ClxTest{
public:
	ClxTest();
	~ClxTest();
	void Output() const; //������Ա����
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
	//m_count++; // ���뱨����������ͨ�������������m_count, ����޷���������޸�
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