/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:37 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	std::vector<int> v;
	v.resize(10);

	for (size_t i = 0; i < 10; i++)
		v[i] = i * 2;


	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::vector<int> res;
	res.resize(v.size());
	std::adjacent_difference(v.begin(), v.end(), res.begin());
	for (size_t i = 0; i < res.size(); i++)
		std::cout << res[i] << " ";

}
