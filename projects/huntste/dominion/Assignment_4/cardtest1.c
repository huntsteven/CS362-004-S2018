/* Card unit test for adventurerCard */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//set NOISY_TEST to 0 to remove prints
#define NOISY_TEST 1

int main() {
  
	int numPlayers = 2;
	int seed = 999;
	struct gameState state, storestate;
	int r;
	int ret;
	int p = 0;
	int kcards[10] = {adventurer, minion, cutpurse, steward, smithy,
			   council_room, village, mine, tribute, ambassador};
			   
	memset(&state, 23, sizeof(struct gameState));
	r = initializestateame(numPlayers, kcards, seed, &state);

	printf ("Testing adventurer card\n");

	memcpy(&storestate, &state, sizeof(struct gameState)); 

	ret = adventurerCard(p, &state);
	
	#if (NOISY_TEST == 1)
	if (state.deckCount[p] == (storestate.deckCount[p]- ret)) {
		printf("deckCount passes\n");
	}
	else {
		printf("deckCount fails\n");
	}
	
	if (state.whoseTurn == storestate.whoseTurn) {
		printf("player turn passes\n");
	}
	else{
		printf("player turn fails\n");
	}

	if (state.handCount[p] == (storestate.handCount[p] + 2)) {
		printf("handCount passes\n");
	}
	else {
		printf("handCount fails\n");
	}
	
	if (state.discardCount[p] == (storestate.discardCount[p] + ret - 2))
	{
		printf("discardCount passes\n");
	}
	else {
		printf("discardCount fails\n");
	}
   
	#endif
	
	printf("Finished test.\n");
	

    return 0;
}