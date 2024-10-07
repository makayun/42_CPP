/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:53:48 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/07 11:56:10 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MaterialSource : public IMateriaSource
{
	private:

	protected:

	public:
		MaterialSource();
		explicit    MaterialSource(const MaterialSource &copy);
		MaterialSource&    operator=(const MaterialSource &copy);
		~MaterialSource();
};

#endif
