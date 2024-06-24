/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:01:32 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/24 17:03:42 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructer called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}
