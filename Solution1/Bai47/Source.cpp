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
void swap(int &a, int &b) {
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
	if (j > l)quicksort(a, l, j);
}

int solve(int a[], int n) {
	if (a[0] > 0) return 0;
	for (int i = 1; i < n-1; i++) {
		if ((a[i+1] - a[i]) > 1) return a[i] +1;
	}
	return a[n - 1] + 1;
}

int main() {
	int a[100001], n;
	cin >> n;
	ImportArray(a, n);
	quicksort(a,0, n-1);
	cout << solve(a, n);
	return 0;
}