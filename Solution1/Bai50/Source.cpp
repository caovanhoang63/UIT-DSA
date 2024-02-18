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
void quicksort(int a[], int l, int r) {
	int i = l;
	int j = r;
	int p = a[(l + r) / 2];
	while (i < j) {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			swap(a[i++], a[j--]);
		}
	}
	if (i < r) quicksort(a, i, r);
	if (j > l) quicksort(a, l, j);
}


void solve(int a[], int n) {
	int b[100001],m=0,c[100001],p=0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) b[m++] = a[i];
		if (a[i] < 0) c[p++] = a[i];
 	}
	quicksort(b,0, m-1);
	quicksort(c,0, p-1);
	m = 0;
	p--;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) a[i] = b[m++];
		if (a[i] < 0) a[i] = c[p--];
	}
}

int main() {
	int a[100001], n;
	cin >> n;
	ImportArray(a, n);
	solve(a, n);
	PrintArray(a, n);
	return 0;
}