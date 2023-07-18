/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:48:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:00:38 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "Animal.hpp"

class Cat : public Animal {
  public:
	Cat();
	Cat(const Cat& src);
	~Cat();
	Cat&	operator=(Cat const &src);

	void makeSound() const;
};

