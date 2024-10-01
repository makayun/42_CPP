/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:12:21 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/01 15:28:32 by mmakagon         ###   ########.fr       */
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
};

#endif
