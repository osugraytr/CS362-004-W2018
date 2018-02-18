CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
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

assignment3_tests:

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittestresults.out		#testIsGameOver
	gcov dominion.c >> unittestresults.out		
	cat dominion.c.gcov >>  unittestresults.out
	./unittest2 >> unittestresults.out		#testCompare
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./unittest3 >> unittestresults.out		#testInitilizeGame
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./unittest4 >> unittestresults.out		#testFullDeckCount
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./cardtest1 >> unittestresults.out		#testSmithy_function  // at 10610
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./cardtest2 >> unittestresults.out		#Outpost_Switch
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./cardtest3 >> unittestresults.out		#Great_hall_Switch
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out
	./cardtest4 >> unittestresults.out		#adventure_Switch
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >>  unittestresults.out

randomtests: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestadventurer > randomtestadventurer.out		#Adventurer
	gcov dominion.c >> randomtestadventurer.out			
	cat dominion.c.gcov >> randomtestadventurer.out			
	./randomtestcard1 > randomtestcard1.out				#Great_Wall
	gcov dominion.c >> randomtestcard1.out				
	cat dominion.c.gcov >> randomtestcard1.out			
	./randomtestcard2 > randomtestcard2.out				#Smithy
	gcov dominion.c >> randomtestcard2.out				
	cat dominion.c.gcov >> randomtestcard2.out			

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer randomtestcard1 randomtestcard2 unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 
