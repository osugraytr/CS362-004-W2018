/* randomcardtest1.c
 * Random test for smithy card from the dominion-base code, dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define TESTCARD "Smithy"

int main()
{
	int i;

	/* Set up random seed */
	srand(0);

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

	printf("----------------Random Card Test 1: %s----------------\n", TESTCARD);

	/* Begin random tester */
	int randomHandCount;
	int passCount = 0;
	int failCount = 0;
	int loopCount = 0;

	while(loopCount < 1000)
	{
		/* Randomize hand count */
		randomHandCount = (rand() + 0) % (1000 + 1);

		/* Copy game state to a test case */
		memcpy(&testG, &G, sizeof(struct gameState));

		/* Player 1 */
		currentPlayer = 0;
		printf("Initial p1 hand size = %d\n", testG.handCount[currentPlayer] = randomHandCount);
		play_smithy(currentPlayer, &testG, 0);
		printf("Hand size after smithy = %d, expected = %d\n", testG.handCount[currentPlayer], randomHandCount + 3);

		/* Assert */
		if(testG.handCount[currentPlayer] == randomHandCount + 3)
		{
			printf("PASS\n");
			passCount++;
		}
		else
		{
			printf("FAIL\n");
			failCount++;
		}

		/* Player 2 */
		currentPlayer = 1;
		printf("Initial p2 hand size = %d\n", testG.handCount[currentPlayer] = randomHandCount);
		play_smithy(currentPlayer, &testG, 0);
		printf("Hand size after smithy = %d, expected = %d\n", testG.handCount[currentPlayer], randomHandCount + 3);

		/* Assert */
		if(testG.handCount[currentPlayer] == randomHandCount + 3)
		{
			printf("PASS\n");
			passCount++;
		}
		else
		{
			printf("FAIL\n");
			failCount++;
		}

		loopCount++;
	}

	printf("Loop count: %d\n", loopCount);
	printf("Test count: %d\n", loopCount * 2);
	printf("Pass count: %d\n", passCount);
	printf("Fail count: %d\n", failCount);
	printf("TEST COMPLETED\n");

	return 0;

}
