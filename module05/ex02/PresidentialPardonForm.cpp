/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:59:31 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 14:22:20 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("no target") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& in_target)
	: AForm("PresidentialPardonForm", 25, 5), target(in_target) {
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (getIsSigned())
	{
		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException(executor.getName() + "'s grade is too low");

		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw AForm::FormIsNotSignedException();
}
