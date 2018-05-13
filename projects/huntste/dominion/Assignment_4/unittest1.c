/* discardCard() unit test */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int checkIfDiscard(int handPos, int currentPlayer, struct gameState *after, int trashFlag)
{
	struct gameState before;
	memcpy(&before, after, sizeof(struct gameState));
	
	int result;
	
	result = discardCard(handPos, currentPlayer, after, trashFlag);
	
	if( trashFlag < 1)
	{
		before.playedCardCount++;
	}
	
	before.handCount[currentPlayer]--;
	
	if(result != 0)
	{
		printf("ERROR: discardCard failed.\n\n");
	}
	else if(before.playedCardCount != after->playedCardCount)
	{
		printf("ERROR: Played card counts do not match before and after.\n\n");
	}
	else if(before.handCount[currentPlayer] != after->handCount[currentPlayer])
	{
		printf("ERROR: Player's hand card counts do not match before and after.\n\n");
	}
	
	return 0;
}

int main()
{
	int numPlayers;
	int p;
	int handPos;
	struct gameState G; 
	int trashFlag;
	int i;
	
	int maxHand = 10;
	int playedCardCount = 0;
	
	SelectStream(2);
	PutSeed(3);
	printf("Testing discardCard() unittest1.\n");
	 for(numPlayers = 2; numPlayers <= MAX_PLAYERS; numPlayers++)
	 {
		for(p = 0;  p < numPlayers; p++)
		{
			for(handPos = 0; handPos < maxHand; handPos++)
			{
				for (i = 0; i < sizeof(struct gameState); i++) {
					((char*)&G)[i] = floor(Random() * 256);
				}
				G.numPlayers = numPlayers;
				G.playedCardCount = playedCardCount;
				G.handCount[p] = maxHand;
				trashFlag = floor(Random()*2);
				
				checkIfDiscard(handPos, p, &G, trashFlag);
			}
		}
	 }
	 
	 printf ("Discard card tests finished.\n\n");
	 
	 return 0;
}