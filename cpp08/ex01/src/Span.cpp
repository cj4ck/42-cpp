/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:37:59 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 13:05:17 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : MyException(), _size(0), _vec() {}

Span::Span(unsigned int N) {
	int over_flow = static_cast<int>(N);
	if (over_flow < 0)
		throw MyException("Size N overflow, negative value not allowed!", __func__, __FILE__, __LINE__);
	_size = N;
}

Span::Span(Span const &src) : MyException() { *this = src;}
Span::~Span() {}

//* std::vector overloads `=` and it does perform deep copy.
Span& Span::operator=(Span const & rhs) {
	_size = rhs._size;
	_vec = rhs._vec;
	return (*this);
}

void Span::addNumber(int n) {
	if (_vec.size() >= _size)
		throw MyException("Vector is full!", __func__, __FILE__, __LINE__);
	_vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_size - _vec.size() < (unsigned long int)std::distance(begin, end)) throw std::exception();
	_vec.insert(_vec.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (this->_size < 1 || this->_vec.size() <= 1) throw MyException("Vector has too little objects!", __func__, __FILE__, __LINE__);

	std::vector<int> copy(this->_vec);
	std::sort(copy.begin(), copy.end());
	int ret = *(copy.begin() + 1) - *copy.begin();
	for (iterator it = copy.begin(); it != copy.end() - 1; ++it) {
		if(*(it + 1) - *it < ret) 
			ret = *(it + 1) - *it;
	}
	return ret;
}

unsigned int Span::longestSpan() const {
	if (_vec.size() <= 1 || this->_vec.size() <= 1) throw MyException("Vector has too little objects!", __func__, __FILE__, __LINE__);
	return
		*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

std::vector<int> Span::getVec() const { return _vec; }
