
#include <wiring.h>
#include <PID_Autotune.h>
#include <PID_Beta6.h>

/* Open Loop Constructor***********************************************
 * Uses the Ziegler-Nichols Open-Loop method to determine PID parameters
 * 
 * This method estimates the optimal P,I,D parametrs by executing a 'step'
 * function with the output variable; it sets it to a value then observes
 * how long the system takes to stabalize given this value.
 ***************************************************************************/ 
PIDtune::PIDtune(double *Input, double *Output, int smoothingSamples, float stability )
{
	float _input = Input;
	float _output = Output;

	int _smoothingSamples = smoothingSamples;
	float _stability = stability;
	
	float _startOutput;
	float _targetOutput;

	// Container for observations
	// data[i][0] => time of observation
	// data[i][1] => PID's input (or delta input) at observation
	float rawData[][2];
	float smoothedData[][2];
	float deltaData[][2];
		
	bool tuning = false;
}

PIDtune::Start( double targetOutput )
{
	_startOutput &= _output;
	_targetOutput = targetOutput;
	
	tuning = true;
}

PIDtune::Loop()
{
	if( tuning && asymptoticRatio() <= stability )
	{
		a, b = tangentLineAtInflectionPoint();
		
		tau0 = intersectionOfLine(a, b, smoothedData[0][1] ) - smoothedData[0][0]
		tau1 = intersectionOfLine(a, b, smoothedData[-1][1] ) - tau0
		
		K = ( targetOutput - _startOutput ) * tau1 / ( smoothedData[-1][1] - smoothedData[0][1] ) * tau0
		P = 1.2 * K
		I = 2 * tau0
		D = .5 * tau0
		
		return {P,I,D}
	}
	else
	{
		rawData.push( {time, &_input } );
		
		smoothData();
		
		differentiateData();
		
		return false;
	}
}

private:
	
	PIDtune::asymptoticRatio()
	{
		// The ratio of the most recent change in Input to the overall change in Input
		// As the Input approaches an asymptote, this ratio will approach 0
		return (smoothedData[-1] - smoothedData[-2]) / ( smoothedData[-1] - smoothedData[1] )
	}

	PIDtune::tangentLineAtInflectionPoint()
	{
		
	}
	
	PIDtune::intersectionOfLine( float a, float b, float Y )
	{
		
	}
	
	PIDtune::smoothData()
	{
		
	}
	
	PIDtune::differentiateData()
	{
		
	}