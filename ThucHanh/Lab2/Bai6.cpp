#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <chrono>
using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;
int KoLinhCanh(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int DungLinhCanh(int a[], int n, int x)
{
    int i;
    a[n] = x;
    for (i = 0;; i++)
    {
        if (a[i] == x)
            break;
    }
    if (i == n)
        return -1;
    return i;
}
int main()
{
    int m;
    int index, k;
    int *a;
    srand(time(NULL));
    cout << "Nhap so phan tu: ";
    cin >> m;
    a = new int[m + 1];
    // random cac phan tu trong mang
    for (int j = 0; j < m; j++)
    {
        int p = rand() % (m + 1); // a[i] = 0->m+1
        a[j] = p;
    }
    // random k
    cout << "Phan tu can tim kiem la: ";
    k = rand() % m;
    cout << k << endl;
    // khong su dung linh canh
    auto t1 = high_resolution_clock::now();
    cout << "Chi so cua phan tu can tim kiem la: " << KoLinhCanh(a, m, k) << endl;
    auto t2 = high_resolution_clock::now();
    duration<double, milli> kodunglinhcanh = t2 - t1;
    // su dung linh canh
    auto t3 = high_resolution_clock::now();
    cout << "Chi so cua phan tu can tim kiem la: " << DungLinhCanh(a, m, k) << endl;
    auto t4 = high_resolution_clock::now();
    duration<double, milli> linhcanh = t4 - t3;
    cout << "Thoi gian thuc hien cua thuat toan khi su dung linh canh: " << linhcanh.count() << "ms\n";
    cout << "Thoi gian thuc hien cua thuat toan khong su dung linh canh: " << kodunglinhcanh.count() << "ms\n";
    delete[] a;
    return 0;
}