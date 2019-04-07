#ifndef _MYLIST_H_
#define _MYLIST_H_

struct ListNode{
	int v;
	ListNode *prev;
	ListNode *next;
};

//双向链表 类似std list
class List{
public:
	/*
	@brief 构造函数
	*/
	List();
	/*
	@brief 析构函数
	*/
	~List();

	/*
	@brief 链表尾部添加元素
	@param[in] v 要追加的元素
	*/
	void push_back(int v);

	/*
	@brief 链表头部添加元素
	@param[in] v 要追加的元素
	*/
	void push_front(int v);

	/*
	@brief 删除所有值等于指定的元素
	@param[in] v 要删除的元素
	*/
	void remove(int v);

	/*
	@brief 把链表添加到末尾
	@param[in] l 要添加的链表
	*/
	void merge(List & l);

	/*
	@brief 打印链表
	*/
	void PrintList();

//private:
	ListNode *m_pHead; // 双向链表的表头
};


#endif // _MYLIST_H_