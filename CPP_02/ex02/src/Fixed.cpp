/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:12:22 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/18 11:43:49 by antonweizma      ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed& other)
{
	return (_fixed_point_value > other._fixed_point_value);
}

bool	Fixed::operator<(const Fixed& other)
{
	return (_fixed_point_value < other._fixed_point_value);
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (_fixed_point_value >= other._fixed_point_value);
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (_fixed_point_value <= other._fixed_point_value);
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (_fixed_point_value != other._fixed_point_value);
}

bool	Fixed::operator==(const Fixed& other)
{
	return (_fixed_point_value == other._fixed_point_value);
}

Fixed	Fixed::operator+(const Fixed& other)
{
	return(Fixed(_fixed_point_value + other._fixed_point_value));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return(Fixed(_fixed_point_value - other._fixed_point_value));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return(Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return(Fixed(toFloat() / other.toFloat()));
}

Fixed	Fixed::operator++(void)
{
	_fixed_point_value++;
	return(*this);
}

Fixed	Fixed::operator--(void)
{
	_fixed_point_value--;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	_fixed_point_value++;
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixed_point_value--;
	return(tmp);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

