#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class IsogramLengthChoice {
	Invalid,
	OK,
	Not_Number,
	To_High_Number,
	To_Low_Number
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
	IsogramLengthChoice CheckIsogramLength(int32) const;
	EWordStatus CheckGuessValidity(FString) const;
	void Reset();
	int32 AmountOfGuesses();
	int32 IsogramsCracked();
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 Guesses;
	int32 IsogramGuessedRight;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
	bool IsToLowNumber(int32) const;
	bool IsToHighNumber(int32) const;
	bool NotANumber(int32) const;
};