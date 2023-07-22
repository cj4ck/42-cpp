/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:03:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 13:47:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}

	explicit MutantStack(const typename std::stack<T>::container_type& cont) : std::stack<T>(cont) {} //container_type = `std::deque<T>` by default.

	MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
	~MutantStack() {}
	MutantStack<T>& operator=(const MutantStack<T>& rhs) {
		if (this != &rhs) {
			std::stack<T>::operator=(rhs);
		}
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); } //c represents underlying container 
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

