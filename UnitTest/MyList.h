#ifndef _MYLIST_H_
#define _MYLIST_H_

struct ListNode{
	int v;
	ListNode *prev;
	ListNode *next;
};

//˫������ ����std list
class List{
public:
	/*
	@brief ���캯��
	*/
	List();
	/*
	@brief ��������
	*/
	~List();

	/*
	@brief ����β�����Ԫ��
	@param[in] v Ҫ׷�ӵ�Ԫ��
	*/
	void push_back(int v);

	/*
	@brief ����ͷ�����Ԫ��
	@param[in] v Ҫ׷�ӵ�Ԫ��
	*/
	void push_front(int v);

	/*
	@brief ɾ������ֵ����ָ����Ԫ��
	@param[in] v Ҫɾ����Ԫ��
	*/
	void remove(int v);

	/*
	@brief ��������ӵ�ĩβ
	@param[in] l Ҫ��ӵ�����
	*/
	void merge(List & l);

	/*
	@brief ��ӡ����
	*/
	void PrintList();

//private:
	ListNode *m_pHead; // ˫������ı�ͷ
};


#endif // _MYLIST_H_