// by Xalvi :]
#include <iostream>
#include <string>
#define K 10
#define Q 10
#define J 10
#define A 11
int Got_A();

void Out(std::string description, int outfile)
{
	std::cout << std::endl << description << "\t" << outfile << std::endl;
}

int Picked_Card(const int cards[])
{
	int Pickd_Card = cards[rand() % 13];
	if (Pickd_Card == A)
		Pickd_Card = Got_A();
	std::cout << "\nPicked up card:\t" << Pickd_Card << std::endl;
	return Pickd_Card;
}

int Conclusion(int Plr1, int Plr2)
{
	if (Plr1 > Plr2)
	{
		return 1;
	}
	if (Plr2 > Plr1)
	{
		return 2;
	}
	if (Plr1 == Plr2)
	{
		return 0;
	}
}

int Pick_or_no()
{
	int yes_no = 0;
	std::cout << "\nYou want to take another one card?\n\"1\" = Yes\n\"0\" = No\n";
	std::cin >> yes_no;
	if (yes_no == 1)
		return 1;
	else if (yes_no == 0)
		return 0;
	else
	{
		std::cout << "\n Wrong number!";
		return Pick_or_no();
	}
}

int Got_A()
{
	int A_Data = 0;
	std::cout << "\nYou got \"A\", pick the value of the card: \"1\" or \"11\":";
	std::cin >> A_Data;
	if (A_Data == 11)
		return 11;
	else if (A_Data == 1)
		return 1;
	else
	{
		std::cout << "\nWrong number!\n";
		return Got_A();
	}
}

std::string Black_Jack() // Main fuction :]
{
	//cards types and some stuff...

	const int cards_number = 13;
	const int cards[cards_number]{ 2,3,4,5,6,7,8,9,10,J,Q,K,A };

	// Player 1 and start cards.

	int Player_1 = 0;
	int Plr_1_StartCards[2]{ 0,0 };
	Plr_1_StartCards[0] = cards[rand() % 13]; // card 1.
	Plr_1_StartCards[1] = cards[rand() % 13]; // card 2.

	std::cout << "First starter card:\t" << (Plr_1_StartCards[0] == 11 ? "A" : std::to_string(Plr_1_StartCards[0])) << std::endl;
	std::cout << "Second starter card:\t" << (Plr_1_StartCards[1] == 11 ? "A" : std::to_string(Plr_1_StartCards[1])) << std::endl;

	if (Plr_1_StartCards[0] == A)
	{
		Plr_1_StartCards[0] = Got_A();
		std::cout << "First card after \"A\":\t" << Plr_1_StartCards[0] << std::endl;
	}
	if (Plr_1_StartCards[1] == A)
	{
		Plr_1_StartCards[1] = Got_A();
		Out("Second card after \"A\":\t", Plr_1_StartCards[1]);
	}

	// Player 1 start cards value

	Player_1 = Plr_1_StartCards[0] + Plr_1_StartCards[1];
	std::cout << "Player 1 total:\t" << Player_1 << std::endl;

	// Player 1 pickable cards.

	while (Player_1 < 21) // Pick up card.
	{
		if (Pick_or_no() == 1)
		{
			Player_1 += Picked_Card(cards);
			std::cout << "Player 1 total after picking up the card:\t" << Player_1 << std::endl;
		}
		else
			break;
	}

	std::cout << "\n Player 1 total:\t" << Player_1 << "\nConclusion:";
	if (Player_1 == 21)
		std::cout << "\nYou got maximum value! (21/21)\n";
	else if (Player_1 > 21)
	{
		std::cout << "\nYou have more than you need!(" << Player_1 << "/21)\n";
		std::cout << "\nPlayer 2 Won!\n";
		return "Player 2 Won!";
	}
	else
		std::cout << "You have: (" << Player_1 << "/21)\n";

	// Player 2 and start cards.
	std::cout << "\nPlayer 2!\n";
	int Player_2 = 0;
	int Plr_2_StartCards[2]{ 0,0 };

	Plr_2_StartCards[0] = cards[rand() % 13]; // card 1.
	Plr_2_StartCards[1] = cards[rand() % 13]; // card 2.
	std::cout << "First starter card:\t" << (Plr_2_StartCards[0] == 11 ? "A" : std::to_string(Plr_2_StartCards[0])) << "\n";
	std::cout << "Second starter card:\t" << (Plr_2_StartCards[1] == 11 ? "A" : std::to_string(Plr_2_StartCards[1])) << "\n";

	if (Plr_2_StartCards[0] == A)
	{
		Plr_2_StartCards[0] = Got_A();
		std::cout << "First card after \"A\":\t" << Plr_2_StartCards[0] << std::endl;
	}

	if (Plr_2_StartCards[1] == A)
	{
		Plr_2_StartCards[1] = Got_A();
		std::cout << "Second card after \"A\":\t" << Plr_2_StartCards[1] << std::endl;
	}
	// Player 2 start cards value

	Player_2 = Plr_2_StartCards[0] + Plr_2_StartCards[1];
	std::cout << "Player 2 total:\t" << Player_2;

	// Player 2 pickable cards.

	while (Player_2 < 21) // Pick up card.
	{
		if (Pick_or_no() == 1)
		{
			Player_2 += Picked_Card(cards);
			std::cout << "Player 2 total after picking up the card:\t" << Player_2 << std::endl;
		}
		else
			break;
	}

	std::cout << "\n Player 2 total:\t" << Player_2 << "\nConclusion:";
	if (Player_2 == 21)
		std::cout << "\nYou got maximum value! (21/21)\n";
	else if (Player_2 > 21)
	{
		std::cout << "\nYou have more than you need!(" << Player_2 << "/21)\n";
		std::cout << "\nPlayer 1 Won!\n";
		return "Player 1 Won!";
	}
	else
		std::cout << "You have: (" << Player_2 << "/21)\n";

	//Finally... Conclusion!!!
	if (Conclusion(Player_1, Player_2) == 1)
	{
		std::cout << "Player 1 won!:\t(" << Player_1 << " > " << Player_2 << ")\n";
		return "Player 1 won!";
	}
	if (Conclusion(Player_1, Player_2) == 2)
	{
		std::cout << "Player 2 won!:\t(" << Player_2 << " > " << Player_1 << ")\n";
		return "Player 2 won!";
	}
	if (Conclusion(Player_1, Player_2) == 0)
	{
		std::cout << "Draw!\t(" << Player_1 << " = " << Player_2 << ")\n";
		return "Draw!";
	}
	// Function end!
}
int main()
{
	srand(time(NULL));
	Black_Jack(); // <-- "main" function
	return 0;
}
