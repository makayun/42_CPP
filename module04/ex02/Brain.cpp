/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:18:19 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 13:43:02 by mmakegon         ###   ########.fr       */
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

const std::string	Brain::getIdea(size_t id) const {
	if (id >= IDEAS_MAX)
		return ("BAD IDEA =)");
	return (ideas[id]);
}

void	Brain::setIdea(const std::string &in_idea, size_t id) {
	std::cout << "Trying to set an idea:\n" << in_idea << "\nto the brain slot: " << id << std::endl;
	if (id >= IDEAS_MAX)
		std::cerr << "BAD IDEA =)" << std::endl;
	else
		ideas[id] = in_idea;
}
