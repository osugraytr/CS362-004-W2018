/* cardtest3.c
 * Unit test for council room card from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 * 	gcc -o cardtest2 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Council Room"

int main()
{
	int i, cardCount;

	/* Set up variables needed for council room*/
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

	printf("----------------Card Test 3: %s----------------\n", TESTCARD);

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Test if 4 cards are added to the hand */
	for(p = 0; p < numPlayers; p++)
	{
		/* Reset numbuys */
		testG.numBuys = 1;

		/* Set all cards to curses, enum value = 0 */
		memcpy(testG.hand[p], curses, sizeof(int) * 5);

		/* Print hand */
		printf("Player %d hand before council room\n", p + 1);
		printf("Number of buys = %d\n", testG.numBuys);
		for(i = 0; i < 5; i++)
		{
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
		}

		/* Play council room */
		play_council_room(p, &testG, handPos);
		

		/* Print hand */
		printf("Number of buys = %d, expected = 2\n", testG.numBuys);
		printf("Player %d hand after council room\n", p + 1);
		for(i = 0; i < 5; i++)
		{
			printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
		}

		/* Assert 4 cards been added to the hand and buys is + 1 */
		cardCount = 0;

		for(i = 0; i < 5; i++)
		{

			if(testG.hand[p][i] != 0)
			{
				cardCount++;
			}

		}

		if(cardCount == 4 && testG.numBuys == 2)
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
