/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:08:38 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/06 21:24:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "colors.h"

class Weapon {
  public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type);
  private:
	std::string _type;
};
