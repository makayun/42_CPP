/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:02 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 14:36:31 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	replace_string( const std::string &input,
							const std::string &to_find,
							const std::string &to_replace)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	if (input.empty() || to_find.empty())
		return (input);

	while (1)
	{
		found = input.find(to_find, pos);
		if (found == std::string::npos) // found == (unsigned long) -1
			break ;
		result.append(input, pos, found - pos);
		result.append(to_replace);
		pos = found + to_find.length();
	}

	result.append(input, pos, input.length() - pos);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Try: " << argv[0] << " <filename>, <string to find>, <string to replace>" << std::endl;
		return (1);
	}

	const std::string	&filename = argv[1];
	const std::string	&s1 = argv[2];
	const std::string	&s2 = argv[3];
	const std::string	&out_filename = filename + ".replace";
	std::string			line;
	std::string			replaced_line;

	std::ifstream input_file(filename.c_str());
	if (!input_file)
	{
		std::cerr << "Error: Can't open the file: " << filename << std::endl;
		return (1);
	}
	std::ofstream output_file(out_filename.c_str());
	if (!output_file)
	{
		std::cerr << "Error: Can't open the file: " << out_filename << std::endl;
		return (1);
	}

	while (std::getline(input_file, line))
	{
		replaced_line = replace_string(line, s1, s2);
		output_file << replaced_line << std::endl;
	}
	input_file.close();
	output_file.close();

}
