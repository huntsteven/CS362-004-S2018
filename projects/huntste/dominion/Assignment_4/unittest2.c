/* updateCoin() unit test */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = rand() % 999;
    int numPlayers = 2;
    int maxBonus = 10;
    int p; 
	int r; 
	int handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int failCount = 0;
    int passCount = 0;
    int copper[MAX_HAND];
    int silver[MAX_HAND];
    int gold[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        copper[i] = copper;
        silver[i] = silver;
        gold[i] = gold;
    }

    printf ("Testing updateCoins()\n");
    for (p = 0; p < numPlayers; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memset(&G, 23, sizeof(struct gameState));
                r = initializeGame(numPlayers, k, seed, &G);
                G.handCount[p] = handCount;
                memcpy(G.hand[p], copper, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
            	printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

                if (G.coins == handCount * 1 + bonus)
		{
			passCount++;
		}
		else
		{
			printf("Copper coins failed\n");
			failCount++;
		}
                memcpy(G.hand[p], silver, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
 
               	if (G.coins == handCount * 2 + bonus)
		{
			passCount++;
		}
		else
		{
			printf("Silver coins failed\n");
			failCount++;
		}

                memcpy(G.hand[p], gold, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
                if (G.coins == handCount * 3 + bonus)
		{
			passCount++;
		}
		else
		{
			printf("Gold coins failed\n");
			failCount++;
		}		
            }
        }
    }

    printf("Number of passes: %d\n", passCount);
    printf("Number of fails: %d\n", failCount);

    return 0;
}