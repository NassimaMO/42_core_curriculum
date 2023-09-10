/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:23:37 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:23:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main( int argc, char **argv )
{
    if ( argc != 4 )
        return ( std::cout << "Argument error." << std::endl, 1 );
    //args: filename, s1, s2
    //replace every occurence of s1 by s2 in filename to filename.replace
    //std::string     filename( argv[1] );
    std::ifstream   file( argv[1] );
    std::ofstream   anotherFile( "file.replace" );
    //std::ofstream   anotherFile( filename + ".replace" );

    if ( !file || !anotherFile )
        return ( std::cout << "Uhoh! A problem occured" << std::endl, 2 );
    std::string     content;

    if ( file.is_open() )
    {
        std::string     content;
        int             index;
        std::string     s1 = argv[2];
        if ( anotherFile.is_open() )
        {
            while ( getline( file, content ) )
            {
                if ( content.find( s1 ) < content.length() )
                {
                    index = content.find( s1 );
                    content.erase(content.begin() + index, content.begin() + index + s1.size() );
                    content.insert(index, argv[3]);
                }
                anotherFile << content << std::endl;
            }
        }
        else
            return ( std::cout << "Uhoh! A problem occured" << std::endl, 3 );
    }
    else
        return ( std::cout << "Uhoh! A problem occured" << std::endl, 4 );
    //str.find(s1);
    //str.insert(num, s2);
}