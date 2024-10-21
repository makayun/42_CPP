/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:34:32 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& in_target)
	: Form("Presidential pardon", 25, 5), target(in_target) {
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy) {
		Form::operator=(copy);
		this->target = copy.getTarget();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	Form::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblerbox" << std::endl;
}
