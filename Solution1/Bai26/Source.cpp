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
		cout << p->data << " ";
		p = p->pNext;
	}
}
//Them vao cuoi danh sach
void AddTail(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
//Xoa phan tu lon hon phan tu o chi so k
List deleteBigger(List l, int k) {
	List ll;
	Init(ll);
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	int data = p->data;
	Node* a = l.pHead;
	while (a != NULL) {
		if (a->data <= data) {
			Node* newnode = GetNode(a->data);
			AddTail(ll, newnode);
		}
		a= a->pNext;
	}
	return ll;
}
void PrintNode(List l, int k) {
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	cout << p->data<<endl;
}
int main() {
	int n, x, k;
	List l;
	Init(l);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddTail(l, GetNode(x));
	}
	cin >> k;
	PrintNode(l, k);
	
	PrintList(deleteBigger(l, k));
	return 0;
}