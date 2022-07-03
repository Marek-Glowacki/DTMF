#include "FrameGenerator.h"
#include "KoderDTMF.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <SFML/Audio.hpp>

using namespace std;
#define M_PI 3.14159265358979323846

double FrameGenerator::gFrame(char frame[], int duration, int bTime, float sampleRate, float A, sf::Int16 output[]) {
	int j = 0;
	int p = 0; //po³o¿enie
	//dlugoœæ ramki = 6*(sampleRate*(duration+ bTime)/1000)
	//double* frame_len = new double[6*(sampleRate*(duration+ bTime)/1000)];

	//class
	KoderDTMF DTMF;
	//sf::Int16 *temp = new sf::Int16[(sampleRate * double((duration + bTime))) / 1000];
	sf::Int16 temp[((44100 * 500) / 1000)]; //sta³a wartoœæ do biblioteki 500ms + 100ms
	
	int s;
	s = (sampleRate * (bTime + duration) / 1000);
	p = (sampleRate * (bTime + duration) / 1000);


	//Generowanie znaków u¿ytkownika
	
	for (int i = 0; i < 6; i++) {

		DTMF.gDTMF(frame[i], duration, bTime, sampleRate, A, temp);
		//output.append(temp);
		p = i * (sampleRate * (bTime + duration) / 1000);

		
		
		j = 0;
		while (j <= (s) ) {
			output[p + j] = temp[j];
			j++;
		}
		
	}


	return 0;
}


