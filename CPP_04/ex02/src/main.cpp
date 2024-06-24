/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:00:23 by aweizman          #+#    #+#             */
/*   Updated: 2024/06/24 17:32:30 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	Animal*	animals[10];

	for(int i = 0; i < 5; i++)
		animals[i] = new Cat();
	for(int i = 5; i < 10; i++)
		animals[i] = new Dog();
	for(int i = 9; i >= 0; i--)
		delete animals[i];
}
