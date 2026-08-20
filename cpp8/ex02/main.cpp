#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "--- subject example ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[3,5,737]
	mstack.push(0);
	//[3,5,737,0]

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--- comparing with a normal std::stack ---" << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "std::stack size: " << s.size() << std::endl;

	std::cout << "--- MutantStack with std::list as container ---" << std::endl;
	MutantStack<int, std::list<int> > listStack;
	listStack.push(1);
	listStack.push(2);
	listStack.push(3);
	for (MutantStack<int, std::list<int> >::iterator lit = listStack.begin();
		 lit != listStack.end(); ++lit)
		std::cout << *lit << " ";
	std::cout << std::endl;

	return 0;
}
