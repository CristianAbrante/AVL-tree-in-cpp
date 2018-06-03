/**
 *	@author	Carlos Dominguez Garcia, 
 *			Daute Rodriguez Rogriguez,
 *			Angel Luis Igareta Herraiz,
 *			Cristian Abrante Dorta,
 *			Alberto
 *	@date	25/04/2017
 *	@brief	Menu function
 */

/*
	//Example of use. Compile with g++ -std=c++11 (main name).cpp FormattedOutput.cpp Menu.cpp

	#include "Menu.hpp"

	int main (void)
	{
		OptionsList_t options = {"Hi", "Bye"};
		int userOption = showMenu (options, "Hi there");

		std::cout << "\n\tYou said " << options [userOption] << "\n\n";

		return 0;
	}
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>//	std::invalid_argument

#include "TerminalAttributes.hpp"	//	Termios::terminal
#include "FormattedOutput.hpp"	//	Interfaz mas o menos amigable para las secuencias de escape ANSI, para que quede bonito


using OptionsList_t = std::vector<std::string>;


/**
 *	@brief				Functions that displays a menu to the user and process his/her input.
 *	@param options		Vector of strings, each position represents an option that is going to be shown to the user.
 *	@param information	String to be shown to the user to describe the menu.
 *	@return				Position of the options vector that the user chose.
 */
int showMenu (OptionsList_t options, std::string information = "");

#endif
