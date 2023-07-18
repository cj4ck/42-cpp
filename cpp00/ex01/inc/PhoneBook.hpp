/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:47:12 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/04 18:38:17 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "colors.h"
#include "Contact.hpp"

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
  private:
	int _contacts_counter;
	Contact _contacts[8];
};
