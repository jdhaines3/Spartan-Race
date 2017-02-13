#include <iostream>
#include <stdlib.h> 
#include <ctime>

#define RACE_LENGTH 50

/*void advanceRacerA(int* ptrRacerA);
void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);
*/
int main()
{
	//set ptr's to zero for starting position
	
	int* ptrRacerA;
	int* ptrRacerB;
	
	int racerA = 0, racerB = 0;
	
	ptrRacerA = &racerA;
	ptrRacerB = &racerB;
	
	
	//set obstacle name to char array in order to compare later
	std::string obstacleA = "";
	std::string obstacleB = "";
	
	//char array for race in order to print later
	std::string race(RACE_LENGTH, ' ');
	
	int keepGoing = 0;
	
	//while loop to repeat until someone wins
	while (keepGoing == 0) {
		
		//test fill array with white space plus end line
		race[5] = 'A';
		std::cout << race << std::endl;
		keepGoing = 1;
	

	}
	
	
	
	
	/* random number generator
	srand (time(NULL));
	
	obstacleNumA = rand() % 100 + 1;
	obstacleNumB = rand() % 100 + 1;
	
	std::cout << obstacleNumA << std::endl;
	std::cout << obstacleNumB << std::endl;
	*/
	return 0;
}
