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
int PrintReverse(int s);
int main() {
	int s;
	cin >> s;
	cout<<PrintReverse(s);
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
int	PrintReverse(int s) {
	Stack<int >st;
	while (s != 0) {
		st.Push(s % 10);
		s /= 10;
	}
	int result = 0, i = 1;
	while (!st.IsEmpty()) {
		result += st.Pop()*i;
		i *= 10;
	}
	return result;
}