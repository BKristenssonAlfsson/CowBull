#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid,
	OK,
	Not_Isogram,
	Word_To_Short,
	Not_Lowercase
};

class Game {
public:
	Game();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	FString getIsogram(int32);

	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;
	void Reset();
	int32 AmountOfGuesses();
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 Guesses;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};