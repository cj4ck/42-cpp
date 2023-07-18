/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:48:02 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/04 18:40:42 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	_contacts_counter = 0;
}
PhoneBook::~PhoneBook(){}

std::string get_field(std::string prompt)
{
	std::string result;
	std::cout << F << BASE_B << "56m[◎]" << R << " Insert " << prompt << ": ";
	getline(std::cin, result, '\n');
	return(result);
}

void PhoneBook::add_contact()
{
	Contact new_contact;
	new_contact.set_first_name(get_field("First Name"));
	new_contact.set_last_name(get_field("Last Name"));
	new_contact.set_nickname(get_field("Nickname"));
	new_contact.set_phone_number(get_field("Phone Number"));
	new_contact.set_darkest_secret(get_field("Darkest Secret"));
	_contacts[_contacts_counter % 8] = new_contact;
	_contacts_counter++;
}

std::string turncate_text(const std::string& text)
{
	unsigned long column_width = 10;
	if(text.length() > column_width)
		return(text.substr(0, column_width - 1) + ".");
	return text;
}

void PhoneBook::search_contact()
{
	int tmp = 0;
	std::cout << "\n" << BASE_B << "56m" << std::setw(45) << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
	while(tmp < _contacts_counter && tmp < 8)
	{
		std::cout <<  "|" << std::setw(10) << std::right << tmp + 1 << "|";
		std::cout << std::setw(10) << std::right << turncate_text(_contacts[tmp].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << turncate_text(_contacts[tmp].get_last_name())<< "|";
		std::cout << std::setw(10) << std::right << turncate_text(_contacts[tmp].get_nickname())<< "|\n";
		tmp++;
	}
	std::cout << R << "\n";
	int index = std::atoi(get_field("index of the entry to display").c_str());
	if( index > 0 && index <= 8 && index <= _contacts_counter)
	{
		std::cout << BASE_T << "56m" << std::setw(18) <<"    FIRST NAME" << R << " | " << _contacts[index - 1].get_first_name() << "\n";
		std::cout << BASE_T << "56m" << std::setw(18) <<"    LAST NAME" << R << " | " <<_contacts[index - 1].get_last_name() << "\n";
		std::cout << BASE_T << "56m" << std::setw(18) <<"    NICKNAME" << R << " | " <<_contacts[index - 1].get_nickname() << "\n";
		std::cout << BASE_T << "56m" << std::setw(18) <<"    PHONE NUMBER" << R << " | " <<_contacts[index - 1].get_phone_number() << "\n";
		std::cout << BASE_T << "56m" << std::setw(18) <<"    DARKEST SECRET" << R << " | " <<_contacts[index - 1].get_darkest_secret() << "\n";
	}
	else
		std::cerr << ERROR << "Contact doesn't exist\n\n" << R;
}

// void	PhoneBook::demi_phonebook()
// {
// 	_contacts_counter = 4;
// 	for(int i = 0; i < 4; i++)
// 	{
// 	_contacts[i].set_first_name("Klaudiusz");
// 	_contacts[i].set_last_name("Jackowski");
// 	_contacts[i].set_nickname("cj4ck");
// 	_contacts[i].set_phone_number("574357960");
// 	_contacts[i].set_darkest_secret("-");
// 	}
// }