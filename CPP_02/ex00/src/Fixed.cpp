/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:12:22 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/12 21:59:11 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructer called" << std::endl;
}

Fixed::Fixed(const Fixed &temp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = temp;
}

Fixed &Fixed::operator=(const Fixed &temp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point_value = temp.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_value;
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}
