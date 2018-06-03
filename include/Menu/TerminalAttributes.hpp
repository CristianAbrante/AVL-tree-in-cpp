/**
    @author Carlos Dominguez Garcia
    @date   30/04/2017
    @brief  This class wraps the functionality given by the header termios.h in Unix systems
            to modify attributes of a terminal.
*/

#ifndef TERMINAL_ATTRIBUTES_HPP
#define TERMINAL_ATTRIBUTES_HPP

#include <system_error>

#include <unistd.h>	// STDIN_FILENO	(fichero de entrada estandar)
#include <termios.h>// Todo lo relacionado con termios


namespace Termios
{
    class TerminalAttributes_t
    {
     private:
    
    /* "termios" es un struct que contiene los atributos de una terminal.	
	 *	Para mas info sobre las siguientes lineas mirar "man termios"	*/

	        /** @note Two attributes are necesary, one is to remember the original configuration,
	                   the other one to perform the new changes */
         termios oldAttributes_,
                 newAttributes_;
         
     public:
        /** @brief  Gets attributes of the terminal at standar input    */
         TerminalAttributes_t (void);
         
        /** @brief  Sets terminal's original attributes */
         ~TerminalAttributes_t (void);
         
        /** @brief  With this, the user input isn't showed in the terminal  */
         void dontEchoInput (void);
         
        /** @brief  This take out canonical mode. Among other things, it allows input to be taken
                    directly, with no need to press Enter   */
         void setNonCanonicalMode (void);
         
        /** @brief  Sets terminal's original attributes */
         void resetAttributes (void);
         
    };

    extern  TerminalAttributes_t  terminal;

}//namespace Termios    

#endif