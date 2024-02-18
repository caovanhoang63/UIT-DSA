#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};
//khoi tao danh sach lien ket
void Init(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
//Tao node moi
Node* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
//Ham xuat danh sach
void PrintList(List l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->data<<" ";
		p = p->pNext;
	}
}
//Them vao cuoi danh sach
void AddTail(List& l,Node *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Thaydoi(List& l, int a, int b) {
	Node* p = l.pHead;
	while(p != NULL) {
		if (p->data == a) p->data = b;
		p = p->pNext;
	}
}

int main() {
	int n, x, a, b;
	cin >> n;
	List l;
	Init(l);
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddTail(l, GetNode(x));
	}
	cin >> a >> b;
	Thaydoi(l, a, b);
	PrintList(l);
	return 0;
}