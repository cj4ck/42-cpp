/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:27:19 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/19 21:07:13 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"

Data::Data() {}

Data::Data(Data const & src) { *this = src; }

Data & Data::operator=(Data const & rhs) {
	if (this != &rhs) {
		this->intraName = rhs.intraName;
	}
	return *this;
}

Data::~Data() {}

std::ostream & operator<<(std::ostream & ostream, const Data &src) {
	ostream << src.intraName;
	// ostream << ", " << src.test;
	return (ostream);
}
