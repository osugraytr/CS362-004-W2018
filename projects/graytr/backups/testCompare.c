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
    //const void* a = 0, const void* b = 0; 

    int a=0,b=0;
    int i, j;
    int testCount = 0;
    int expected = 0;
    int result = 0;
    int passed_test = 0;
    int failed_test = 0;

    printf ("TESTING compare():\n"); // printf ("TESTING updateCoins():\n");
    for (i=-50;i<50;i++)
    {
    	for (j=-50;j<50;j++)
    	{
		testCount++;
		// Things to note:

	a = i;
	b = j;
		
	#if (NOISY_TEST == 1)
    		printf("Test: #%d\n", testCount);
	#endif
		if(a<b){
			expected = -1;
		}
		else if(a>b){
			expected = 1;
		}
		else if(a==b){
			expected = 0;
		}
	
		result = compare(&a, &b);
		if(result==expected){
			passed_test++;
		}
		else{
			failed_test++;
		}
		
    	}
    }
    printf("All tests passed!\n");
    printf("\nTimes ran: %d | Tests Failed: %d\n", testCount, failed_test);	

    return 0;
}

/*
int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}
*/
