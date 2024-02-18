#include <iostream>
using namespace std;

void Solve(int a[],int n) {
	int chan[10],le[10], dem_chan = 0, dem_le = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[dem_chan++] = a[i];
		}
		else {
			le[dem_le++] = a[i];
		}
	}
	for (int i = 0; i < dem_chan - 1; i++) {
		for (int j = i + 1; j < dem_chan; j++) {
			if (chan[i] < chan[j]) {
				swap(chan[i], chan[j]);
			}
		}
	}
	for (int i = 0; i < dem_le - 1; i++) {
		for (int j = i + 1; j < dem_le; j++) {
			if (le[i] > le[j]) {
				swap(le[i], le[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] =chan[--dem_chan];
		}
		else {
			a[i] = le[--dem_le];
		}
	}
}

int main() {
	int A[] = {12,8,2,14,3,5,10,15,36};
	
	Solve(A,9);
	for (int i = 0; i < 9; i++) {
		cout << A[i] << " ";
	}
	return 0;
}
