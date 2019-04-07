#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include <ctime>

using FText = std::string;
using int32 = int;

void Intro();
void PlayGame();
void PrintGameSummary();
FText GetGuess();
bool AskToPlayAgain();
Game BCGame;

int main() {
	srand(time(nullptr));
	do {
		Intro();
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

bool is_digits(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

void Intro() {
	FString wantedLength;
	int32 convert;
	IsogramLengthChoice Choice = IsogramLengthChoice::Invalid;

	std::cout << "\nWelcome to Bulls and Cows" << std::endl;

	do {
		std::cout << "Please enter how long word you'd like to guess on. Between 2 and 17 letters in the word.";
		std::getline(std::cin, wantedLength);
		
		convert = std::stoi(wantedLength);

		Choice = BCGame.CheckIsogramLength(convert);

		switch (Choice) {
		case IsogramLengthChoice::To_Low_Number:
			std::cout << "To low number\n\n";
			break;
		case IsogramLengthChoice::To_High_Number:
			std::cout << "To High number\n\n";
			break;
		default:
			break;
		}
	} while (Choice != IsogramLengthChoice::OK);

	BCGame.getIsogram(convert);
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
		std::cout << "You have guessed right on " << BCGame.IsogramsCracked() << " isograms.\n";
		std::cout << "You have guessed " << BCGame.AmountOfGuesses() << " guesses in total.\n";
		std::cout << "Hope you had fun. See you next time :)";
		return false;
	}
}
