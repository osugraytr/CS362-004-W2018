/* randomtestadventurer.c
 * Random tester for adventurer card from the dominion-base code, dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define TESTCARD "Adventurer"

int main()
{
	int i, treasureCount;

	/* Set up random seed */
	srand(0);

	/* Set up variables needed for adventurer*/
	int drawntreasure = 1; /* This will be randomized */
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

	printf("----------------Card Random Tester: %s----------------\n", TESTCARD);

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	/* Test if the correct number of treasure cards were added to the hand */
	int case0 = 0;
	int case1 = 0;
	int case2 = 0;
	while(!case0 || !case1 || !case2)
	{
		/* Randomize drawntreasure */
		drawntreasure = (rand() + 0) % (2 + 1);

		/* Check off case based on randomized drawntreasure */
		if(drawntreasure == 0)
		{
			case0 = 1;
		}
		else if(drawntreasure == 1)
		{
			case1 = 1;
		}
		else if(drawntreasure == 2)
		{
			case2 = 1;
		}
		else
		{
			printf("ERROR HULL BREACH\n");
			exit(0);
		}

		for(p = 0; p < numPlayers; p++)
		{

			/* Set all cards to curses, enum value = 0 */
			memcpy(testG.hand[p], curses, sizeof(int) * 5);

			/* Print hand and other important things */
			printf("Randomized drawntreasure: %d\n", drawntreasure);

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

			/* Print random testing info */
			printf("Expected treasure in hand : 2-%d=%d\n", drawntreasure, 2-drawntreasure);
			printf("Actual treaure in hand    : %d\n", treasureCount);

			/* Determine correct number of treasure cards in hand */
			if(treasureCount == 2 - drawntreasure)
			{
				printf("PASS\n");
			}
			else
			{
				printf("FAIL\n");
			}

		}

	}

	printf("TEST COMPLETED\n");

	return 0;

}
