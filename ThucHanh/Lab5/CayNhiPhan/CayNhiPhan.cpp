#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node {
	int info;
	Node* pLeft;
	Node* pRight;
};
typedef struct Node* Tree;
void init(Tree& t) {
	t = NULL;

}
Node* createNode(int x) {
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
void insertNode(Tree& t, int x) {
	if (t != NULL) {
		if (x == t->info) {
			return;
		}
		else if (x < t->info)
			insertNode(t->pLeft, x);
		else {
			insertNode(t->pRight, x);
		}
		return;
	}
	t = createNode(x);
	return;
}
void Nhap(Tree& t) {
	int n, x;
	cout << "Nhap so phan tu: ";
	cin >> n;
	cout << "Nhap cac phan tu cua cay: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		Node* p = createNode(x);
		if (p != NULL) {
			insertNode(t, p);
		}
	}
}
void LNR(Tree t) {
	if (t != NULL) {
		LNR(t->pLeft);
		cout << t->info << " ";
		LNR(t->pRight);
	}
}
void NLR(Tree t) {
	if (t != NULL) {
		cout << t->info << " ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}
void RNL(Tree t) {
	if (t != NULL) {
		RNL(t->pRight);
		cout << t->info << " ";
		RNL(t->pLeft);
	}
}
void ThayThe(Tree& p, Tree& t) {
	if (t->pLeft != NULL)
		ThayThe(p, t->pLeft);
	else
	{
		p->info == t->info;
		p = t;
		t = t->pRight;
	}
}
void deleteByValue(Tree& t, int x) {
	if (t != NULL) {
		if (t->info < x)
			deleteByValue(t->pRight, x);
		else if (t->info > x) deleteByValue(t->pLeft, x);
		else {
			Node* p = t;
			if (t->pLeft == NULL) t = t->pRight;
			else if (t->pRight == NULL) t = t->pLeft;
			else {
				ThayThe(p, t->pRight);
			}
			delete p;
		}
	}

}
int Nhap(Tree& t, string filename) {
	ifstream fi(filename);
	if (fi.fail() == true) {
		return 0;
	}
	int n, x;
	fi >> n;
	for (int i = 0; i < n; i++) {
		fi >> x;
		Node* p = createNode(x);
		if (p != NULL)
			insertNode(t, p);
	}
	return 1;
}
int demNodeCoGiaTriNhoHonX(Tree t, int x) {
	int dem = 0;
	if (t != NULL)
	{
		if (t->info < x)
			dem++;
		dem += demNodeCoGiaTriNhoHonX(t->pLeft, x) + demNodeCoGiaTriNhoHonX(t->pRight, x);
	}
	return dem;
}
Node* timNodeCoGiaTriNhoNhat(Tree t) {
	if (t == NULL)
		return NULL;
	else {
		if (t->pLeft == NULL) {
			return t;
		}
		else {
			return timNodeCoGiaTriNhoNhat(t->pLeft);
		}
	}
}
// Cau 1
void inNodeChan(Tree t) {
	if (t != NULL) {
		inNodeChan(t->pLeft);
		if (t->info % 2 == 0)
			cout << t->info << " ";
		inNodeChan(t->pRight);
	}
}
// Cau 2
void inNodeCoGiaTriLonHonX(Tree t, int x) {
	if (t != NULL) {
		inNodeCoGiaTriLonHonX(t->pLeft, x);
		if (t->info > x)
			cout << t->info << " ";
		inNodeCoGiaTriLonHonX(t->pRight, x);
	}
}
// Cau 3 
int demNode(Tree t) {
	if (t == NULL)
		return 0;
	return 1 + demNode(t->pLeft) + demNode(t->pRight);
}
// Cau 4 
int tinhChieuCao(Tree t) {
	if (t == NULL)
		return 0;
	return 1 + max(tinhChieuCao(t->pLeft), tinhChieuCao(t->pRight));
}
// Cau 5
Node* timNodeCoGiaTriX(Tree t, int x) {
	if (t == NULL)
		return NULL;
	else {
		if (t->info == x)
			return t;
		else if (t->info < x) {
			timNodeCoGiaTriX(t->pRight, x);
		}
		else {
			timNodeCoGiaTriX(t->pLeft, x);
		}
	}
}
// Cau 6
Node* timNodeCoGiaTriLonNhat(Tree t) {
	if (t == NULL)
		return NULL;
	else {
		if (t->pRight == NULL) {
			return t;
		}
		else {
			return timNodeCoGiaTriLonNhat(t->pRight);
		}
	}
}
// Cau 7
Node* timNodeCoGiaTriNhoNhatCuaCayConBenPhai(Tree t) {
	if (t == NULL)
		return NULL;
	else {
		if (t->pRight == NULL)
			return NULL;
		else
			return timNodeCoGiaTriNhoNhat(t->pRight);
	}
}
// Cau 8
int demLa(Tree t) {
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	return demLa(t->pLeft) + demLa(t->pRight);
}
// Cau 9 
int demNodeCoMotCayCon(Tree t) {
	if (t == NULL)
		return 0;
	if (t != NULL) {
		if (((t->pLeft == NULL) ^ (t->pRight == NULL)) == 1) 
			return 1 + demNodeCoMotCayCon(t->pLeft) + demNodeCoMotCayCon(t->pRight);
		else
			return demNodeCoMotCayCon(t->pLeft) + demNodeCoMotCayCon(t->pRight);
	}
}

// cau 10
int demNodeChiCoCayConBenPhai(Tree t) {
	if (t != NULL) {
		if (t->pLeft == NULL && t->pRight != NULL)
			return 1 + demNodeChiCoCayConBenPhai(t->pLeft) + demNodeChiCoCayConBenPhai(t->pRight);
		return demNodeChiCoCayConBenPhai(t->pLeft) + demNodeChiCoCayConBenPhai(t->pRight);
	}
	return 0;
}
// cau 11
int demNodeChiCoCayConBenTrai(Tree t) {
	if (t != NULL) {
		if (t->pLeft != NULL && t->pRight == NULL)
			return 1 + demNodeChiCoCayConBenTrai(t->pLeft) + demNodeChiCoCayConBenTrai(t->pRight);
		return demNodeChiCoCayConBenTrai(t->pLeft) + demNodeChiCoCayConBenTrai(t->pRight);
	}
	return 0;
}
// cau 12 
int demNodeCo2CayCon(Tree t) {
	if (t != NULL) {
		if (t->pLeft != NULL && t->pRight != NULL)
			return 1 + demNodeCo2CayCon(t->pLeft) + demNodeCo2CayCon(t->pRight);
		return demNodeCo2CayCon(t->pLeft) + demNodeCo2CayCon(t->pRight);
	}
	return 0;
}
// cau 13
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
// cau 14
int tinhDoDaiTuGocDenNode(Tree t, int x) {
	if (t == NULL)
		return -1;
	if (t->info == x)
		return 0;
	int khoangcach = -1;
	if ((khoangcach = tinhDoDaiTuGocDenNode(t->pLeft, x)) >= 0 || (khoangcach = tinhDoDaiTuGocDenNode(t->pRight, x)) >= 0)
		return khoangcach + 1;
	return khoangcach;
}
int main() {
	Tree t;
	init(t);
	int cau,x;
	Nhap(t);
	while (true) {
		cout << "Nhap cau ma co muon kiem tra di a ^^"<<endl;
		cout << "Hoac nhan 0 de ket thuc =<" << endl;
		cin >> cau;
		switch (cau)
		{
		case 1:
			cout << "Cac so chan trong cay la: ";
			inNodeChan(t);
			cout << endl;
			break;
		case 2:
			cout << "Nhap so x: ";
			cin >> x;
			cout << "Cac so co gia tri lon hon x o trong cay la: ";
			inNodeCoGiaTriLonHonX(t, x);
			cout << endl;
			break;
		case 3:
			cout << "So node trong cay la: " << demNode(t) << endl;
			break;
		case 4:
			cout << "Do cao cua cay la: " << tinhChieuCao(t) << endl;
			break;
		case 5:
		{
			cout << "Nhap gia tri x: ";
			cin >> x;
			Node* kq = timNodeCoGiaTriX(t, x);
			if (kq == NULL)
				cout << "gia tri " << x << " khong ton tai trong mang" << endl;
			else
				cout << "gia tri " << kq->info << " ton tai trong mang" << endl;
			break;
		}
		case 6:
			cout << "Node co gia tri lon nhat trong cay la " << timNodeCoGiaTriLonNhat(t)->info << endl;
			break;
		case 7:
		{
			Node* kq = timNodeCoGiaTriNhoNhatCuaCayConBenPhai(t);
			if (kq == NULL)
				cout << "Khong ton tai cay hoac khong ton tai cay con ben phai " << endl;
			else
				cout << "Node co gia tri nho nhat cua cay con ben phai la " << kq->info << endl;
			break;
		}
		case 8:
			cout << "So node la trong cay la " << demLa(t) << endl;
			break;
		case 9:
			cout << "So Node co 1 cay con la: " << demNodeCoMotCayCon(t) << endl;
			break;
		case 10:
			cout << "So Node chi co cay con ben phai la: " << demNodeChiCoCayConBenPhai(t) << endl;
			break;
		case 11:
			cout << "So Node chi co cay con ben trai la: " << demNodeChiCoCayConBenTrai(t) << endl;
			break;
		case 12:
			cout << "So Node co 2 cay con la: " << demNodeCo2CayCon(t) << endl;
			break;
		case 13:
			cout << "Nhap muc can in: ";
			cin >> x;
			xuatCayTheoTungMuc(t, x);
			cout << endl;
			break;
		case 14:
		{
			cout << "Nhap node can tinh do dai: ";
			cin >> x;
			int kq = tinhDoDaiTuGocDenNode(t, x);
			if (kq == -1)
				cout << "Node khong ton tai trong cay" << endl;
			else
				cout << "Do dai tu goc den node can tinh la " << kq << endl;
			break;
		}
		case 0: 
			break;
		default:
			cout << "Cau nay khong co trong de co oi =((" << endl;
			break;
		}
		if (cau == 0)
			break;
		cout << "Nhan phim bat ky de tiep tuc!" << endl;
		system("pause");
		system("cls");

	}
	return 0;
}