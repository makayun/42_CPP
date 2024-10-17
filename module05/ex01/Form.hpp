/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:42:17 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/17 08:30:09 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#ifndef COLOR_RED
#define COLOR_RED "\033[1;91m"
#endif

#ifndef COLOR_RES
#define COLOR_RES "\033[0m"
#endif

#ifndef GRADE_MAX
#define GRADE_MAX 1
#endif

#ifndef GRADE_MIN
#define GRADE_MIN 150
#endif

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const short			sign_grade;
		const short			exec_grade;
		bool				is_signed;

		class GradeTooHighException : public std::out_of_range {
			public:
				GradeTooHighException(const std::string& message);
		};

		class GradeTooLowException : public std::out_of_range {
			public:
				GradeTooLowException(const std::string& message);
		};

		class FormIsSignedException : public std::invalid_argument {
			public:
				FormIsSignedException(void);
		};



	public:
		Form(void);
		Form(const std::string in_name, const short in_sign_grade, const short in_exec_grade);
		explicit	Form(const Form& copy);
		Form&		operator=(const Form& copy);
		~Form();

		std::string	getName(void) const;
		short		getSignGrade(void) const;
		short		getExecGrade(void) const;
		bool		getIsSigned(void) const;

		void		beSigned(const Bureaucrat& in_brcrt);
};

std::ostream&	operator<<(std::ostream &out, Form const& in);

#endif
