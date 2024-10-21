/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:18:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 00:44:24 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Form_HPP
#define Form_HPP

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

	protected:

		class GradeTooHighException : public std::out_of_range {
			public:
				explicit GradeTooHighException(const std::string& message);
		};

		class GradeTooLowException : public std::out_of_range {
			public:
				explicit GradeTooLowException(const std::string& message);
		};

		class FormIsSignedException : public std::invalid_argument {
			public:
				FormIsSignedException(void);
		};

		class FormIsNotSignedException : public std::invalid_argument {
			public:
				FormIsNotSignedException(void);
		};

		Form(void);
		Form(const std::string& in_name, const short in_sign_grade, const short in_exec_grade);


	public:
		explicit	Form(const Form& copy);
		Form&		operator=(const Form& copy);
		~Form();

		std::string		getName(void) const;
		short			getSignGrade(void) const;
		short			getExecGrade(void) const;
		bool			getIsSigned(void) const;

		void			beSigned(const Bureaucrat& in_brcrt);
		virtual void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream &out, Form const& in);

#endif
