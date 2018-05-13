/* card unit test for greatHallCard */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define Random rand

int testGreatHall (struct gameState *after, int p, int handP) {
    struct gameState before;
    memcpy (&before, after, sizeof(struct gameState));

    int r = pGreatHall(after, p, handP);

    //draw card is draw one card and add one action
    drawCard(p, &before);
    before.numActions++;
    //discard great hall
    discardCard(handP, p, &before, 0);

    assert (r == 0);

    assert(memcmp(&before, after, sizeof(struct gameState)) == 0);
}

int main () {
    int x;
    int i;
    struct gameState state;
    int handP;

    for (x=0; x < 1000; x++){
        int p = floor(Random() * 2);\
        state.numActions = floor(Random() * 11);

        for(i=0; i<state.handCount; i++){
            if (state.hand[p][i] == great_hall){
                handP = i;
                testGreatHall (&state, p, handP);
            }
        }
    }
    return 0;
}