/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:03:56 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 17:03:35 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::string s= "ClapA";
	ScavTrap	clapA(s);
	ScavTrap	clapB;

	clapA.attack("clapB");
	clapB.takeDamage(1);
	clapB.beRepaired(2);
	clapB.guardGate();
}
