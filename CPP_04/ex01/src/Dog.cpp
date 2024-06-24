/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:53 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/24 17:07:42 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_brain = new Brain();
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructer called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound: Wuf Wuf" << std::endl;
}
