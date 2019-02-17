#include <iostream>
#include <string>

using namespace std;

string Guess = "";
constexpr int WORD_LENGTH = 6;

void Intro();
string GetGuess();

int main() {
	
	Intro();

	GetGuess();

	cout << "You guessed on the word " << Guess << endl;

	return 0;
}

void Intro() {
	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Guess the isogram that has " << WORD_LENGTH << " letters in it!" << endl;

	return;
}

string GetGuess() {
	cout << "Please, enter your guess: ";
	getline(cin, Guess);
	return Guess;
}
