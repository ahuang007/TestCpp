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

void List::remove(int v){
	ListNode * pNode = m_pHead->next;
	while (pNode != m_pHead){
		ListNode * pTmpNode = pNode->next;
		if (pNode->v == v){
			pNode->prev->next = pNode->next;
			pNode->next->prev = pNode->prev;
			delete pNode;
		} 
		pNode = pTmpNode;
	}
}

void List::PrintList(){
	ListNode *pNode = m_pHead->next;
	while (pNode != m_pHead){
		cout << pNode->v << " ";
		pNode = pNode->next;
	}
	cout << endl;
}

