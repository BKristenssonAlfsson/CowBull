#include <iostream>
#include <string>

using namespace std;

string Guess = "";
constexpr int WORD_LENGTH = 6;
constexpr int amountOfGuesses = 5;


void Intro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main() {
	
	Intro();
	do {
		PlayGame();
	} while (AskToPlayAgain() == true);
	
	return 0;
}

void Intro() {
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Guess the isogram that has " << WORD_LENGTH << " letters in it!" << endl;
	cout << endl;
	return;
}

void PlayGame() {
	for (int i = 1; i <= amountOfGuesses; i++) {
		cout << "Guess number: " << i << endl;
		GetGuess();
		cout << "You guessed on the word " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() {
	cout << "Please, enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {

	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}

}
