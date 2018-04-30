/* endTurn() unit test */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
   struct gameState endTurnState;
   struct gameState testendTurnState;
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   int numPlayers = 2;
   int seed = 999;
   int result;

   initializeGame(numPlayers, k, seed, &endTurnState);
   printf("Testing endTurn() \n"); 
   memcpy(&testendTurnState, &endTurnState, sizeof(struct gameState));
   printf("testendTurnState.whosendTurnStateurn = 0 \n"); 
   testendTurnState.whosendTurnStateurn = 0;
   result =  endTurn(&testendTurnState);
   
   printf("expected = 0\n");
   printf("result = %d\n", result);
   printf("testendTurnState.whosendTurnStateurn: expected = 1, actual = %d\n\n", testendTurnState.whosendTurnStateurn);
   memcpy(&testendTurnState, &endTurnState, sizeof(struct gameState));

   printf("testendTurnState.whosendTurnStateurn = 1 \n"); 
   testendTurnState.whosendTurnStateurn = 1;
   result =  endTurn(&testendTurnState);
   printf("Expected: 0\n");
   printf("Result: %d\n", result);
   printf("testendTurnState.whosendTurnStateurn: expected = 0, actual = %d\n\n", testendTurnState.whosendTurnStateurn);
   return 0;
}