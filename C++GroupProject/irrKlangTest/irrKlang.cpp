#include "irrKlang.h"

#include <irrKlang.h>
#include <iostream>
using namespace std;
using namespace irrklang;




irrKlang::irrKlang()
{
}


irrKlang::~irrKlang()
{
}

int main()
{
	ISoundEngine * engine = createIrrKlangDevice(); //Creates engine
	
	//Skriv folder destination fra .exe fil, for at henvise til folder ved .exe filen. Derved skabe bedre overblik.
	engine->play2D("sounds/Nope.mp3"); //Play sound. Sound is placed in folder with .exe file
	
	int tmp;

	cout << "Press 1 + enter to exit";
	cin >> tmp;

	engine->drop(); //deletes engine

	return 0;
}