#include <math.h>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <vector>
#include <SFML/Audio.hpp>
#include <fstream>
#include "FrameGenerator.h"

using namespace std;

int main() {
	char c[6];
	int duration = 0; //czas trwania
	int bTime = 0;	  //przerwa
	float sampleRate = 44100;
	float A = 3000;
	//sf::Int16 output[((44100 * 4 *600)/1000)+1]; //tymczasowo sta³a wartoœæ - praca z bibliotek¹ SFML
	
	sf::Int16 output[((44100 * 6 * 500) / 1000)];


	//W przypadku realnej pracy - przekazywanie tablicy double
	//double* output = new double[(44100 * double((duration + bTime))) / 1000]; 

	//class
	FrameGenerator Frame;

	//User Input
	c[0] = '*';
	c[5] = '#';
	cout << "Podaj 4 znaki: ";
	for (int i = 1; i < 5; i++) {
		cin >> c[i];
	}

	cout << "Podaj c zas trwania syganlu oraz czas przerwy ";
	cin >> duration >> bTime;

	Frame.gFrame(c, duration, bTime, sampleRate, A, output);
	//*output = DTMF.gDTMF(c, duration, bTime) // w przypadku przekazywania tablicy przez wskaŸnik a nie jako parametr wejœciowy

	//zapis do pliku
	ofstream file;
	file.open("frame_data.csv");
	for (int i = 0; i < (44100 * 6 * double(duration + bTime)/1000); i++) {
		file << i << "," << output[i] << endl;
	}
	file.close();


	//Odtwarzanie dŸwiêku - biblioteka SFML
	
	sf::SoundBuffer Buffer;
	if (!Buffer.loadFromSamples(output, ( (duration + bTime) * 264.6), 1, 44100)) {
		cerr << "Loading failed" << endl;
		return 1;
	}

	sf::Sound Sound;
	Sound.setBuffer(Buffer);
	Sound.setLoop(false);
	Sound.play();


	while (1) {
		sf::sleep(sf::milliseconds(100));
	}

	
	return 0;
}