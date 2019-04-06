#include "MyList.h"
#include <iostream>
using namespace std;

List::List(){
	cout << "List Construct ----" << endl;
	m_pHead = new ListNode;
	m_pHead->next = m_pHead;
	m_pHead->prev = m_pHead;
}

List::~List(){
	cout << "List DeConstruct ----" << endl;
	while (m_pHead->next != m_pHead){
		ListNode* pNode = m_pHead->next;
		m_pHead->next = pNode->next;
		delete pNode;
	}
	m_pHead->next = m_pHead;
	m_pHead->prev = m_pHead;

	delete  m_pHead;
	m_pHead = NULL;
}

void List::push_back(int v){
	ListNode* pNewNode = new ListNode;
	pNewNode->v = v;
	pNewNode->prev = m_pHead->prev;
	pNewNode->next = m_pHead;
	m_pHead->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
	
}

void List::push_front(int v){
	ListNode* pNewNode = new ListNode;
	pNewNode->v = v;
	m_pHead->next->prev = pNewNode;
	pNewNode->next = m_pHead->next;
	m_pHead->next = pNewNode;
	pNewNode->prev = m_pHead;
}

