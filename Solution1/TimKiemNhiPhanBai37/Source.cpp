#include <iostream>
using namespace std;

int BinarySearch(int a[], int n,int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (a[m] < x) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	if (a[l] == x) return l;
	else return -1;
}

void PrintArray(int a[], int l,int r) {
	for (int i = l; i <= r; i++) {
		cout << a[i] << " ";
	}
}

void ImportArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool solve(int a[], int b[], int n, int s) {
	b[0] = a[0];
	int k;
	for (int i = 1; i < n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == s) 
		{
			PrintArray(a, 0, i);
			return 1;
		}
		else {
			if (b[i] > s) {
				k = BinarySearch(b,i,b[i]-s);
				if (k != -1) 
				{
					PrintArray(a, k+1, i);
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int a[1000], b[1000], n, s;
	cin >> n;
	ImportArray(a, n);
	cin >> s;
	bool k = solve(a, b, n, s);
	if (k == 0) cout << -1;
	return 0;
}