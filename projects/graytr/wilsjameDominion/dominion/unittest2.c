/* unittest2.c
 * Unit test for updateCoins function from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 * 	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTFUNCTION "updateCoins"

int main()
{
	int i;

	/* Set up variables needed for updateCoins internal variables */ 
	int player, hand_count, bonus;
	int bonus_max = 10;
	int hand_max = 5;
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	
	/* Fill treasure arrays */
	for(i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}
		
	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k, randomSeed, &G);

	printf("----------------Unit Test 2: %s----------------\n", TESTFUNCTION);
	
	/** TEST 1: Add each treasure and bonus at a time to hand for all players **/
	printf("TEST 1: Add each treasure card and bonus to a varying hand size for all palyers\n");

	for(player = 0; player < numPlayers; player++)
	{

		/* Test range of hand sizes 1-5 */
		for(hand_count = 1; hand_count < hand_max + 1; hand_count++)
		{

			/* Test range of bonus */
			for(bonus = 0; bonus < bonus_max + 1; bonus++)
			{

				/* Reset: Copy game state to a test case */
				memcpy(&testG, &G, sizeof(struct gameState));

				/* Set players hand size */
				testG.handCount[player] = hand_count;

				/* Copper test */
				memcpy(testG.hand[player], coppers, sizeof(int) * hand_count);
				updateCoins(player, &testG, bonus);
				printf("Coins from copper = %d, expected = %d\n", testG.coins, hand_count * 1 + bonus);
				assert(testG.coins == hand_count * 1 + bonus);
				printf("PASS\n");

				/* Silver test */
				memcpy(testG.hand[player], silvers, sizeof(int) * hand_count);
				updateCoins(player, &testG, bonus);
				printf("Coins from silver = %d, expected = %d\n", testG.coins, hand_count * 2 + bonus);
				assert(testG.coins == hand_count * 2 + bonus);
				printf("PASS\n");

				/* Gold test */
				memcpy(testG.hand[player], golds, sizeof(int) * hand_count);
				updateCoins(player, &testG, bonus);
				printf("Coins from gold = %d, expected = %d\n", testG.coins, hand_count * 3 + bonus);
				assert(testG.coins == hand_count * 3 + bonus);
				printf("PASS\n");
			}

		}

	}

	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;

}
