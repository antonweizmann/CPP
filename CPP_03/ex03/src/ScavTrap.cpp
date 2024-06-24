/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:42:19 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 11:38:19 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructer called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_health = src._health;
		_energy = src._energy;
		_attack = src._attack;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy == 0)
		std::cout << "ScavTrap " << _name << " has no energy." << std::endl;
	else if (_health == 0)
		std::cout << "ScavTrap " << _name << " has died" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		_energy--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
}
