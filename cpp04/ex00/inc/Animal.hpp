/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:14:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 13:58:06 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"

//* Abstract Class
class Animal {
  public:
	Animal();
	Animal(const Animal&);
	virtual ~Animal();
	Animal&	operator=(Animal const &src);
	virtual void makeSound() const;
	// virtual void makeSound() = 0;
	std::string	getType() const;
  protected:
	std::string	_type; //*_type can't be initiazlized
};
