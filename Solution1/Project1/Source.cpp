#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//dinh nghia kieu du lieu node
struct Node {
	int info;
	Node* pNext;
};
typedef struct Node NODE;
//dinh nghia kieu du lieu danh sach
struct List {
	Node* pHead;
	Node* pTail;
};
typedef struct List LIST;
//khoi tao danh sach
void Init(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;

}
//kieam tra danh sach rong
bool isEmpty(LIST l) {
	if (l.pHead == NULL) return 1;
	return 0;
}
//tao 1 node moi
NODE* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
//them vao vi tri cuoi
void addTail(List &l, Node*p) {
	if (l.pHead==NULL) {
		l.pHead=l.pTail= p;

	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
// xuat danh sach
void printList(List l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->info <<" ";
		p = p->pNext;
	}
	cout << endl;
}
//nhap danh sach voi so phan tu biet truoc
int NhapList(List& l) {
	Init(l);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Node* p = GetNode(x);
		if (p != NULL)
		{
			addTail(l, p);
		}
	}
	return 1;
}
//them vao vi tri dau
void addHead(List& l,Node *p) {
	p->pNext = l.pHead;
	l.pHead=p;
}
//them vao vi tri khac dau cuoi
void addAt(List& l, int k, Node* np) {
	Node* p = l.pHead;
	for (int i = 0; i < k-1 ; i++) {
		p = p->pNext;
	}
	np->pNext = p->pNext;
	p->pNext = np;
}
//xoa tai vi tri dau
void deleteHead(List& l) {
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete(p);
}
//xoa tai vi tri cuoi
void deleteTail(List& l) {
	Node* p = l.pHead;
	while (p->pNext->pNext != NULL) {
		p = p->pNext;
	}
	p->pNext = NULL;
	delete(l.pTail);
}
//xoa tai 1 vi tri khac dau cuoi
void deleteAt(List& l, int k) {
	Node* p = l.pHead;
	//duyet den phan tu thu k - 1
	for (int i = 0; i < k - 1; i++) {
		p = p->pNext;
	}
	Node* temp = p->pNext->pNext;
	//xoa node k
	delete(p->pNext);
	//lien ket node k -1 den node k +1 
	p->pNext = temp;
}
//xuat node tai vi tri k bat ki
void Delete(List& l,int n ,int k) {
	if (k == 0) deleteHead(l);
	else if (k == (n - 1)) deleteTail(l);
	else deleteAt(l,k);
}
//Ham in ra node
void printNode(List l,int k) {
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	cout << p->info;
}
//ham nhap danh sach bang file input
int Nhap(List& l, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true) return 0;
	int n;
	int x;
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++) {
		fi >> x;
		Node* p = GetNode(x);
		if (p != NULL) addTail(l, p);
	}
	return 1;
}
//ham dem so luong node
int CountNode(List l) {
	if (l.pHead == NULL) return 0;
	int count = 0;
	Node* p = l.pHead;
	while (p != NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}
// Xoa
void DeleteVal(List& l, int x) {
	if (l.pHead->info == x)
	{
		deleteHead(l);
		return;
	}
	Node* p = l.pHead;
	while (p->pNext!=NULL && p->pNext->info!=x) {
		p = p->pNext;
	}
	if (p->pNext != NULL) {
		Node* temp = p->pNext;
		p->pNext = temp->pNext;
		delete temp;
	}

}
int main() {
	List l;
	int n;
	NhapList(l);
	DeleteVal(l, 10);
	printList(l);
	return 0;
}