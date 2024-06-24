/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:40:12 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/24 17:04:47 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		void	makeSound(void) const;
};

#endif
