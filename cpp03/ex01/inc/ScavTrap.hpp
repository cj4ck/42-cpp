/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:57:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 22:35:29 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.h"

class ScavTrap : public ClapTrap {
  public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& src);
	~ScavTrap();
	ScavTrap&	operator=(ScavTrap const &src);

	void		attack(const std::string& target);

	void	guardGate();
};
