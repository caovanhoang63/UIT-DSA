#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* pLeft;
	Node* pRight;
};
typedef Node* Tree;
void Init(Tree& t) {
	t = NULL;
}
Node* GetNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->info = x;
	p->pLeft = p->pRight = NULL;
	return p;
}
 void Insert(Tree&t,Node* p) {
	if (t == NULL) {
		t =p;
	}
	else {
		if (t->info == p->info) return;
		if (p->info < t->info) Insert(t->pLeft, p);
		else Insert(t->pRight, p);
	}

}

void Print(Tree t) {
	if (t != NULL) {
		Print(t->pLeft);
		cout << t->info<<" ";
		Print(t->pRight);
	}
}
//Dem so luong node la
int CountLa(Tree t)  {
	if (t == NULL) return 0;
	if (t->pLeft == NULL && t->pRight == NULL) 
	{
		cout << t->info <<" ";
		return 1;
	}
	return CountLa(t->pLeft) + CountLa(t->pRight) ;
}
// Dem so node trong cay
int Count(Tree t) {
	int count = 0;
	if (t != NULL) {
		count = 1 + Count(t->pLeft) + Count(t->pRight);
	}
	return count;
}
//xac dinh bac cua 1 cay
int Level(Tree t ) {
	if (t == NULL) return -1;
	if (t->pLeft == NULL && t->pRight == NULL) return 0;
	// chon nhanh dai nhat trong hai nhanh trai phai de duyet
	return 1 + max(Level(t->pLeft), Level(t->pRight));
}
//xac dinh 1 cay co phai la cay AVL hay ko
// cay AVL la cay nhi phan co hieu bac cua cay ben trai so voi cay ben phai ko lon hon 1
bool check(Tree t) {
	if (t == NULL) return 1;
	if (abs(Level(t->pLeft) - Level(t->pRight)) > 1 ) return 0;
	return check(t->pLeft) && check(t->pRight);
}
//bien doi cay nhi phan ve dang AVL
/**********************************/
//ham xoay phai
void turnRight(Tree& t) {
	Node* b = t->pLeft;
	Node* d = b->pRight;
	t->pLeft = d;
	b->pRight = t;
	t = b;
}
//ham xoay trai
void turnLeft(Tree& t) {
	Node* b = t->pRight;
	Node* d = b->pLeft;
	t->pRight = d;
	b->pLeft = t;
	t = b;
}
//ham bien doi 
void updateAVL(Tree& t) {
	//neu cay ko phai la cay AVL thi thuc hien xoay cay theo cac truong hop
	if(abs(Level(t->pLeft) - Level(t->pRight)) > 1)
	{
		//neu cay bi lech sang trai
		if (Level(t->pLeft) > Level(t->pRight)) {
			//neu cay bi lech trai trai => xoay cay sang phai
			if (Level(t->pLeft->pLeft) >= Level(t->pLeft->pRight))
				turnRight(t);
			// neu cay bi lech trai phai => xoay trai cay con ben trai roi xoay phai cay
			else {
				turnLeft(t->pLeft);
				turnRight(t);
			}
		}
		//neu cay bi lech phai
		else if (Level(t->pLeft) < Level(t->pRight)) {
			//neu cay bi lech phai phai => xoay cay sang trai
			if (Level(t->pRight->pRight) >= Level(t->pRight->pLeft))
				turnLeft(t);
			//neu cay bi lech phai trai => xoay phai cay con ben phai roi xoay trai cay
			else {
				turnRight(t->pRight);
				turnLeft(t);
			}
		}
	}
	if (t->pLeft != NULL) updateAVL(t->pLeft);
	if (t->pRight != NULL) updateAVL(t->pRight);
}
/**********************************/
// Dem so node co gia tri bang x
int Count(Tree t, int x) {
	if (t == NULL) return 0;
	if (t->info == x) return 1 + Count(t->pLeft,x) + Count(t->pRight,x);
	else if (t->info < x) return Count(t->pRight, x);
	return Count(t->pLeft, x);
}
// ham xoa node
void DeleteNode(Tree& t) {
	if (t != NULL) {
		if (t->pLeft != NULL) DeleteNode(t->pLeft);
		if (t->pRight != NULL)DeleteNode(t->pRight);
		delete(t);
	}
}
Tree Delete(Tree& t, int x) {
	if (t != NULL) {
		if (t->info == x) DeleteNode(t);
		else if (t->info < x) return Delete(t->pRight, x);
		else Delete(t->pLeft, x);
	}
	return t;
}
Node* getS(Node* p) {
	Node* current = p->pRight;
	Node* parent = NULL;
	Node* s = NULL;
	while (current != NULL) {
		parent = s;
		s = current;
		current = current->pLeft;
	}
	if (s != p->pRight) {
		p->pRight->pLeft = s->pRight;
		s->pRight = p->pRight;
	}
	return s;
}
bool DelX(Tree& t, int x) {
	if (t) {
		Node* current = t;
		Node* parent = t;
		bool isLeft = false;
		while (current->info != x) {
			parent = current;
			if (current->info > x) {
				isLeft = true;
				current = current->pLeft;
			}
			else {
				isLeft = false;
				current = current->pRight;
			}
		}
		if (current) {
			if (current->pLeft == NULL && current->pRight == NULL) {
				if (current == t) t = NULL;
				else if (isLeft) 
					parent->pLeft = NULL;
				else parent->pRight = NULL;
			}
			else if (current->pLeft == NULL) {
				if (current == t) t = current->pRight;
				else if (isLeft) parent->pLeft = current->pRight;
				else parent->pRight = current->pRight;
			}
			else if (current->pRight == NULL) {
				if (current == t) t = current->pLeft;
				else if (isLeft) parent->pLeft = current->pLeft;
				else parent->pRight = current->pLeft;
			}
			else if (current->pRight != NULL && current->pLeft != NULL) {
				Node* temp = getS(current); //S la node trai nhat cua cay con ben phai
				if (current == t) t = temp;
				else if (isLeft) parent->pLeft = temp;
				else parent->pRight = temp;
				temp->pLeft = current->pLeft;
			}
			delete current;
			return 1;
		}
		return 0;
	}
}
int main() {
	int n, temp;
	cin >> n;
	Tree t;
	Init(t);
	for (int i = 0; i < n; i++) {
	cin >> temp;
		Insert(t, GetNode(temp));
	}
	cout << "So Node trong cay la: " << CountLa(t)<<endl;
	Print(t);

	int x;
	cout << "\n Nhap gia tri cua node can xoa: " << endl;
	cin >> x;
	DelX(t, x);
	if (t == NULL) cout << "NULL";
	else Print(t);
	return 0;
}