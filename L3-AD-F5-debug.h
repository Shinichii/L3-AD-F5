/*
	@Auteur : Aurelien DENIS
	@Groupe : F5
*/
#define DEBUG_MODE_ENABLED

#ifdef DEBUG_MODE_ENABLED
#define DEBUG_MSG(X) do {std::cout << X << std::endl;}while(0)
#else
#define DEBUG_MSG(X)
#endif
