/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:27:19 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 19:51:14 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"

Data::Data(std::string const & str) : _str(str) {}

Data::Data(Data const & src) { *this = src; }

Data & Data::operator=(Data const & rhs) {
	if (this != &rhs) {
		this->_str = rhs._str;
	}
	return *this;
}

Data::~Data() {}
