/* unittest1.c
 * Unit test for isGameOver function from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 * 	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTFUNCTION "isGameOver"

int main()
{
	int i, j, m;

	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k, randomSeed, &G);

	printf("----------------Unit Test 1: %s----------------\n", TESTFUNCTION);

	/** TEST 1: Game ends if stack of province cards is empty **/
	printf("TEST 1: Empty Province card pile\n");

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Empty province pile */
	testG.supplyCount[province] = 0;
	printf("province count = %d, expected = %d\n", testG.supplyCount[province], 0);
	
	/* Test isGameOver */
	printf("isGameOver = %d, expected = %d\n", isGameOver(&testG), 1);
	assert(isGameOver(&testG) == 1);

	printf("TEST SUCCESSFULLY COMPLETED\n");

	printf("----------------Unit Test 2: %s----------------\n", TESTFUNCTION);

	/** TEST 2: Game ends if three supply piles are at 0 **/
	printf("TEST 2: Game ends if three supply piles are empty\n");

	for(i = 0; i < 10; i++)
	{

		/* Copy game state to a test case */
		memcpy(&testG, &G, sizeof(struct gameState));

		/* Empty pile */
		testG.supplyCount[k[i]] = 0;
				
		for(j = 0; j < 10; j++)
		{

			if(j != i)
			{

				/* Empty pile */
				testG.supplyCount[k[j]] = 0;
				
				for(m = 0; m < 10; m++)
				{

					if(m != i && m != j)
					{

						/* Empty pile */
						testG.supplyCount[k[m]] = 0;
						printf("> card count for k[%d] = %d\n", i, testG.supplyCount[k[i]]);
						printf(">> card count for k[%d] = %d\n", j, testG.supplyCount[k[j]]);
						printf(">>> card count for k[%d] = %d\n", m, testG.supplyCount[k[m]]);

						/* Test isGameOver */
						printf("isGameOver = %d, expected = %d\n", isGameOver(&testG), 1);
						assert(isGameOver(&testG) == 1);
						printf("PASS\n");
					}

				}

			}

		}

	}

	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;

}
