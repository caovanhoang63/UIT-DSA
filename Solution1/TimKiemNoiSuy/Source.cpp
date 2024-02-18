#include <iostream>
using namespace std;

int  interpolationSearch(int a[], int n,int x) {
	int l = 0, r = n - 1;
	while (a[l] != a[r] && x >= a[l] && x <= a[r]){
		int m = l + (r - l) * (x - a[l]) / (a[r] - a[l]);
		if (a[m] == x) return m;
		if (a[m] < x) l = m + 1;
		else if(a[m]>x) r = m - 1;
		else {
			//tim kiem phan tu bang x dau tien
			if (m > 0 && a[m - 1] == x) r = m - 1;
			else return m;
		}
	}
	return -1;
}
void ImportArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void PrintArray(int a[], int n) {
	for (int i = 0; i <n; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	int a[1000], n, x;
	cin >> n;
	ImportArray(a, n);
	cin >> x;
	cout<<interpolationSearch(a, n, x);
	return 0;
}