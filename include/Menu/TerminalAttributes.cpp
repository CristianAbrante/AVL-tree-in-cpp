#include "TerminalAttributes.hpp"

namespace Termios
{
    
    TerminalAttributes_t  terminal; //Variable global, imitando a cout o cin

    
    TerminalAttributes_t::TerminalAttributes_t(void)
    {
            /*	Obtenemos los atributos que definen a la terminal de la entrada estandar.
                Devuelve -1 en error    */
             if ( tcgetattr (STDIN_FILENO, &oldAttributes_) != 0 )
                throw std::system_error (errno, std::system_category(), "Error getting terminal attributes");

             newAttributes_ = oldAttributes_;
    }
    
    
         TerminalAttributes_t::~TerminalAttributes_t (void)
         {
             tcsetattr (STDIN_FILENO, TCSANOW, &oldAttributes_);
         }
    
         
         void TerminalAttributes_t::dontEchoInput (void)
         {
             newAttributes_.c_lflag &= ~(ECHO);
    
             if ( tcsetattr (STDIN_FILENO, TCSANOW, &newAttributes_) != 0 )
                throw std::system_error (errno, std::system_category(), "Error setting terminal attributes");
         }
    
         
         void TerminalAttributes_t::setNonCanonicalMode (void)
         {
             newAttributes_.c_lflag &= ~(ICANON);
    
             if ( tcsetattr (STDIN_FILENO, TCSANOW, &newAttributes_) != 0 )
                throw std::system_error (errno, std::system_category(), "Error setting terminal attributes");         
         }
    
         
         void TerminalAttributes_t::resetAttributes (void)
         {
             if ( tcsetattr (STDIN_FILENO, TCSANOW, &oldAttributes_) != 0 )
                throw std::system_error (errno, std::system_category(), "Error setting terminal attributes");
         }    
    
}
