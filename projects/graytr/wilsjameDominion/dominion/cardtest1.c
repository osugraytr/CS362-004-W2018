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
    int maxhandCount = 5;
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

    int expected_hand0 = -1;
    int expected_hand1 = -1;
    int expected_deck0 = -1;
    int expected_deck1 = -1;

    int result_hand0 = -1;
    int result_hand1 = -1;
    int result_deck0 = -1;
    int result_deck1 = -1;
    srand(time(NULL));


    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    //gainCard(gold, state, 1, currentPlayer);
    
//    memcpy(G.hand[p], smithy, sizeof(int) * maxhandCount0); // set all the cards to smithy
//    G.hand[0][0] = smithy;
//    printf("\n\nhere-> %d\n\n\n",G.hand[0][0]);
    
    printf ("TESTING Smithy_card():\n"); // printf ("TESTING updateCoins():\n");
    for (deckCount0 = 0; deckCount0 <= maxhandCount; deckCount0++)
    {
    	for (deckCount1 = 0; deckCount1 <= maxhandCount; deckCount1++)
    	{
    		for (handCount0 = 0; handCount0 <= maxhandCount; handCount0++)
    		{
    			for (handCount1 = 0; handCount1 <= maxhandCount; handCount1++)
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
        printf("Test #%d Player 1 deck size: %d, hand size: %d | Player 2 deck size: %d, hand size: %d :", testCount, deckCount0, handCount0, deckCount1, handCount1);
#endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    	//G.handp[p][handPos];			// Set handPos to smithy


        G.handCount[0] = handCount0;                 // set the number of cards on hand	
        G.handCount[1] = handCount1;                 // set the number of cards on hand	

        G.deckCount[0] = deckCount0;                 // set the number of cards on hand	
        G.deckCount[1] = deckCount1;                 // set the number of cards on hand	

	expected_hand0 = handCount0+2;
	if(deckCount0<3){	// Sets Expected dexk and hand size for player 1
		expected_deck0 = 0;
		expected_hand0 = (handCount0+deckCount0)-1;
	}
	else{
		expected_deck0 = deckCount0-3;	
	}

	expected_hand1 = handCount1; // Expected hand size for player 2
	expected_deck1 = deckCount1; // Expected deck size for player 2
            		
    	//printf("Player %d's turn = %d\n", whoseTurn(&G));
    	//printf("->Count P0 ->Before: hand count = %d | deck cout = %d\n", G.handCount[0], G.deckCount[0]);
    	//printf("->Count P2 ->Before: hand count = %d | deck cout = %d\n", G.handCount[1], G.deckCount[1]);
	
	
	cardEffect(smithy, choice1, choice2, choice3, &G, handPos, 1); // default player 0's turn


    	//printf("<-Count P0 <-After: hand count = %d | deck cout = %d\n", G.handCount[0], G.deckCount[0]);
    	//printf("<-Count P2 <-After: hand count = %d | deck cout = %d\n", G.handCount[1], G.deckCount[1]);
	
        //updateCoins(p, &G, bonus);//TODO: change this to work for isGameOver();

    	result_hand0 = G.handCount[0];
    	result_hand1 = G.handCount[1];
    	result_deck0 = G.deckCount[0];
    	result_deck1 = G.deckCount[1];

	
//				printf("rd1 = %d, rd0 = %d\ned1 = %d, ed0 = %d\nrh1 = %d, rh0 = %d\neh1 = %d, eh0 = %d\n", result_deck1, result_deck0, expected_deck1, expected_deck0, result_hand1, result_hand0, expected_hand1, expected_hand0);
				// Fail if p1's things change at all
				// Fail if p0's hand is not +2 or deck is not -3
				
				//See if test passed
				if(result_hand0==expected_hand0){
					if(result_hand1==expected_hand1){
						if(result_deck1==expected_deck1){
							if(result_deck0==expected_deck0){
								passed_test++;
								printf("	PASSED TEST\n");
							}
							else{
								failed_test++;
								printf("\n	FAILED TEST\n");
							}
						}
						else{
							failed_test++;
							printf("\n	FAILED TEST\n");
						}
					}
					else{
						failed_test++;
						printf("\n	FAILED TEST\n");
					}
				}
				else{
					failed_test++;
					printf("\n	FAILED TEST\n");
				}
				
			}
		}
    	}
    }
    printf("All tests passed!\n");
    printf("\nTimes ran: %d | Tests Failed: %d\n", testCount, failed_test);	

    return 0;
}
