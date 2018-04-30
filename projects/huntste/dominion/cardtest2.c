/* card unit test for smithyCard */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = rand() % 999;
    int numPlayers = 2;
    int p, player, round;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState old;
	struct gameState new;
    int maxHandCount = 5;
    int fails = 0;
    int passes = 0;

    printf ("Testing smithyCard\n");
	
	for(p = 0; p < maxHandCount; p++)
	{
		memset(&old, 23, sizeof(struct gameState));
		memset(&new, 23, sizeof(struct gameState));
		
		initializeGame(numPlayers, k, seed, &new);
		
		for(round = 0; round < 2; round++)
		{
			for(player = 0; player < numPlayers; player++)
			{
				memcpy(&old, &new, sizeof(struct gameState));
				smithyCard(smithy, player, &new);

				printf("Player %d\n", player);
				printf("Old deckCount: %d old handCount: %d\n", old.deckCount[player], old.handCount[player]);
				printf("New deckCount: %d new handCount: %d\n", new.deckCount[player], new.handCount[player]);

				if((new.handCount[player] == old.handCount[player] + 3) && (new.deckCount[player] == old.deckCount[player] - 3))
				{
					passes++;
				}
				else
				{
					fails++;
				}
			}	
		}		
	}
    printf("Number of passes: %d\n", passes);
    printf("Number of fails: %d\n", fails);

    return 0;
}