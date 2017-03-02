#include "L3-AD-F5-parser-testUnit.h"

int main()
{
	if(testUnitParser())
	{
		std::cout << "Tous les tests passes avec succes" << std::endl;
	}
	else
	{
		std::cout << "Tests rates, revoyez votre code" << std::endl;
	}
}
