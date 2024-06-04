/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:13:07 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/04 11:59:58 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(){

}

PhoneBook::~PhoneBook(){

}

int	PhoneBook::fill_contact(int	index){
	std::string	input;

	std::cout << "Please enter the contact details now \033[1;32m[enter 0 to save go back to Phonebook] [enter 1 to go back to Phonebook without saving]\033[0m" << std::endl;
	std::cout << "First Name: " << std::endl;
	getline(std::cin, input);
	if (!input.compare("0")) return (0);
	if (!input.compare("1")) return (1);
	_contacts[index].set_fname(input);
	std::cout << "Last Name: " << std::endl;
	getline(std::cin, input);
	if (!input.compare("0")) return (0);
	if (!input.compare("1")) return (1);
	_contacts[index].set_lname(input);
	std::cout << "Nickname: " << std::endl;
	getline(std::cin, input);
	if (!input.compare("0")) return (0);
	if (!input.compare("1")) return (1);
	_contacts[index].set_nick(input);
	std::cout << "Phonenumber: " << std::endl;
	getline(std::cin, input);
	if (!input.compare("0")) return (0);
	if (!input.compare("1")) return (1);
	_contacts[index].set_phone(input);
	std::cout << "Darkest Secret: " << std::endl;
	getline(std::cin, input);
	if (!input.compare("0")) return (0);
	if (!input.compare("1")) return (1);
	_contacts[index].set_secret(input);
	_max_reached++;
	return (2);
}

void	PhoneBook::run_phonebook(void){
	std::string	input;

	_max_reached = 0;
	std::cout << "\033[1;32mWelcome to My Awesome Phonebook!\033[0m" << std::endl;
	std::cout << "You have up to 8 contacts saved \033[1;32m[Enter ADD to add a new contact]\033[0m" << std::endl;
	std::cout << "You can search for contact information \033[1;32m[Enter SEARCH to look for a specific contact]\033[0m" << std::endl;
	std::cout << "You can leave My Awesome Phonebook \033[1;32m[Enter EXIT to leave the phonebook]\033[0m" << std::endl;
	std::cout << "\033[1;32mThanks for using My Awesome Phonebook!\033[0m" << std::endl;
	while (1)
	{
		std::cout << "\033[1;32m> \033[0m";
		getline(std::cin, input);

		if (!input.compare("ADD"))
		{
			_max_reached++;
			if (fill_contact(_max_reached % 8 - 1) == 1) _max_reached--;
		}
		else if (!input.compare("SEARCH"))
		{
			std::string	input;
			int			index = 0;

			std::cout << "|\033[1;32mIndex     \033[0m|\033[1;32mFirst Name\033[0m|\033[1;32mLast Name \033[0m|\033[1;32mNickname  \033[0m|" << std::endl;
			for (int i = 0; i < _max_reached - 1 && i < 8; i++){
				_contacts[i].display_contact(std::to_string(i));
			}
			std::cout << std::endl << "You can look at all the infos of a contact \033[1;32m[Enter the index of the contact to show] [press enter to go back to Phonebook]\033[0m" << std::endl;
			getline(std::cin, input);
			if (input.length() == 1)
				index = std::stoi(input);
			if (index < _max_reached - 1 && index < 8 && index >= 0 && !std::to_string(index).compare(input)) _contacts[index].display_full();
		}
		else if (!input.compare("EXIT"))
			break;
	}
	for (int i = 0; i < _max_reached && i < 8; i++) _contacts[i].~Contact();
	PhoneBook::~PhoneBook();
	exit(0);
}
