/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measureTime.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:39:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/16 14:59:50 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEASURETIME_TPP
#define MEASURETIME_TPP

#include <iostream>
#include <ctime>

template<typename ClassType, typename ReturnType>
void measureTime(const ClassType& obj, ReturnType(ClassType::*funptr)(void) const) {
	std::clock_t	start, end;
	double			elapsed;
	ReturnType		result;

	start = std::clock();
	result = (obj.*funptr)();
	end = std::clock();
	std::cout << "Function result: " << result << std::endl;

	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Elapsed time: " << std::fixed << elapsed << " seconds" << std::endl;
}

template<typename ClassType, typename ArgType>
void measureTime(ClassType& obj, void(ClassType::*funptr)(const ArgType&), const ArgType& arg) {
	std::clock_t	start, end;
	double			elapsed;

	start = std::clock();
	(obj.*funptr)(arg);
	end = std::clock();

	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Elapsed time: " << std::fixed << elapsed << " seconds" << std::endl;
}

// template<typename ClassOut, typename ArgType>
// void measureTime(ClassOut& obj, void(ClassOut::*funptr)(ArgType, ArgType), ArgType arg_one, ArgType arg_two) {
// 	std::clock_t	start, end;
// 	double			elapsed;

// 	start = std::clock();
// 	(obj.*funptr)(arg_one, arg_two);
// 	end = std::clock();

// 	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
// 	std::cout << "Elapsed time: " << std::fixed << elapsed << " seconds" << std::endl;
// }

#endif
