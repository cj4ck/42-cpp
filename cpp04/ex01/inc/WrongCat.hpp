/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:48:21 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 14:41:56 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Colors.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
	WrongCat();
	WrongCat(const WrongCat& src);
	~WrongCat();
	WrongCat&	operator=(WrongCat const &src);

	void makeSound() const;
};

