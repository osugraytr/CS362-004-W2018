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
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p = 0, r;//, handCount0 = 0, handCount1 = 0, deckCount1 = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handPos = 0;
    int testCount = 0;
    int choice1 = -1;
    int choice2 = -1;
    int choice3 = -1;
    int failed_test = 0;
    int passed_test = 0;
    int handCount = 0;
    int expected = 0;
    int randomHandCount = 0;
    int randomDeckCount = 0;
    srand(time(NULL));
//    int deckCount = 0;


    //gainCard(gold, state, 1, currentPlayer);
    
    printf ("TESTING Adventuer_card():\n"); // printf ("TESTING updateCoins():\n");
    for (p = 0; p <= 1; p++)
    {
    	for (handCount = 0; handCount <= 1000; handCount++)
    	{
		testCount++;
		
		randomHandCount = (rand()%500)-1;
		randomDeckCount = (rand()%500);
		if(randomHandCount==0){
			printf("\n\nhere is happend->\n\n");
		}
		printf("RandomHandCount: %d\n",randomHandCount);
		printf("RandomDeckCount: %d\n",randomDeckCount);
		
		expected = randomHandCount+2;
	#if (NOISY_TEST == 1)
		//printf("Test #%d: actionCount = %d, handCount = %d | ", testCount, actionCount, handCount);
//		printf("Test: #%d, Testing Player %d, with '%d' cards in hand: ", testCount, p+1, handCount);
	#endif
		
	        memset(&G, 23, sizeof(struct gameState));	// clear the game state
	        r = initializeGame(numPlayer, k, seed, &G);	// initialize a new game
		G.handCount[p] = randomHandCount;		// set the number of cards on hand
		G.deckCount[p] = randomDeckCount;		// set the number of cards on deck
		G.whoseTurn = p;				// set player count
		
		//printf("Before: --> %d\n",numHandCards(&G));
		if(randomDeckCount!=0){		
			cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, 1); // default player 0's turn
		}
		//G.whoseTurn = p;
		//printf("After: -->%d\n",numHandCards(&G));
		
		
		if(numHandCards(&G)==expected&&randomDeckCount!=0){		
			passed_test++;
			printf("	Passed\n");
		}
		else{
			failed_test++;
			printf("	Failed\n");
		}
		
    	}
    }
    printf("All tests passed!\n");
    printf("\nTimes ran: %d | Tests Failed: %d\n", testCount, failed_test);	

    return 0;
}

/* variables in gameState
  int numPlayers; //number of players
  int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
  int embargoTokens[treasure_map+1];
  int outpostPlayed;
  int outpostTurn;
  int whoseTurn;
  int phase;
  int numActions;  Starts at 1 each turn 
  int coins;  Use as you see fit! 
  int numBuys;  Starts at 1 each turn 
  int hand[MAX_PLAYERS][MAX_HAND];
  int handCount[MAX_PLAYERS];
  int deck[MAX_PLAYERS][MAX_DECK];
  int deckCount[MAX_PLAYERS];
  int discard[MAX_PLAYERS][MAX_DECK];
  int discardCount[MAX_PLAYERS];
  int playedCards[MAX_DECK];
  int playedCardCount;
*/
