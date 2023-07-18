/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:18:00 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/18 18:33:44 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
	
	void		action() const;
	std::string getTarget() const;
	
  private:
	PresidentialPardonForm();
	std::string _target;
};
