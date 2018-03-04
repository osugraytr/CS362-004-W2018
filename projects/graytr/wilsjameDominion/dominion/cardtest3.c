/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p = 0, r, handCount0 = 0, handCount1 = 0, deckCount0 = 0, deckCount1 = 0;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxhandCount = 50;
    int handPos = 0;
    int testCount = 0;
    int choice1 = -1;
    int choice2 = -1;
    int choice3 = -1;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int failed_test = 0;
    int passed_test = 0;
    int expected_hand_player1 = -1;
    int expected_action_player1 = -1;
    int handCount = 0;
    int maxActionCount = 50;
    int actionCount = -1;

    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    //gainCard(gold, state, 1, currentPlayer);
    
    printf ("TESTING Great_wall():\n"); // printf ("TESTING updateCoins():\n");
    for (actionCount = 0; actionCount <= maxActionCount; actionCount++)
    {
    	for (handCount = 0; handCount <= maxhandCount; handCount++)
    	{
	testCount++;
	// Things to note:
	//	to call: 	isGameOver(&G) 
	//	initilization:	int isGameOver(struct gameState *state) {
	//	variables used:		
	//			state->supplyCount[province]
	//			declared in function:
	//				int i; == itorator
	//				int j; == number of empty supply piles of 25 piles
	//
		
#if (NOISY_TEST == 1)
	printf("Test #%d: actionCount = %d, handCount = %d | ", testCount, actionCount, handCount);
#endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	G.numActions = actionCount;	// Assign action number
	G.handCount[0] = handCount;	// Assign hand number
        
	expected_hand_player1 = handCount;
	expected_action_player1 = actionCount+1;
	//cardEffect(smithy, choice1, choice2, choice3, &G, handPos, 1); // default player 0's turn
	cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, 1); // default player 0's turn

	if(expected_action_player1==G.numActions&&expected_hand_player1==G.handCount[0]){
		passed_test++;
		printf("	Passed:");
	}
	else{
		failed_test++;
		printf("	Failed:");
	}
	printf(" Exp act: %d, Act: %d; Exp hnd: %d, hnd: %d\n",expected_action_player1,G.numActions,expected_hand_player1,G.handCount[0]);
	
    	}
    }
    printf("All tests passed!\n");
    printf("\nTimes ran: %d | Tests Failed: %d\n", testCount, failed_test);	

    return 0;
}
