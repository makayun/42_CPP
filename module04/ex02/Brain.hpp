/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:12:21 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/01 23:39:33 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define IDEAS_MAX 100

class Brain
{
	private:
		std::string ideas[IDEAS_MAX];

	public:
		Brain();
		explicit    Brain(const Brain &copy);
		Brain&    operator=(const Brain &copy);
		~Brain();

		const std::string	getIdea(size_t id) const;
		void				setIdea(const std::string &in_idea, size_t id);
};

#endif
