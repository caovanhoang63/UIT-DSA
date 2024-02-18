#pragma once

template<class K,class V>class HashTableInterface {
public:
	virtual bool isEmpty() = 0 ;
	virtual void hash() = 0 ;
	virtual V insert(K v, V v) = 0 ;
	virtual int has();
	virtual V get(K k);
	virtual void clear();
};