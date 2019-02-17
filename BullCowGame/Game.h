#pragma once
#include <string>

class Game {
public:
	Game();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	void Intro();
	void PlayGame();
	bool CheckGuessValidity(std::string);
	bool AskToPlayAgain();
	std::string GetGuess();

private:
	int MyCurrentTry;
	int MyMaxTries;
};