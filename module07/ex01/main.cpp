/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:46:32 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/01 17:27:20 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "iter.hpp"

#define NEW_SECTION std::cout << "\n\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;

template <typename T>
void printElement(const T& elem) {
	std::cout << elem << " ";
}

template <typename T>
void incrementElement(T& elem) {
	++elem;
}

int main() {
	NEW_SECTION

	int intArray[] = {1, 2, 3, 4, 5};
	int intArraySize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original intArray: ";
	iter(intArray, intArraySize, printElement<int>);

	std::cout << "\nIncremented intArray: ";
	iter(intArray, intArraySize, incrementElement<int>);
	iter(intArray, intArraySize, printElement<int>);

	NEW_SECTION

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original doubleArray: ";
	iter(doubleArray, doubleArraySize, printElement<double>);

	std::cout << "\nIncremented doubleArray: ";
	iter(doubleArray, doubleArraySize, incrementElement<double>);
	iter(doubleArray, doubleArraySize, printElement<double>);

	NEW_SECTION

	std::string stringArray[] = {"hello", "world", "template", "functions"};
	int stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "stringArray: ";
	iter(stringArray, stringArraySize, printElement<std::string>);

	NEW_SECTION

	return 0;
}
