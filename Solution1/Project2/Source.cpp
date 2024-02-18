#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

void Init(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

Node* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return  NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void addTail(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List& l) {
	Init(l);
	int n;
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL) {
			addTail(l, p);
		}
	}
}
void printList(List l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->pNext;
	}
}
void addHead(List& l, Node* p) {
	p->pNext = l.pHead;
	l.pHead = p;
}
void addAt(List& l, int k, Node* np) {
	Node* p = l.pHead;
	for (int i = 2; i <= k - 1; i++) {
		p = p->pNext;
	}
	np->pNext = p->pNext;
	p->pNext = np;
}
int main() {
	List l;
	Nhap(l);
	int x;
	cin >> x;
	int k;
	cin >> k;
	addAt(l, k, GetNode(x));
	printList(l);
	return 0;
}