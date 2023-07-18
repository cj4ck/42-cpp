/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:55:31 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:15:18 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "Colors.hpp"
#define ARR_N 100

class Brain {
  public:
	Brain();
	Brain(const Brain& src);
	~Brain();
	Brain&	operator=(Brain const &src);

	const std::string* getIdeas() const;
	void	setIdeas(std::string idea, int index);

  private:
	std::string _ideas[ARR_N];
};
