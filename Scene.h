#pragma once
#include "Player.h"
#include "Enemy.h"

// シーンの種類にCLEARを追加
enum SceneType { TITLE, GAME, CLEAR };

class IScene {
public:
    virtual ~IScene() {}
    virtual void Update(char* keys, char* preKeys) = 0;
    virtual void Draw() = 0;
    virtual SceneType GetNextScene() const = 0;
    virtual bool ShouldChangeScene() const = 0;
};

// --- タイトルシーン ---
class TitleScene : public IScene {
private:
    bool changeScene_ = false;
public:
    void Update(char* keys, char* preKeys) override;
    void Draw() override;
    SceneType GetNextScene() const override { return GAME; }
    bool ShouldChangeScene() const override { return changeScene_; }
};

// --- ゲームシーン ---
class GameScene : public IScene {
private:
    Player* player_;
    Enemy* enemy_;
    bool changeScene_ = false;
    SceneType nextScene_ = TITLE;
    bool CheckCollision(int x1, int y1, int r1, int x2, int y2, int r2);

public:
    GameScene();
    ~GameScene();
    void Update(char* keys, char* preKeys) override;
    void Draw() override;
    SceneType GetNextScene() const override { return nextScene_; }
    bool ShouldChangeScene() const override { return changeScene_; }
};

// --- クリアシーン ---
class ClearScene : public IScene {
private:
    bool changeScene_ = false;
    SceneType nextScene_ = GAME;
public:
    void Update(char* keys, char* preKeys) override;
    void Draw() override;
    SceneType GetNextScene() const override { return nextScene_; }
    bool ShouldChangeScene() const override { return changeScene_; }
};