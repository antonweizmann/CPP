/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:53 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/19 15:58:38 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("unasigned")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructer called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound:" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
