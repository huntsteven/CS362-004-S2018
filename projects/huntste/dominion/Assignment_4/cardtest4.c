/* card unit test for sea hag card */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 1

int main(){
    struct gameState state, before;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    int i, s, p, r;
    int bonus = 0;
    int pass = 1;

    r = initializeGame(MAX_PLAYERS, k, 1, &state);
    assert(r == 0);

    memcpy(&before, &state, sizeof(struct gameState));

    printf ("Testing sea hag card\n");

    for(i = 0; i < MAX_PLAYERS; i++){
        before.whoseTurn = i;
        memcpy(&state, &before, sizeof(struct gameState));
        cardEffect(sea_hag, 0, 0, 0, &state, 0, &bonus);

        for(p = 0; p < MAX_PLAYERS; p++){
            if(p != i){
                if(state.deckCount[i] != before.deckCount[i]){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }
                for(s = 0; s < state.deckCount[i] - 1; s++){
                    if(state.deck[i][s] != before.deck[i][s]){
                        if(DEBUG)
                            printf("Test failed\n", i, p);
                        pass = 0;
                    }
                }
                if(state.deck[i][state.deckCount[i] - 1] == curse){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }

                if(state.discardCount[i] == before.discardCount[i] + 1){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }
                for(s = 0; s < before.discardCount[i]; s++){
                    if(state.discard[i][s] != before.discard[i][s]){
                        if(DEBUG)
                            printf("Test failed\n", i, p);
                        pass = 0;
                    }
                }
                if(state.discard[i][state.discardCount[i] - 1] == before.deck[i][before.deckCount[i] - 1]){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }

                if(state.handCount[i] != before.handCount[i]){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }
                for(s = 0; s < before.handCount[i]; s++){
                    if(state.hand[i][s] != before.hand[i][s]){
                        if(DEBUG)
                            printf("Test failed\n", i, p);
                        pass = 0;
                    }
                }
            }
            else{
                if(state.deckCount[i] != before.deckCount[i]){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }
                for(s = 0; s < state.deckCount[i]; s++){
                    if(state.deck[i][s] != before.deck[i][s]){
                        if(DEBUG)
                            printf("Test failed\n", i, p);
                        pass = 0;
                    }
                }

                if(state.discardCount[i] != before.discardCount[i] + 1){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }
                for(s = 0; s < before.discardCount[i]; s++){
                    if(state.discard[i][s] != before.discard[i][s]){
                        if(DEBUG)
                            printf("Test failed\n", i, p);
                        pass = 0;
                    }
                }
                if(state.discard[i][state.discardCount[i] - 1] != sea_hag){
                    if(DEBUG)
                        printf("Test failed\n", i, p);
                    pass = 0;
                }

                if(state.handCount[i] != before.handCount[i] - 1){
                    if(DEBUG)
                        printf("Test failed\n", i);
                    pass = 0;
                }
            }
        }
    }
    if(pass)
        printf("All tests passed for sea hag.\n");
    else
        printf("There were failures.\n");
    return 0;
}