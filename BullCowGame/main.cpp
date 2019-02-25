#include <iostream>
#include <string>
#include "Game.h"

using FText = std::string;
using int32 = int;

void Intro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
Game BCGame;

int main() {
	
	do {
		Intro();
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

void Intro() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Guess the isogram that has " << BCGame.GetHiddenWordLength() << " letters in it!" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 amountOfGuesses = BCGame.GetMaxTries();

	for (int32 i = 1; i <= amountOfGuesses; i++) {
		FText Guess = GetGuess();

		EWordStatus Status = BCGame.CheckGuessValidity(Guess);

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess() {
	int32 CurrentGuess = BCGame.GetCurrentTry();
	FText Guess;
	std::cout << "Try " << CurrentGuess << ". Please, enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again? y/n ";
	FText Response = "";
	std::getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}
