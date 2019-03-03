#include "Game.h"
#include "iostream"
#include <map>
#define TMap std::map

using int32 = int;

Game::Game()
{
	Reset();
}

int32 Game::GetMaxTries() const { return MyMaxTries; }

int32 Game::GetCurrentTry() const { return MyCurrentTry; }

int32 Game::GetHiddenWordLength() const { return MyHiddenWord.length();  }

bool Game::IsGameWon() const { return bGameIsWon; }

void Game::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "alpine";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
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
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
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
