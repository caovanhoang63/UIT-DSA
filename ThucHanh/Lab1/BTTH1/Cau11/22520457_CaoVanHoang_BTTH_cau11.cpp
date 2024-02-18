#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
using namespace std;

int sosinhvien = 0;
struct Ngay {
	int ngay,thang,nam;
};
// cau a
struct SinhVien {
	int MSSV;
	string Ten;
	Ngay NgaySinh;
	int GioiTinh;
	float DTB;
};
bool KtTrungMSSV(int , SinhVien []);
bool KtNamNhuan(int );
bool Nhap(Ngay& );
void Nhap(SinhVien [], int );
bool Nhap(SinhVien[],int, string);
void SapMSSV(SinhVien [], int );
void SapDTB(SinhVien [], int ); 
string Xuat(Ngay );
void Xuat(SinhVien );
void Xuat(SinhVien [], int);
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
	SapDTB(x, n);
	Xuat(x, n);
	return 0;
}


bool KtTrungMSSV(int x, SinhVien a[]) {
	for (int i = 0; i < sosinhvien; i++) {
		if (x == a[i].MSSV)
			return 1;
	}
	return 0;
}

bool KtNamNhuan(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}

bool Nhap(Ngay& ngay) {
	cout << "Nhap ngay: ";
	cin >> ngay.ngay;
	cout << "Nhap thang: ";
	cin >> ngay.thang;
	cout << "Nhap nam: ";
	cin >> ngay.nam;
	if ((ngay.ngay <= 0) || (ngay.thang <= 0) || (ngay.nam <= 0))
		return 0;
	if ((!KtNamNhuan(ngay.nam) && ngay.thang == 2 && ngay.ngay == 29) || (ngay.ngay >= 32) || ngay.thang >= 13)
		return 0;
	switch (ngay.thang)
	{
	case 2:
		if (ngay.ngay > 29)
			return 0;
	case 4:
	case 6:
	case 9:
	case 11:
		if (ngay.ngay == 31)
			return 0;
	}
	return 1;
}

void Nhap(SinhVien a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << " : " << endl;
		SinhVien temp;
		while (true)
		{
			cout << "Nhap MSSV: ";
			cin >> temp.MSSV;
			if ((KtTrungMSSV(temp.MSSV, a)) || (temp.MSSV <= 0)) {
				cout << "MSSV khong hop le, vui long nhap lai !" << endl;
				continue;
			}
			break;
		}
		cin.ignore();
		cout << "Nhap Ten: ";
		getline(cin, temp.Ten);
		cout << "Nhap ngay thang nam sinh: " << endl;
		while (true) {
			bool check = Nhap(temp.NgaySinh);
			if (check)
				break;
			else
			{
				cout << " Ngay thang nam sinh khong hop le, vui long nhap lai: " << endl;
			}
		}
		cout << "Nhap gioi tinh: ";
		cin >> temp.GioiTinh;
		while (!(temp.GioiTinh == 1 || temp.GioiTinh == 0)) {
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
string Xuat(Ngay ngay) {

	return  to_string(ngay.ngay) +  "/" + to_string( ngay.thang) + "/" + to_string(ngay.nam) ;
}
void Xuat(SinhVien a) {
	cout << "MSSV: " << a.MSSV << endl;
	cout << "Ten: " << a.Ten << endl;
	cout << " nam sinh: ";
	cout << "Ngay sinh" << Xuat(a.NgaySinh)<<endl;
	cout << "Gioi tinh: ";
	if (a.GioiTinh == 1)
		cout << "Nam" << endl;
	else
		cout << "Nu" << endl;
	cout << "Diem trung binh: " << a.DTB << endl;
}
void Xuat(SinhVien a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Thong tin cua sinh vien thu " << i + 1 << " : " << endl;
		Xuat(a[i]);
	}
}
bool Nhap(SinhVien a[], int n, string filename) {
	ofstream fo(filename);
	if (fo.fail() == true)
	{
		cout << "Loi mo file!" << endl;
		return 0;
	}
	fo << n;
	for (int i = 0; i < n; i++) {
		fo<<a[i]->MSSV << " " << a[i]->GioiTinh << " " << a[i]->Ten << " " << xuat(a->NgaySinh)
	}
}
