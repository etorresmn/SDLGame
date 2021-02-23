#include <iostream>
#include <iterator>
#include <regex>
#include "ConfigProperties.h"

ConfigReader::ConfigReader(std::string configFile)
{
	std::string strRawLine;
	std::regex regText;
	std::smatch match;

	_configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		_configFile.open(configFile);
	}
	catch (const std::exception&)
	{
		std::cout << "Error!, could not open " << configFile << std::endl;
		return;
	}

	regText = "\\S+";	//match anything that is not white space (get all words an numbers)
	std::sregex_iterator matchIterator;
	std::sregex_iterator matchEnd;

	while (!_configFile.eof()) {
		std::getline(_configFile, strRawLine);

		matchIterator = std::sregex_iterator(strRawLine.cbegin(), strRawLine.cend(), regText); //create a regex iterator that contains all matches
		matchEnd = std::sregex_iterator();

		match = *matchIterator;
		//Check if the first word is window, font, rectangle or circle and if the number of arguments matches
		if (match.str() == "Window" && std::distance(matchIterator, matchEnd) == 5) {
			match = *(++matchIterator);
			_window.width = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_window.height = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_window.frameLimit = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_window.fullScreenMode = (int)std::stoul(match.str(), nullptr, 10);
		}
		else if (match.str() == "Font" && std::distance(matchIterator, matchEnd) == 6) {
			match = *(++matchIterator);
			_font.fileName = match.str();
			match = *(++matchIterator);
			_font.size = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_font.color.Red = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_font.color.Green = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_font.color.Blue = (int)std::stoul(match.str(), nullptr, 10);
		}
		else if (match.str() == "Player" && std::distance(matchIterator, matchEnd) == 12) {
			match = *(++matchIterator);
			_player.shapeRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.collisionRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.speed = std::stof(match.str(), nullptr);
			match = *(++matchIterator);
			_player.outlineColor.Red = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.outlineColor.Green = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.outlineColor.Blue = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.outlineThickness = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_player.shapeVertices = (int)std::stoul(match.str(), nullptr, 10);
		}
		else if (match.str() == "Enemy" && std::distance(matchIterator, matchEnd) == 11) {
			match = *(++matchIterator);
			_enemy.shapeRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.collisionRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.minSpeed = std::stof(match.str(), nullptr);
			match = *(++matchIterator);
			_enemy.maxSpeed = std::stof(match.str(), nullptr);
			match = *(++matchIterator);
			_enemy.outlineColor.Red = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.outlineColor.Green = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.outlineColor.Blue = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.outlineThickness = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.smallLifeSpan = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_enemy.spawnInterval = (int)std::stoul(match.str(), nullptr, 10);
		}
		else if (match.str() == "Bullet" && std::distance(matchIterator, matchEnd) == 13) {
			match = *(++matchIterator);
			_bullet.shapeRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.collisionRadius = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.speed = std::stof(match.str(), nullptr);
			match = *(++matchIterator);
			_bullet.fillColor.Red = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.fillColor.Green = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.fillColor.Blue = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.outlineColor.Red = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.outlineColor.Green = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.outlineColor.Blue = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.outlineThickness = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.shapeVertices = (int)std::stoul(match.str(), nullptr, 10);
			match = *(++matchIterator);
			_bullet.lifeSpan = (int)std::stoul(match.str(), nullptr, 10);
		}
	}
	_configFile.close();
}

WindowProperties ConfigReader::GetWindowProperties(void)
{
	return _window;
}

FontProperties ConfigReader::GetFontProperties(void)
{
	return _font;
}

PlayerProperties ConfigReader::GetPlayerProperties(void)
{
	return _player;
}

BulletProperties ConfigReader::GetBulletProperties(void)
{
	return _bullet;
}

EnemyProperties ConfigReader::GetEnemyProperties(void)
{
	return _enemy;
}
