/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:18:37 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 00:35:37 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS - DESTRUCTORS */

Form::Form(void) :	name("Empty Form"),
						sign_grade(GRADE_MIN),
						exec_grade(GRADE_MIN),
						is_signed(false)
{
}

Form::Form(const std::string& in_name, const short in_sign_grade, const short in_exec_grade) :
			name(in_name),
			sign_grade(in_sign_grade),
			exec_grade(in_exec_grade),
			is_signed(false)
{
	if (sign_grade < GRADE_MAX || exec_grade < GRADE_MAX)
		throw GradeTooHighException("Bad form initialisation, the grade is too high");
	else if (sign_grade > GRADE_MIN || exec_grade > GRADE_MIN)
		throw GradeTooLowException("Bad form initialisation, the grade is too low");
}

Form::Form(const Form& copy) :	name(copy.getName()),
									sign_grade(copy.getSignGrade()),
									exec_grade(copy.getExecGrade()),
									is_signed(copy.getIsSigned())
{
	*this = copy;
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy)
		this->is_signed = copy.getIsSigned();
	return (*this);
}

Form::~Form() {
}


/* EXCEPTIONS */

Form::GradeTooHighException::GradeTooHighException(const std::string& message)
	: std::out_of_range(COLOR_RED + message + COLOR_RES) {
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message)
	: std::out_of_range(COLOR_RED + message + COLOR_RES) {
}

Form::FormIsSignedException::FormIsSignedException(void)
	: std::invalid_argument(COLOR_RED + std::string("The form is alredy signed!") + COLOR_RES) {
}

Form::FormIsNotSignedException::FormIsNotSignedException(void)
	: std::invalid_argument(COLOR_RED + std::string("The form is not signed yet!") + COLOR_RES) {
}


/* GETTERS */

std::string Form::getName(void) const {
	return (this->name);
}

short Form::getSignGrade(void) const {
	return (this->sign_grade);
}

short Form::getExecGrade(void) const {
	return (this->exec_grade);
}

bool Form::getIsSigned(void) const {
	return (this->is_signed);
}


/* MEMBER FUNCTIONS */

void Form::beSigned(const Bureaucrat& in_brcrt) {
	if (this->is_signed == true)
		throw FormIsSignedException();
	else if (in_brcrt.getGrade() > this->sign_grade)
		throw GradeTooLowException(in_brcrt.getName() + "'s grade is too low");
	else
		this->is_signed = true;
}

void Form::execute(const Bureaucrat& executor) const {
	if (getIsSigned())
	{
		if (executor.getGrade() > this->getExecGrade())
			throw Form::GradeTooLowException(executor.getName() + "'s grade is too low");
	}
	else
		throw Form::FormIsNotSignedException();
}


/* OUTPUT */

std::ostream&	operator<<(std::ostream &out, Form const& in) {
	out	<< in.getName()
		<< ", sign grade: "	<< in.getSignGrade()
		<< ", exec grade: "	<< in.getExecGrade()
		<< ", is signed: "	<< in.getIsSigned();
	return (out);
}
