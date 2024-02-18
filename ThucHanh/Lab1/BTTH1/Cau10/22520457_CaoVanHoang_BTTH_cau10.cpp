#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SoHang {
	bool dau;
	float he_so;
	int bac;
};
struct DaThuc {
	SoHang* dathuc;
	int so_so_hang;
};
void Nhap(SoHang *a) {
	cout << "Nhap dau: ";
	cin >> a->dau;
	cout << "Nhap he so: ";
	cin >> a->he_so;
	cout << "Nhap bac: ";
	cin >> a->bac;
}
void Nhap(DaThuc& a) {
	cout << "Nhap so so hang: ";
	cin >> a.so_so_hang;
	a.dathuc = new SoHang[a.so_so_hang];
	for (int i = 0; i < a.so_so_hang; i++) {
		cout << "Nhap so hang thu " << i+1 << ": " << endl;
		Nhap((a.dathuc+i));
	}
}
void Xuat(SoHang* a) {
	if (a->dau == 0) cout<<'-';
	else cout<<'+';
	cout << setprecision(3) << (a->he_so);
	if(a->bac !=0)
	{
		if (a->bac == 1)
			cout << 'x';
		else
			cout << "x^" << a->bac;
	}
	
}
void Xuat(DaThuc a) {
	for (int i = 0; i < a.so_so_hang; i++) {
		Xuat(a.dathuc + i);
	}
}
void swap(SoHang* a, SoHang* b) {
	SoHang temp = *a;
	*a = *b;
	*b = temp;
}
void sort(DaThuc& a) {
	for (int i = 0; i < a.so_so_hang - 1; i++) {
		for (int j = i + 1; j < a.so_so_hang; j++) {
			if ((a.dathuc + i)->bac > (a.dathuc + j)->bac) {
				swap(a.dathuc + i, a.dathuc + j);
			}
		}
	}
}
int main() {
	DaThuc a;
	Nhap(a);
	sort(a);
	Xuat(a);
	return 0;
}