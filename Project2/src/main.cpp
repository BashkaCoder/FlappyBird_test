#include <iostream>
#include <SDL.h>
#include <stdexcept>

#include "application.h"

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char* args[]) 
{
	try
	{
		Application app;
		app.exec();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	

	return 0;
}