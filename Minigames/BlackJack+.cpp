// by Xalvi [:
#include <iostream>
#include <string>

#define K 10
#define Q 10
#define J 10
#define A 11

int Got_A();

int Picked_Card(const int* cards)
{
	int Pickd_Card = cards[rand() % 52];
	if (Pickd_Card == 0)
	{
		while (Pickd_Card == 0)
		{
			Pickd_Card = cards[rand() % 52];
		}
	}
	std::cout << "Picked card:\t" << (Pickd_Card == 11 ? "A" : std::to_string(Pickd_Card)) << std::endl;
	return Pickd_Card;
}

int Pick_or_no()
{
	char yes_no;
	std::cout << "\nYou want to take another one card?\n\"y\" = Yes\n\"n\" = No\n";
	std::cin >> yes_no;
	if (yes_no == 'y' || yes_no == 'Y')
		return 1;
	else if (yes_no == 'n' || yes_no == 'N')
		return 0;
	else
	{
		std::cout << "\n Wrong symbol!";
		return Pick_or_no();
	}
}

int Got_A()
{
	int A_Data = 0;
	std::cout << "\nPick the value of the \"A\": \"1\" or \"11\":";
	std::cin >> A_Data;
	if (A_Data == 1)
		return 1;
	if (A_Data == 1)
		return 11;
	if (A_Data != 1 && A_Data != 11)
		return Got_A();
}

int Check_A(int* cards, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (cards[i] == A)
		{
			return 1;
		}
	}
	return 0;
}

int Choose_A(int* cards, int size)
{
	int Chosen = 0;
	for (int i = 0; i < size; i++)
	{
		if (cards[i] == A)
		{
			std::cout << "\nChoose \"A\" value:";
			std::cin >> Chosen;
			if (Chosen == 1)
				return 1;
			if (Chosen == 11)
				return 12;
			if (Chosen != 1 && Chosen != 11)
				return Choose_A(cards, size);
		}
	}
}

void Out_Arr(int* arr, int size)
{
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << (arr[i] == A ? "A" : std::to_string(arr[i])) << "\t";
	}
	std::cout << std::endl;
}

void Out_Full(int* arr, int size)
{
	int data = 0;
	for (size_t i = 0; i < size; i++)
	{
		data += arr[i];
	}
	std::cout << "Full value:\t" << data << std::endl;
}

int Full_Sum(int* arr, int size)
{
	int data = 0;
	for (size_t i = 0; i < size; i++)
	{
		data += arr[i];
	}
	return data;
}

void Delete_card(int*& cards, int size, int selected)
{
	for (int i = 0; i < size; i++)
	{
		if (cards[i] == selected)
		{
			cards[i] = 0;
			break;
		}
	}
}

int Player(int* cards, int cards_number)
{
	// Player and start cards.

	int Player = 0;
	int Plr_StartCards[2]{ 1,1 };
	int Amount = 2;

	// Player start cards value 

	Plr_StartCards[0] = cards[rand() % 52]; // card 1.
	Plr_StartCards[0] = 0;
	if (Plr_StartCards[0] == 0)
	{
		while (Plr_StartCards[0] == 0)
			Plr_StartCards[0] = cards[rand() % 52];
	}
	Delete_card(cards, cards_number, Plr_StartCards[0]);
	Plr_StartCards[1] = cards[rand() % 52]; // card 2.
	if (Plr_StartCards[1] == 0)
	{
		while (Plr_StartCards[1] == 0)
			Plr_StartCards[1] = cards[rand() % 52];
	}
	Delete_card(cards, cards_number, Plr_StartCards[1]);

	// Player cards stuff....

	int* Cards = new int[Amount];
	Cards[0] = Plr_StartCards[0];
	Cards[1] = Plr_StartCards[1];
	std::cout << "\n--------------------\n";
	std::cout << "First starter card:\t" << (Plr_StartCards[0] == A ? "A" : std::to_string(Plr_StartCards[0])) << std::endl;
	std::cout << "Second starter card:\t" << (Plr_StartCards[1] == A ? "A" : std::to_string(Plr_StartCards[1])) << std::endl;

	// Player pickable cards.

	while (true) // Pick up card.
	{
		if (Pick_or_no() == 1)
		{
			int Picked_Data = Picked_Card(cards);
			Amount += 1;
			Cards[Amount - 1] = Picked_Data;
			Delete_card(cards, cards_number, Picked_Data);
			std::cout << "\nYour cards now:\t";
			Out_Arr(Cards, Amount);
		}
		else
			break;
	}
	std::cout << "\n Player total:\t" << std::endl;
	for (int i = 0; i < Amount; i++)
	{
		if (i + 1 == Amount)
			std::cout << (Cards[i] == A ? "A" : std::to_string(Cards[i])) << "." << std::endl << "---------------------------------\n";
		else
			std::cout << (Cards[i] == A ? "A" : std::to_string(Cards[i])) << ",\t";
	}

	if (Check_A(Cards, Amount) == 1)
	{
		while (Check_A(Cards, Amount) == 1)
		{
			for (int i = 0;i < Amount;i++)
			{
				if (Cards[i] == A)
				{
					Cards[i] = Choose_A(Cards, Amount);
				}
			}
		}
	}
	for (int i = 0; i < Amount; i++)
	{
		if (Cards[i] == 12)
			Player += 11;
		else
			Player += Cards[i];
	}
	std::cout << "\nTotal value:\t" << Player << std::endl;

	if (Player == 21)
		std::cout << "\nYou got maximum value! (21/21)\n";
	else if (Player > 21)
	{
		std::cout << "\nYou have more than you need!(" << Player << "/21)\n";
	}
	else
		std::cout << "You have: (" << Player << "/21)\n";

	std::cout << "\n\nRemember your value!\n\n------" << Player << "------\n\n";
	std::cout << "\n--------------------\n";

	system("pause");
	system("cls");

	return Player;
}

std::string Black_Jack_Plus() // Main fuction
{
	// BlackJack+ feature.
	// How many players chosing.

	int players = 0;
	std::cout << "\nHow many players will play? (2 or 3 or 4)";
	std::cin >> players;
	while (players != 2 && players != 3 && players != 4)
	{
		if (players != 2 && players != 3 && players != 4)
		{
			std::cout << "\nWrong number!\n";
		}
		std::cin >> players;

	}
	std::cout << std::endl << players;
	//cards types and some stuff...

	const int cards_number = 52;
	int cards[cards_number]{ 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, J, J, J, J, Q, Q, Q, Q, K, K, K, K, A, A, A, A };

	// Players

	int	Player_1 = Player(cards, cards_number);
	int Player_1_Data = Player_1;
	if (Player_1 > 21)
		Player_1 = 0;

	int Player_2 = Player(cards, cards_number);
	int Player_2_Data = Player_2;
	if (Player_2 > 21)
		Player_2 = 0;

	int Player_3 = 0;
	int Player_3_Data = 0;
	int Player_4 = 0;
	int Player_4_Data = 0;
	Player_4 = 0;

	if (players == 3)
	{
		Player_3 = Player(cards, cards_number);
		Player_3_Data = Player_3;
		if (Player_3 > 21)
			Player_3 = 0;
	}
	if (players == 4)
	{
		Player_3 = Player(cards, cards_number);
		Player_3_Data = Player_3;
		if (Player_3 > 21)
			Player_3 = 0;
		Player_4 = Player(cards, cards_number);
		Player_4_Data = Player_4;
		if (Player_4 > 21)
			Player_4 = 0;
	}

	// Conclusion

	if (players == 2)
	{
		if (Player_1 == 0 && Player_2 == 0)
		{
			std::cout << "\n\t Both players have more than 21.\n\t" << "( " << Player_1_Data << "/21 | " << Player_2_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Both have more than needed.";
		}
		if (Player_1 > Player_2)
		{
			std::cout << "\n\t Player 1 won!\n\t( " << Player_1_Data << "/21 > " << Player_2_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 won!";
		}
		if (Player_2 > Player_1)
		{
			std::cout << "\n\t Player 2 won!\n\t( " << Player_1_Data << "/21 < " << Player_2_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 won!";
		}
		if (Player_2 == Player_1)
		{
			std::cout << "\n\t Draw.\n( " << Player_1_Data << " = " << Player_2_Data << " )\n";
			std::cout << "\n--------------------\n";
			return "Draw.";
		}
	}
	if (players == 3)
	{
		if (Player_1 == 0 && Player_2 == 0 && Player_3 == 0) // ALL MORE 21
		{
			std::cout << "\n\t All players have more than 21.\n\t" << "( " << Player_1_Data << "/21 | " << Player_2_Data << "/21 | " << Player_3_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "All have more than needed.";
		}
		if (Player_1 == Player_2 && Player_1 > Player_3)
		{
			std::cout << "\n\t Player 1 and Player 2 won!\n\t( " << Player_1_Data << "/21 = " << Player_2_Data << "/21 > " << Player_3_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 and Player 2 won!";
		}
		if (Player_2 == Player_3 && Player_2 > Player_1)
		{
			std::cout << "\n\t Player 2 and Player 3 won!\n\t( " << Player_2_Data << "/21 = " << Player_3_Data << "/21 > " << Player_1_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 and Player 3 won!";
		}
		if (Player_1 == Player_3 && Player_1 > Player_2)
		{
			std::cout << "\n\t Player 1 and Player 3 won!\n\t( " << Player_1_Data << "/21 = " << Player_3_Data << "/21 > " << Player_2_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 and Player 3 won!";
		}
		if (Player_1 > Player_2 && Player_1 > Player_3) // PLR1 BIGGEST
		{
			std::cout << "\n\t Player 1 won!\n\t( " << Player_1_Data << "/21 > " << Player_2_Data << "/21 | " << Player_3_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 won!";
		}
		if (Player_2 > Player_1 && Player_2 > Player_3) // PLR2 BIGGEST
		{
			std::cout << "\n\t Player 2 won!\n\t( " << Player_2_Data << "/21 > " << Player_1_Data << "/21 | " << Player_3_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 won!";
		}
		if (Player_3 > Player_1 && Player_3 > Player_2) // PLR3 BIGGEST
		{
			std::cout << "\n\t Player 3 won!\n\t( " << Player_3_Data << "/21 > " << Player_1_Data << "/21 | " << Player_2_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 3 won!";
		}
		if (Player_2 == Player_1 && Player_2 == Player_3 && Player_1 == Player_3) // DRAW
		{
			std::cout << "\n\t Draw.\n( " << Player_1_Data << " = " << Player_2_Data << " = " << Player_3_Data << " )\n";
			std::cout << "\n--------------------\n";
			return "Draw.";
		}
	}
	if (players == 4)
	{
		if (Player_1 == 0 && Player_2 == 0 && Player_3 == 0 && Player_4 == 0) // ALL MORE 21
		{
			std::cout << "\n\t All players have more than 21.\n\t" << "( " << Player_1_Data << "/21 | " << Player_2_Data << "/21 | " << Player_3_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "All have more than needed.";
		}
		if (Player_1 == Player_2 && Player_1 > Player_3 && Player_1 > Player_4)
		{
			std::cout << "\n\t Player 1 and Player 2 won!\n\t( " << Player_1_Data << "/21 = " << Player_2_Data << "/21 > " << Player_3_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 and Player 2 won!";
		}
		if (Player_2 == Player_3 && Player_2 > Player_1 && Player_2 > Player_4)
		{
			std::cout << "\n\t Player 2 and Player 3 won!\n\t( " << Player_2_Data << "/21 = " << Player_3_Data << "/21 > " << Player_1_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 and Player 3 won!";
		}
		if (Player_1 == Player_3 && Player_1 > Player_2 && Player_1 > Player_4)
		{
			std::cout << "\n\t Player 1 and Player 3 won!\n\t( " << Player_1_Data << "/21 = " << Player_3_Data << "/21 > " << Player_2_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 and Player 3 won!";
		}
		if (Player_1 == Player_4 && Player_1 > Player_2 && Player_1 > Player_3)
		{
			std::cout << "\n\t Player 1 and Player 4 won!\n\t( " << Player_1_Data << "/21 = " << Player_4_Data << "/21 > " << Player_2_Data << "/21" << Player_3_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 and Player 4 won!";
		}
		if (Player_2 == Player_4 && Player_2 > Player_3 && Player_2 > Player_1)
		{
			std::cout << "\n\t Player 2 and Player 4 won!\n\t( " << Player_2_Data << "/21 = " << Player_4_Data << "/21 > " << Player_3_Data << "/21" << Player_1_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 and Player 4 won!";
		}
		if (Player_3 == Player_4 && Player_3 > Player_1 && Player_3 > Player_2)
		{
			std::cout << "\n\t Player 3 and Player 4 won!\n\t( " << Player_3_Data << "/21 = " << Player_4_Data << "/21 > " << Player_2_Data << "/21" << Player_1_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 3 and Player 4 won!";
		}
		if (Player_1 > Player_2 && Player_1 > Player_3 && Player_1 > Player_4) // PLR1 BIGGEST
		{
			std::cout << "\n\t Player 1 won!\n\t( " << Player_1_Data << "/21 > " << Player_2_Data << "/21 | " << Player_3_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 1 won!";
		}
		if (Player_4 > Player_2 && Player_4 > Player_3 && Player_4 > Player_1) // PLR4 BIGGEST
		{
			std::cout << "\n\t Player 1 won!\n\t( " << Player_1_Data << "/21 > " << Player_2_Data << "/21 | " << Player_3_Data << "/21 | " << Player_4_Data << "/21 )\n";
			return "Player 4 won!";
		}
		if (Player_2 > Player_1 && Player_2 > Player_3 && Player_2 > Player_4) // PLR2 BIGGEST
		{
			std::cout << "\n\t Player 2 won!\n\t( " << Player_2_Data << "/21 > " << Player_1_Data << "/21 | " << Player_3_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 2 won!";
		}
		if (Player_3 > Player_1 && Player_3 > Player_2 && Player_3 > Player_4) // PLR3 BIGGEST
		{
			std::cout << "\n\t Player 3 won!\n\t( " << Player_3_Data << "/21 > " << Player_1_Data << "/21 | " << Player_2_Data << "/21 | " << Player_4_Data << "/21 )\n";
			std::cout << "\n--------------------\n";
			return "Player 3 won!";
		}
		if (Player_2 == Player_1 && Player_2 == Player_3 && Player_1 == Player_3 && Player_1 == Player_4 && Player_2 == Player_4 && Player_3 == Player_4) // DRAW
		{
			std::cout << "\n\t Draw.\n( " << Player_1_Data << " = " << Player_2_Data << " = " << Player_3_Data << Player_4_Data << " )\n";
			std::cout << "\n--------------------\n";
			return "Draw.";
		}
	}
}

int main()
{
	srand(time(NULL));
	Black_Jack_Plus();
	return 0;
}