#include <iostream>
using namespace std;

int BinarySearch(int a[], int n,int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (a[m] < x) {
			l = m+1;
		}
		else if (a[m] > x) {
			r = m;
		}
	}
	if (a[l] == x) return l;
	else return -1;
}

int main() {
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x;
	cin >> x;
	cout << BinarySearch(a, n, x);
	return 0;
}