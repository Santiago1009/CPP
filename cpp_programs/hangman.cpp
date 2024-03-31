#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <string>
using namespace std;

class Hangman
{

private:
	string words[20] = {
		"dog", "cat", "house", "tree", "ball",
		"car", "book", "computer", "beach", "valley",
		"sun", "moon", "star", "cloud", "river",
		"sea", "city", "plane", "train", "bicycle"};

public:
	int index;
	string systemWord;

	// Constructor
	Hangman()
	{
		int in = 0 + rand() % (21 - 0);

		this->index = in;
		this->systemWord = words[index];
		cout << endl
			 << "Initializing data..." << endl;
	}

	// Destructor
	~Hangman() { cout << endl
					  << "Deleting data..." << endl; }

	friend ostream &operator<<(ostream &os, const Hangman &hangman)
	{
		os << endl
		   << "The word was: " << hangman.systemWord << endl;
		return os;
	}
};

class Game : public Hangman
{

private:
	string userWord;
	char letter;
	int lives;
	list<char> guessedLetters;
	list<char> wrongLetters;

public:
	// Constructor
	Game()
	{
		lives = 5;
		guessedLetters.clear();
		wrongLetters.clear();

		for (int i = 0; i < systemWord.length(); i++)
			userWord += "_";
	}

	void start()
	{
		cout << "=============\n";
		cout << "SPECIAL HANGMAN \n";
		cout << "=============\n";
		cout << "Instructions: Don't let the aliens abduct the little monkey, guess the word.\n";
	}

	// Method for the user to guess a letter
	char guessLetter()
	{
		char attempt;
		cout << endl
			 << "Enter a letter: ";
		cin >> attempt;
		this->letter = attempt;
		return attempt;
	}

	// Method to check if the guessed letter is in the word
	void checkLetter(char let)
	{
		bool correct = false;
		for (int i = 0; i < systemWord.length(); i++)
		{
			if (let == systemWord[i])
			{
				userWord[i] = let;
				guessedLetters.push_back(let);
				correct = true;
			}
		}
		if (!correct)
		{
			wrongLetters.push_back(let);
			lives--;
		}
	}

	// Method to print the current state of the game
	void printState()
	{
		cout << endl
			 << "Incorrect letters: " << endl;
		for (auto it = wrongLetters.begin(); it != wrongLetters.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl
			 << "Lives: " << lives << endl;
		cout << endl
			 << "Word to guess: " << endl;

		for (int i = 0; i < userWord.length(); i++)
			cout << userWord[i] << " ";
	}

	// Method to check if the game has ended
	bool gameEnded()
	{
		return (lives == 0 || userWord == systemWord);
	}

	void end()
	{
		if (Hangman::systemWord == userWord)
			cout << endl
				 << "You did it! You saved the little monkey" << endl;
		else
			cout << endl
				 << "You couldn't save the little monkey :c " << endl;
	}

	void displayHangman()
	{
		if (this->lives == 5)
		{
			cout << "                  .                           \n";
			cout << "                  |                           \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    '-----------..  \n";
			cout << "              /     \\        (  HELP! )  \n";
			cout << "             /   0   \\      / '-----------'   \n";
			cout << "            /  --|--  \\    /                  \n";
			cout << "           /     |     \\                      \n";
			cout << "          /     / \\     \\                     \n";
			cout << "         /               \\                    \n";
		}
		else if (this->lives == 4)
		{
			cout << "                 .                            \n";
			cout << "                 |                            \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    ,-----------..  \n";
			cout << "              /  0  \\        (  HELP! )  \n";
			cout << "             / --|-- \\      / `-----------'   \n";
			cout << "            /    |    \\    /                  \n";
			cout << "           /    / \\    \\                      \n";
			cout << "          /             \\                     \n";
			cout << "         /               \\                    \n";
		}
		else if (this->lives == 3)
		{
			cout << "                 .                            \n";
			cout << "                 |                            \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    ,-----------..  \n";
			cout << "              /--|--\\        (  HELP! ) \n";
			cout << "             /   |   \\      / `-----------'  \n";
			cout << "            /   / \\   \\    /                 \n";
			cout << "           /           \\                     \n";
			cout << "          /             \\                    \n";
			cout << "         /               \\                   \n";
		}
		else if (this->lives == 2)
		{
			cout << "                 .                            \n";
			cout << "                 |                            \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    ,-----------..  \n";
			cout << "              /  |  \\        (  HELP! ) \n";
			cout << "             /  / \\  \\      / `-----------'  \n";
			cout << "            /         \\    /                 \n";
			cout << "           /           \\                     \n";
			cout << "          /             \\                    \n";
			cout << "         /               \\                   \n";
		}
		else if (this->lives == 1)
		{
			cout << "                 .                            \n";
			cout << "                 |                            \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    ,-----------..  \n";
			cout << "              / / \\ \\        (  HELP! ) \n";
			cout << "             /       \\      / `-----------'  \n";
			cout << "            /         \\    /                 \n";
			cout << "           /           \\                     \n";
			cout << "          /             \\                    \n";
			cout << "         /               \\                   \n";
		}
		else if (this->lives == 0)
		{
			cout << "                 .                            \n";
			cout << "                 |                            \n";
			cout << "              .-\"^\"-.                       \n";
			cout << "             /_....._\\                       \n";
			cout << "         .-\"`         `\"-.                  \n";
			cout << "        (  ooo  ooo  ooo  )                   \n";
			cout << "         '-.,_________,.-'    ,-----------..  \n";
			cout << "              /     \\        (     :(      ) \n";
			cout << "             /       \\      / `-----------'  \n";
			cout << "            /         \\    /                 \n";
			cout << "           /           \\                     \n";
			cout << "          /             \\                    \n";
			cout << "         /               \\                   \n";
		}
	}
};

int main()
{
	srand(time(NULL));
	int choice = 1;

	while (choice == 1)
	{
		Game game;

		while (!game.gameEnded())
		{
			system("cls");

			game.start();
			game.displayHangman();
			game.printState();
			char letter = game.guessLetter();
			game.checkLetter(letter);
		}

		if (game.gameEnded())
		{
			system("cls");

			game.start();
			game.displayHangman();
			game.printState();
		}

		game.end();
		cout << game << endl;
		cin.ignore();
		cout << "Do you want to play again? (1 = Yes, 0 = No): ";
		cin >> choice;
	}

	return 0;
}
