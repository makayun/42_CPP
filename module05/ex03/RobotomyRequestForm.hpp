/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:50 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 00:52:27 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREAUESTFORM_HPP
#define ROBOTOMYREAUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		RobotomyRequestForm();

	public:
		explicit				RobotomyRequestForm(const std::string& in_target);
		explicit				RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		std::string				getTarget(void) const;

		void					execute(const Bureaucrat& executor) const;
};

#endif
