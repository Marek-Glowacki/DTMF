#pragma once
#include <SFML/Audio.hpp>
class KoderDTMF
{

public:
	const double sampleRate = 44100;
	double gDTMF(char c, int duration, int bTime, float sampleRate, float A, sf::Int16 output[]);
};

