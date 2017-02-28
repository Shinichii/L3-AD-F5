#include "L3-AD-F5-parser.h"

#define IS_SUCCESSFUL ==1
#define HAS_FAILED ==0

bool testUnit()
{
	if(test_Normal_Opening() IS_SUCCESSFUL)
	{
		DEBUG_MSG("[DEBUG] Le test n°1 a ete passe avec succes.");
		if(test_File_Not_Found() HAS_FAILED)
		{
			DEBUG_MSG("[DEBUG] Le test n°2 a ete passe avec succes.");
			return true;
		}
		else
		{
			DEBUG_MSG("[DEBUG] Le test n°2 a echoue.");
			return false;
		}
	}
	else
	{
		DEBUG_MSG("[ERROR]Le test n°1 a echoue.");
		return false;
	}

}
bool test_Normal_Opening()
{
	/*@TODO : Finir la fonction*/
	return true;
}
bool test_File_Not_Found()
{
	/*@TODO : Finir la fonction*/
	return false;
}
