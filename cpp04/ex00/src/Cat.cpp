/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:04 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:50:16 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Cat" << E;
	this->_type = "Cat";
}

Cat::~Cat() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Cat" << E;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Cat" << E;
}

Cat&	Cat::operator=(Cat const& src) {
	_type = src.getType();
	std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Cat" << E;
	return(*this);
}

void Cat::makeSound() const { std::cout << "Meow! Meow! 🐈" << E; }
