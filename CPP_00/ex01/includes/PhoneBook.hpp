/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:14:35 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/04 11:03:39 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	private:
			Contact	_contacts[8];
			int		_max_reached;
	public:
			PhoneBook(void);
			~PhoneBook(void);
			void	run_phonebook(void);
			int		fill_contact(int index);
};
#endif
