/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:42:19 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 16:15:11 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string& name) : _name(name), _health(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap() : _name("NoName"), _health(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructer called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_health = src._health;
		_energy = src._energy;
		_attack = src._attack;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy." << std::endl;
	else if (_health == 0)
		std::cout << "ClapTrap " << _name << " has died" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		_energy--;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy." << std::endl;
	else if (_health == 0)
		std::cout << "ClapTrap " << _name << " has died" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " gains " << amount << " health points!" << std::endl;
		_health += amount;
		_energy--;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_health == 0)
		std::cout << "ClapTrap " << _name << " is already dead, but its body gets mutilated a little further." << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		if (_health < amount)
			_health = 0;
		else
			_health -= amount;
	}
}
