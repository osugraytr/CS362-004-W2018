/* cardtest2.c
 * Unit test for adventurer card from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 * 	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Adventurer"

int main()
{
	int i, treasureCount;

	/* Set up variables needed for adventurer*/
	int drawntreasure = 0;
	int temphand[MAX_HAND]; memset(temphand, '\0', sizeof(temphand));
	int z = 0; //this is the counter for the temp hand
	int p;

	int curses[MAX_HAND];
	for(i = 0; i < MAX_HAND; i++)
	{
		curses[i] = curse;
	}

	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k1[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k1, randomSeed, &G);

	printf("----------------Card Test 2: %s----------------\n", TESTCARD);

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Test if two treasure cards are added to the hand */
	for(p = 0; p < numPlayers; p++)
	{

		/* Set all cards to curses, enum value = 0 */
		memcpy(testG.hand[p], curses, sizeof(int) * 5);

		/* Print hand */
		printf("Player %d hand before adventurer\n", p + 1);
		for(i = 0; i < 5; i++)
		{
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
		}

		/* Play adventurer */
		play_adventurer(drawntreasure, &testG, p, temphand, z);

		/* Print hand */
		printf("Player %d hand after adventurer\n", p + 1);
		for(i = 0; i < 5; i++)
		{
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
		}

		/* Assert two treasures have been added to the hand */
		treasureCount = 0;

		for(i = 0; i < 5; i++)
		{

			if(testG.hand[p][i] == 4 || testG.hand[p][i] == 5 || testG.hand[p][i] == 6)
			{
				treasureCount++;
			}

		}

		if(treasureCount == 2)
		{
			printf("PASS\n");
		}
		else
		{
			printf("FAIL\n");
		}

	}

	printf("TEST COMPLETED\n");

	return 0;

}
