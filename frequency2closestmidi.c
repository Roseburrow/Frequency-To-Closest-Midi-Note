//Calculates the closest midi note to a given frequency.

#include <stdio.h>
#include <math.h>

int main()
{
    double semitone_ratio;
    double c0; //the frequency of midi note 0.
    double c5; //the frequency of middle C.
    double input_frequency; //the given frequency.
    double output_frequency; //the unrounded frequency of the closest midinote.
    double newnotefrequency; //the frequency of the closest midi note. 
    int midinote; //the midi note closest to the input frequency.

    //CALCULATE REQUIRED VALUES.

    //To raise something a semitone do semitone_ration^semitone rise.
    semitone_ratio = pow(2.0, 1.0/12.0); //Approx 1.0594631.

    //Find middle C, 3 semitones below low A (220Hz).
    c5 = 220.0 * pow(semitone_ratio, 3.0);

    //Use c5 to find midi note 0, 5 octaves below c5. 0.5 is 1 octave fall.
    c0 = c5 * pow(0.5, 5.0);

    printf("Please enter a frequency: "); //Get frequency.
    scanf("%lf", &input_frequency);

    //Finds a value to base semitone_ratio.
    output_frequency = log(input_frequency / c0) / log(semitone_ratio);

    //Round output to the nearest whole no. 
    midinote = (int) (output_frequency + 0.5);
    
    //Get the frequency of the calculated midi note...
    newnotefrequency = c0 * pow(semitone_ratio, midinote); //Make this a method.

    printf("Given Frequency: %f\n" 
	   "Closest Midi Note: %d\n" 
	   "Midi Note Frequency: %f\n"
	   ,input_frequency, midinote, newnotefrequency);

    return 0;
}
