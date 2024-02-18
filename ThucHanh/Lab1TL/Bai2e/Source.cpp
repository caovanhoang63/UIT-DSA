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
	bool danh_dau[100] = {0};
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			am[dem_am++] = a[i];
			a[i] = -1;
		}
		else {
			duong[dem_duong++] = a[i];
			a[i] = 1;
		}
	}
	SapTang(am, dem_am);
	SapGiam(duong, dem_duong);
	int c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			a[i] = am[c++];
		}
		else {
			a[i] = duong[d++];
		}
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