#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// dinh nghia kieu du lieu node
struct Node
{
	int info;
	Node *pNext;
};
typedef struct Node NODE;
// dinh nghia kieu du lieu danh sach
struct List
{
	Node *pHead;
	Node *pTail;
};
typedef struct List LIST;
// khoi tao danh sach
void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
// kieam tra danh sach rong
bool isEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
// tao 1 node moi
NODE *GetNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
// them vao vi tri cuoi
void addTail(List &l, Node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
// nhap danh sach voi so phan tu biet truoc
int NhapList(List &l)
{
	Init(l);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		Node *p = GetNode(x);
		if (p != NULL)
		{
			addTail(l, p);
		}
	}
	return 1;
}
// them vao vi tri dau
void addHead(List &l, Node *p)
{
	p->pNext = l.pHead;
	l.pHead = p;
}
// xoa tai vi tri dau
void deleteHead(List &l);
// xoa tai vi tri cuoi
void deleteTail(List &l);

// Bai 1 : Nhap danh sach lien ket don, ket thuc khi nhap so 0
void Nhap1(List &l)
{
	Init(l);
	int n;
	while (cin >> n && n != 0)
	{
		Node *p = new Node;
		if (p != NULL)
			p = GetNode(n);
		addTail(l, p);
	}
}
// bai 2: Xuat danh sach lien ket don
void printList(List l)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}
// Bai 3: Dem so phan tu cua danh sach
int CountNode(List l)
{
	if (l.pHead == NULL)
		return 0;
	int count = 0;
	Node *p = l.pHead;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
// Bai 4: Xuat phan tu thu n cua danh sach lien ket duoc danh so tu 0
void printNode(List l, int k)
{
	Node *p = l.pHead;
	for (int i = 0; i < k; i++)
	{
		p = p->pNext;
	}
	cout << p->info;
}
// Bai 5: kiem tra so nguyen x co ton tai trong danh sach khong
bool ktTonTai(List l, int x)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			return 1;
		p = p->pNext;
	}
	return 0;
}
// Bai 6: them vao sau node k
void addAfterK(List &l, int k, int x)
{
	Node *p = l.pHead;
	while (p->info != x && p != NULL)
	{
		if (p->info == k)
		{
			Node *temp = new Node;
			if (temp != NULL)
			{
				temp = GetNode(x);
				temp->pNext = p->pNext;
				p->pNext = temp;
			}
		}
		p = p->pNext;
	}
}
// Bai 7: Them vao vi tri thu n trong danh sach duoc danh so tu 0
void addAt(List &l, int k, int x)
{
	Node *np = new Node;
	if (np != NULL)
	{
		np = GetNode(x);
		if (k == 0)
		{
			addHead(l, np);
			return;
		}
		Node *p = l.pHead;
		for (int i = 0; i < k - 1; i++)
		{
			p = p->pNext;
		}
		np->pNext = p->pNext;
		p->pNext = np;
	}
}
// Bai 8 : Xuat nguoc danh sach lien ket
void XuatNguoc(List l)
{
	List rlist;
	Init(rlist);
	Node *p = l.pHead;
	while (p != NULL)
	{
		Node *temp = GetNode(p->info);
		addHead(rlist, temp);
		p = p->pNext;
	}
	printList(rlist);
}
// Bai 9 : Xoa phan tu co gia tri x trong dslk
bool DeleteVal(List &l, int x)
{
	if (l.pHead->info == x)
	{
		deleteHead(l);
		return 1;
	}
	Node *p = l.pHead;
	while (p->pNext != NULL && p->pNext->info != x)
	{
		p = p->pNext;
	}
	if (p->pNext != NULL)
	{
		Node *temp = p->pNext;
		p->pNext = temp->pNext;
		delete temp;
		return 1;
	}
	return 0;
}
// Bai 10: Xoa phan tu dau
void deleteHead(List &l)
{
	Node *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete (p);
}
// Bai 11: Xoa phan tu cuoi
void deleteTail(List &l)
{
	Node *p = l.pHead;
	while (p->pNext->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = NULL;
	delete (l.pTail);
}
// Bai 12: Xoa toan bo danh sach lien ket
void deleteList(List &l)
{
	if (l.pHead == NULL)
		return;
	Node *p = l.pHead;
	while (p != NULL)
	{
		Node *temp = p;
		p = p->pNext;
		delete temp;
	}
	l.pHead = l.pTail = NULL;
}
// Bai 13: Them bao toan sap tang
void ThemBaoToan(List &l, int x)
{
	Node *p = new Node;
	if (p != NULL)
	{
		p = GetNode(x);
		if (l.pHead->info > x || l.pHead == NULL)
		{
			p->pNext = l.pHead;
			l.pHead = p;
		}
		else
		{
			Node *temp = l.pHead;
			while (temp->pNext != NULL && temp->pNext->info <= x)
				temp = temp->pNext;
			p->pNext = temp->pNext;
			temp->pNext = p;
		}
	}
}
// Bai 14 : Noi danh sach B vao danh sach A
void Noi(List &A, List B)
{
	if (A.pHead == NULL)
	{
		A.pHead = B.pHead;
		A.pTail = B.pTail;
		return;
	}
	A.pTail->pNext = B.pHead;
	A.pTail = B.pTail;
}
// Bai 15: Tach danh sach
void Tach(List &l, List &a, List &b)
{
	int n = CountNode(l) / 2;
	Node *p = l.pHead;
	if (CountNode(l) % 2 == 1)
		for (int i = 0; i < n; i++)
			p = p->pNext;
	if (CountNode(l) % 2 == 0)
		for (int i = 0; i < n - 1; i++)
			p = p->pNext;
	a.pHead = l.pHead;
	a.pTail = p;
	b.pHead = p->pNext;
	b.pTail = l.pTail;
	a.pTail->pNext = NULL;
}
// Bai 16
void TachChanLe(List &l, List &a, List &b)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		if (p->info % 2 != 0)
		{
			Node *temp = p;
			p = p->pNext;
			temp->pNext = NULL;
			addTail(a, temp);
		}
		else
		{
			Node *temp = p;
			p = p->pNext;
			temp->pNext = NULL;
			addTail(b, temp);
		}
	}
}
// Bai 17 : Noi danh sach a va danh sach b sao cho duoc danh sach c van duoc sap tang
void NoiBaoToan(List &a, List &b, List &c)
{
	Node *pa = a.pHead;
	Node *pb = b.pHead;
	while (pa != NULL && pb != NULL)
	{
		if (pa->info < pb->info)
		{
			Node *temp = pa;
			pa = pa->pNext;
			temp->pNext = NULL;
			addTail(c, temp);
		}
		else
		{
			Node *temp = pb;
			pb = pb->pNext;
			temp->pNext = NULL;
			addTail(c, temp);
		}
	}
	while (pa != NULL)
	{
		Node *temp = pa;
		pa = pa->pNext;
		temp->pNext = NULL;
		addTail(c, temp);
	}
	while (pb != NULL)
	{
		Node *temp = pb;
		pb = pb->pNext;
		temp->pNext = NULL;
		addTail(c, temp);
	}
}
int main()
{
	List l;
	// Bai 1
	Nhap1(l);
	// Bai 2
	printList(l);
	// // Bai 3
	// cout << "So phan tu cua danh sach lien ket: " << CountNode(l) << endl;
	// // Bai 4
	// cout << "Phan tu thu 3 cua danh sach lien ket: ";
	// printNode(l, 3);
	// cout << endl;
	// // Bai 5
	int x;
	// cout << "Nhap x: ";
	// cin >> x;
	// if (ktTonTai(l, x))
	// 	cout << "x ton tai trong danh sach" << endl;
	// else
	// 	cout << "x khong ton tai trong danh sach" << endl;
	// // Bai 6
	int k;
	// cout << "Nhap k: ";
	// cin >> k;
	// cout << "Nhap x: ";
	// cin >> x;
	// addAfterK(l, k, x);
	// cout << "Danh sach sau khi them x: ";
	// printList(l);
	// Bai 7
	// cout << "Nhap vi tri n: ";
	// cin >> k;
	// cout << "Nhap x: ";
	// cin >> x;
	// addAt(l, k, x);
	// cout << "Danh sach sau khi them x: ";
	// printList(l);
	// Bai 8
	// XuatNguoc(l);
	// Bai 9
	// cout << "Nhap x: ";
	// cin >> x;
	// if (DeleteVal(l, x))
	// {
	// 	cout << "Xoa thanh cong" << endl;
	// 	cout << "Danh sach sau khi xoa x: ";
	// 	printList(l)
	// }
	// else
	// 	cout << "Xoa that bai" << endl;
	// Bai 12
	// deleteList(l);
	// printList(l);
	// Bai 13
	// cout << "Nhap x: ";
	// cin >> x;
	// ThemBaoToan(l, x);
	// cout << "Danh sach sau khi them x: ";
	// printList(l);
	// Bai 14:
	// List b;
	// Init(b);
	// Nhap1(b);
	// Noi(l, b);
	// printList(l);
	// Bai 15:
	// List a, b;
	// Init(a);
	// Init(b);
	// Tach(l, a, b);
	// cout << "Danh sach thu nhat: ";
	// printList(a);
	// cout << "Danh sach thu hai: ";
	// printList(b);
	// Bai 16
	// List a, b;
	// Init(a);
	// Init(b);
	// TachChanLe(l, a, b);
	// cout << "Danh sach le: ";
	// printList(a);
	// cout << "Danh sach chan: ";
	// printList(b);
	// Bai 17
	// List a, b;
	// Init(a);
	// Init(b);
	// Nhap1(a);
	// NoiBaoToan(l, a, b);
	// printList(b);
	return 0;
}