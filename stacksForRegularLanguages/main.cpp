#include "stack_p1.h"
#include "stacks_for_regular_languages.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{


	/*-------- Testing stack_p1 ------- */

	stack_p1<int> s; //defining new stack

	s.push(10);
	s.push(20);

	std::cout << s.peek() << " ";
	while (!s.isEmpty())
	{
		std::cout << s.pop() << " ";
	}
	std::cout << s.isEmpty() << " ";

	//Output - 20 20 10 1

	/*-------- End of Testing stack_p1 ------- */

	/*-------- Testing L1, L2, L3, L4 ------- */

	char arr1[10] = "ABABBA";
	char arr2[10] = "AAABBB";
	char arr3[10] = "ABAB";
	char arr4[10] = "ABBABB";

	stacks_for_regular_languages<char> obj;

	std::cout << obj.L1(arr1) << " ";
	std::cout << obj.L2(arr2) << " ";
	std::cout << obj.L3(arr3) << " ";
	std::cout << obj.L4(arr4) << " ";

	//Output - 1 1 1 1

	std::cout << obj.L2(arr3) << " ";
	std::cout << obj.L3(arr4) << " ";

	//Output - 0 0

	/*-------- End of Testing L1, L2, L3, L4 ------- */
	system("pause");
	return 0;


}
