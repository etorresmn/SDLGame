#pragma once

#include "SDL_cpp.h"
#include <fstream>
#include <string>
#include <vector>

struct RGBColor {
    int Red;
    int Green;
    int Blue;
};

struct WindowProperties {
    uint32_t width;
    uint32_t height;
    uint32_t frameLimit;
    uint32_t fullScreenMode;
};

struct FontProperties {
    std::string fileName;
    int size;
    RGBColor color;
};

struct PlayerProperties {
    int shapeRadius;
    int collisionRadius;
    float speed;
    float centerPosition;
    RGBColor outlineColor;
    int outlineThickness;
    int shapeVertices;
};

struct EnemyProperties {
    int shapeRadius;
    int collisionRadius;
    float minSpeed;
    float maxSpeed;
    RGBColor outlineColor;
    int outlineThickness;
    int minVertices;
    int maxVertices;
    int smallLifeSpan;
    int spawnInterval;
};

struct BulletProperties {
    int shapeRadius;
    int collisionRadius;
    float speed;
    RGBColor fillColor;
    RGBColor outlineColor;
    int outlineThickness;
    int shapeVertices;
    int lifeSpan;
};

class ConfigReader {
private:
    std::ifstream _configFile;
    WindowProperties _window;
    FontProperties _font;
    PlayerProperties _player;
    EnemyProperties _enemy;
    BulletProperties _bullet;

public:
    ConfigReader(std::string configFile);

    WindowProperties GetWindowProperties(void);

    FontProperties GetFontProperties(void);

    PlayerProperties GetPlayerProperties(void);

    BulletProperties GetBulletProperties(void);

    EnemyProperties GetEnemyProperties(void);
};