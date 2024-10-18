/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:21 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 14:20:50 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPARDONFORM_HPP
#define PresidentialPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		PresidentialPardonForm();

	public:
		explicit				PresidentialPardonForm(const std::string& in_target);
		explicit				PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		void					execute(const Bureaucrat& executor) const;
};

#endif
