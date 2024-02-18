#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void Giua(int  arr[], int left, int right) {
	int p = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j) {
			swap(arr[i++], arr[j--]);
		}
	}
	if (i < right) {
		Giua(arr, i, right);
	}
	if (j > left) {
		Giua(arr, left, j);
	}
}
void Dau(int arr[], int left, int right) {
	int p = arr[left];
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j) {
			swap(arr[i++], arr[j--]);
		}
	}
	if (i < right) {
		Dau(arr, i, right);
	}
	if (j > left) {
		Dau(arr, left, j);
	}
}
void Cuoi(int  arr[], int left, int right) {
	int p = arr[ right];
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < p)
			i++;
		while (arr[j] > p)
			j--;
		if (i <= j) {
			swap(arr[i++], arr[j--]);
		}
	}
	if (i < right) {
		Cuoi(arr, i, right);
	}
	if (j > left) {
		Cuoi(arr, left, j);
	}
}

int main() {

	int n;
	cin >> n;
	int* dau = new int [n], * giua = new int[n],  * cuoi = new int[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dau[i] = giua[i] = cuoi[i] = x;
	}

	for (int i = 0; i < n; i++) {
		cout << dau[i] << " ";
	}
	cout << endl;
	clock_t start, end;
	float time_use;
	start = clock();
	Giua(giua, 0, n - 1);
	
	cout << endl;
	end = clock();
	time_use = (float)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		cout << giua[i] << " ";
	}
	cout << endl;
	cout << "Thoi gian thuc hien khi phan tu chot nam o giua: " << time_use << endl;

	start = clock();
	Dau(dau, 0, n - 1);
	end = clock();
	time_use = (float)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		cout << dau[i] << " ";
	}
	cout << endl;
	cout << "Thoi gian thuc hien khi phan tu chot nam o dau: " << time_use << endl;

	start = clock();
	Cuoi(cuoi, 0, n - 1);
	end = clock();
	time_use = (float)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		cout << cuoi[i] << " ";
	}
	cout << endl;
	cout << "Thoi gian thuc hien khi phan tu chot nam o cuoi: " << time_use << endl;

	delete[] dau;
	delete[]giua;
	delete[] cuoi;
	return 0;
}
