#include "KoderDTMF.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;
#define M_PI 3.14159265358979323846

double KoderDTMF::gDTMF(char c, int duration, int bTime, float sampleRate, float A, sf::Int16 output[]) { //bez tablicy w wersji domyœlnej
	//float sampleRate = 44100.0;
	//double* output = new double[(sampleRate * double((duration + bTime))) / 1000.0]; //zmiana pod bibliotekê
	float increment, sampleValue;
	int  rowFreq, colFreq;
	//A = 6000; //aplituda
	rowFreq = 0;
	colFreq = 0;


	//Czêstotliwoœci odpowiadaj¹ce poszczególnym znakom - wiersz
	switch (c) {
	case'1': case'2': case'3': case 'A': case 'a': rowFreq = 697; break;
	case'4': case'5': case'6': case 'B': case 'b': rowFreq = 770; break;
	case'7': case'8': case'9': case 'C': case 'c': rowFreq = 852; break;
	case'*': case'0': case'#': case 'D': case 'd': rowFreq = 941; break;
	}
	//Czêstotliwoœci odpowiadaj¹ce poszczególnym znakom - kolumna
	switch (c) {
	case'1': case'4': case'7': case '*': colFreq = 1209; break;
	case'2': case'5': case'8': case '0': colFreq = 1336; break;
	case'3': case'6': case'9': case '#': colFreq = 1477; break;
	case'A': case'B': case'C': case 'D': colFreq = 1633; break;
	case'a': case'b': case'c': case 'd': colFreq = 1633; break;
	}

	//Inicjalizacja zmiennych do 1 generacji
	increment = (2.0 * M_PI) / (sampleRate);
	sampleValue = 0;
	int i = 0;
	int j = 0;

	//Inicjalizacja
	for (i = 0; i <= (((sampleRate * (bTime + duration) / 1000))); i++) {
		
		output[i] = 0;
	}

	
	//Generowanie sinusoidy 
	for (i = 0; i <= (((sampleRate * duration) / 1000))+1; i++) {
		output[i] += sinf(sampleValue * rowFreq) * A;
		output[i] += sinf(sampleValue * colFreq) * A;
		sampleValue += increment;
	}


	//Generowanie przerwy
	while (j < (sampleRate * bTime) / 1000) {
		j++;
		i++;
		output[i] = 0;
	}

	return 0;
	//return *output;
}