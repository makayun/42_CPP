/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:58 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 00:30:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AForm.hpp"

#define GRN "\033[1;92m"
#define RED "\033[0;31m"
#define RES "\033[0m"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		explicit				ShrubberyCreationForm(const std::string& in_target);
		explicit				ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		std::string				getTarget(void) const;

		void					execute(const Bureaucrat& executor) const;
		void					drawTrees(std::ostream& out, short width, short trees) const;
};

#endif
