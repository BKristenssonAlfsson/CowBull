#include "Game.h"
#include "iostream"

using int32 = int;

Game::Game()
{
	Reset();
}

int32 Game::GetMaxTries() const { return MyMaxTries; }

int32 Game::GetCurrentTry() const { return MyCurrentTry; }

int32 Game::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void Game::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "alpine";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
}

bool Game::IsGameWon() const
{
	return false;
}

EWordStatus Game::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EWordStatus::Not_Isogram;
	} 
	else if (false) {
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
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j < HiddenWordLength; j++) {
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
	return BullCowCount;
}
