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