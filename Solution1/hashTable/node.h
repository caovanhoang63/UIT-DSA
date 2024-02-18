#pragma once

template <class K,class V>class Node {
private:
	K key;
	V value;
	int hash;
	Node* pNext;
	Node* pPrev;
public:
	Node(K key, V value) {
		this->key = key;
		this->value = value;
	}
	bool equals(Node* <K, V> other);
	void push_back();
	void init();
	void deleteNode();
	Node* getNode();
	friend Node* createNode(K,V);
	V getValue();
	K getKey();
	~Node();
};