/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:20:17 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/29 15:10:37 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	_name	= "NoName";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
	_name	= name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructer called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) :  ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_health = src._health;
		_energy = src._energy;
		_attack = src._attack;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My Name is " << _name << " and my parents name is " << ClapTrap::_name << std::endl;
}
