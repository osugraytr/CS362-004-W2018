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
    int p;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    int passed_tests = 0;
    int failed_tests = 0;
    int tests_ran = 0;
    int expected = -1;	//Pass = 1 | Fail = 0
    int result = -1;	//Pass = 1 | Fail = 0
    int zero_or_more=0;
    int how_many_zeros=0;

    printf ("TESTING isGameOver():\n"); // printf ("TESTING updateCoins():\n");
    
    // Cycled through players
    // No fail condition here
    for (p = 0; p < numPlayer; p++)
    {
	// Places a 1 or a 0 inside of state->supplyCount[province]
	// Should fail if zero_or_more = 0 | Pass if zero_or_more > 0;
        for (zero_or_more = 0; zero_or_more <= 8; zero_or_more++)
        {
            // Places a num of zero's into different state->supplyCount[i] places
	    // Should fail if how_many_zeros > 2 | Pass if zero_or_more < 2;
            for (how_many_zeros = 0; how_many_zeros <= 4; how_many_zeros++)
            {
		tests_ran++;
        	//printf("Player = %d | state->supplyCount = %d | ammount of zero's in state->supplyCount[i] = %d | ", p, zero_or_more, how_many_zeros);	
		// Things to note:
		//
		//	To call: 	isGameOver(&G) 
		//	initilization:	int isGameOver(struct gameState *state) {
		//	variables used:		
		//			state->supplyCount[province]
		//			declared in function:
		//				int i; == itorator
		//				int j; == number of empty supply piles of 25 piles
		//
		//	Failing conditions:
		//		zero_or_more	= 0
		//		how_many_zeros	> 2
		//	

#if (NOISY_TEST == 1)
        	printf("TEST# %d : Player = %d | state->supplyCount[province] = %d | ammount of zero's in state->supplyCount[i] = %d | ", tests_ran, p, zero_or_more, how_many_zeros);	
#endif

		if(zero_or_more==0){
			expected = 1;
		}
		else if(how_many_zeros>2){
			expected = 1;
		}
		
		if(expected==1){
			printf(" Expected 1: Result: ");
		}
		else{
			printf(" Expected 0: Result: ");	
			expected = 0;
		}

		for(i=0;i<how_many_zeros;i++){

		}
//
		//Logic for test HERE
		//
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, k, seed, &G); // initialize a new game
                //G.handCount[p] = handCount;                 // set the number of cards on hand
		if(G.supplyCount[province]!=8){
			printf("\n\n\n");
		}

		G.supplyCount[province] = zero_or_more;		// set provinceCount to zero_or_more
		for(i=0;i<how_many_zeros;i++){			// sets between 0-4 zero's
			G.supplyCount[i] = 0;
		}

                result = isGameOver(&G);			// Test done here
		printf(" %d\n", result);			// Result

		if(result==expected){				// Marks weather test passed or not
			passed_tests++;
		}
		else{
			failed_tests++;			
    			printf("Test: %d Failed\n", tests_ran);
			//for(i=0;i<25;i++){
			//	rintf("G.supplycount[%d] = %d\n", i, G.supplyCount[i]); // prints all G.supplyCounts's
			//}
		}
		expected = -1;
		result = -1;

	    }
	}
    }
    
    printf("Tests For:\n	Players: 2\n	G.supplyCount[province] from 0-8\n	Between 0-4 Zero's in G.supplyCount array\n");	
    printf("\nTimes ran: %d | Tests Failed: %d\n", tests_ran, failed_tests);	
    printf("All tests Done!\n");
    return 0;
}

//FUNCTION TRYING TO TEST
/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}

*/
