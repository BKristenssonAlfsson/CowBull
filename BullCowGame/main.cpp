#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string Guess = "";
	constexpr int WORD_LENGTH = 6;

	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Guess the isogram that has " << WORD_LENGTH << " letters in it!" << endl;

	cout << "Please, enter your guess: ";
	getline(cin, Guess);
	cout << "You guessed on the word " << Guess << endl;

	return 0;
}