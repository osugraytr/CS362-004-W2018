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
    int i=0;
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
    int expected = 0;

	
    int handCount = 0;
    int deckCount = 0;
    int discardCount = 0;
    int result = 0;


//    int deckCount = 0;


    //gainCard(gold, state, 1, currentPlayer);
    
    printf ("TESTING Adventuer_card():\n"); // printf ("TESTING updateCoins():\n");
    for (p = 0; p <= 1; p++)
    {
    	for (handCount = 0; handCount <= 10; handCount++)
    	{
	    	for (deckCount = 0; deckCount <= 10; deckCount++)
		{
		    	for (discardCount = 0; discardCount <= 10; discardCount++)
    			{
				testCount++;
				
				expected = handCount+deckCount+discardCount;
			#if (NOISY_TEST == 1)
				printf("Player: %d, Hand Size: %d, Deck Size: %d, Discard Size: %d, Expected: %d, Result: ", p, handCount, deckCount, discardCount, expected);
				//printf("Test: #%d, Testing Player %d, with '%d' cards in hand: ", testCount, p+1, handCount);
			#endif	
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on hand
				G.deckCount[p] = deckCount;		    // set number of cards in deck
				G.discardCount[p] = discardCount;	    // set number of cards in discard

				for(i=0;i<handCount;i++){
					G.hand[p][i] = 0;
				}
				for(i=0;i<deckCount;i++){
					G.deck[p][i] = 0;
				}
				for(i=0;i<discardCount;i++){
					G.discard[p][i] = 0;
				}

//				memcpy(G.hand[p], copper , sizeof(int) * handCount); // set all the cards to Curse

//				memcpy(G.deck[p], copper , sizeof(int) * deckCount); // set all the cards to Curse

//				memcpy(G.discard[p], copper , sizeof(int) * discardCount); // set all the cards to Curse
				//	for(i=0;i<handCount;i++){
				//		G.hand[p][i] = copper;
				//		printf("Hand at [%d] = %d; ",i,G.hand[0][i]);
				//	}
				//printf("Before: --> %d\n",numHandCards(&G));
				result = fullDeckCount(p, 0, &G);
				//printf("After: -->%d\n",numHandCards(&G));
				if(expected==result){
					passed_test++;
    					printf("Passed\n");
				}
				else{
					failed_test++;
    					printf("Failed\n");
				}
	
				expected = 0;
			}
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
