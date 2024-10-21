/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:06 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:17:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& in_name, const short in_grade) : name(in_name) {
	if (in_grade < GRADE_MAX)
		throw GradeTooHighException(name);
	else if (in_grade > GRADE_MIN)
		throw GradeTooLowException(name);
	else
		grade = in_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy)
		this->grade = copy.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName(void) const {
	return (name);
}

short Bureaucrat::getGrade(void) const {
	return (grade);
}

std::ostream&	operator<<(std::ostream &out, Bureaucrat const& in) {
	out	<< in.getName() << ", bureaucrat grade " << in.getGrade();

	return (out);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name)
	: std::out_of_range(COLOR_RED + name + ": the grade is too high!" + COLOR_RES) {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name)
	: std::out_of_range(COLOR_RED + name + ": the grade is too low!" + COLOR_RES) {
}

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(GRADE_MIN) {
}

void	Bureaucrat::promote(void) {
	if (grade == GRADE_MAX)
		throw GradeTooHighException(name);
	else {
		grade--;
		std::cout << name << " had been promoted to grade " << grade << std::endl;
	}
}

void	Bureaucrat::promote(short value) {
	if ((grade - value) < GRADE_MAX)
		throw GradeTooHighException(name);
	else {
		grade -= value;
		std::cout << name << " had been promoted to grade " << grade << std::endl;
	}
}

void	Bureaucrat::demote(void) {
	if (grade == GRADE_MIN)
		throw GradeTooLowException(name);
	else {
		grade++;
		std::cout << name << " had been demoted to grade " << grade << std::endl;
	}
}

void	Bureaucrat::demote(short value) {
	if ((grade + value) > GRADE_MIN)
		throw GradeTooLowException(name);
	else {
		grade += value;
		std::cout << name << " had been demoted to grade " << grade << std::endl;
	}
}

void	Bureaucrat::signForm(Form& in_form) {
	try
	{
		in_form.beSigned(*this);
		std::cout << name << " signed " << in_form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< COLOR_RED
					<< name << " couldn't sign " << in_form.getName()
					<< " because: " << e.what()
					<< COLOR_RES << std::endl;
	}
}
