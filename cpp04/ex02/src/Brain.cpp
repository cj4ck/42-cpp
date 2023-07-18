/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:57:11 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 16:16:04 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()  { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for class: " << BLUE << "Brain" << E;
	for (int i = 0; i < ARR_N; i++) {
		if (i % 3) {
			this->_ideas[i] = "💭 (🍽️ + 😋...)";
		}
		else if (i % 5) {
			this->_ideas[i] = "💭 (😴...)";
		}
		else
			this->_ideas[i] = "💭 (🤪...)";
		// std::cout << _ideas[i] << E;
	}
}

Brain::~Brain() { std::cout << SYS_MSG_DES << "Def Destructor " << G << "called for class: " << BLUE << "Brain" << E; }

Brain::Brain(const Brain& src) { std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for class: " << BLUE << "Brain" << E;
	for (int i = 0; i < ARR_N; i++) {
		this->_ideas[i] = src._ideas[i];
	}
}

Brain&	Brain::operator=(Brain const& src) { std::cout << SYS_MSG_CON << "Copy Asigmnet operator overload " << G << "called for class: " << BLUE << "Brain" << E;
	for (int i = 0; i < ARR_N; i++) {
		this->_ideas[i] = src._ideas[i];
	}
	return(*this);
}

const std::string* Brain::getIdeas() const {
	return (_ideas);
}

void	Brain::setIdeas(std::string idea, int index) {
	if (index >= 0 && index < ARR_N) {
		_ideas[index] = idea;
	}
	else
		std::cout << "Index out of bounds" << std::endl;
}
