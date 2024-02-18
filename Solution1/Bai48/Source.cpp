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
		if (i <= j) swap(a[i++], a[j--]);
	}
	if (i < r) quicksort(a, i, r);
	if (j > l) quicksort(a, l, j);
}
void solve(int a[], int n) {
	quicksort(a, 0, n - 1);
	int i = 1;
	int count = 1;
	//while (i < n) {
	//	if (a[i] == a[i + 1]) {
	//		count++;
	//		i++;
	//	}
	//	else {
	//		cout << a[i] << " - " << count << " ";
	//		i++;
	//		count = 1;
	//	}

	//}
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) count++;
		else {
			cout << a[i] << " " << count << "; ";
			count = 1;
		}
	}
}

int main() {
	int a[100001], n;
	cin >> n;
	ImportArray(a, n);
	solve(a, n);
	return 0;
}