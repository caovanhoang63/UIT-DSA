#include <iostream>
using namespace std;

int indexMin(int a[],int  n) {
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (a[k] > a[i]) {
			k = i;
		}
	}
	return k;
}

int indexMax(int a[], int n) {
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (a[k] <= a[i]) {
			k = i;
		}
	}
	return k;
}
int count(int a[], int n,int k) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			count++;
		}
	}
	return count;
}

void odd_in_even(int a[], int n) {
	int k = 0;
	for (int i = 0; i < n; i += 2) {
		if (a[i] % 2 != 0) 
		{	
			k++;
			cout << a[i] << " ";
		}
	}
	if (k == 0) cout << "NULL";
}

int main() {
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	odd_in_even(a, n);
	return 0;
}
