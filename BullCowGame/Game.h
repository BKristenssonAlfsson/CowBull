#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class Game {
public:
	Game();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);
	BullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};