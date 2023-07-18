/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:57:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/14 16:24:28 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.h"

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& src);
	~DiamondTrap();
	DiamondTrap&	operator=(DiamondTrap const &src);

	// void	attack(const std::string& target);
	void	whoAmI();
  private:
	std::string _name;
};
