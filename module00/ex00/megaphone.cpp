/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:32:21 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/12 15:32:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc && argv && argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " " ;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}