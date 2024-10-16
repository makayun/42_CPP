/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:06:58 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/16 13:55:18 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#ifndef GRADE_MAX
#define GRADE_MAX 1
#endif

#ifndef GRADE_MIN
#define GRADE_MIN 150
#endif
/* Looks strange, but it follows the logic
The lesser the number - the greater rights the bureaucrat has */

#ifndef COLOR_RED
#define COLOR_RED "\033[1;91m"
#endif

#ifndef COLOR_RES
#define COLOR_RES "\033[0m"
#endif

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		short				grade;

		class GradeTooHighException : public std::out_of_range {
			public:
				GradeTooHighException(const std::string& name);
		};

		class GradeTooLowException : public std::out_of_range {
			public:
				GradeTooLowException(const std::string& name);
		};

	public:
		Bureaucrat(void);
		explicit		Bureaucrat(const std::string& in_name, const short in_grade);
		explicit		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat&		operator=(const Bureaucrat &copy);
		~Bureaucrat();

		void			promote(void);
		void			promote(short value);
		void			demote(void);
		void			demote(short value);

		std::string		getName(void) const;
		short			getGrade(void) const;

		void			signForm(Form& in_form);
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &in);

#endif
