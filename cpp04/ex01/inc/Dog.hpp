/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:47:40 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:14:22 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	Brain*		_brain;
  public:
	Dog();
	Dog(const Dog& src);
	~Dog();
	Dog&	operator=(Dog const &src);

	void makeSound() const;
};

