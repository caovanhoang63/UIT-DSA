#include <iostream>
#include <time.h>
using namespace std;

int SS_Selec = 0;
int G_Selec = 0;
int SS_Heap = 0;
int G_Heap = 0;
int SS_Merge = 0;
int G_Merge = 0;
int SS_Quick = 0;
int G_Quick = 0;
// 1 swap = 3 gan'
void HeapSort(int  arr[],int n);
void BuildHeap(int arr[],int n);
void Heapify(int arr[], int i, int heap_size);
void merge(int a[], int l, int m, int r);
void MergeSort(int a[], int l, int r);


void SelectionSort(int arr[],int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			SS_Selec++;
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			G_Selec += 3;
			swap(arr[min], arr[i]);
		}
	}
}

void HeapSort(int arr[],int n) {
	// khoi tao heap
	BuildHeap(arr,n);
	for (int i = n - 1; i > 0; i--) {
		// doi cho phan tu goc cua heap ve cuoi day
		swap(arr[0], arr[i]);
		G_Heap += 3;
		// hieu chinh lai heap
		Heapify(arr, 0, i);
	}
}

void BuildHeap(int arr[],int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}
void Heapify(int  arr[], int i, int heap_size) {
	int root = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	// neu node con ben trai lon hon node goc thi doi cho
	SS_Heap += 2;
	if (left<heap_size && arr[left]>arr[root])
	{	
		G_Heap++;
		root = left;
	}
	// neu node con ben phai lon hon node goc thi doi cho
	SS_Heap += 2;
	if (right<heap_size && arr[right] >arr[root])
	{
		G_Heap++;
		root = right;
	}
	SS_Heap++;
	if (root != i) {

		swap(arr[root], arr[i]);
		G_Heap += 3;
		// hieu chinh lai heap sau khi da doi cho vi tri cac node 
		Heapify(arr, root, heap_size);
	}
}

void QuickSort(int arr[], int left, int right) {
	int p = arr[(left + right) / 2];
	int i = left;
	int j = right;
	SS_Quick++;
	while (i < j) {
		while (arr[i] < p)
		{
			SS_Quick++;
			i++;
		}
		while (arr[j] > p)
		{
			SS_Quick++;
			j--;
		}
		SS_Quick++;
		if (i <= j) {
			swap(arr[i++], arr[j--]);
			G_Quick++;
		}
	}
	SS_Quick++;
	if (i < right) {
		QuickSort(arr, i, right);
	}
	SS_Quick++;
	if (j > left) {
		QuickSort(arr, left, j);
	}
}


void MergeSort(int arr[], int left, int right) {
	SS_Merge++;
	if (left < right) {
		G_Merge++;
		int mid = left + (right - left) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
void merge(int  arr[], int left, int mid, int right) {
	int i, j, k;
	G_Merge+=2;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	//cho cac phan tu tu a[l] den a[m] vao trong L[]
	for (int i = 0; i < n1; i++)
	{
		G_Merge++;
		L[i] = arr[left + i];
	}
	//cho cac phan tu tu a[m+1] den a[r] vao trong r[L]
	for (int j = 0; j < n2; j++)
	{
		G_Merge++;
		R[j] = arr[mid + 1 + j];
	}
	G_Merge+=3;
	i = j = 0;
	k = left;
	//tron hai mang L[] va R[] da duoc sap tang vao a[]
	/*************************************/
	SS_Merge += 2;
	while (i < n1 && j < n2)
	{
		G_Merge++;
		SS_Merge+=2;
		arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
	}
	while (i < n1)
	{
		SS_Merge++;
		G_Merge++;
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		SS_Merge++;
		G_Merge++;
		arr[k++] = R[j++];
	}
	/************************************/
	delete[]R;
	delete[]L;
}



int main() {
	
	int n;
	cin>> n;
	
	int* inter = new int[n], * quick = new int[n], * heap = new int[n], * merg = new int[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		inter[i] = quick[i] = heap[i] = merg[i] = x;
	}
	clock_t start, end;
	float time_use;
	start = clock();
	SelectionSort(inter,n);
	end = clock();
	time_use = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Thuat toan selection sort: " << endl;
	cout << "So phep gan thuc hien : " <<G_Selec << endl;
	cout << "So phep so sanh su dung: " << SS_Selec << endl;
	cout << "Thoi gian thuc thi: " << time_use << endl<<endl;
	start = clock();
	HeapSort(heap,n);
	end = clock();
	time_use = (float)(  end-start) / CLOCKS_PER_SEC;
	cout << "Thuat toan heap sort: " << endl;
	cout << "So phep gan thuc hien : " << G_Heap << endl;
	cout << "So phep so sanh su dung: " << SS_Heap << endl;
	cout << "Thoi gian thuc thi: " << time_use << endl<<endl;
	start = clock();
	QuickSort(quick, 0, n - 1);
	end = clock();
	time_use = (float)(  end-start) / CLOCKS_PER_SEC;
	cout << "Thuat toan quick sort: " << endl;
	cout << "So phep gan thuc hien : " << G_Quick << endl;
	cout << "So phep so sanh su dung: " << SS_Quick << endl;
	cout << "Thoi gian thuc thi: " << time_use << endl<<endl;
	start = clock();
	MergeSort(merg, 0, n - 1);
	end= clock();
	time_use = (float)(  end - start) / CLOCKS_PER_SEC;
	cout << "Thuat toan merge sort: " << endl;
	cout << "So phep gan thuc hien : " << G_Merge << endl;
	cout << "So phep so sanh su dung: " << SS_Merge << endl;
	cout << "Thoi gian thuc thi: " << time_use << endl<<endl;

	return 0;
}