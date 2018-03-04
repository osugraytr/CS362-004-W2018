/* cardtest1.c
 * Unit test for smithy card from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 * 	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Smithy"

int main()
{
	int i;

	/* Set up variables needed for smithy */
	int currentPlayer;
	int handPos = 0;

	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k1[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k1, randomSeed, &G);

	printf("----------------Card Test 1: %s----------------\n", TESTCARD);

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Player 1 */
	currentPlayer = 0;
	printf("Initial p1 hand size = %d\n", testG.handCount[currentPlayer]);
	play_smithy(currentPlayer, &testG, 0);
	printf("Hand size after smithy = %d, expected = %d\n", testG.handCount[currentPlayer], 8);

	/* Assert */
	if(testG.handCount[currentPlayer] == 8)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	/* Player 2 */
	currentPlayer = 1;
	printf("Initial p2 hand size = %d\n", testG.handCount[currentPlayer]);
	play_smithy(currentPlayer, &testG, 0);
	printf("Hand size after smithy = %d, expected = %d\n", testG.handCount[currentPlayer], 8);

	/* Assert */
	if(testG.handCount[currentPlayer] == 8)
	{
		printf("PASS\n");
	}
	else
	{
		printf("FAIL\n");
	}

	printf("TEST COMPLETED\n");

	return 0;

}
