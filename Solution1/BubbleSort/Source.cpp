#include <iostream>
using namespace std;

void ImportArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void PrintArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		//bien swapped giup giam cac thao tac thay doi khong can thiet
		bool swapped = 1;
		for (int j = i; j < n; j++) {
			if (a[i] >= a[j]) 
			{
				swap(a[i], a[j]);
				//neu viec thay doi dien ra thi ta tiep tuc vong lap
				//neu viec thay doi khong duoc thuc hien, nghia la 2 phan tu da o dung vi tri
				//thi ket thuc viec so sanh, hoan doi va ket thuc vong lap
				swapped = 0;
			}
		}
		if (swapped) break;
 	}
}

int main() {
	int a[1000], n;
	cin >> n;
	ImportArray(a, n);
	Sort(a, n);
	PrintArray(a, n);
	return 0;
}