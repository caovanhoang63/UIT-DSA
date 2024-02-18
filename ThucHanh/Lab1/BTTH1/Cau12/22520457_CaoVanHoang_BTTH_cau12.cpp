#include <iostream>
using namespace std;
void HeapSort(int arr[], int n);
void BuildHeap(int arr[], int n);
void Heapify(int  arr[], int i, int heap_size,int n);
void Input(int a[], int &n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void Print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void Print(int a[], int i, int j) {
	for (i; i <= j; i++) {
		cout << a[i]<<" ";
	}
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n;j++) {
			
			if (a[i] > a[j]) {
				cout << "Doi cho cap nghich the (" << i << "," << j << ")" << endl;
				swap(a[i], a[j]); 
				Print(a, n);
				cout << endl;
			}
		}
	}
}

void HeapSort(int arr[], int n) {
	cout << "Khoi tao heap: " << endl;
	BuildHeap(arr, n);
	cout << "Heap hoan chinh:" << endl;
	Print(arr, n);
	cout << endl;
	for (int i = n - 1; i > 0; i--) {
		cout << "Dua node goc ve cuoi mang: " << endl;
		swap(arr[0], arr[i]);
		Print(arr, n);
		cout << endl;
		if(i>1)
			cout << "Chinh sua lai heap sau khi da dua node goc ve cuoi" << endl;
		Heapify(arr, 0, i, n);
	}
	cout << "Mang sau khi da hoan thanh sap xep" << endl;
	Print(arr, n);
}


void BuildHeap(int arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, i, n, n);
	}
}
void Heapify(int  arr[], int i, int heap_size,int n) {
	int root = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left<heap_size && arr[left]>arr[root])
	{
		root = left;
	}
	if (right<heap_size && arr[right] >arr[root])
	{
		root = right;
	}
	if (root != i) {

		swap(arr[root], arr[i]);
		cout << "hoan doi vi tri (" << root << "," << i << ") " << endl;
		Print(arr, n);
		cout << endl;
		cout << "Hieu chinh lai heap: " << endl;
		Heapify(arr, root, heap_size, n);
	}
}

void QuickSort(int arr[], int left, int right,int n) {
	int p = arr[(left + right) / 2];
	cout << "Phan tu chot la: " << p << endl;
	int i = left;
	int j = right;
	Print(arr, n);
	cout << endl;
	while (i < j) {
		while (arr[i] > p)
		{
			i++;
		}
		while (arr[j] < p)
		{
			j--;
		}
		if (i <= j) {
			swap(arr[i++], arr[j--]);
			Print(arr, n);
			cout << " (" << i-1 << "," << j+1 << ")" << endl;
		}
	}
	if (i < right) {
		cout << "Thuc hien tren doan [" << i << "," << right << "]" << endl;
		QuickSort(arr, i, right, n);
	}
	if (j > left) {
		cout << "Thuc hien tren doan [" << left << "," << j << "]" << endl;
		QuickSort(arr, left, j,n);
	}
}

void BubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i + 1; j--) {

			if (arr[j] < arr[j- 1]) {
				swap(arr[j], arr[j - 1]);
				Print(arr, n);
				cout << "Hoan vi (" << j << "," << j-1 << ")" << endl;
			}
		}
	}
}

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (arr[min] < arr[j])
				min = j;
		}
		cout << "Gia tri lon nhat trong doan [" << i << "," << n - 1 << "] = " << arr[min]<<endl;
		if (min != i)
			cout << "Thuc hien hoan vi (" << i << "," << min << ")" << endl;
			swap(arr[min], arr[i]);
		Print(arr, n);
		cout << endl;
	}
}

void InsertionSort(int arr[], int n) {
	for (int i = 1; i < n ; i++) {
		int vt = i - 1;
		int x = arr[i];
		for (; vt >= 0 && arr[vt] > x;vt--) 
			arr[vt + 1] = arr[vt];
		cout << "Chen gia tri arr [" << i << "] = " << x << " vao vi tri " << vt + 1 << endl;
		arr[vt + 1] = x;
		Print(arr, n);
		cout << endl;
	}
}
void merge(int  arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	i = j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}
	delete[]R;
	delete[]L;
}
void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		Print(arr, left, mid);
		cout << endl;
		MergeSort(arr, mid + 1, right);
		Print(arr, mid + 1, right);
		cout << endl;
		cout << "Tron doan [" << left << "," << right << "] " << endl;
		merge(arr, left, mid, right);
	}
}

int main() {
	int a[] = {10,5,30,70,40,80,90};
	SelectionSort(a, 7);
	Print(a, 7);
	return 0;
}