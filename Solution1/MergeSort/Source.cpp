#include <iostream>
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

void merge(int a[], int l, int m, int r) {
	int i, j, k;
	// l = 0  r= 9 => m = 4.5 = 4
	// n1 = 4 - 0 + 1 = 5    0 1 2 3 4
	int n1 = m - l + 1;
	// n2 = 9 - 4 = 5	     5 6 7 8 9	
	int n2 = r - m ;
	//cap phat dong cho hai mang L[] va R[]
	int* L = new int[n1];
	int* R = new int[n2];
	//cho cac phan tu tu a[l] den a[m] vao trong L[]
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	//cho cac phan tu tu a[m+1] den a[r] vao trong r[L]
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = j  = 0;
	k = l;
	//tron hai mang L[] va R[] da duoc sap tang vao a[]
	/*************************************/
	while (i < n1 && j < n2)
		a[k++] = L[i] <= R[j] ?L [i++] : R[j++];
	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
	/************************************/
	delete[]R;
	delete[]L;
}

void mergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void Sort(int a[], int n) {
	mergeSort(a, 0, n - 1);
}

int main() {
	int a[1000], n;
	cin >> n;
	ImportArray(a, n);
	Sort(a, n );
	PrintArray(a, n);
	return 0;
}
