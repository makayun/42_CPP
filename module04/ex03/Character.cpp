/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:34:15 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/14 12:15:47 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &in_name) : name(in_name) {
	for (int i = 0; i < SLOTS_MAX; i++)
		slot[i] = NULL;
}

Character::Character(const Character &copy) {
	*this = copy;
}

Character& Character::operator=(const Character &copy) {
	if (this != &copy) {
		this->name = copy.getName();
		for (int i = 0; i < SLOTS_MAX; i++)
			this->slot[i] = copy.slot[i];
	}
	return (*this);
}

Character::~Character() {
	for (int)
}
