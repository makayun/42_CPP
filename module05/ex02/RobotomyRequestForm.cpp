/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 00:56:30 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& in_target)
	: AForm("RobotomyRequestForm", 72, 45), target(in_target) {
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		this->target = copy.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	std::cout << "** some drilling noises **" << std::endl;
	if (std::time(0) % 2 == 0) {
		AForm::execute(executor);
		std::cout << target << " was successfully robotomized" << std::endl;
	}
	else
		throw std::runtime_error("ROBOTOMY FAILED, THAT HAPPENS TIME TO TIME");
}
