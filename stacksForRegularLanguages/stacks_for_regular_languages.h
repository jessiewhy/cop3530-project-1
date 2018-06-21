//
//  stacks_for_regular_languages.h
//
//
//  Created by Cheryl Resch on 5/29/18.
//
#ifndef stacks_for_regular_languages_h
#define stacks_for_regular_languages_h
#include "stack_p1.h"

template <class T>
class stacks_for_regular_languages : public stack_p1<T>
{
public:
	bool L1(char * inputString);
	bool L2(char * inputString);
	bool L3(char * inputString);
	bool L4(char * inputString);
};

template <class T>
bool stacks_for_regular_languages<T>::L1(char* inputString) {
	stack_p1<char> s1;
	int n = sizeof(inputString) / sizeof(char);
	for (int i = 0; i < n; ++i)
	{
		char c = inputString[i];
		if (s1.isEmpty()) {
			s1.push(c);
			continue;
		}
		if (s1.peek() == c) {
			s1.push(c);
		}
		else {
			s1.pop();
		}
	}
	return s1.isEmpty();
}

template <class T>
bool stacks_for_regular_languages<T>::L2(char* inputString) {
	stack_p1<char> sA;
	bool foundB = false;
	char first = *inputString;

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...push all A to stack, will use to track how many ordered Bs are in string
	for (char *it = inputString; *it; ++it ) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;
		
		//found A...push to stack
		if (foundB == false) {
			if (*it == 'A') sA.push(*it);
			else foundB = true;
		}
		
		//if list iteration is continuing after all pops are finished
		if (foundB == true) {
			if (*it == 'A') return false;
		}
	}

	//want: pop A as many times as you find B
	//iterate string again...pop sA every time string lands on B
	for (char *it = inputString; *it; ++it) {
		if (*it != first) {
			//if A stack is not empty and equal to B, pop
			if (!sA.isEmpty()) sA.pop();
			//else stack is empty and iterator lands on character not equal to A, language not valid
			else return false;
		}
	}

	//empty stack = accepted language, else language false
	if (sA.isEmpty()) return true;
	else return false;
}

template <class T>
bool stacks_for_regular_languages<T>::L3(char* inputString) {
	stack_p1<char> s1;
	int n = sizeof(inputString) / sizeof(char);
	for (int i = 0; i < n; ++i)
	{
		char c = inputString[i];
		if (s1.isEmpty()) {
			s1.push(c);
			continue;
		}
		if (s1.peek() == c) {
			s1.push(c);
		}
		else {
			s1.pop();
		}
	}
	return s1.isEmpty();
}

template <class T>
bool stacks_for_regular_languages<T>::L4(char* inputString) {
	stack_p1<char> s1;
	int n = sizeof(inputString) / sizeof(char);
	for (int i = 0; i < n; ++i)
	{
		char c = inputString[i];
		if (s1.isEmpty()) {
			s1.push(c);
			continue;
		}
		if (s1.peek() == c) {
			s1.push(c);
		}
		else {
			s1.pop();
		}
	}
	return s1.isEmpty();
}
#endif /*stacks_for_regular_languages_h*/