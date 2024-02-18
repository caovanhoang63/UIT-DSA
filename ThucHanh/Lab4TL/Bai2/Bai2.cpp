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
void PrintReverse(string s);
int main() {
	string s;
	cin >> s;
	PrintReverse(s);
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
void PrintReverse(string s) {
	Stack <char> st;
 	for(auto x : s){
		st.Push(x);
	}
	while (!st.IsEmpty()) {
		cout<<st.Pop();
	}
}