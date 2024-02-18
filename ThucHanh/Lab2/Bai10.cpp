#include <iostream>
using namespace std;

void Print(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
}
int BinarySearch(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        cout << "Khong gian tim kiem: ";
        Print(a, l, r);
        cout << endl;
        int m = l + (r - l) / 2;
        cout << "Mid =" << m << endl;
        cout << "a[Mid] =" << a[m] << endl;
        if (a[m] == x)
        {
            cout << "Phan tu tai vi tri mid = " << x << " ket thuc tim kiem" << endl;
            return m;
        }
        if (a[m] < x)
        {
            cout << "Phan tu tai vi tri mid < " << x << " tiep tuc tim kiem trong phan ben phai" << endl;
            l = m + 1;
        }
        else
        {
            cout << "Phan tu tai vi tri mid > " << x << " tiep tuc tim kiem trong phan ben trai" << endl;
            r = m - 1;
        }
    }
    return -1;
}

int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Khong gian tim kiem: ";
        Print(a, i, n - 1);
        cout << endl;
        if (a[i] == x)
        {
            cout << "a[" << i << "] = " << x << " ket thuc giai thuat" << endl;
            return i;
        }
        cout << "a[" << i << "] = " << a[i] << " khong bang " << x << " tiep tuc tim kiem " << endl;
    }
    return -1;
}

int main()
{
    int n, *a;
    cout << "Nhap so phan tu: ";
    cin >> n;
    a = new int[n];
    cout << "Nhap gia tri cac phan tu cho mang : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Nhap phan tu can tim kiem: ";
    int x;
    cin >> x;
    int index = LinearSearch(a, n, x);
    cout << "Vi tri phan tu can tim la: " << index;
    delete[] a;
    return 0;
}