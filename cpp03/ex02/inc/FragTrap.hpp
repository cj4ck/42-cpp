/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:57:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/13 22:38:08 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.h"

class FragTrap : public ClapTrap {
  public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& src);
	~FragTrap();
	FragTrap&	operator=(FragTrap const &src);

	void	attack(const std::string& target);

	void	highFivesGuys();
};

