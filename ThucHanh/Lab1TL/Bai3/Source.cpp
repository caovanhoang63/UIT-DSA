#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sosinhvien = 0;
struct SinhVien {
	int MSSV;
	string Ten;
	int NamSinh;
	int GioiTinh;
	float DTB;
};
bool KtTrungMSSV(int x, SinhVien a[]) {
	for (int i = 0; i < sosinhvien; i++) {
		if (x == a[i].MSSV)
			return 1;
	}
	return 0;
}

void Nhap(SinhVien a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 <<" : "<<endl;
		SinhVien temp;
		while (true)
		{
			cout << "Nhap MSSV: ";
			cin >> temp.MSSV;
			if ((KtTrungMSSV(temp.MSSV, a)) || (temp.MSSV <= 0) ) {
				cout << "MSSV khong hop le, vui long nhap lai !" << endl;
				continue;
			}
			break;
		}
		cin.ignore();
		cout << "Nhap Ten: ";
		getline(cin, temp.Ten);
		cout << "Nhap nam sinh: ";
		cin >> temp.NamSinh;
		cout << "Nhap gioi tinh: ";
		cin >> temp.GioiTinh;
		while (!(temp.GioiTinh== 1 || temp.GioiTinh==0)) {
			cout << "Gioi tinh khong hop le, vui long nhap lai! " << endl;
			cin >> temp.GioiTinh;
		}
		cout << "Nhap diem trung binh: ";
		cin >> temp.DTB;
		while (temp.DTB < 0 || temp.DTB >10) {
			cout << "Diem trung binh khong hop le, vui long nhap lai! " << endl;
			cin >> temp.DTB;
		}
		a[i] = temp;
		sosinhvien++;
	}
}

void SapMSSV(SinhVien a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++)
		{
			if (a[i].MSSV > a[j].MSSV)
			{
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void SapDTB(SinhVien a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++)
		{
			if (a[i].DTB < a[j].DTB)
			{
				SinhVien temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Xuat(SinhVien a) {
	cout << "MSSV: "<< a.MSSV<<endl;
	cout << "Ten: " << a.Ten<<endl;
	cout << "Nhap nam sinh: " << a.NamSinh << endl;
	cout << "Nhap gioi tinh: " << a.GioiTinh << endl;
	cout << "Nhap diem trung binh: "<<a.DTB<<endl;
}
void Xuat(SinhVien a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Thong tin cua sinh vien thu " << i + 1 << " : " << endl;
		Xuat(a[i]);
	}
}
int main() {
	SinhVien x[100];
	cout << "Nhap so luong sinh vien: ";
	int n;
	cin >> n;
	Nhap(x, n);
	cout << "Danh sach theo MSSV: " << endl;
	SapMSSV(x, n);
	Xuat(x, n);
	cout << "Danh sach theo diem trung binh: " << endl;
	SapDTB(x,n);
	Xuat(x, n);
	return 0;
}