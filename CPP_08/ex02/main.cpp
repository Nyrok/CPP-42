#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

static void	subjectTest(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

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
}

static void	listTest(void)
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

static void	extraTests(void)
{
	MutantStack<std::string>	words;

	words.push("one");
	words.push("two");
	words.push("three");

	std::cout << "reverse: ";
	for (MutantStack<std::string>::reverse_iterator it = words.rbegin(); it != words.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "modify through iterator: ";
	for (MutantStack<std::string>::iterator it = words.begin(); it != words.end(); ++it)
		*it += "!";
	std::cout << words.top() << std::endl;

	MutantStack<std::string>		copy(words);
	MutantStack<std::string>		assigned;
	MutantStack<std::string> const	&constRef = copy;

	assigned = words;
	words.pop();
	std::cout << "original size after pop: " << words.size() << std::endl;
	std::cout << "copy (const_iterator): ";
	for (MutantStack<std::string>::const_iterator it = constRef.begin(); it != constRef.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "assigned size: " << assigned.size() << std::endl;

	MutantStack<int, std::vector<int> >	vstack;

	vstack.push(1);
	vstack.push(2);
	std::cout << "std::vector underlying: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "empty: " << vstack.empty() << std::endl;
}

int	main(void)
{
	std::cout << "--- MutantStack ---" << std::endl;
	subjectTest();
	std::cout << std::endl << "--- std::list ---" << std::endl;
	listTest();
	std::cout << std::endl << "--- Extra ---" << std::endl;
	extraTests();
	return (0);
}
