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
	char first = *inputString;
	stack_p1<std::string> pattern;
	stack_p1<std::string> pattern2;
	bool foundB = false;
	std::string containsPattern="";
	std::string checkStr="";

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...find pattern, concatenate pattern to string, push string to stack
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...start string concatenation 
		if (foundB == false) {
			if (*it == 'A') containsPattern += *it;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, push pattern to stacks for later
		//else iterator is on a B, so continue string concatenation
		if (foundB == true) {
			if (*it == 'A') {
				pattern.push(containsPattern);
				pattern2.push(containsPattern);
				containsPattern = *it;   //reset
				foundB = false;
			}
			else containsPattern += *it;
		}
	}
	//push last pattern repeat to stacks
	pattern.push(containsPattern);
	pattern2.push(containsPattern);

	//concenate new string of last stack entry
	while (!pattern.isEmpty()) checkStr += pattern.pop();

	//WANT: inputString == postString
	//if not equal return false
	if (inputString != checkStr) return false;
	
	//WANT: each stack entry of pattern to pass l2
	while(!pattern2.isEmpty()){
		//get top entry of stack to push to l2 to check
		if (!L2(&pattern2.pop().at(0))) return false;
	}
	
	//if strings are equal and each individual pattern is l2 case, then return true
	return true;
}

template <class T>
bool stacks_for_regular_languages<T>::L4(char* inputString) {
	char first = *inputString;
	stack_p1<std::string> pattern;
	stack_p1<std::string> pattern2;
	bool foundB = false;
	std::string containsPattern = "";
	std::string checkStr = "";

	//if does not start with A, automatically false
	if (first != 'A') return false;

	//iterate string...find pattern, concatenate pattern to string, push string to stack
	for (char *it = inputString; *it; ++it) {
		//automatically false case
		if ((*it != 'A') && (*it != 'B')) return false;

		//found A...start string concatenation 
		if (foundB == false) {
			if (*it == 'A') containsPattern += *it;
			else foundB = true;
		}

		//if iterator is A, pattern is finished, push pattern to stacks for later
		//else iterator is on a B, so continue string concatenation
		if (foundB == true) {
			if (*it == 'A') {
				pattern.push(containsPattern);
				pattern2.push(containsPattern);
				containsPattern = *it;   //reset
				foundB = false;
			}
			else containsPattern += *it;
		}
	}
	//push last pattern repeat to stacks
	pattern.push(containsPattern);
	pattern2.push(containsPattern);

	//concatenate new string of last stack entry
	while (!pattern.isEmpty()) checkStr += pattern.pop();

	//WANT: inputString == postString
	//if not equal return false
	if (inputString != checkStr) return false;

	//has an incomplete pattern, so language is invalid
	if (foundB == false) return false;

	//if strings are equal and each individual pattern is l2 case, then return true
	return true;
}
#endif /*stacks_for_regular_languages_h*/