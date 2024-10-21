/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:58 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 01:09:30 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AForm.hpp"

#define TREES_WIDTH 9
#define TREES_COUNT 4

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		void		drawTrees(std::ostream& out, short width, short trees) const;

	public:
		ShrubberyCreationForm();
		explicit				ShrubberyCreationForm(const std::string& in_target);
		explicit				ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		std::string	getTarget(void) const;

		void		execute(const Bureaucrat& executor) const;
};

#endif
