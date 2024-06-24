/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:53 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/24 17:21:34 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
	type = "Cat";
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructer called" << std::endl;
}

Cat::Cat(const Cat& src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound: Miao Miao" << std::endl;
}
