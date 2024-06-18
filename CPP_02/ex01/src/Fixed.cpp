/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:12:22 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/18 10:56:46 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

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
	std::cout << "Copy constructor called" << std::endl;
	*this = temp;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_value = (input << _fracBits) & 0xFFFFFFFF;
}


Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_value = roundf(input * (1 << _fracBits));
}

Fixed &Fixed::operator=(const Fixed &temp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &temp)
		_fixed_point_value = temp.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return _fixed_point_value;
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixed_point_value / (1 << _fracBits));
}

int	Fixed::toInt(void) const
{
	return (_fixed_point_value >> _fracBits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& temp)
{
	output << temp.toFloat();
	return (output);
}
