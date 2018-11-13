#include <iostream>
#include <cstdlib>
#include <ctime>

int rollDice();

int main()
{
	enum Status {CONTINUE, LOST, WON};
	Status gameStatus;

	int playerPoints;

	srand(time(0));

	int dice = rollDice();

	switch(dice)
	{
		case 7:
		case 11:
			gameStatus = WON;
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			break;
		default:
			gameStatus = CONTINUE;
			playerPoints = dice;
			break;
	}

	while(gameStatus == CONTINUE)
	{
		dice = rollDice();

		if(dice == playerPoints)
		{
			gameStatus = WON;
		}

		else
		{
			if(dice == 7)
			{
				gameStatus = LOST;
			}
		}
	}

	if(gameStatus == WON)
	{
		std::cout << "Player wins" << std::endl;
	}

	else
	{
		std::cout << "Player loses" << std::endl;
	}

	return 0;
}

int rollDice()
{
	int dice1 = 1 + rand()%6;
	int dice2 = 1 + rand()%6;

	int sum = dice1 + dice2;

	std::cout << "Player rolls " << dice1 << " + " << dice2 << " = " << sum << std::endl;

	return sum;
}