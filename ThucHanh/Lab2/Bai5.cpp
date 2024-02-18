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
int BinarySearch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int Linear_Search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int main()
{

    int m;
    int index, k;
    int *a;
    srand(time(NULL));
    duration<double, milli> liner_use;
    duration<double, milli> binary_use;
    for (int i = 1; i <= 100; i++)
    {
        m = rand() % 29999 + 101;
        a = new int[m];
        for (int j = 0; j < m; j++)
        {
            int p = rand() % (m + 1);
            a[j] = p;
        }
        // random k
        index = rand() % m;
        int k = a[index];
        // sort
        sort(a, a + m - 1);
        // liner search
        auto t1 = high_resolution_clock::now();
        Linear_Search(a, m, k);
        auto t2 = high_resolution_clock::now();
        liner_use += t2 - t1;
        // binarysearch
        auto t3 = high_resolution_clock::now();
        BinarySearch(a, m, k);
        auto t4 = high_resolution_clock::now();
        binary_use += t4 - t3;
        delete[] a;
    }
    cout << "Thoi gian thuc hien cua thuat toan tim kiem nhi phan: " << binary_use.count() << "ms\n";
    cout << "Thoi gian thuc hien cua thuat toan tim tim tuyen tinh: " << liner_use.count() << "ms\n";
    return 0;
}