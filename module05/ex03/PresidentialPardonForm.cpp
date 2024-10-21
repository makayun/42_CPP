/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 16:19:26 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
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
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblerbox" << std::endl;
}
