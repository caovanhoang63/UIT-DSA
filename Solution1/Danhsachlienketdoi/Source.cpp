#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
	Node* pPre;
};

struct douList {
	Node* pHead;
	Node* pTail;
};

void Init(douList& l) {
	l.pHead = l.pTail = NULL;
}
Node* GetNode(int x) {
	Node* p=new Node;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	p->pPre = NULL;
	return p;
}
void AddTail(douList& l, Node*p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->pPre = l.pTail;
		l.pTail=p;
	}
}
void AddHead(douList& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pHead->pPre = p;
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void PrintdouList(douList l) {
	Node* p = l.pHead;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}
void AddAt(douList& l,Node* np, int k) {
	Node* p = l.pHead;
	for (int i = 0; i < k - 1; i++) {
		p = p->pNext;
	}
	np->pNext = p->pNext;
	p->pNext->pPre = np;
	np->pPre = p;
	p->pNext = np;
}
void DeleteHead(douList& l) {
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	l.pHead->pPre = NULL;
	delete(p);
}
void DeleteTail(douList& l) {
	Node* p = l.pTail;
	l.pTail = l.pTail->pPre;
	l.pTail->pNext = NULL;
	delete(p);
}
void DeleteAt(douList &l,int k){
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	p->pPre->pNext = p->pNext;
	p->pNext->pPre = p->pPre;
	delete(p);
}
int main() {
	int n,x,k;
	douList l;
	Init(l);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddTail(l, GetNode(x));
	}
	PrintdouList(l);
	DeleteHead(l);
	PrintdouList(l);
	DeleteTail(l);
	PrintdouList(l);

	return 0;
}