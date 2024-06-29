/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:13:07 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/29 14:51:52 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(){

}

PhoneBook::~PhoneBook(){

}

void	get_input(std::string *input, std::string item)
{
	getline(std::cin, *input);
	while (input->empty())
	{
		std::cout << "\033[1;31mThis field cannot be left empty\033[0m" << std::endl;
		std::cout << item << std::endl;
		getline(std::cin, *input);
		if (!input->compare("0")) return ;
	}
}

int	PhoneBook::fill_contact(int	index){
	std::string	input;

	std::cout << "Please enter the contact details now \033[1;32m[enter 0 to abort and go back to Phonebook]\033[0m" << std::endl;
	std::cout << "First Name: " << std::endl;
	get_input(&input, "First Name: ");
	if (!input.compare("0")) return (0);
	_contacts[index].set_fname(input);
	std::cout << "Last Name: " << std::endl;
	get_input(&input, "Last Name: ");
	if (!input.compare("0")) return (0);
	_contacts[index].set_lname(input);
	std::cout << "Nickname: " << std::endl;
	get_input(&input, "Nickname: ");
	if (!input.compare("0")) return (0);
	_contacts[index].set_nick(input);
	std::cout << "Phonenumber: " << std::endl;
	get_input(&input, "Phonenumber:");
	if (!input.compare("0")) return (0);
	_contacts[index].set_phone(input);
	std::cout << "Darkest Secret: " << std::endl;
	get_input(&input, "Darkest Secret: ");
	if (!input.compare("0")) return (0);
	_contacts[index].set_secret(input);
	return (1);
}

void	PhoneBook::search(void)
{
	std::string	input;
	int			index = 0;

	std::cout << "|\033[1;32m     Index\033[0m|\033[1;32mFirst Name\033[0m|\033[1;32m Last Name\033[0m|\033[1;32m  Nickname\033[0m|" << std::endl;
	for (int i = 0; i < _max_reached && i < 8; i++){
		std::stringstream ss;
		ss << i;
		_contacts[i].display_contact(ss.str());
	}
	std::cout << std::endl << "You can look at all the infos of a contact \033[1;32m[Enter the index of the contact to show] [press enter to go back to Phonebook]\033[0m" << std::endl;
	getline(std::cin, input);
	while (1)
	{
		if (index)
			getline(std::cin, input);
		if (input.empty())
			break ;
		try {
			std::stringstream stoi(input);
			stoi >> index;
			if (stoi.fail())
        		std::cout << "Invalid argument for stoi: " + input << std::endl;
			if (index < 8 && index >= 0)
			{
				if (index < _max_reached)
				{
					_contacts[index].display_full();
					break ;
				}
				std::cout << "\033[1;31mInvalid Index.\033[0m Please enter a index that is shown" << std::endl;
			}
			else
				std::cout << "\033[1;31mInvalid Index.\033[0m Please enter a number between 0 and 8" << std::endl;
		} catch (const std::invalid_argument&){
			std::cout << "\033[1;31mInvalid Input.\033[0m Please enter a valid number" << std::endl;
		} catch (const std::out_of_range&){
			std::cout << "\033[1;31mInput out of range.\033[0m Please enter a valid number" << std::endl;
		}
		index = 1;
	}
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
			if (fill_contact((_max_reached - 1) % 8) == 0) _max_reached--;
		}
		else if (!input.compare("SEARCH"))
			PhoneBook::search();
		else if (!input.compare("EXIT"))
			break;
	}
	for (int i = 0; i < _max_reached && i < 8; i++) _contacts[i].~Contact();
	PhoneBook::~PhoneBook();
	return ;
}
