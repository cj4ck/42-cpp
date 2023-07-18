/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:48:43 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "WrongCat" << E;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "WrongCat" << E;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "WrongCat" << E;
}

WrongCat&	WrongCat::operator=(WrongCat const& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload" << G << "called for class: " << BLUE << "WrongCat" << E;
	return(*this);
}

void WrongCat::makeSound() const { std::cout << "WrongMeow! Meow! 🐈" << E; }
