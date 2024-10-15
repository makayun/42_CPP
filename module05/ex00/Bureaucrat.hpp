/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:06:58 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/14 15:32:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GRADE_MAX 1
#define GRADE_MIN 150
/* Looks strange, but it follows the logic
The lesser the number - the greater rights the bureaucrat has */

class Bureaucrat
{
	private:
		const std::string	name;
		short				grade;

		void				GradeTooHighException(void);
		void				GradeTooLowException(void);

	public:
		explicit			Bureaucrat(const std::string& in_name, const short in_grade);
		explicit			Bureaucrat(const Bureaucrat &copy);
		Bureaucrat&			operator=(const Bureaucrat &copy);
		~Bureaucrat();

		void				promote(void);
		void				promote(short value);
		void				demote(void);
		void				demote(short value);

		std::string			getName(void) const;
		unsigned short		getGrade(void) const;
};

std::ostream&	operator<<(std::ostream &out, Bureaucrat const &in);
