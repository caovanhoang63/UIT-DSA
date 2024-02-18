#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;

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

int LinerSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

void Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}

int main()
{
    int a[10001], b[10001];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int x = rand() % 10001 - 5000;
        a[i] = b[i] = x;
    }
    Sort(b, 10000);
    int x;
    cout << "Nhap phan tu can tim: ";
    cin >> x;
    time_t st, ed;
    double time_use;
    st = clock();
    int index = LinerSearch(a, 10000, x);
    ed = clock();
    if (index == -1)
        cout << "Phan tu khong ton tai !" << endl;
    else
        cout << "Chi so cua phan tu can tim: " << index << endl;
    ;
    time_use = float(ed - st) / CLOCKS_PER_SEC;
    cout << "Liner Search: " << setprecision(30) << fixed << time_use << endl;
    st = clock();
    index = BinarySearch(b, 10000, x);
    ed = clock();

    if (index == -1)
        cout << "Phan tu khong ton tai !" << endl;
    else
        cout << "Chi so cua phan tu can tim: " << index << endl;
    time_use = float(ed - st) / CLOCKS_PER_SEC;
    cout << "Binary Search: " << setprecision(30) << fixed << time_use << endl;
    return 0;
}