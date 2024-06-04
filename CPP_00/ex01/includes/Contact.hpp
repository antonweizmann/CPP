/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:16:48 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/04 10:30:52 by antonweizma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
			std::string _fname;
			std::string _lname;
			std::string _nick;
			std::string _phone;
			std::string _secret;
	public:
			Contact(void);
			~Contact(void);
			void	display_contact(std::string index);
			void	display_full(void);
			void	set_fname(std::string input);
			void	set_lname(std::string input);
			void	set_nick(std::string input);
			void	set_phone(std::string input);
			void	set_secret(std::string input);
};

#endif
