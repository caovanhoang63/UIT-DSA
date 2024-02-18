#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};
typedef struct Node NODE;

struct cirList {
	Node* pHead;
	Node* pTail;
};

void Init(cirList& l) {
	l.pHead = l.pTail = NULL;
}

Node* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void AddTail(cirList& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	l.pTail->pNext = p;
	p->pNext = l.pHead;
	l.pTail = p;
}
void PrintList(cirList l,int k) {
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	cout << p->data << " ";
	Node* p2 = p->pNext;
	while (p2 != p) {
		cout << p2->data<<" ";
		p2 = p2->pNext;
	}
}

int main() {
	int n, x;
	cirList l;
	Init(l);
 	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddTail(l, GetNode(x));
	}
	int k;
	cin >> k;
	PrintList(l,k);
	return 0;
}
