/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:42:19 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/18 17:12:25 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string& name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructer called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_health = src._health;
		_energy = src._energy;
		_attack = src._attack;
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (_energy == 0)
		std::cout << "FragTrap " << _name << " has no energy." << std::endl;
	else if (_health == 0)
		std::cout << "FragTrap " << _name << " has died" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		_energy--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants a high five!" << std::endl;
}
