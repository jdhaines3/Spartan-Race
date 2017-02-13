#include <iostream>
#include <stdlib.h> 
#include <ctime>

#define RACE_LENGTH 50

void advanceRacerA(int* ptrRacerA);
/*void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);*/

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
	
	return;
}
	
	
	
int main()
{
	//set ptr's to zero for starting position
	
	int* ptrRacerA;
	int* ptrRacerB;
	
	int racerA, racerB;
	
	ptrRacerA = &racerA;
	ptrRacerB = &racerB;
	
	*ptrRacerA = 0;
	*ptrRacerB = 0;
	
	//char array for race in order to print later
	std::string race(RACE_LENGTH, ' ');
	
	int keepGoing = 0;
	
	//while loop to repeat until someone wins
	while (keepGoing == 0) {
		
		advanceRacerA (ptrRacerA);
		
		/*//test fill array with white space plus end line
		race[ptrRacerA] = 'A';
		
		std::cout << race + '|' << std::endl;*/
		std::cout << *ptrRacerA << std::endl;
		keepGoing = 1;
	

	}
	
	return 0;
}
