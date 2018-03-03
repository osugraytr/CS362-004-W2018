/* unittest4.c
 * Unit test for numHandCards function from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 * 	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTFUNCTION "numHandCards"

int main()
{
	int i;

	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k1[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k1, randomSeed, &G);

	printf("----------------Unit Test 4: %s----------------\n", TESTFUNCTION);

	/** TEST 1: Initial hand count **/
	printf("TEST 1: Initial hand counts \n");

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Test player 1 hand */
	printf("Testing player 1\n");
	testG.whoseTurn = 0;
	printf("Player 1 initial handcount = %d, expected = %d\n", numHandCards(&testG), 5);
	assert(numHandCards(&testG) == 5);
	printf("PASS\n");

	/* Test player 2 hand */
	printf("Testing player 2\n");
	testG.whoseTurn = 1;
	printf("Player 2 initial handcount = %d, expected = %d\n", numHandCards(&testG), 5);
	printf("FAIL\n");
	printf("TEST COMPLETED\n");

	printf("----------------Unit Test 4: %s----------------\n", TESTFUNCTION);

	/** TEST 2: manipiulate hand count **/
	printf("TEST 2: manipulate hand counts \n");

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	for(i = 4; i >= 0; i--)
	{
		/* Test player 1 hand */
		printf("Testing player 1\n");
		testG.whoseTurn = 0;
		testG.handCount[0] = i;
		printf("Player 1 handcount = %d, expected = %d\n", numHandCards(&testG), i);
		assert(numHandCards(&testG) == i);
		printf("PASS\n");

		/* Test player 2 hand */
		printf("Testing player 2\n");
		testG.whoseTurn = 1;
		testG.handCount[1] = i;
		printf("Player 2 handcount = %d, expected = %d\n", numHandCards(&testG), i);
		assert(numHandCards(&testG) == i);
		printf("PASS\n");
	}

	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;

}
