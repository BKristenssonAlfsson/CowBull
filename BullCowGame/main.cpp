#include <iostream>
#include <string>
#include "Game.h"

std::string Guess = "";
constexpr int WORD_LENGTH = 6;

void Intro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
Game BCGame;

int main() {
	
	Intro();
	do {
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

void Intro() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Guess the isogram that has " << WORD_LENGTH << " letters in it!" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int amountOfGuesses = BCGame.GetMaxTries();

	for (int i = 1; i <= amountOfGuesses; i++) {
		GetGuess();
		std::cout << "You guessed on the word " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	int CurrentGuess = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentGuess << ". Please, enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? y/n ";
	std::string Response = "";
	std::getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}
