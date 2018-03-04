/* cardtest4.c
 * Unit test for village card from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 * 	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "village"

int main()
{
	int i, actionCount, cardCount;

	/* Set up variables needed for viilage*/
	int handPos = 0;
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

	printf("----------------Card Test 4: %s----------------\n", TESTCARD);

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Test if 1 cards are added to the hand */
	for(p = 0; p < numPlayers; p++)
	{
		/* Reset actions */
		testG.numActions = 1;

		/* Set all cards to curses, enum value = 0 */
		memcpy(testG.hand[p], curses, sizeof(int) * 5);

		/* Print hand */
		printf("Player %d hand before village\n", p + 1);
		printf("Number of actions = %d\n", testG.numActions);
		for(i = 0; i < 5; i++)
		{ 
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]); 
		}

		/* Play village */
		play_village(p, &testG, handPos);

		/* Print hand */
		printf("Number of actions = %d, expected = 3\n", testG.numActions);
		printf("Player %d hand after village\n", p + 1);
		for(i = 0; i < 5; i++)
		{
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
		}

		/* Assert 1 card been added to the hand and actions is + 2 */
		cardCount = 0;

		for(i = 0; i < 5; i++)
		{

			if(testG.hand[p][i] != 0)
			{
				cardCount++;
			}

		}

		if(cardCount == 1 && testG.numActions == 3)
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
