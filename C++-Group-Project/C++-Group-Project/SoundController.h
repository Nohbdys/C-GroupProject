#pragma once

class SoundController
{
private:

public:
	SoundController();
	void virtual PlaySound();
	void virtual ShutDownSound();
	void virtual Initial(char * soundNum);
};