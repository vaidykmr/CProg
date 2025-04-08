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

    FILE *fp;
    // This function talks to the OS to create the file, creates a separate region for the file and then return us the pointer to that file. This is what fp is holding
    fp = fopen("sine.raw", "wb");

    if (fp == NULL)
    {
        printf("Failed to open the file \n");
        return -1;
    }

    while(i < total_samples)
    {
        time = i/samples_per_second;
        angle = 2*3.14*tone_frequency*time;
        samples = max_value_encoding * sin(angle);
        fwrite(&samples, 2, 1, fp);  // pass by reference
        printf("%d ", samples);
        i = i+1;
    }

}
