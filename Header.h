#ifndef header
#define header

#include <ctime>
#include <cstdlib>

namespace Header
{
	int createrandom(int min, int max)				//Eine zufällige Zahl zwischen zwei Zahlen ausgeben
	{
		srand((unsigned int)time(NULL));
		int random = min + rand() % max;
		return random;
	}
	void delay(int i)								//eine bestimmte Zeit warten
	{
		unsigned long delayt = i * 5000000000L;
		for (unsigned long wait = 0; wait < delayt; ++wait)
			;
	}
}


#endif
