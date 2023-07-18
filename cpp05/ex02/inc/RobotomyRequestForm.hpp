/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:09:34 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:33:50 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
	
	void		action() const;
	std::string getTarget() const;
	
  private:
	RobotomyRequestForm();
	std::string _target;
};
