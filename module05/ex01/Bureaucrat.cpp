/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:06 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/15 15:33:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* CONSTRUCTORS - DESTRUCTORS */

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(GRADE_MIN) {
}

Bureaucrat::Bureaucrat(const std::string& in_name, const short in_grade) : name(in_name) {
	if (in_grade < GRADE_MAX) {
		GradeTooHighException();
		grade = GRADE_MAX;
	}
	else if (in_grade > GRADE_MIN) {
		GradeTooLowException();
		grade = GRADE_MIN;
	}
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


/* GETTERS */

std::string Bureaucrat::getName(void) const {
	return (name);
}

unsigned short Bureaucrat::getGrade(void) const {
	return (grade);
}


/* EXCEPTIONS */

void Bureaucrat::GradeTooHighException(void) {
	throw std::out_of_range(getName() + ": the grade is too high!!!");
}

void Bureaucrat::GradeTooLowException(void) {
	throw std::out_of_range(getName() + ": the grade is too low!!!");
}

/* OPERATORS */

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &in) {
	out	<< in.getName() << ", bureaucrat grade " << in.getGrade();

	return (out);
}

/* MEMBER FUNCTIONS */

void	Bureaucrat::promote(void) {
	if (grade == GRADE_MAX)
		GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::promote(short value) {
	if ((grade - value) < GRADE_MAX)
		GradeTooHighException();
	else
		grade -= value;
}

void	Bureaucrat::demote(void) {
	if (grade == GRADE_MIN)
		GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::demote(short value) {
	if ((grade + value) > GRADE_MIN)
		GradeTooLowException();
	else
		grade += value;
}

void Bureaucrat::signForm(Form& in_form) {
	try
	{
		in_form.beSigned(*this);
		std::cout << this->name << " signed " << in_form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
