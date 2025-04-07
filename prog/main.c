#include <stdio.h>
#include <math.h>

int main()
{
    int duration = 2;  // 2 seconds time duration
    float samples_per_second = 44100;  // sampling frequency
    int max_value_encoding = 32767; //max value of short int
    int tone_frequency = 440; // sine wave frequency = 440 Hz

    int i = 0;  // time step (sample time step (ith sample))
    int total_samples = duration * samples_per_second; // calculate the total samples for 2 seconds of time duration
    float time = 0;
    float angle;
    short int samples;
    while(i < total_samples)
    {
        time = i/samples_per_second;
        angle = 2*3.14*tone_frequency*time;
        samples = max_value_encoding * sin(angle);
        printf("%d ", samples);
        i = i+1;
    }

}
