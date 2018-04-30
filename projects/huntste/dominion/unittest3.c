/* isGameOver() unit test */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i, j, endgame = 0;
    int pass = 0, fail = 0;
    int tests = 500; 
    int seed = 999;
    srand(seed);
    struct gameState state;

    printf ("Testing isGameOver:\n");
    for(j=0; j < tests; j++)
    {
     endgame = 0;

    int zeroes = 0;

    for(i = curse; i <= treasure_map; i++)
    {
        state.supplyCount[i] = rand() % 12 - 1;
        if(state.supplyCount[i] == 0)
            zeroes++;
    }

    if(state.supplyCount[province] == 0 || zeroes >= 3)
        endgame = 1;

    if(endgame != isGameOver(&state))
    {
        printf("Error");
        printf("isGameOver(): %d (should be: %d) provinces %d  supplyCounts %d, ", isGameOver(&state), endgame, state.supplyCount[province],state.supplyCount[curse]);
        for(i = duchy; i <= treasure_map; i++)
        {
            printf("%d, ", state.supplyCount[i]);
        }
        printf("\b\b\n");
        fail++;
    }

    else
    {
        pass++;
    }

    }
    printf("Test results: %d fails  %d/%d passes\n", fail, pass, tests);
    return 0;
}