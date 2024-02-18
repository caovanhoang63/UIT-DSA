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
void merge(int a[], int l, int m, int r) {
	int i=0, j=0, k=l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for  (i=0; i < n1; i++)
		L[i] = a[l + i];
	for (j=0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = j = 0;
	while (i < n1 && j < n2)
		a[k++] = L[i] <= R[j] ? L[i++] : R[j++];
	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
	delete[]L,R;
}
void mergesort(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, m, r);
	}
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
int solve(int a[], int n, int k) {
	quicksort(a, 0, n - 1);
	int count = 0;
	for (int i = 1; i < n; i++) {
		if ((a[i] - a[i - 1]) > k)count++;
	}
	return count +1;
}
int main() {
	int a[100001], n,k;
	cin >> n;
	ImportArray(a, n);
	cin >> k;
	cout<<solve(a, n, k);
	return 0;
}