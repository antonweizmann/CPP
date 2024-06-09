/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:27:35 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/09 14:28:55 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){
	
}

void	Harl::get_message(int case_nbr)
{
	void (Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	switch (case_nbr)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		(this->*complaints[0])();
		std::cout << std::endl;
		get_message(1);
		break;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		(this->*complaints[1])();
		std::cout << std::endl;
		get_message(2);
		break;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		(this->*complaints[2])();
		std::cout << std::endl;
		get_message(3);
		break;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		(this->*complaints[3])();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

void	Harl::complain(std::string level)
{
	std::string cases[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	case_nbr;

	case_nbr = 5;
	for (int i = 0; i < 4; i++)
	{
		if (cases[i] == level)
		{
			case_nbr = i;
			break ;
		}
	}
	get_message(case_nbr);
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
