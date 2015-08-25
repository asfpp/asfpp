/*
 * This action modifies the node's sensor measurements.
 *
 *  Author : Francesco Racciatti
 *  e-mail : racciatti.francesco@gmail.com
 */

#ifndef FAKEREAD_H
#define FAKEREAD_H

#include "Action.h"

using namespace std;

enum Noise{
	// user defined constant noises
	CON = 0,
	// sensor dependent constant noises
	SEN,
	SAT,
	FIX,
	MIN,
	MAX,
	AVG,
	// random noise
	RND,
	// piecewise constant noises
	INF,
	SUP,
	MED,
	SGN,
	// divergent noises
	LIN,
	// bounding noises
	SYM,
	SHP,
	// periodic noises
	SIN,
	SQR,
	SAW,
	TRI,
};

class Fakeread: public Action {

	private:
	int sensorID;
	Noise noise;
	vector<double> noiseParams;

	Noise mapNoise(string str);

	public:
	
	static const int fakereadArgc4 = 4;	// sensorID, noise, alpha, beta
	static const int fakereadArgc5 = 5; // sensorID, noise, alpha, beta, gamma
	static const int fakereadArgc6 = 6; // sensorID, noise, alpha, gamma, deltaH, deltaL
	static const int fakereadArgc7 = 7; // sensorID, noise, alpha, beta, tau, phi, gamma

	static const int noiseArgc2 = 2; // alpha, beta
	static const int noiseArgc3 = 3; // alpha, beta, gamma
	static const int noiseArgc4 = 4; // alpha, gamma, deltaH, deltaL
	static const int noiseArgc5 = 5; // alpha, beta, tau, phi, gamma

	Fakeread(int theSensorID, string theNoise, vector<double>& theNoiseParams);
	virtual ~Fakeread() {}

	void execute(vector< vector<Noise> >& theNoises, vector< vector< vector<double> > >& theNoisesParams, vector< vector<double> >& theNoisesValues, vector< vector<double> >& theSensorsValues) const;
	
};

#endif
