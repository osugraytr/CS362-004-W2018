#Include gcov flags
CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

### Compile Tests ###
#####################

### Assignment 4 random tests:
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

### End assignment 4 random tests

### Assignment 3 unit tests:
#testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
#	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
#
##Testing isGameOver
#unittest1: unittest1.c dominion.o rngs.o
#	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
#
##Testing updateCoins
#unittest2: unittest2.c dominion.o rngs.o
#	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
#
##Testing supplyCount
#unittest3: unittest3.c dominion.o rngs.o
#	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
#
##Testing numHandCards
#unittest4: unittest4.c dominion.o rngs.o
#	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
#
##Testing Smithy
#cardtest1: cardtest1.c dominion.o rngs.o
#	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
#
##Testing Adventurer
#cardtest2: cardtest2.c dominion.o rngs.o
#	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
#
##Testing Council Room
#cardtest3: cardtest3.c dominion.o rngs.o
#	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
#
##Testing Village
#cardtest4: cardtest4.c dominion.o rngs.o
#	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
### End assignment 3

### End unit tests ###
######################


### Run tests ###
#################

### Assignment 4
randomtestresult.out: randomtestadventurer randomtestcard1 randomtestcard2

	./randomtestadventurer &> randomtestresult.out
	gcov dominion.c >> randomtestresult.out
	cat dominion.c.gcov >> randomtestresult.out
	echo "Random Test Adventurer Summary" >> randomtestresult.out
	echo "Adventurer stats" >> randomtestresult.out
	gcov -abcfu dominion.c | sed -n '/play_adventurer/{n;p; n;p; n;p; n;p}' >> randomtestresult.out

	./randomtestcard1 >> randomtestresult.out
	gcov dominion.c >> randomtestresult.out
	cat dominion.c.gcov >> randomtestresult.out
	echo "Random Test Card 1 Smithy Summary" >> randomtestresult.out
	echo "Smithy stats" >> randomtestresult.out
	gcov -abcfu dominion.c | sed -n '/play_smithy/{n;p; n;p; n;p; n;p}' >> randomtestresult.out

	./randomtestcard2 >> randomtestresult.out
	gcov dominion.c >> randomtestresult.out
	cat dominion.c.gcov >> randomtestresult.out
	echo "Random Test Card 2 Village Summary" >> randomtestresult.out
	echo "Village stats" >> randomtestresult.out
	gcov -abcfu dominion.c | sed -n '/play_village/{n;p; n;p; n;p; n;p}' >> randomtestresult.out

randomtestcard1.out: randomtestcard1 

	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	echo "Random Test Card 1 Smithy Summary" >> randomtestcard1.out
	echo "Smithy stats" >> randomtestcard1.out
	gcov -abcfu dominion.c | sed -n '/play_smithy/{n;p; n;p; n;p; n;p}' >> randomtestcard1.out

randomtestcard2.out: randomtestcard2 

	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	echo "Random Test Card 2 Village Summary" >> randomtestcard2.out
	echo "Village stats" >> randomtestcard2.out
	gcov -abcfu dominion.c | sed -n '/play_village/{n;p; n;p; n;p; n;p}' >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer 

	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	echo "Random Test Adventurer Summary" >> randomtestadventurer.out
	echo "Adventurer stats" >> randomtestadventurer.out
	gcov -abcfu dominion.c | sed -n '/play_adventurer/{n;p; n;p; n;p; n;p}' >> randomtestadventurer.out

#	./cardtest1 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 1 Summary" >> unittestresult.out
#	echo "Smithy stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_smithy/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./cardtest2 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 2 Summary" >> unittestresult.out
#	echo "Adventurer stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_adventurer/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
### End assignment 4

### Assignment 3 
#unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
#	./unittest1 &> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Unit Test 1 Summary" >> unittestresult.out
#	echo "isGameOver stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/isGameOver/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./unittest2 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Unit Test 2 Summary" >> unittestresult.out
#	echo "updateCoins stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/updateCoins/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./unittest3 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Unit Test 3 Summary" >> unittestresult.out
#	echo "supplyCount stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/updateCoins/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./unittest4 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Unit Test 4 Summary" >> unittestresult.out
#	echo "numHandCards stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/numHandCards/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./cardtest1 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 1 Summary" >> unittestresult.out
#	echo "Smithy stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_smithy/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./cardtest2 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 2 Summary" >> unittestresult.out
#	echo "Adventurer stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_adventurer/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./cardtest3 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 3 Summary" >> unittestresult.out
#	echo "Council Room stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_council_room/{n;p; n;p; n;p; n;p}' >> unittestresult.out
#
#	./cardtest4 >> unittestresult.out
#	gcov dominion.c >> unittestresult.out
#	cat dominion.c.gcov >> unittestresult.out
#	echo "Card Test 4 Summary" >> unittestresult.out
#	echo "Village stats" >> unittestresult.out
#	gcov -abcfu dominion.c | sed -n '/play_village/{n;p; n;p; n;p; n;p}' >> unittestresult.out
### End assignment 3

### End run tests ###
#####################

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2
