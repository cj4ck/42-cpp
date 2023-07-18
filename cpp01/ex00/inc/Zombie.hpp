/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:04:05 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/10 15:40:26 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {
  public:
	Zombie(std::string name);
	~Zombie();
	void announce( void );
  private:
	std::string name;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );
