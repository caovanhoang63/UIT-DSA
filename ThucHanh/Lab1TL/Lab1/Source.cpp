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
// Ham khoi tao danh sach lien ket
void init(List& l) {
	l.pHead = l.pTail = NULL;
}
// Ham tao node moi 
Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
// Ham them vao dau danh sach
void AddHead(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}else{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
// Ham them vao cuoi danh sach
void AddTail(List& l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
// Bai 1: Ham nhap danh sach lien ket , duong lai khi nhap so 0


// Bai 2: Ham xuat danh sach
void Print(List l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}
// Bai 3: Ham dem so phan tu cua danh sach
int Count(List l) {
	Node* p = l.pHead;
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->pNext;
	}
	return count;
}
// Bai 4: Xuat phan tu thu n 
int printNode(List l, int k) {
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	return p->info;
}
// Bai 5: Kiem tra mot so co trong danh sach khong
bool checkExist(List l, int x) {
	Node* p = l.pHead;
	while (p != NULL) {
		if (p->info == x)
			return 1;
		p = p->pNext;
	}
	return 0;
}
// Bai 6: Them phan tu moi vao phia sau phan tu biet truoc gia tri k
void addValues(List& l, int x, int k) {
	Node* p = l.pHead;
	while(p->info != k) {
		p = p->pNext;
	}
	Node* NewNode = CreateNode(k);
	NewNode->pNext = p->pNext->pNext;
	p->pNext = NewNode;
}
// Bai 7: Them phan tu vao vi tri k 
void addPos(List& l, int x, int k) {
	if (k == 0) {
		AddTail(l, CreateNode(x));
	}
	Node* p = l.pHead;
	for (int i = 0; i < k; i++) {
		p = p->pNext;
	}
	Node* NewNode = CreateNode(x);
	NewNode->pNext = p->pNext->pNext;
	p->pNext = NewNode;
}
// Bai 8: xuat nguoc danh sach
void PrintFromTail(List& l) {
	List templist;
	init(templist);
	Node* p = l.pHead;
	while (p != NULL) {
		AddHead(templist, p);
		p = p->pNext;
	}
}
// Bai 9: Xoa phan tu co gia tri x trong danh sach lien ket
// neu xoa duoc in ra 1, neu khong xoa duoc xuat 0
bool deleteValues(List& l, int x) {
	Node* p = l.pHead;
	while (p != NULL) {
		if (p->pNext->info == x) {
			Node* temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete temp;
			return 1;
		}
	}
	return 0;
}
// Bai 10: Xoa phan tu dau danh sach
void deleteHead(List& l) {
	Node* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
// Bai 11: Xoa phan tu cuoi danh sach
void deleteTail(List& l) {
	Node* p = l.pHead;
	while (p->pNext->pNext != NULL) {
		p = p->pNext;
	}
	Node* temp = p->pNext;
	p->pNext = NULL;
	l.pTail = p;
	delete temp;
}
// Bai 12: Xoa toan bo danh sach
void deleteList(List& l) {
	Node* p = l.pHead;
	while (p != NULL) {
		Node* temp = p;
		p = p->pNext;
		delete temp;
	}
}
// Bai 13: Them phan tu vao danh sach da duoc sap xep tang dan 
void InsertASD(List& l, int x) {
	if (l.pHead->info <= x) {
		AddHead(l, CreateNode(x));
	}
	Node* p = l.pHead;
	while (p->pNext != NULL) {
		if (p->info <= x && p->pNext->info >= x) {
			Node* NewNode = CreateNode(x);
			NewNode->pNext = p->pNext;
			p->pNext = NewNode;
			return;
		}
	}
	AddTail(l, CreateNode(x));
}
// Bai 14: Noi danh sach A vao danh sach B 
void connect(List& a, List b) {
	a.pTail->pNext = b.pHead;
	a.pTail = b.pTail;
}
// Bai 15: Tach danh sach A ra thanh danh sach B va C 
void split(List &  a, List& b, List& c) {
	Node* p = a.pHead;
	b.pHead = a.pHead;
	for (int i = 0; i < (Count(a) - 1) / 2; i++) {
		p = p->pNext;
	}
	b.pTail = p;
	c.pHead = p->pNext;
	p->pNext = NULL;
	c.pTail = a.pTail;
	a.pHead = NULL;
	a.pTail = NULL;
	deleteList(a);
}
// Bai 16: Tach danh sach lien ket don thanh hai danh sach, B chua so le, C chua so chan
void split_Odd_Even(List& a, List& b, List& c) {
	Node* p = a.pHead;
	while (p != NULL) {
		Node* temp = p;
		p = p->pNext;
		temp->pNext = NULL;
		if (temp->info % 2 != 0) {
			AddTail(b, temp);
		}
		else {
			AddTail(c, temp);
		}
	}
	a.pHead = a.pTail = NULL;
	deleteList(a);
}
// Bai 17: Noi va sap xep tang dan
void connect(List& a, List& b, List& c) {
	Node* ap = a.pHead;
	Node* bp = b.pHead;
	while (ap != NULL && bp != NULL) {
		if (ap->info <= bp->info) {
			Node* temp = ap;
			ap = ap->pNext;
			AddTail(c, temp);
		}
		else {
			Node* temp = bp;
			bp = bp->pNext;
			AddTail(c, temp);
		}
	}
	while (ap != NULL) {
		Node* temp = ap;
		ap = ap->pNext;
		AddTail(c, temp);
	}
	while (bp != NULL) {
		Node* temp = bp;
		bp = bp->pNext;
		AddTail(c, temp);
	}
}
int main() {
	//Bai 1:
	List a,b,c;
	init(a);
	init(b);
	init(c);
	int x;
	while (1) {
		cin >> x;
		if (x == 0) break;
		AddTail(a, CreateNode(x));
	}
	while (1) {
		cin >> x;
		if (x == 0) break;
		AddTail(b, CreateNode(x));
	}
	connect(a, b, c);
	Print(c);

	return 0;
}