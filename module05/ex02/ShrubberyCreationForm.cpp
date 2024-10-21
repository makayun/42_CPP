/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:54 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:33:13 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& in_target)
	: Form("Shrubbery creation", 145, 137), target(in_target) {
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy) {
		Form::operator=(copy);
		this->target = copy.getTarget();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::drawTrees(std::ostream& out, short width, short trees) const {
	int q = width / 2 + 1;

	for (int i = 0; i < q; i++) {
		for (int j = 0; j < trees; j++) {
			out << std::setw(q - i) << std::setfill(' ') << "*";
			out << std::setw(i * 2 + 1) << std::setfill('*') << " ";
			out << std::setw(q - i) << std::setfill(' ') << " ";
		}
		out << std::endl;
	}
	for (int k = 0; k < trees; k++) {
		out << std::setw(q) << std::setfill(' ') << "|";
		out << std::setw(q + 1) << std::setfill(' ') << " ";
	}
	out << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	Form::execute(executor);
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str(), std::ofstream::out);
	if (file.is_open()) {
		drawTrees(file, TREES_WIDTH, TREES_COUNT);
		file.close();
	}
	else
		std::cerr << "Can't open the file!" << std::endl;
}

