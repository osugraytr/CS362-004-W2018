/* randomtestcardtest1.c
 * Random test for village card from the dominion-base code, dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define TESTCARD "village"

int main()
{
	int i, actionCount, cardCount;

	/* Set up random seed */
	srand(0);

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

	printf("----------------Random Card Test 2: %s----------------\n", TESTCARD);

	/* Begin random tester */
	int randomHandCount;
	int randomNumActions;
	int addedCards;
	int failCountActions = 0;
	int failCountCards = 0;
	int passCountActions = 0;
	int passCountCards = 0;
	int loopCount = 0;
	
	while(loopCount < 1000)
	{

		/* Copy game state to a test case */
		memcpy(&testG, &G, sizeof(struct gameState));

		/* Test if 1 cards are added to the hand */
		for(p = 0; p < numPlayers; p++)
		{
			/* Randomize hand count */
			/* Randomize actions */
			randomHandCount = (rand() + 0) % (1000 + 1);
			randomNumActions = (rand() + 0) % (1000 + 1);
			
			/* Set hand count */
			/* Set added cards */
			/* Set actions */
			testG.handCount[p] = randomHandCount;
			addedCards = 0;
			testG.numActions = randomNumActions;

			/* Set all cards to curses, enum value = 0 */
			memcpy(testG.hand[p], curses, sizeof(int) * randomHandCount);

			/* Print initial hand stats */
			printf("Player %d hand before village\n", p + 1);
			printf("Cards = %d\n", testG.handCount[p]);
			printf("Actions = %d\n", testG.numActions);

			/* Printing hand
			for(i = 0; i < 5; i++)
			{ 
				printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]); 
			}
			*/

			/* Play village */
			play_village(p, &testG, handPos);

			/* Print hand and test */
			printf("Player %d hand after village\n", p + 1);
			printf("Number of actions = %d, expected = %d\n", testG.numActions, randomNumActions + 2);
			/* Test if number of actions is correct */
			if(testG.numActions == randomNumActions + 2)
			{
				printf("PASS\n");
				passCountActions++;
			}
			else
			{
				printf("FAIL\n");
				failCountActions++;
			}

			/* Print hand
			printf("Player %d hand after village\n", p + 1);
			for(i = 0; i < 5; i++)
			{
				printf("testG.hand[%d] = %d\n", i, testG.hand[p][i]);
			}
			*/

			/* Test if number of cards added is correct */
			addedCards = 0;

			for(i = 0; i < randomHandCount; i++)
			{

				if(testG.hand[p][i] != 0)
				{
					addedCards++;
				}

			}

			/* Print test */
			printf("Number of cards added = %d, expected = %d\n", addedCards, 1);

			if(addedCards == 1)
			{
				printf("PASS\n");
				passCountCards++;
			}
			else
			{
				printf("FAIL\n");
				failCountCards++;
			}

		}
		
		loopCount++;

	} //end main while()

	printf("TEST COMPLETED\n");
	printf("Loop count %d\n", loopCount);
	printf("Pass Actions count %d\n", passCountActions);
	printf("Fail Actions count %d\n", failCountActions);
	printf("Pass Card Added count %d\n", passCountCards);
	printf("Fail Card Added count %d\n", failCountCards);


	return 0;

}
