#include <iostream>
#include <stack>
#include <ctime>

using namespace std;
// phan tu chot o giua
int PhanDoanGiua(int arr[], int l, int r) {
	int p = arr[(r + l) / 2];
	int i = l, j = r;
	while (i < j) {
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j)
			swap(arr[i++],arr[j--]);
	}
	return i;
}
void Giua(int arr[], int n) {
	stack<int>st;
	st.push(0);
	st.push(n - 1);
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();
		int p = PhanDoanGiua(arr, j, i);
		if (p  - 1 > j) {
			st.push(j);
			st.push(p - 1);
		}

		if (p  <  i) {
			st.push(p);
			st.push(i);
		}
	}
}
// phan tu chot o cuoi
int PhanDoanCuoi(int arr[], int l, int r) {
	int p = arr[r], i = l - 1;
	for (int j = l; j < r; j++) {
		if (arr[j] <= p) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}
void Cuoi(int arr[], int n) {
	stack<int>st;
	st.push(0);
	st.push(n - 1);
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();
		int p = PhanDoanCuoi(arr, j, i);
		if (p - 1 > j) {
			st.push(j);
			st.push(p - 1);
		}
		if (p + 1 < i) {
			st.push(p + 1);
			st.push(i);
		}
	}
}
// phan tu chot o dau
int PhanDoanDau(int arr[], int l, int r) {
	int p = arr[l], i = r + 1;
	for (int j = r; j > l; j--) {
		if (arr[j] >= p) {
			i--;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i - 1], arr[l]);
	return i - 1;
}
void Dau(int arr[], int n) {
	stack<int>st;
	st.push(0);
	st.push(n - 1);
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();
		int p = PhanDoanDau(arr, j, i);
		if (p - 1 > j) {
			st.push(j);
			st.push(p - 1);
		}
		if (p + 1 < i) {
			st.push(p + 1);
			st.push(i);
		}
	}
}
int main() {
	int* dau, * giua, * cuoi;
	int n;

	cin >> n;
	dau = new int[n];
	giua = new int[n];
	cuoi = new int[n];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		dau[i] = giua[i] = cuoi[i] =x ;
	}

	clock_t st, ed;
	st = clock();
	Dau(dau, n);
	ed = clock();
	float time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "Thoi gian thuc hien khi phan tu chot nam o dau: " << time_use << endl;

	st = clock();
	Giua(giua,n);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "Thoi gian thuc hien khi phan tu chot nam o giua: " << time_use << endl;
	
	st = clock();
	Cuoi(cuoi, n);
	ed = clock();
	time_use = (float)(ed - st) / CLOCKS_PER_SEC;
	cout << "Thoi gian thuc hien khi phan tu chot nam o cuoi: " << time_use << endl;

	delete[] dau; 
	delete[] giua;
	delete[] cuoi;
	return 0;
}