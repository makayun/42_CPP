/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:18:19 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/01 15:35:11 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
}

Brain::Brain(const Brain &copy) {
	*this = copy;
}

Brain& Brain::operator=(const Brain &copy) {
	if (this != &copy)
		for (int i = 0; i < IDEAS_MAX; ++i)
			this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain() {
}
