/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:42:17 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/15 15:32:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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

		void				GradeTooHighException(std::string message);
		void				GradeTooLowException(std::string message);

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

#endif
