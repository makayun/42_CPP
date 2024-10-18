/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:33 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 16:19:35 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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

		std::string				getTarget(void) const;

		void					execute(const Bureaucrat& executor) const;
};

#endif
