/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:40 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:26:40 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	int		i;
	std::string	loud_line = "";

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (i = 1; i < argc; i++)
		loud_line = loud_line + argv[i];
	for (int i=0; (long unsigned int)i < loud_line.length(); i++)
        std::cout << (char)toupper(loud_line[i]) << std::flush;
	std::cout << std::endl;
	return (0);
}
