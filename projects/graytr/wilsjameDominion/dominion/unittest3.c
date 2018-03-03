/* unittest3.c
 * Unit test for supplyCount function from the dominion-base code, dominion.c.
 * Include the following lines in Makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 * 	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TESTFUNCTION "supplyCount"

int main()
{
	int i;

	/* Set up variables needed for game state initialization */
	int numPlayers = 2;
	int randomSeed = 1000;
	int k1[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	int k2[10] = {minion, steward, tribute, ambassador, cutpurse, embargo,
				outpost, salvager, sea_hag, treasure_map};
	struct gameState G, G2, testG;

	/* Initialize a game state and player cards */
	initializeGame(numPlayers, k1, randomSeed, &G);
	initializeGame(numPlayers, k2, randomSeed, &G2);

	printf("----------------Unit Test 1: %s----------------\n", TESTFUNCTION);

	/** TEST 1: Decrement card piles **/
	printf("TEST 1: Decrement kingdom cards\n");

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Testing card pile 1\n");
	/* Test card pile 1 */
	for(i = 0; i < 10; i++)
	{

		/* Decrement cards */
		printf("Before k1[%d] count = %d, expected = %d\n", i, supplyCount(k1[i], &testG), testG.supplyCount[k1[i]]);
		testG.supplyCount[k1[i]]--;
		printf("After k1[%d] count = %d, expected = %d\n", i, supplyCount(k1[i], &testG), testG.supplyCount[k1[i]]);
		assert(supplyCount(k1[i], &testG) == testG.supplyCount[k1[i]]);
		printf("PASS\n");
	}

	/* Copy game state to a test case */
	memcpy(&testG, &G2, sizeof(struct gameState));

	printf("Testing card pile 2\n");
	/* Test card pile 2 */
	for(i = 0; i < 10; i++)
	{

		/* Decrement cards */
		printf("Before k2[%d] count = %d, expected = %d\n", i, supplyCount(k2[i], &testG), testG.supplyCount[k2[i]]);
		testG.supplyCount[k2[i]]--;
		printf("After k1[%d] count = %d, expected = %d\n", i, supplyCount(k2[i], &testG), testG.supplyCount[k2[i]]);
		assert(supplyCount(k2[i], &testG) == testG.supplyCount[k2[i]]);
		printf("PASS\n");
	}
				
	printf("TEST SUCCESSFULLY COMPLETED\n");

	printf("----------------Unit Test 2: %s----------------\n", TESTFUNCTION);

	/** TEST 2: Increment card piles **/
	printf("TEST 2: Increment kingdom cards\n");

	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("Testing card pile 1\n");
	/* Test card pile 1 */
	for(i = 0; i < 10; i++)
	{

		/* Increment cards */
		printf("Before k1[%d] count = %d, expected = %d\n", i, supplyCount(k1[i], &testG), testG.supplyCount[k1[i]]);
		testG.supplyCount[k1[i]]++;
		printf("After k1[%d] count = %d, expected = %d\n", i, supplyCount(k1[i], &testG), testG.supplyCount[k1[i]]);
		assert(supplyCount(k1[i], &testG) == testG.supplyCount[k1[i]]);
		printf("PASS\n");
	}

	/* Copy game state to a test case */
	memcpy(&testG, &G2, sizeof(struct gameState));

	printf("Testing card pile 2\n");
	/* Test card pile 2 */
	for(i = 0; i < 10; i++)
	{

		/* Increment cards */
		printf("Before k2[%d] count = %d, expected = %d\n", i, supplyCount(k2[i], &testG), testG.supplyCount[k2[i]]);
		testG.supplyCount[k2[i]]++;
		printf("After k1[%d] count = %d, expected = %d\n", i, supplyCount(k2[i], &testG), testG.supplyCount[k2[i]]);
		assert(supplyCount(k2[i], &testG) == testG.supplyCount[k2[i]]);
		printf("PASS\n");
	}
				
	printf("TEST SUCCESSFULLY COMPLETED\n");

	printf("----------------Unit Test 3 %s----------------\n", TESTFUNCTION);

	/** TEST 3: Cards not in game should retun -1**/
	printf("TEST 3: Cards not in game should return -1\n");

	/* Test card not in game 1 */
	/* Copy game state to a test case */
	memcpy(&testG, &G, sizeof(struct gameState));
	printf("Card not in game 1 supply k1[%d] = %d, expected = %d\n", 11, supplyCount(k1[11], &testG), -1);
	if(supplyCount(k1[11], &testG) != -1)
	{
		printf("FAIL\n");
	}

	/* Test card not in game 2 */
	/* Copy game state to a test case */
	memcpy(&testG, &G2, sizeof(struct gameState));
	printf("Card not in game 2 supply k2[%d] = %d, expected = %d\n", 11, supplyCount(k2[11], &testG), -1);
	if(supplyCount(k1[11], &testG) != -1)
	{
		printf("FAIL\n");
	}

	return 0;

}
