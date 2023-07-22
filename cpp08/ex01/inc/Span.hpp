/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:26:51 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/22 13:05:06 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include "MyException.hpp"

class Span : public MyException {
  public :
	Span(unsigned int N);
	Span(Span const &);
	~Span();
	Span& operator=(Span const &);


	void addNumber(int);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	std::vector<int> getVec() const;
  private :
	Span();
	unsigned int _size;
	std::vector<int> _vec;
	typedef std::vector<int>::iterator iterator;
};
