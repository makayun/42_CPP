/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:12:45 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 13:17:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS - DESTRUCTORS */

AForm::AForm(void) :	name("Empty Aform"),
					sign_grade(GRADE_MIN),
					exec_grade(GRADE_MIN),
					is_signed(false)
{
}

AForm::AForm(const std::string in_name, const short in_sign_grade, const short in_exec_grade) :
			name(in_name),
			sign_grade(in_sign_grade),
			exec_grade(in_exec_grade),
			is_signed(false)
{
	if (sign_grade < GRADE_MAX || exec_grade < GRADE_MAX)
		throw GradeTooHighException("Bad Aform initialisation, the grade is too high");
	else if (sign_grade > GRADE_MIN || exec_grade > GRADE_MIN)
		throw GradeTooLowException("Bad Aform initialisation, the grade is too low");
}

AForm::AForm(const AForm& copy) :	name(copy.getName()),
								sign_grade(copy.getSignGrade()),
								exec_grade(copy.getExecGrade()),
								is_signed(copy.getIsSigned())
{
	*this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy)
		this->is_signed = copy.getIsSigned();
	return (*this);
}

AForm::~AForm() {
}


/* EXCEPTIONS */

AForm::GradeTooHighException::GradeTooHighException(const std::string& message)
	: std::out_of_range(COLOR_RED + message + COLOR_RES) {
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
	: std::out_of_range(COLOR_RED + message + COLOR_RES) {
}

AForm::FormIsSignedException::FormIsSignedException(void)
	: std::invalid_argument(COLOR_RED + std::string("The form is alredy signed!") + COLOR_RES) {
}

AForm::FormIsNotSignedException::FormIsNotSignedException(void)
	: std::invalid_argument(COLOR_RED + std::string("The form is not signed yet!") + COLOR_RES) {
}


/* GETTERS */

std::string AForm::getName(void) const {
	return (this->name);
}

short AForm::getSignGrade(void) const {
	return (this->sign_grade);
}

short AForm::getExecGrade(void) const {
	return (this->exec_grade);
}

bool AForm::getIsSigned(void) const {
	return (this->is_signed);
}


/* MEMBER FUNCTIONS */

void AForm::beSigned(const Bureaucrat& in_brcrt) {
	if (this->is_signed == true)
		throw FormIsSignedException();
	else if (in_brcrt.getGrade() > this->sign_grade)
		throw GradeTooLowException(in_brcrt.getName() + "'s grade is too low");
	else
		this->is_signed = true;
}

std::ostream&	operator<<(std::ostream &out, AForm const& in) {
	out	<< in.getName()
		<< ", sign grade: " << in.getSignGrade()
		<< ", exec grade: " << in.getExecGrade();
	return (out);
}
