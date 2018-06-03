#include "FormattedOutput.hpp"



/*	Text	*/
std::string setFormat (const int key)
{
	return ( "\033[" + std::to_string(key) + "m" );
}

std::ostream& setFormat (const int key, std::ostream& os)
{
	os << "\033[" << key << 'm';
	return os;
}



/*	Cursor	*/

std::ostream& Cursor::moveTo (const int i, const int j, std::ostream& os)
{
	os << "\033[" << i << ';' << j << 'H';
	return os;
}

std::string Cursor::moveTo (const int i, const int j)
{
	return ( "\033[" + std::to_string(i) 
			+ ";"  + std::to_string(j) + "H");
}

std::ostream& Cursor::moveColumns (const int n, std::ostream& os)
{
    if (n < 0)
        os << "\033[" << -n << 'D';
    else
        os << "\033[" << n << 'C';

    return os;        
}
std::string Cursor::moveColumns (const int n)
{
    if (n < 0)
        return ( "\033[" + std::to_string(-n) + "D" );
    else
        return ( "\033[" + std::to_string(n) + "C" );
}

std::ostream& Cursor::moveRows (const int n, std::ostream& os)
{
    if (n < 0)
        os << "\033[" << -n << 'B';
    else
        os << "\033[" << n << 'A';

    return os;        
}

std::string Cursor::moveRows (const int n)
{
    if (n < 0)
        return ( "\033[" + std::to_string(-n) + "B" );
    else
        return ( "\033[" + std::to_string(n) + "A" );
}




/*	Screen	*/

bool Screen::configIsSet = false;



std::ostream& Screen::saveConfig (std::ostream& os)
{
	if (configIsSet)
		throw std::bad_function_call{};

	os << "\033[?47h";

	configIsSet = true;
	return os;
}

std::string Screen::saveConfig (void)
{
	if (configIsSet)
		throw std::bad_function_call{};

	configIsSet = true;
	return ("\033[?47h");
}


	
std::ostream& Screen::restoreConfig (std::ostream& os)
{
	configIsSet = false;
	os << "\033[0m\033[?47l";
	return (os);
}

std::string Screen::restoreConfig (void)
{
	configIsSet = false;
	return ("\033[0m\033[?47l");
}



std::ostream& Screen::clear (int key, std::ostream& os)
{
	os << "\033[" << key << 'J';
	return os;
}

std::string Screen::clear (int key)
{
	return ("\033[" + std::to_string (key) + "J" );
}



std::ostream& Screen::eraseLine (int key, std::ostream& os)
{
	os << "\033[" << key << 'K';
	return os;
}

std::string Screen::eraseLine (int key)
{
	return ("\033[" + std::to_string (key) + "K" );
}
