/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:28:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/06 22:10:29 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "colors.h"
#include "Weapon.hpp"

class HumanA {
  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
  private:
	Weapon &_weapon;
	std::string _name;
};

