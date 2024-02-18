#include <iostream>
#include <string>
using namespace std;
struct Date {
	int ngay, thang, nam;
};
struct MayTinh {
	string id;
	string ten;
	Date NSX;
	float gia;
};
struct Node {
	MayTinh data;
	Node* pNext;
};
struct Queue {
	Node* front;
	Node* rear;
};
void Nhap(Date&);
void Xuat(Date);
void Nhap(MayTinh&);
void Xuat(MayTinh);
void Init(Queue&);
Node* CreateNode(MayTinh);
bool IsEmpty(Queue);
void Enqueue(Queue&,Node*);
void Dequeue(Queue&);
Node* Front(Queue);
void Nhap(int n,Queue&);
void Tim(Queue);
void Xuat(int n, Queue&);
int Size(Queue);
int main() {
	int n;
	cout << "Nhap so may tinh: ";
	cin >> n;
	Queue que;
	Init(que);
	Nhap(n, que);
	int chucnang;
	system("cls");
	while (true) {
		system("cls");
		cout << "Nhap chuc nang: (1: Tim, 2:Xuat) " << endl;
		cin >> chucnang;
		switch (chucnang)
		{
		case 1:
		{
			Tim(que);
			break;
		}
		case 2:
		{
			cout << "Thong tin cua cac may tinh" << endl;
			Xuat(n, que);
			break;
		}
		default:
			cout << "Chuc nang khong ton tai" << endl;
			break;
		}
		system("pause");
		if (chucnang == 2)
			break;
	}
	
	return 0;
}
void Init(Queue& que) {
	que.front = que.rear = NULL;
}
Node* CreateNode(MayTinh x)  {
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
} 
bool IsEmpty(Queue que) {
	if (que.front == NULL)
		return 1;
	return 0;
}
void Enqueue(Queue& que, Node* p) {
	if (que.front == NULL) {
		que.front = que.rear = p;
		return;
	}
	que.rear->pNext = p;
	que.rear = p;
}
void Dequeue(Queue& que) {
	if (que.front == NULL)
		return;
	Node* temp = que.front;
	que.front = que.front->pNext;
	temp->pNext = NULL;
	delete temp;
}
Node* Front(Queue que) {
	return que.front;
}
void Nhap(Date& date) {
	cout << "Nhap ngay: ";
	cin >> date.ngay;
	cout << "Nhap thang: ";
	cin >> date.thang;
	cout << "Nhap nam: ";
	cin >> date.nam;
}
void Xuat(Date date) {
	cout << date.ngay <<"/"<< date.thang <<"/" << date.nam;
}
void Nhap(MayTinh& mt) {
	cout << "Nhap ma: ";
	cin.ignore();
	cin >> mt.id;
	cout << "Nhap ten: ";
	cin.ignore();
	getline(cin, mt.ten);
	cout << "Nhap ngay san xuat: " << endl;
	Nhap(mt.NSX);
	cout << "Nhap gia: ";
	cin >> mt.gia;
}
void Xuat(MayTinh mt) {
	cout << "Ma may tinh: " << mt.id << endl;
	cout << "Ten: " << mt.ten << endl;
	cout << "Ngay san xuat: ";
	Xuat(mt.NSX);
	cout << endl;
	cout << "Gia: " << mt.gia << endl;
}
void Nhap(int n, Queue& que) {
	for (int i = 0; i < n; i++) {
		MayTinh temp;
		cout << "Nhap may tinh thu " << i + 1 << endl;
		Nhap(temp);
		Node* p = CreateNode(temp);
		if (p != NULL) {
			Enqueue(que, p);
		}
	}
}
void Tim( Queue que) {
	string id;
	cout << "Nhap id can tim: " << endl;
	cin >> id;
	Node* p = que.front;
	cout << "Danh sach cac may tinh can tim" << endl;
	cout << "-----------------------------------------------" << endl;
	while (p!=NULL) {
		if (p->data.id == id) {
			Xuat(p->data);
			cout << "-----------------------------------------------" << endl;
		}
		p = p->pNext;
	}
}
int Size(Queue& que) {
	Node* p = que.front;
	int dem = 0;
	while (p != NULL) {
		dem++;
		p = p->pNext;
	}
	return dem;
}
void Xuat(int n, Queue& que) {
	int i = 0; 
	cout << "-----------------------------------------------" << endl;
	while (!IsEmpty(que)) {
		i++;
		cout << "Thong tin cua may tinh thu " << i << endl;
		cout << "-----------------------------------------------" << endl;
		Xuat(que.front->data);
		Dequeue(que);
		cout << "-----------------------------------------------" << endl;
	}
}