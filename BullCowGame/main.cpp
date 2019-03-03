#include <iostream>
#include <string>
#include "Game.h"

using FText = std::string;
using int32 = int;

void Intro();
void PlayGame();
void PrintGameSummary();
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
	std::cout << "\nWelcome to Bulls and Cows" << std::endl;
	std::cout << "Guess the isogram that has " << BCGame.GetHiddenWordLength() << " letters in it!" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 amountOfGuesses = BCGame.GetMaxTries();

	while( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= amountOfGuesses ) {
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

FText GetGuess() {
	EWordStatus Status = EWordStatus::Invalid;
	FText Guess;
	do {

		int32 CurrentGuess = BCGame.GetCurrentTry();
		
		std::cout << "Try " << CurrentGuess << " of " << BCGame.GetMaxTries();
		std::cout << ". Please, enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EWordStatus::Word_To_Short:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please write your word with lowercase. \n\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Your word " << Guess << " is not an isogram. (No repeating letters) \n\n";
			break;
		default:
			break;
		}
	} while (Status != EWordStatus::OK);
	return Guess;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "You guessed right. You won. Great played!\n";
	}
	else {
		std::cout << "You failed. Better luck next time!\n";
	}
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
