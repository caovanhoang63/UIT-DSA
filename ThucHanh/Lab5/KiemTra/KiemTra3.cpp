#include <iostream>
using namespace std;

struct Node {
	char info;
	Node* pLeft;
	Node* pRight;
};
typedef struct Node* Tree;
void init(Tree& t) {
	t = NULL;

}
Node* createNode(char x) {
	Node* p = new Node;
	if (p != NULL) {
		p->info = x;
		p->pRight = p->pLeft = NULL;
	}return p;
}
void insertNode(Tree& t, Node* p) {
	if (t != NULL) {
		if (p->info == t->info) {
			return;
		}
		else if (p->info < t->info)
			insertNode(t->pLeft, p);
		else {
			insertNode(t->pRight, p);
		}
		return;
	}
	t = p;
	return;
}
int demNode(Tree t) {
	if (t == NULL)
		return 0;
	return 1 + demNode(t->pLeft) + demNode(t->pRight);
}
void xuatCayTheoTungMuc(Tree t, int muc) {
	if (t == NULL)
		return;
	if (muc == 0)
		cout << t->info << " ";
	else if (muc > 0) {
		xuatCayTheoTungMuc(t->pLeft, muc - 1);
		xuatCayTheoTungMuc(t->pRight, muc - 1);
	}
}
void LNR(Tree t) {
	if (t != NULL) {
		LNR(t->pLeft);
		cout << t->info << " ";
		LNR(t->pRight);
	}
}
void Nhap(Tree& t) {
	int n;
	char x;
	cout << "Nhap so phan tu cua cay: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		Node* p = createNode(x);
		if (p != NULL) {
			insertNode(t, p);
		}
	}
}
int demLa(Tree t) {
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	return demLa(t->pLeft) + demLa(t->pRight);
}
void xuatNodeCo1CayCon(Tree t) {
	if (t != NULL) 
	{
		if (((t->pLeft == NULL) ^ (t->pRight == NULL)) == 1)
			cout << t->info << " ";
		xuatNodeCo1CayCon(t->pLeft);
		xuatNodeCo1CayCon(t->pRight);
	}
}
int main() {
	Tree t;
	init(t);
	Nhap(t);
	LNR(t);
	cout << "\nSo node la trong cay:  " << demLa(t) << endl;
	cout << "Nhap muc can xuat: ";
	int muc;
	cin >> muc;
	cout << "Cac gia tri o muc " << muc << " la: ";
	xuatCayTheoTungMuc(t, muc);
	cout << "Cac node co 1 cay con: ";
	xuatNodeCo1CayCon(t);
	return 0;
}