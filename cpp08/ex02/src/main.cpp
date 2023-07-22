/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:10:01 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 13:47:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>
#include "../inc/MutantStack.hpp"
#include "../inc/Colors.hpp"

int main() {
	std::cout << G << "\n  -=[ " << ITALIC << "output should stay the same" << R << G <<  " ]=-" << E;
	std::cout << BLUE << "━━━=[ MutantStack Test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << BLUE << mstack.top() << E;

	mstack.pop();
	std::cout << BLUE << mstack.size() << E;

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
		std::cout << BLUE << *it << E;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << G << "\n  -=[ " << ITALIC << "output should stay the same" << R << G <<  " ]=-" << E;
	std::cout << BLUE << "━━━=[ List Test ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	std::list< int > lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << BLUE << lst.back() << E;

	lst.pop_back();
	std::cout << BLUE << lst.size() << E;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	++it;
	--it;
	while (lst_it != lst_ite)
	{
		std::cout << BLUE << *lst_it << E;
		++lst_it;
	}
	std::list<int> l(lst);
	
	std::cout << E << SYS_MSG << BLUE << "now some iterator tests... " << E << E;

	std::cout << BLUE << "━━━=[ Empty Stack ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	MutantStack<int> emptyStack;
	std::cout  << SYS_MSG << "Empty Stack size: " << emptyStack.size() << "\n";
	if (emptyStack.begin() == emptyStack.end()) {
		std::cout  << SYS_MSG << "Empty Stack is empty.\n";
	} else {
		std::cout << SYS_MSG << "Error: Empty Stack should be empty, but it has elements.\n";
	}

	std::cout << BLUE << "━━━=[ Accessing Top of Empty Stack ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	try {
		if (emptyStack.empty()) {
			std::cout << SYS_MSG << "Empty Stack is empty. Cannot access top.\n";
		} else {
			std::cout << SYS_MSG << "Top element of emptyStack: " << emptyStack.top() << "\n";
		}
		emptyStack.top(); // This should throw an exception (std::out_of_range) when accessing the top of an empty stack but subject didn't mention exceptions . . .
	} catch (const std::out_of_range& ex) {
		std::cout << SYS_MSG << "Caught exception: " << ex.what() << "\n";
	}

	std::cout << BLUE << "━━━=[ Iterating Over an Empty Stack ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	if (emptyStack.empty()) {
		std::cout << SYS_MSG << "Empty Stack is empty. Cannot access top.\n";
	} else {
		std::cout << SYS_MSG << "Top element of emptyStack: " << emptyStack.top() << "\n";
	}
	for (MutantStack<int>::const_iterator it = emptyStack.begin(); it != emptyStack.end(); ++it) {
		std::cout << SYS_MSG << "Const Stack Element: " << *it << "\n";
	}

	std::cout << BLUE << "━━━=[ Different Types ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
		std::cout << SYS_MSG << "String Stack Element: " << *it << "\n";
	}

	std::cout << BLUE << "━━━=[ Copying Empty Stack ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	MutantStack<int> copiedEmptyStack(emptyStack);
	std::cout  << SYS_MSG << "Copied Empty Stack size: " << copiedEmptyStack.size() << "\n";

	std::cout << BLUE << "━━━=[ Copying Stack with Elements ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	MutantStack<int> intStack;
	intStack.push(42);
	intStack.push(4);
	intStack.push(2);
	if (intStack.empty()) {
		std::cout << SYS_MSG << "Empty Stack is empty.\n";
	} else {
		std::cout << SYS_MSG << "intStack Stack is not empty."<< "\n";
	}
	MutantStack<int> copiedStack(intStack);
	std::cout  << SYS_MSG << "Copied Stack size: " << copiedStack.size() << "\n";
	for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
		std::cout << SYS_MSG << "Copied Stack Element: " << *it << "\n";
	}

	std::cout << BLUE << "━━━=[ Assignment Operator ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	MutantStack<int> assignedStack;
	assignedStack = intStack;
	std::cout  << SYS_MSG << "Assigned Stack size: " << assignedStack.size() << "\n";
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
		std::cout << SYS_MSG << "Assigned Stack Element: " << *it << "\n";
	}

	std::cout << BLUE << "━━━=[ Const Iterator ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << E;
	const MutantStack<int> constStack = intStack;
	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
		std::cout << SYS_MSG << "Const Stack Element: " << *it << "\n";
	}
	return 0;
}
