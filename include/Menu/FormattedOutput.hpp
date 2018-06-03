/**
 *	@author	Carlos Dominguez Garcia, 
 *			Daute Rodríguez Rogríguez,
 *			Angel Luis Igareta Herraiz,
 *			Cristian Abrante Dorta,
 *			Alberto
 *	@date	25/04/2017
 *	@brief	In this header there are several interfaces made to use ANSI escape sequences in a readable way.
 *			There are two versions of each function, one direcly outputs the escape sequence in the stream. 
 *			The other one returns the sequence in a string.
 *	@note	The sintax to use any of the functions is very similar and friendly to read.
 */



/*
	//  Example of use. Compile with g++ -std=c++11 (main name).cpp FormattedOutput.cpp

	#include "FormattedOutput.hpp"

	int main (void)
	{
		Screen::saveConfig (std::cout); 
	 	std::cout << setFormat(Text::blue) << "Hello world\n";

	 	setFormat (Text::resetAttributes, std::cout);
	 	std::cout << Cursor::moveTo(0,0) << "Hello";

		std::cin.get();

		std::cout << Screen::restoreConfig();

		return 0;
	}


*/


#ifndef FORMATTED_OUTPUT_HPP
#define FORMATTED_OUTPUT_HPP

#include <iostream>
#include <string>
#include <functional> //std::bad_function_call

/**
 *	@brief      Sets the text format.
 *	@param key  Attribute to set, it has to be one of the Text value.
 */
std::string     setFormat (const int key);
std::ostream&   setFormat (const int key, std::ostream& os);

namespace Text
{
	enum TextColor_t	{	black = 30, 
							red, 
							green, 
							yellow, 
							blue, 
							magenta, 
							cyan, 
							white };

	enum BackgroundColor_t	{	blackBackground = 40, 
								redBackground, 
								greenBackground, 
								yellowBackground, 
								blueBackground, 
								magentaBackground, 
								cyanBackground, 
								whiteBackground	};

	enum OtherTextAttr_t	{	resetAttributes = 0, 
								bold = 1, 
								underscore = 4	};

}



namespace Cursor
{
	/** @brief  Moves cursor to a certain position in the screen */
	std::ostream& moveTo (const int i, const int j, std::ostream& os);
	std::string moveTo (const int i, const int j);

        /** @brief      Moves cursor N cells to the right if N > 0, 
         *              to the left if N < 0. Because (0,0) is at top
         *              left corner of the screen
         */
        std::ostream& moveColumns (const int n, std::ostream& os);
        std::string moveColumns (const int n);

        /** @brief      Moves cursor N cells down if N < 0,
         *              or up if N > 0.Because (0,0) is at top
         *              left corner of the screen
         */        
        std::ostream& moveRows (const int n, std::ostream& os);
        std::string moveRows (const int n);
        
}


/** @brief  Values to be used in the methods clear and eraseLine of the Screen	*/
namespace Clear
{
	enum ClearScreen_t { fromCursorToBegin = 0, fromCursorToEnd, everything };
}

struct Screen
{
  private:
	static bool configIsSet;

  public:
	/** @brief  When we use a man page in the terminal, we go to a "new page". This is what this
                    method does. However, it can only go back to the "last page". Thats why the boolean
                    configIsSet is there. This method throws an exception if saveConfig is called more than once
                    without previusly calling restoreConfig.
	*/
	static std::ostream& saveConfig (std::ostream& os);
	static std::string saveConfig (void);

	/** @brief  Reset text format and returns back from the "new page" entered from saveConfig	*/
	static std::ostream& restoreConfig (std::ostream& os);
	static std::string restoreConfig (void);

	/** @brief  Clears the screen, the value passed is to determine what portion of the screen to erase. */
	static std::ostream& clear (int key, std::ostream& os);
	static std::string clear (int key);

	/** @brief  Clears the current line, the value passed is to determine what portion of the line to erase. */
	static std::ostream& eraseLine (int key, std::ostream& os);
	static std::string eraseLine (int key);
};

#endif
