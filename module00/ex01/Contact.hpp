/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:33:26 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/13 11:02:30 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define ERROR   -1
#define ALL_FINE 1

enum e_fields
{
	FIRST_NAME,
	SECOND_NAME,
	NICKNAME,
	PHONE_NUM,
	SECRET
};


class Contact
{
	private:
		std::array<std::string, 5> field;
	
	public:
		Contact();
		~Contact();

		int	set_field(int type, std::string field);

		std::string get_field(int type);

		size_t get_max_fields(void);
};

#endif
