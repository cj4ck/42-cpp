/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:48:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:45:36 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal {
//   public:
	Brain*		_brain;
  public:
	Cat();
	Cat(const Cat& src);
	~Cat();
	Cat&	operator=(Cat const &src);

	void makeSound() const;
};

