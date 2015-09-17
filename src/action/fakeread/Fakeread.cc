#include "Fakeread.h"

/* constructor */
Fakeread::Fakeread(int theSensorID, string theNoise, vector<double>& theNoiseParams):Action(FAKEREAD){

	sensorID = theSensorID;
	noise = mapNoise(theNoise);
	for(int i=0; i<(int)theNoiseParams.size(); i++){
		noiseParams.push_back(theNoiseParams[i]);
	}

}


void Fakeread::execute(vector< vector<Noise> >& theNoises, vector< vector< vector<double> > >& theNoisesParams, vector< vector<double> >& theNoisesValues, vector< vector<double> >& theSensorsValues) const{

	//check if null attack
	bool isNullAttack;
	
	switch( (int) noiseParams.size() ){
					   
		case Fakeread::noiseArgc2: // check alpha && beta
			isNullAttack = ( (noiseParams[0] == 1.0) && (noiseParams[1] == 0.0) );
			break;
			
		case Fakeread::noiseArgc3: // check alpha && beta && gamma
			isNullAttack = ( (noiseParams[0] == 1.0) && (noiseParams[1] == 0.0) && (noiseParams[2] == 0.0) );	
			break;
			
		case Fakeread::noiseArgc4: // check alpha && gamma && deltaH && deltaL
			isNullAttack = ( (noiseParams[0] == 1.0) && (noiseParams[1] == 0.0) && (noiseParams[2] == 0.0) && (noiseParams[3] == 0.0) );	
			break;
			
		case Fakeread::noiseArgc5: // check alpha && beta && gamma
			isNullAttack = ( (noiseParams[0] == 1.0) && (noiseParams[1] == 0.0) && (noiseParams[4] == 0.0) );	
			break;

	};
	
	// if null attack remove it if it is present in noises vector @ local filter
	if( isNullAttack ){
		
		for(int i=0; i<(int)theNoises[sensorID].size(); i++){
			
			if( theNoises[sensorID][i] == noise ){
				theNoises[sensorID].erase( theNoises[sensorID].begin() + i );
				theNoisesParams[sensorID].erase( theNoisesParams[sensorID].begin() + i );
				theNoisesValues[sensorID].erase( theNoisesValues[sensorID].begin() + i );
			}
			
		}	
	
	}
	
	// if not null attack, overwrite it if it is present in the noises vector @ local filter, otherwise add it
	else{
		
		bool isAttackPresent = false;

		for( int i=0; i<(int)theNoises[sensorID].size(); i++){
		
			if( theNoises[sensorID][i] == noise ){ // attack founded, overwrite it
			
				isAttackPresent = true;
				
				// overwrite the noises parameters stored in the noisesParameters vector @ local filter
				for(int j=0; j<(int)theNoisesParams[sensorID][i].size(); j++){
					theNoisesParams[sensorID][i][j] = noiseParams[j];				
				}			
				
				// overwrite the noises values stored in the noisesValues @ local filter
				switch(noise){
								
					case FIX: // FIX fixes the last sensed value at occurrence time of the attack
						theNoisesValues[sensorID][i] = theSensorsValues[sensorID][0]; 
						break;
					
					case MIN: // MIN fixes the minimum sensed value at occurrence time of the attack (i.e. inf)
						theNoisesValues[sensorID][i] = theSensorsValues[sensorID][4]; 
						break;
					
					case MAX: // MAX fixes the maximum sensed value at occurrence time of the attack (i.e. sup)
						theNoisesValues[sensorID][i] = theSensorsValues[sensorID][5]; 
						break;
					
					case AVG: // AVG fixes the average of the sensed value at occurrence time of the attack (i.e. med)
						theNoisesValues[sensorID][i] = theSensorsValues[sensorID][6]; 
						break;
									
					default:
						theNoisesValues[sensorID][i] = 0;
						break;
						
				};
				
			} // end if
		
		} // end for
		
		// add the attack
		if(!isAttackPresent){
		
			// add the noise in the noises vector @ local filter
			theNoises[sensorID].push_back(noise);
			
			// add the noise params in the noisesParams vector @ local filter
			theNoisesParams[sensorID].push_back( vector<double>() );
			for( int i=0; i<(int)noiseParams.size(); i++){
				theNoisesParams[sensorID].back().push_back( noiseParams[i] );
			}
			
			// add the noise values in the noisesValues vector @ local filter
			switch(noise){
			
				case FIX: 
					theNoisesValues[sensorID].push_back( theSensorsValues[sensorID][0]);
					break;
				
				case MIN:
					theNoisesValues[sensorID].push_back( theSensorsValues[sensorID][4]);
					break;
					
				case MAX:
					theNoisesValues[sensorID].push_back( theSensorsValues[sensorID][5]);
					break;
				
				case AVG:
					theNoisesValues[sensorID].push_back( theSensorsValues[sensorID][6]);
					break;
			
				default: 
					theNoisesValues[sensorID].push_back(0);
					break;
			};
		
		}
		
	} // end else
	

}


/* maps the noise function name (string) in NOISE type */
Noise Fakeread::mapNoise(string str){

	if(str == "con"){
		return CON;
	}

	if(str == "sen"){
		return SEN;
	}

	if(str == "sat"){
		return SAT;
	}

	if(str == "fix"){
		return FIX;
	}
	
	if(str == "min"){
		return MIN;
	}
	
	if(str == "max"){
		return MAX;
	}

	if(str == "avg"){
		return AVG;
	}

	if(str == "rnd"){
		return RND;
	}

	if(str == "inf"){
		return INF;
	}

	if(str == "sup"){
		return SUP;
	}

	if(str == "med"){
		return MED;
	}

	if(str == "sgn"){
		return SGN;
	}

	if(str == "sym"){
		return SYM;
	}

	if(str == "shp"){
		return SHP;
	}

	if(str == "lin"){
		return LIN;
	}

	if(str == "sin"){
		return SIN;
	}

	if(str == "sqr"){
		return SQR;
	}

	if(str == "saw"){
		return SAW;
	}

	if(str == "tri"){
		return TRI;
	}
	
	cerr<<"Fakeread::mapNoise -> noise function not recognized\n";

}

