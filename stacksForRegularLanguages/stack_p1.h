//
//  stack_p1.h
//
//
//  Created by Resch,Cheryl on 5/30/18.
//
#ifndef stack_p1_h
#define stack_p1_h
#include <vector>

template <class T>
class stack_p1
{
protected:
	std::vector<T> elems;
public:
	void push(T item);
	T pop();
	T peek();
	bool isEmpty();
};

template <class T>
void stack_p1<T>::push(T item) {
	elems.push_back(item);
}

template <class T>
T stack_p1<T>::pop() {
	T temp = elems.back();
	elems.pop_back();
	return temp;
}

template <class T>
T stack_p1<T>::peek() {
	return elems.back();
}

template <class T>
bool stack_p1<T>::isEmpty() {
	return elems.empty();
}

#endif /* stack_p1_h */#pragma once
