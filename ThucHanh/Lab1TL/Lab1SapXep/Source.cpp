#include <iostream>
using namespace std;

void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int index_min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[index_min] > a[j]) {
				index_min = j;
			}
		}
		if (i != index_min) swap(a[i], a[index_min]);
	}
}

void Insert(int a[], int k, int x) {
	int vt = k - 1;
	for (; vt >= 0 && a[vt] > x; vt--)
		a[vt + 1] = a[vt];
	a[vt + 1] = x;
}

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		Insert(a, i, a[i]);
	}
}

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i ; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];

				a[i] = a[j];
				a[j] = temp;
			}
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
int main() {
	int a[1000];
	int n;
	cin >> n;
	ImportArray(a, n);
	InterchangeSort(a, n);
	PrintArray(a, n);
	return 0;

}

