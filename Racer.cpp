#include <iostream>
#include <stdlib.h> 
#include <ctime>

#define RACE_LENGTH 50

void advanceRacerA(int* ptrRacerA);
void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);

void advanceRacerA (int* ptrRacerA)
{
	//random number generator
	srand (time(NULL));
	
	int obstacleNumA;
	
	//pick number between one and 100
	obstacleNumA = rand() % 100 + 1;
	
	//determine obstacle by rand number and percentages
	if (obstacleNumA <= 30){
		*ptrRacerA = (*ptrRacerA) + 4;
	}else if(31 <= obstacleNumA && obstacleNumA <= 40) {
		*ptrRacerA = (*ptrRacerA) + 5;
	}else if(41 <= obstacleNumA && obstacleNumA <= 70) {
		*ptrRacerA = (*ptrRacerA) - 2;
	}else if(71 <= obstacleNumA && obstacleNumA <= 90) {
		*ptrRacerA = (*ptrRacerA) - 3;
	}else if(91 <= obstacleNumA && obstacleNumA <= 100) {
		*ptrRacerA = (*ptrRacerA) - 4;
	}
	
	//ensure value at ptrRacerA doesn't go below 0 (start of race) or above 50 (finish line)
	if (*ptrRacerA <= 0) {
		*ptrRacerA = 0;
	}else if (*ptrRacerA >= RACE_LENGTH) {
		*ptrRacerA = RACE_LENGTH;
	}
	
	return;
}
	
void advanceRacerB (int* ptrRacerB)
{
	//random number generator
	srand (time(NULL));
	
	int obstacleNumB;
	
	//pick number between one and 100
	obstacleNumB = rand() % 100 + 1;
	
	//determine obstacle by rand number and percentages
	//percentages will be different for B as well as int change of value at pointer
	if (obstacleNumB <= 40){
		*ptrRacerB = (*ptrRacerB) + 5;
	}else if(41 <= obstacleNumB && obstacleNumB <= 50) {
		*ptrRacerB = (*ptrRacerB) + 6;
	}else if(51 <= obstacleNumB && obstacleNumB <= 70) {
		*ptrRacerB = (*ptrRacerB) - 1;
	}else if(71 <= obstacleNumB && obstacleNumB <= 90) {
		*ptrRacerB = (*ptrRacerB) - 2;
	}else if(91 <= obstacleNumB && obstacleNumB <= 100) {
		*ptrRacerB = (*ptrRacerB) - 4;
	}
	
	//similar space constraints as ptrRacerA
	if (*ptrRacerB <= 0) {
		*ptrRacerB = 0;
	}else if (*ptrRacerB >= RACE_LENGTH) {
		*ptrRacerB = RACE_LENGTH;
	}
	
	return;
}	
	
void printPosition(int* ptrRacerA, int* ptrRacerB)
{

	//char array for race in order to print later
	std::string race(RACE_LENGTH + 1, ' ');
	//set last char in race to finish line
	race[RACE_LENGTH] = '|';
	
	//set position of racerA to the race's index value of *ptrRacerA; same with racerB
	race[*ptrRacerA] = 'A';
	race[*ptrRacerB] = 'B';
	
	//print line
	std::cout << race << std::endl;
	
	//due to while loop in main, race will re-initialize as all white spaces in order to clear last turn
	return;
}

int main()
{
	//call pointer ints for each racer
	int* ptrRacerA;
	int* ptrRacerB;

	//call racer ints that the pointers will point to the address of
	int racerA, racerB;
	
	ptrRacerA = &racerA;
	ptrRacerB = &racerB;
	
	//set value of pointers to 0 to start
	*ptrRacerA = 0;
	*ptrRacerB = 0;
	
	//keepGoing variable in order to exit while loop
	int keepGoing = 0;
	
	//while loop to repeat turns until someone wins
	while (keepGoing == 0) {
		
		//start turns to advance racers
		advanceRacerA (ptrRacerA);
		advanceRacerB (ptrRacerB);
		
		/*make sure both aren't zero, because print function won't work correctly;
		also make sure they both aren't on same space. move A back one if so. if both are zero,
		move B forward 1 instead*/
		if (*ptrRacerA == 0 && *ptrRacerB == 0){
			*ptrRacerB = 1;
		}else if(*ptrRacerA == *ptrRacerB) {
			*ptrRacerA = (*ptrRacerA) - 1;
		}
		
		//print their poisition for turn
		printPosition (ptrRacerA, ptrRacerB);
		
		//if a racer ends a turn at 50 (finish line), they win and race stops
		if (*ptrRacerA >= RACE_LENGTH) {
			keepGoing = 1;
		}else if(*ptrRacerB >= RACE_LENGTH) {
			keepGoing = 1;
		}else {
			keepGoing = 0;
		}
	

	}
	
	return 0;
}
