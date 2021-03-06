#pragma once
#include "Game.h"
#include <stdlib.h>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#define TMap std::map

using int32 = int;

Game::Game()
{
	Reset();
}

int32 Game::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ 
		{2, 3},
		{3, 5}, 
		{4, 8}, 
		{5, 12}, 
		{6, 18},
		{7, 23},
		{8, 28},
		{9, 32},
		{10, 36},
		{11, 40},
		{12, 44},
		{13, 48},
		{14, 52},
		{15, 56},
		{16, 60},
		{17, 60}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 Game::GetCurrentTry() const { return MyCurrentTry; }

int32 Game::GetHiddenWordLength() const { return MyHiddenWord.length();  }

FString Game::getIsogram(int32 Wordlength)
{
	std::ifstream file("Isograms.txt");
	std::string wordInFile;
	std::vector<FString> words;

	/*
	while (std::getline(file, wordInFile)) {
		if (wordInFile.length() == Wordlength) {
			std::cout << "str: " << wordInFile << std::endl;
			words.push_back(wordInFile);
		}
	}
	*/

	for (std::string wordInFile; std::getline(file, wordInFile);)
	{
		if (wordInFile.length() == Wordlength)
		{
			std::cout << "str: " << wordInFile << std::endl;
			words.push_back(wordInFile);
		}
	}

	int32 randomWord = rand() % words.size();

	const FString HIDDEN_WORD = words[randomWord];
	MyHiddenWord = HIDDEN_WORD;
	return MyHiddenWord;
}

bool Game::IsGameWon() const { return bGameIsWon; }

void Game::Reset()
{
	bGameIsWon = false;
	MyCurrentTry = 1;
}

int32 Game::AmountOfGuesses() 
{
	return Guesses;
}

int32 Game::IsogramsCracked()
{
	return IsogramGuessedRight;
}

IsogramLengthChoice Game::CheckIsogramLength(int32 SelectedLength) const
{
	if (SelectedLength == -1) {
		return IsogramLengthChoice::Not_Number;
	}
	else if (!IsToLowNumber(SelectedLength)) {
		return IsogramLengthChoice::To_Low_Number;
	}
	else if (!IsToHighNumber(SelectedLength)) {
		return IsogramLengthChoice::To_High_Number;
	}
	else {
		return IsogramLengthChoice::OK;
	}
}

EWordStatus Game::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EWordStatus::Not_Isogram;
	} 
	else if (!IsLowerCase(Guess)) {
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EWordStatus::Word_To_Short;
	}
	else {
		return EWordStatus::OK;
	}
}

FBullCowCount Game::SubmitGuess(FString Guess)
{
	bGameIsWon = false;
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if (Guess[j] == MyHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	Guesses++;
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
		IsogramGuessedRight++;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool Game::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> SeenLetter;

	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (SeenLetter[Letter]) {
			return false;
		} else {
			SeenLetter[Letter] = true;
		}
	}

	return true;
}

bool Game::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

bool Game::IsToLowNumber(int32 SelectedLength) const
{
	if (SelectedLength < 2) {
		return false;
	}
	return true;
}

bool Game::IsToHighNumber(int32 SelectedLength) const
{
	if (SelectedLength > 17) {
		return false;
	}
	return true;
}
