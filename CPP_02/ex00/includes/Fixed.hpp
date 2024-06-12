/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:04:34 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/12 21:58:49 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
			int			_fixed_point_value;
			static const int	_fracBits = 8;
	public:
			Fixed();
			~Fixed();
			Fixed(const Fixed &temp);
			Fixed& operator=(const Fixed &temp);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif
