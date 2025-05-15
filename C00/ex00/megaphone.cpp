/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:07:13 by omalovic          #+#    #+#             */
/*   Updated: 2025/05/15 14:07:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int n, char **args)
{
	if (n == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; args[i]; i++)
		{
			for (int j = 0; args[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(args[i][j]));
		}
		std::cout << std::endl;
	}
	return 0;
}
