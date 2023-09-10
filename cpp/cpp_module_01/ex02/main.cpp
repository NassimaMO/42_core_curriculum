/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:53 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:53 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
    std::string brain( "HI THIS IS BRAIN" );
    std::string *stringPTR(&brain);
    std::string &stringREF(brain);

    std::cout << "string address: " << &brain << std::endl;
    std::cout << "string address of stringPTR: " << &stringPTR << std::endl;
    std::cout << "string address of stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "value: " << brain << std::endl;
    std::cout << "value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "value of stringREF: " << stringREF << std::endl;

}