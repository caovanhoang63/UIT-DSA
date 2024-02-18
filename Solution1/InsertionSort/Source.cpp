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

void Insert(int a[], int k,int x) {
	//gan vt la vi tri cuoi cung cua mang
	int vt = k - 1;
	//dieu kien thuc hien vong lap khi ma phan x van con lon hon gia tri tai vt
	//[1, 2 , 3, 9] x = 5
	//[1, 2, 3 , 9] -> [1, 2, 3, 9, 9] -> [1, 2, 3, 5, 9]
	for (; vt >= 0 && a[vt] > x; vt--)
		a[vt + 1] = a[vt];
	a[vt + 1] = x;
}
//thuc hien viec chen phan tu a[i] vao mot mang con cua a da duoc sap xep truoc do co i phan tu
void Sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		Insert(a, i, a[i]);
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