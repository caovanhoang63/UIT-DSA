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
void Sort(int a[], int n) {
	// a = [9, 1, 3, 7, 8, 4, 2, 6, 5]
	// interval = 9 / 2 = 4
	//[9, 8, 5], [1, 4], [3, 2] [7, 6]
	//[5, 8 , 8] [1 , 4] [2 ,3 ] [7,6]
	int interval, i, j,temp;

	//tinh khoang cach
	for (interval = n / 2; interval >= 1; interval /= 2) {
		//duyet den tuong phan tu trong mang con ma cac phan tu do cach nhau 1 khoang la inteval
		for (int i = interval; i < n; i++) {
			temp = a[i];
			//hoan doi vi tri cua phan tu hien thoi voi phan tu trc do cach no 1 khoang interval
			/*********************************************/
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
			/********************************************/
		}
	}
}

int main() {
	int a[1000], n;
	cin >> n;
	ImportArray(a, n);
	Sort(a, n);
	PrintArray(a, n);
	return 0;
}