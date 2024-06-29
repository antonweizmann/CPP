/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:04:34 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/29 15:03:36 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
	private:
			int			_fixed_point_value;
			static const int	_fracBits = 8;
	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed &temp);
			Fixed(const int input);
			Fixed(const float input);
			Fixed& operator=(const Fixed &temp);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
			bool	operator>(const Fixed& other);
			bool	operator<(const Fixed& other);
			bool	operator>=(const Fixed& other);
			bool	operator<=(const Fixed& other);
			bool	operator==(const Fixed& other);
			bool	operator!=(const Fixed& other);
			Fixed	operator+(const Fixed& other);
			Fixed	operator-(const Fixed& other);
			Fixed	operator*(const Fixed& other);
			Fixed	operator/(const Fixed& other);
			Fixed	operator++(void);
			Fixed	operator--(void);
			Fixed	operator++(int);
			Fixed	operator--(int);
			static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
			static Fixed&	min(Fixed& fixed1, Fixed& fixed2);
			static Fixed&	max(Fixed& fixed1, Fixed& fixed2);
			static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream&	operator<<(std::ostream& output, const Fixed &temp);

#endif
