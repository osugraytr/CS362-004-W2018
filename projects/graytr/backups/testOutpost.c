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
    int p = 0, r, handCount = 0;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxhandCount = 20;
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

    int expected_hand = -1;
    int expected_flag = -1;

    int outpost_flag = -1;
    
    printf ("TESTING outpost():\n"); // printf ("TESTING updateCoins():\n");
    for (outpost_flag = 0; outpost_flag < 2; outpost_flag++)
    {
    	for (handCount = 0; handCount <= maxhandCount; handCount++)
    	{
		testCount++;
		expected_flag = -1;
		expected_hand = -1;
		// Things to note:
		//	what card should do:
		//		setOutpost flag to +1;
		//		discard a card;
		//		
		//G.outpostPlayed = outpost_flag;
			//G.handCount[0] = handCount;
			
		#if (NOISY_TEST == 1)
			printf("Test: #%d, outpostFlag: %d, handCount: %d", testCount, outpost_flag, handCount);
		#endif
	        memset(&G, 23, sizeof(struct gameState));   // clear the game state
	        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	        //G.handCount[0] = handCount0;                 // set the number of cards on hand	
	        //G.handCount[1] = handCount1;                 // set the number of cards on hand	
		
		//Conditions before call
		G.outpostPlayed = outpost_flag;
		G.handCount[0] = handCount;
	
		if(outpost_flag==1){
			expected_hand = expected_hand;
			expected_flag = outpost_flag;
		}
		else if(outpost_flag==0&&handCount==0){
			expected_hand = 0;
			expected_flag = outpost_flag+1;
		}
		else if(outpost_flag==0&&handCount>0){
			expected_flag = outpost_flag+1;
			expected_hand = handCount-1;	
		}
	
		//printf("Outpost flag before: %d, handCount: %d",G.outpostPlayed, G.handCount[0]);
		cardEffect(outpost, choice1, choice2, choice3, &G, handPos, 1); // default player 0's turn
		//printf("	|  Outpost flag after: %d, handCount: %d",G.outpostPlayed, G.handCount[0]);

				
		//See if test passed
		if(expected_hand==G.handCount[0]&&expected_flag==G.outpostPlayed){
			passed_test++;
    			printf("\n");
		}
		else{
			failed_test++;
    			printf(" 	Failed\n");
		}
				
    	}
    }
    printf("All tests ran!\n");
    printf("\nTimes ran: %d | Tests Failed: %d\n", testCount, failed_test);	

    return 0;
}
