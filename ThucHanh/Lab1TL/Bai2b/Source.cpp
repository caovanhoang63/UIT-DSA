#include <iostream>
using namespace std;



void SapTang(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void SapGiam(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++)
		{
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}

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

void XuLy(int a[], int n) {
	int duong[100], dem_duong = 0;
	int am[100], dem_am = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			am[dem_am++] = a[i];
		}
		else {
			duong[dem_duong++] = a[i];
		}
	}
	SapGiam(am, dem_am);
	SapTang(duong, dem_duong);
	cout << endl;
	for (int i = 0; i < dem_am; i++) {
		a[i] = am[i];
	}
	for (int i = dem_am; i < n; i++) {
		a[i] = duong[i - dem_am];
	}
}
int main() {
	int a[1000];
	int n;
	cin >> n;
	ImportArray(a, n);
	XuLy(a, n);
	PrintArray(a, n);
	return 0;

}