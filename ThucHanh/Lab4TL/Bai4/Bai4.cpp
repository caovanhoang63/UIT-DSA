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
void PrintBinary(int s);
void PrintHexa(int s);
int main() {
	int s;
	cin >> s;
	PrintHexa(s);
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
void PrintBinary(int s) {
	Stack<bool> st;
	while (s != 0) {
		st.Push(s % 2);
		s /= 2;
	}
	while (!st.IsEmpty()) {
		cout << st.Pop();
	}
}
void PrintHexa(int s) {
	Stack<char> st;
	while (s != 0) {
		int a = s % 16;
		s /= 16;
		if (a < 10) {
			st.Push(char(a + '0'));
		}
		else {
			switch (a)
			{
			case 10:
				st.Push('a');
				break;
			case 11:
				st.Push('b');
				break;
			case 12:
				st.Push('c');
				break;
			case 13:
				st.Push('d');
				break;
			case 14:
				st.Push('e');
				break;
			case 15:
				st.Push('f');
				break;
			default:
				break;
			}
		}
	}
	while (!st.IsEmpty()) {
		cout << st.Pop();
	}
}