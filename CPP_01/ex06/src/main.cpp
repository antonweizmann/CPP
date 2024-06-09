/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:55:14 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/09 14:21:46 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl_test;

	if (argc != 2)
		return (std::cout << "invalid number of arguments." << std::endl, 1);
	harl_test.complain(argv[1]);
	return (0);
}
