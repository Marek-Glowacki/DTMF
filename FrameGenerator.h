#pragma once
#include <SFML/audio.hpp>
class FrameGenerator
{
public:
	double gFrame(char frame[], int duration, int bTime, float sampleRate, float A, sf::Int16 output[]);
};

