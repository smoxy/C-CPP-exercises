#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOAT_SPEED 1

char* full_steam_ahead(unsigned current_distance) {
    unsigned new_distance = current_distance + BOAT_SPEED;

    char* log_text_suffix = "miles, go ahead!\n";
    int buffer_length = strlen("log_text_suffix") + 3;

    char* buffer;
    sprintf(buffer, "%u %s", new_distance, log_text_suffix);
    return buffer;
}

int main(int argc, char* argv[]) {
    int to_the_atlantic;
    int nautical_miles;

    // check number of arguments
    if (argc < 2) {
        printf("Syntax: %s <miles>\n", argv[0]);
        return 1;
    }

    // parse argv[1]'s content as an int using atoi()
    to_the_atlantic = atoi(argv[1]);
    if (to_the_atlantic < 1) {
        printf("Specify a positive (non-zero) amount!\n");
        return 1;
    }

    // advance the boat towards the Atlantic as requested by the user
    char* captains_log;
    for (nautical_miles = 1; nautical_miles <= to_the_atlantic; nautical_miles++) {
        captains_log = full_steam_ahead(nautical_miles);
        printf("%s", captains_log);
    }
    free(captains_log);

    return 0;
}
