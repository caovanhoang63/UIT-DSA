#include <iostream>
using namespace std;

int main() {
	int a[1000];
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	int c = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) c=i;
		break;
	}
	cout << c;
	return 0;
}