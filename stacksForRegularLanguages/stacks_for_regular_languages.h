//
//  stacks_for_regular_languages.h
//
//
//  Created by Cheryl Resch on 5/29/18.
//
#ifndef stacks_for_regular_languages_h
#define stacks_for_regular_languages_h
#include "stack_p1.h"
#include <string>

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
	stack_p1<char> sA;
	char first = *inputString;

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...push all A to stack, will use to track how many ordered Bs are in string
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...push to stack
		if (*it == 'A') sA.push(*it);
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
		
		//if list finds an A after a B
		if (foundB == true) {
			if (*it == 'A') return false;
		}
	}

	for (char *it = inputString; *it; ++it) {
		if (*it != first) {
			//if A stack is not empty and equal to B, pop
			if (!sA.isEmpty()) sA.pop();
			//else stack is empty and iterator lands on character not equal to A, language not valid
			else return false;
		}
	}

	if (sA.isEmpty()) return true;
	else return false;
}

template <class T>
bool stacks_for_regular_languages<T>::L3(char* inputString) {
	char first = *inputString;
	stack_p1<char> pattern;
	stack_p1<std::string> pattern2;
	bool foundB = false;
	std::string containsPattern = "";
	int patternTracker = 0;

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...find pattern, concatenate pattern to string, push string to stack
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...start string concatenation...use for testing each individual pattern entry later
		if (foundB == false) {
			if (*it == 'A') containsPattern += *it;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, push symbol to stack to symbolize one pattern complete
		//also push complete pattern to patterns2 for individual pattern testing
		//else iterator is on a B, so continue string concatenation
		if (foundB == true) {
			if (*it == 'A') {
				pattern.push('$');
				pattern2.push(containsPattern);
				containsPattern = *it;   //reset
				foundB = false;
			}
			else containsPattern += *it;
		}
	}
	//push last pattern repeat to stacks
	pattern.push('$');
	pattern2.push(containsPattern);

	//patterns in string and pops in stack should be equivalent
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...pattern started 
		if (foundB == false) {
			if (*it == 'A') continue;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, pop pattern stick to mark off one pattern
		//else iterator is on a B, so pattern continues
		if (foundB == true) {
			if (*it == 'A') {
				pattern.pop();
				foundB = false;
			}
			else continue;
		}
	}

	//did pops match number of full patterns in string?
	if (!pattern.isEmpty()) return false;

	//WANT: each individual stack entry of pattern to pass l2
	while (!pattern2.isEmpty()) {
		//get top entry of stack to push to l2 to check
		bool checkL2 = true;
		if (!L2(&pattern2.pop().at(0))) return false;
	}

	//if pattern stack is empty and each individual pattern entry 
	//meets requirements L2 requirements, then language is valid
	return true;
}

template <class T>
bool stacks_for_regular_languages<T>::L4(char* inputString) {
	char first = *inputString;
	stack_p1<char> pattern;
	stack_p1<std::string> pattern2;
	bool foundB = false;
	std::string containsPattern = "";
	int patternTracker = 0;

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...find pattern, concatenate pattern to string, push string to stack
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...start string concatenation...use for testing each individual pattern entry later
		if (foundB == false) {
			if (*it == 'A') containsPattern += *it;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, push symbol to stack to symbolize one pattern complete
		//also push complete pattern to patterns2 for individual pattern testing
		//else iterator is on a B, so continue string concatenation
		if (foundB == true) {
			if (*it == 'A') {
				pattern.push('$');
				pattern2.push(containsPattern);
				containsPattern = *it;   //reset
				foundB = false;
			}
			else containsPattern += *it;
		}
	}
	//push last pattern repeat to stacks
	pattern.push('$');
	pattern2.push(containsPattern);

	//patterns in string and pops in stack should be equivalent
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...pattern started 
		if (foundB == false) {
			if (*it == 'A') continue;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, pop pattern stick to mark off one pattern
		//else iterator is on a B, so pattern continues
		if (foundB == true) {
			if (*it == 'A') {
				pattern.pop();
				foundB = false;
			}
			else continue;
		}
	}

	//did pops match number of full patterns in string?
	if (!pattern.isEmpty()) return false;

	//has an incomplete pattern, so language is invalid
	if (foundB == false) return false;

	//if pattern stack is empty and each individual pattern entry 
	//meets requirements L2 requirements, then language is valid
	return true;
}
#endif /*stacks_for_regular_languages_h*/