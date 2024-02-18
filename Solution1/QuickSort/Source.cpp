#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void PrintArray(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void ImportArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}



void Sort(vector<int> &a, int l, int r){
	int  i = l, j = r;
	int p = a[(l + r) / 2];
	while (i < j) {
		while(a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			swap(a[i++], a[j--]);
		}
	}
	if (i < r) Sort(a, i, r);
	if (j > l) Sort(a, l, j);
}

int main() {
	int n;
	cin >> n;
	vector<int >a(n) ;
	for (auto &x : a) cin >> x;
	Sort(a, 0,n-1);
	for (auto x : a) cout << x << " ";
	return 0;
}