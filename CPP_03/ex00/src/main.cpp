/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:03:56 by aweizman          #+#    #+#             */
/*   Updated: 2024/10/16 11:40:03 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::string s= "ClapA";
	ClapTrap	clapA(s);
	ClapTrap	clapB;

	clapA.attack("clapB");
	clapB.takeDamage(1);
	clapB.beRepaired(2);
}
