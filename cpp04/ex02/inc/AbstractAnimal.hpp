/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:14:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:44:23 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"

//* Abstract Class
class AbstractAnimal {
  public:
	AbstractAnimal();
	AbstractAnimal(const AbstractAnimal&);
	virtual ~AbstractAnimal();
	AbstractAnimal&	operator=(AbstractAnimal const &src);
	// virtual void makeSound() const;
	virtual void makeSound() const = 0;
	virtual std::string	getType() const;
  protected:
	std::string	_type;
};
