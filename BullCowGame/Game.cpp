#include "Game.h"

using int32 = int;

Game::Game()
{
	Reset();
}

int32 Game::GetMaxTries() const { return MyMaxTries; }

int32 Game::GetCurrentTry() const { return MyCurrentTry; }

void Game::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
}

bool Game::IsGameWon() const
{
	return false;
}

bool Game::CheckGuessValidity(FString)
{
	return false;
}

BullCowCount Game::SubmitGuess(FString)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;
	
	return BullCowCount;
}
