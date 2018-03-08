#include "Framework.h"
#include "CWaves.h"
#include <string>
#include "SoundController.h"
#include <vector>

using namespace std;


#define NUMBUFFERS              (4)
#define	SERVICE_UPDATE_PERIOD	(20)


ALuint      uiBuffer;
ALuint      uiSource;
ALint       iState;

SoundController::SoundController()
{

}

void SoundController::Initial(char * soundNum)
{
	char SoundPlayed[12];
	for (size_t i = 0; i < 12; i++)
	{
		SoundPlayed[i] = soundNum[i];
	}

	// Initialize Framework
	ALFWInit();

	ALFWprintf("PlayStatic Test Application\n");

	if (!ALFWInitOpenAL())
	{
		ALFWprintf("Failed to initialize OpenAL\n");
		ALFWShutdown();
	}

	// Generate an AL Buffer
	alGenBuffers(1, &uiBuffer);

	// Load Wave file into OpenAL Buffer
	if (!ALFWLoadWaveToBuffer((char*)ALFWaddMediaPath(SoundPlayed), uiBuffer))
	{
		ALFWprintf("Failed to load %s\n", ALFWaddMediaPath(SoundPlayed));
	}

	// Generate a Source to playback the Buffer
	alGenSources(1, &uiSource);

	// Attach Source to Buffer
	alSourcei(uiSource, AL_BUFFER, uiBuffer);

	// Play Source
	alSourcePlay(uiSource);
	ALFWprintf("Playing Source ");
}

void SoundController::PlaySound()
{

		// Get Source State
		alGetSourcei(uiSource, AL_SOURCE_STATE, &iState);

}

void SoundController::ShutDownSound()
{
	// Clean up by deleting Source(s) and Buffer(s)

	alSourceStop(uiSource);
	alDeleteSources(1, &uiSource);
	alDeleteBuffers(1, &uiBuffer);

	ALFWShutdownOpenAL();

	ALFWShutdown();
}


