#include <iostream>
using namespace std;

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

//void swap(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int index_min(int a[],int j,int n) {
//	int index = j;
//	for (int i = j; i < n; i++) {
//		if (a[index] > a[i])
//		{
//			index = i;
//		}
//	}
//	return index;
//}
//// [3,2,1]
//// i = 1 
//// index_min = 2
//// 1 != 2 
//// [1,2,3]
////
//void Sort(int a[],int n) {
//	for (int i = 1; i < n; i++) {
//		
//		if(i!=index_min(a,i,n))
//			swap(a[i - 1], a[index_min(a, i, n)]);
//	}
//}

// [5,8,6,9]
//  i = 0; index_min = 0
//	j = 1
//	for >> index_min = 0
//  0 != 0 sai -> [5 8 6 9]
//  i = 1; index_min = 1 
//  j = 2 
//  for >> index_min = 2
//  1 != 2 dung -> [5 6 8 9]
//	...
void Sort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		int index_min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[index_min] > a[j]) {
				index_min = j;
			}
		}
		if (i != index_min) swap(a[i], a[index_min]);
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