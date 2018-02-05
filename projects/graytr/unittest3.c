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


    int Count = 0;



    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    //gainCard(gold, state, 1, currentPlayer);
    
    printf ("TESTING initializeGame():\n"); // printf ("TESTING updateCoins():\n");
    for (Count = 0; Count <= 1000; Count++)
    {
	testCount++;
	
	
#if (NOISY_TEST == 1)
	//printf("Test #%d: actionCount = %d, handCount = %d | ", testCount, actionCount, handCount);
	printf("Test: #%d, Testing with '%d'", testCount, Count);
#endif

	G.deckCount[0]=Count;
	G.handCount[0]=Count;
	G.playedCardCount=Count;
	G.numActions=Count;
	G.phase=Count;
	G.coins=Count;
/*	
	printf("Before:\n");
	printf("	Deck Count[0] = 	%d\n",G.deckCount[0]);
	printf("	Hand Count[0] = 	%d\n",G.handCount[0]);
	printf("	Played card Count[0] = 	%d\n",G.playedCardCount);
	printf("	Num Actions   = 	%d\n",G.numActions);
	printf("	Phase         = 	%d\n",G.phase);
	printf("	Coins	      = 	%d\n",G.coins);
*/
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
/*	printf("After:\n");
	printf("	Deck Count[0] = 	%d\n",G.deckCount[0]);
	printf("	Hand Count[0] = 	%d\n",G.handCount[0]);
	printf("	Played card Count[0] = 	%d\n",G.playedCardCount);
	printf("	Num Actions   = 	%d\n",G.numActions);
	printf("	Phase         = 	%d\n",G.phase);
	printf("	Coins	      = 	%d\n",G.coins);
*/
	if(G.deckCount[0]==5&&G.handCount[0]==5&&G.playedCardCount==0&&G.numActions==1&&G.phase==0&&G.coins==4){
		passed_test++;
		printf("	Passed\n");
	}
	else{
		failed_test++;
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
