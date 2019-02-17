#include "Game.h"

Game::Game()
{
	Reset();
}

int Game::GetMaxTries() const { return MyMaxTries; }

int Game::GetCurrentTry() const { return MyCurrentTry; }

void Game::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = 8;
}

void Game::Intro()
{
}

void Game::PlayGame()
{
}

bool Game::IsGameWon() const
{
	return false;
}

bool Game::CheckGuessValidity(std::string)
{
	return false;
}

bool Game::AskToPlayAgain()
{
	return false;
}

std::string Game::GetGuess()
{
	return std::string();
}
