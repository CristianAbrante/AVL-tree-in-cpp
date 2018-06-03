#include "Menu.hpp"

/*	Nota, no es lo mejor pero de momento para pocas opciones no esta mal	*/

int showMenu (OptionsList_t options, std::string information)
{
	if (options.size() < 1)
		throw std::invalid_argument ("Menu: Not enough arguments");
	
	/*	Pasamos a una "nueva pantalla"	*/
	//	Screen::saveConfig (std::cout);	En cloud9 funciona raro. Por eso usaremos...
	Screen::clear (Clear::everything, std::cout);


	int  userChoice = 0;	//	Almacena la posicion del vector que el usuario elige
	bool printMenu = true, 
		 keepLooping = true;


	/*	Para que se pueda recoger el input del usuario sin necesidad de darle a Enter.
		Y para que no se impriman los caracteres que escribe.	*/
	Termios::terminal.dontEchoInput();
	Termios::terminal.setNonCanonicalMode();


	while (keepLooping)
	{

		/*	Solo hara falta que imprimamos el menu si el usuario pulso
		 *	alguna tecla que modifique como se ve la pantalla	*/
		if (printMenu)
		{
			/*	Posiciona cursor al principio y escribe el menu	*/

			std::cout << Cursor::moveTo (0,0)
					  << "\n\n\t" << information << "\n\n"
					  << "\tUse arrows keys to go up or down.\n\tPress Enter to choose an option.\n\n";
			int i = 0;
			while (i < userChoice)
				std::cout << "\t[ ] " << options[i++] << '\n';

			std::cout << "\t[X] " << setFormat(Text::underscore)
					  << options[i++] << setFormat(Text::resetAttributes) << '\n';

			while (i < options.size())
				std::cout << "\t[ ] " << options[i++] << '\n';

			printMenu = false;
		}
		
		/*	Esperamos a que el usuario interactue y procesamos su reaccion	*/
		int aux = std::cin.get();

		switch (aux)
		{

			/*	Solo decrementamos userChoice si presiono flecha abajo y hay 
				mas opciones antes de la actual (userChoice > 0)	*/
			case 'A':
			case 'a':
						if (userChoice > 0)
						{
							--userChoice;
							printMenu = true;
						}
						break;

			/*	De la misma manera para la flecha abajo. Aqui el -1 es debido 
				a que cuando userChoice ya está en la ultima posicion del 
				vector no queremos incrementarlo	*/
			case 'B':
			case 'b':
						if (userChoice < options.size() - 1)
						{
							++userChoice;
							printMenu = true;
						}
						break;

			/*	Si presiona Enter la opcion elegida es userChoice	*/
			case '\n': 
						keepLooping = false;
						break;
		}

	}

	/*	Antes de salir dejamos la salida estandar como estaba	*/
	Termios::terminal.resetAttributes();

	/*	Volvemos a la "pantalla anterior"	*/
//	Screen::restoreConfig (std::cout);	
//	En cloud9 funciona raro, por eso simplemente...
	std::cout << Screen::clear (Clear::everything) << Cursor::moveTo (0,0);
	
	return (userChoice);
}
