/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:14:15 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:43:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"

//* Abstract Class
class WrongAnimal {
  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	virtual ~WrongAnimal();
	WrongAnimal&	operator=(WrongAnimal const &src);
	void makeSound() const; //* keypoint
	std::string	getType() const;
  protected:
	std::string	_type;
};
