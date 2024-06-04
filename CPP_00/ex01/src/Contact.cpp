/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:24:09 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/04 11:40:24 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::display_full(void)
{
	std::cout << "First Name:     " << this->_fname << std::endl;
	std::cout << "Last Name:      " << this->_lname << std::endl;
	std::cout << "Nickname:       " << this->_nick << std::endl;
	std::cout << "Phonenumber:    " << this->_phone << std::endl;
	std::cout << "Darkest Secret: " << this->_secret << std::endl;
}

void	display_element(std::string element)
{
	std::string	output;

	std::cout << "|";
	if (element.length() > 10)
	{
		output = element.substr(0, 9);
		output.append(".");
	}
	else
		output = element;
	std::cout << output;
	for (size_t	k = output.length(); k < 10; k++) std::cout << " ";
}

void	Contact::display_contact(std::string index)
{
	display_element(index);
	display_element(_fname);
	display_element(_lname);
	display_element(_nick);
	std::cout << "|" << std::endl;
}

void	Contact::set_fname(std::string input)
{
	_fname = input;
}

void	Contact::set_lname(std::string input)
{
	_lname = input;
}

void	Contact::set_nick(std::string input)
{
	_nick = input;
}

void	Contact::set_phone(std::string input)
{
	_phone = input;
}

void	Contact::set_secret(std::string input)
{
	_secret = input;
}
