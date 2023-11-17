#include <stdio.h>
#include <time.h>

void currentDate() 
{
    // Get the current time
    time_t currentTime;
    time(&currentTime);

    // Format the time as a string
    char dateString[100];  // Adjust the size based on your needs
    strftime(dateString, sizeof(dateString), "%d-%m-%Y", localtime(&currentTime));

    // Print the time
    printf("Current Date: %s\n", dateString);
}
