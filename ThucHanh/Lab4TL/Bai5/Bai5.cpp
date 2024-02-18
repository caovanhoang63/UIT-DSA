#include <iostream>
#include <string>
using namespace std;
#define SIZE 100
template <class T> class Stack {
public:
	Stack();
	void Push(T k);
	T Pop();
	T Top();
	bool IsFull();
	bool IsEmpty();
	int Size();
private:
	int top;
	T st[SIZE];
};
void TowerOfHaNoi(int, Stack<int>&, Stack<int>&, Stack<int>&);
int main() {
	int n;
	cout << "Nhap so dia: ";
	cin >> n;
	Stack<int> towerA, towerB, towerC;
	// Dua cac dia vao cot thu nhat
	for (int i = n; i >= 1; i--) {
		towerA.Push(i);
	}
	TowerOfHaNoi(n, towerA, towerB, towerC);
	return 0;
}

template <class T >  Stack<T> ::Stack() {
	top = -1;
}
template <class T> void Stack<T>::Push(T k) {
	if (!IsFull()) {
		top++;
		st[top] = k;
	}
}
template <class T> bool Stack<T>::IsFull() {
	if (top == SIZE - 1) {
		return 1;
	}
	return 0;
}
template <class  T > bool Stack<T>::IsEmpty() {
	if (top == -1)
		return 1;
	return 0;
}
template <class T> T Stack<T>::Pop() {
	int x;
	if (!IsEmpty()) {
		x = st[top];
		top--;
		return x;
	}
	return NULL;
}
template <class T> T Stack<T>::Top() {
	if (!IsEmpty()) {
		return st[top];
	}
	return NULL;
}
template <class T> int Stack<T>::Size() {
	return top + 1;
}
void TowerOfHaNoi(int num, Stack<int>&source, Stack<int>& auxiliary, Stack<int>& destination) {
	int TongSoBuoc = pow(2, num) - 1;
	if(num%2!=0)
	{
		for (int i = 1; i <= TongSoBuoc; i++) {
			if (i % 3 == 1) {
				if (!source.IsEmpty() && (destination.IsEmpty() || source.Top() < destination.Top())) {
					destination.Push(source.Top());
					source.Pop();
					cout << "Di chuyen dia " << destination.Top() << " tu cot A sang cot C" << endl;
				}
				else {
					source.Push(destination.Top());
					destination.Pop();
					cout << "Di chuyen dia " << source.Top() << " tu cot C sang cot A" << endl;
				}
			}
			else if (i % 3 == 2) {
				if (!source.IsEmpty() && (auxiliary.IsEmpty() || source.Top() < auxiliary.Top())) {
					auxiliary.Push(source.Top());
					source.Pop();
					cout << "Di chuyen dia " << auxiliary.Top() << " tu cot A sang cot B" << endl;
				}
				else {
					source.Push(auxiliary.Top());
					auxiliary.Pop();
					cout << "Di chuyen dia " << source.Top() << " tu cot B sang cot A" << endl;
				}
			}
			else if (i % 3 == 0) {
				if (!auxiliary.IsEmpty() && (destination.IsEmpty() || auxiliary.Top() < destination.Top())) {
					destination.Push(auxiliary.Top());
					auxiliary.Pop();
					cout << "Di chuyen dia " << destination.Top() << " tu cot B sang cot C" << endl;
				}
				else {
					auxiliary.Push(destination.Top());
					destination.Pop();
					cout << "Di chuyen dia " << auxiliary.Top() << " tu cot C sang cot B" << endl;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= TongSoBuoc; i++) {
			if (i % 3 == 1) {
				if (!source.IsEmpty() && (auxiliary.IsEmpty() || source.Top() < auxiliary.Top())) {
					auxiliary.Push(source.Top());
					source.Pop();
					cout << "Di chuyen dia " << auxiliary.Top() << " tu cot A sang cot B" << endl;
				}
				else {
					source.Push(auxiliary.Top());
					auxiliary.Pop();
					cout << "Di chuyen dia " << source.Top() << " tu cot B sang cot A" << endl;
				}
			}
			else if (i % 3 == 2) {
				if (!source.IsEmpty() && (destination.IsEmpty() || source.Top() < destination.Top())) {
					destination.Push(source.Top());
					source.Pop();
					cout << "Di chuyen dia " << destination.Top() << " tu cot A sang cot C" << endl;
				}
				else {
					source.Push(destination.Top());
					destination.Pop();
					cout << "Di chuyen dia " << source.Top() << " tu cot C sang cot A" << endl;
				}
			}
			else if (i % 3 == 0) {
				if (!auxiliary.IsEmpty() && (destination.IsEmpty() || auxiliary.Top() < destination.Top())) {
					destination.Push(auxiliary.Top());
					auxiliary.Pop();
					cout << "Di chuyen dia " << destination.Top() << " tu cot B sang cot C" << endl;
				}
				else {
					auxiliary.Push(destination.Top());
					destination.Pop();
					cout << "Di chuyen dia " << auxiliary.Top() << " tu cot C sang cot B" << endl;
				}
			}
		}
	}

}
