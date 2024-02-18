#include <iostream>
using namespace std;
int dequy = 0;
int kodequy = 0;
int unRecursion(int a[], int left, int right, int x)
{
    while (left <= right)
    {
        kodequy++;
        int mid = left + (right - left) / 2;
        kodequy++;
        if (a[mid] == x)
        {
            return mid;
        }
        kodequy++;
        if (a[mid] > x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int Recursion(int a[], int left, int right, int x)
{
    dequy++;
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    dequy++;
    if (a[mid] == x)
    {
        return mid;
    }
    dequy++;
    if (a[mid] > x)
    {
        return Recursion(a, mid + 1, right, x);
    }
    else
    {
        return Recursion(a, left, mid - 1, x);
    }
}

int main()
{
    int a[] = {99, 92, 88, 82, 52, 32, 30, 29, 22, 10, 6, 1, 0, -2, -10, -92, -120, -999};
    cout << "De quy \nChi so cua phan tu can tim kiem la: " << Recursion(a, 0, 17, -999) << endl;
    cout << "So phep so sanh can thuc hien: " << dequy << endl;
    cout << "Khong de quy\nChi so cua phan tu can tim kiem la: " << unRecursion(a, 0, 17, 99) << endl;
    cout << "So phep so sanh can thuc hien: " << kodequy << endl;
    return 0;
}