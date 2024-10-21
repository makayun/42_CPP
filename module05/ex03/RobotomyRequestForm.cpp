/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:34:41 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& in_target)
	: Form("Robotomy request", 72, 45), target(in_target) {
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy) {
		Form::operator=(copy);
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
	int*			random_var = new int(42);
	unsigned long	random_address = reinterpret_cast<unsigned long>(&random_var) >> 6;
	delete random_var;

	std::cout << "** some drilling noises **" << std::endl;
	if (random_address & 1) {
		Form::execute(executor);
		std::cout << target << " was successfully robotomized" << std::endl;
	}
	else
		throw std::runtime_error("ROBOTOMY FAILED, THAT HAPPENS TIME TO TIME");
}
