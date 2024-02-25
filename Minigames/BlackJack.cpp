// by Xalvi [:
#include <iostream>
#include <string>

#define K 10
#define Q 10
#define J 10
#define A 11

int Got_A();

int Picked_Card(const int cards[])
{
	int Pickd_Card = cards[rand() % 13];
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

std::string Black_Jack() // Main fuction :]
{
	//cards types and some stuff...

	const int cards_number = 13;
	const int cards[cards_number]{ 2,3,4,5,6,7,8,9,10,J,Q,K,A };

	// Player 1 and start cards.

	int Player_1_Data = 0;
	int Player_1 = 0;
	int Plr_1_StartCards[2]{ 0,0 };
	int Amount_1 = 2;
	// Player 1 start cards value
	Plr_1_StartCards[0] = cards[rand() % 13]; // card 1.
	Plr_1_StartCards[1] = cards[rand() % 13]; // card 2.
	// Player 1 Cards stuff....
	int* Cards_1 = new int[Amount_1];
	Cards_1[0] = Plr_1_StartCards[0];
	Cards_1[1] = Plr_1_StartCards[1];
	std::cout << "\n--------------------\n";
	std::cout << "First starter card:\t" << (Plr_1_StartCards[0] == 11 ? "A" : std::to_string(Plr_1_StartCards[0])) << std::endl;
	std::cout << "Second starter card:\t" << (Plr_1_StartCards[1] == 11 ? "A" : std::to_string(Plr_1_StartCards[1])) << std::endl;

	// Player 1 pickable cards.

	while (true) // Pick up card.
	{
		if (Pick_or_no() == 1)
		{
			int Picked_Data = Picked_Card(cards);
			Amount_1++;
			Cards_1[Amount_1 - 1] = Picked_Data;
			std::cout << "\nYour cards now:\t";
			Out_Arr(Cards_1, Amount_1);
		}
		else
			break;
	}

	std::cout << "\n Player 1 total:\t" << std::endl;
	for (int i = 0; i < Amount_1; i++)
	{
		if (i + 1 == Amount_1)
			std::cout << (Cards_1[i] == A ? "A" : std::to_string(Cards_1[i])) << "." << std::endl << "---------------------------------\n";
		else
			std::cout << (Cards_1[i] == A ? "A" : std::to_string(Cards_1[i])) << ",\t";
	}

	if (Check_A(Cards_1, Amount_1) == 1)
	{
		while (Check_A(Cards_1, Amount_1) == 1)
		{
			for (int i = 0;i < Amount_1;i++)
			{
				if (Cards_1[i] == A)
				{
					Cards_1[i] = Choose_A(Cards_1, Amount_1);
				}
			}
		}
	}
	for (int i = 0; i < Amount_1; i++)
	{
		if (Cards_1[i] == 12)
			Player_1 += 11;
		else
			Player_1 += Cards_1[i];
	}
	std::cout << "\nTotal value:\t" << Player_1 << std::endl;

	if (Player_1 == 21)
		std::cout << "\nYou got maximum value! (21/21)\n";
	else if (Player_1 > 21)
	{
		std::cout << "\nYou have more than you need!(" << Player_1 << "/21)\n";
		std::cout << "\nYou better hope the 2nd player has a little too much!\n";

	}
	else
		std::cout << "You have: (" << Player_1 << "/21)\n";

	Player_1_Data = Player_1;
	std::cout << "\n\nRemember your value!\n\n------" << Player_1 << "------\n\n";
	std::cout << "\n--------------------\n";
	system("pause");
	system("cls");

	// Player 2 and start cards.

	int Player_2_Data = 0;
	int Player_2 = 0;
	int Plr_2_StartCards[2]{ 0,0 };
	int Amount_2 = 2;
	// Player 2 start cards value
	Plr_2_StartCards[0] = cards[rand() % 13]; // card 1.
	Plr_2_StartCards[1] = cards[rand() % 13]; // card 2.
	// Player 2 Cards stuff....
	int* Cards_2 = new int[Amount_2];
	Cards_2[0] = Plr_2_StartCards[0];
	Cards_2[1] = Plr_2_StartCards[1];
	std::cout << "\n--------------------\n";
	std::cout << "First starter card:\t" << (Plr_2_StartCards[0] == 11 ? "A" : std::to_string(Plr_2_StartCards[0])) << std::endl;
	std::cout << "Second starter card:\t" << (Plr_2_StartCards[1] == 11 ? "A" : std::to_string(Plr_2_StartCards[1])) << std::endl;

	// Player 2 pickable cards.

	while (true) // Pick up card.
	{
		if (Pick_or_no() == 1)
		{
			int Picked_Data_2 = Picked_Card(cards);
			Amount_2++;
			Cards_2[Amount_2 - 1] = Picked_Data_2;
			std::cout << "\nYour cards now:\t";
			Out_Arr(Cards_2, Amount_2);
		}
		else
			break;
	}

	std::cout << "\n Player 2 total:\t" << std::endl;
	for (int i = 0; i < Amount_2; i++)
	{
		if (i + 1 == Amount_2)
			std::cout << (Cards_2[i] == A ? "A" : std::to_string(Cards_2[i])) << "." << std::endl << "---------------------------------\n";
		else
			std::cout << (Cards_2[i] == A ? "A" : std::to_string(Cards_2[i])) << ",\t";
	}

	if (Check_A(Cards_2, Amount_2) == 1)
	{
		while (Check_A(Cards_2, Amount_2) == 1)
		{
			for (int i = 0;i < Amount_2;i++)
			{
				if (Cards_2[i] == A)
				{
					Cards_2[i] = Choose_A(Cards_2, Amount_2);
				}
			}
		}
	}
	for (int i = 0; i < Amount_2; i++)
	{
		if (Cards_2[i] == 12)
			Player_2 += 11;
		else
			Player_2 += Cards_2[i];
	}
	std::cout << "\nTotal value:\t" << Player_2 << std::endl;

	if (Player_2 == 21)
		std::cout << "\nYou got maximum value! (21/21)\n";
	else if (Player_2 > 21)
	{
		std::cout << "\nYou have more than you need!(" << Player_2 << "/21)\n";
		std::cout << "\nYou better hope the 1st player has a little too much!\n";

	}
	else
		std::cout << "You have: (" << Player_2 << "/21)\n";

	Player_2_Data = Player_2;
	system("pause");
	system("cls");
	std::cout << "\n--------------------\n";
	// Conclusion.

	if (Player_1 > 21)
		Player_1 = 0;
	if (Player_2 > 21)
		Player_2 = 0;


	if (Player_1 == 0 || Player_2 == 0)
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
	// Function end!

}
int main()
{
	srand(time(NULL));
	Black_Jack();
	return 0;
}