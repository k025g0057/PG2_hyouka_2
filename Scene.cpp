#include "Scene.h"
#include <Novice.h>
#include <math.h>
#include"Player.h"
#include"Enemy.h"

// --- TitleScene ---
void TitleScene::Update(char* keys, char* preKeys) {
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) changeScene_ = true;
}
void TitleScene::Draw() {
    Novice::ScreenPrintf(550, 300, "SHOOTING GAME");
    Novice::ScreenPrintf(530, 350, "PRESS ENTER TO START");
}

// --- GameScene ---
GameScene::GameScene() { player_ = new Player(); enemy_ = new Enemy(); }
GameScene::~GameScene() { delete player_; delete enemy_; }

bool GameScene::CheckCollision(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x1 - x2; int dy = y1 - y2;
    return sqrtf((float)(dx * dx + dy * dy)) <= (float)(r1 + r2);
}

void GameScene::Update(char* keys, char* preKeys) {
    (void)preKeys;
    player_->Update(keys);
    enemy_->Update();

    // 弾20発分と敵の当たり判定をループさせる
    for (int i = 0; i < 20; i++) {
        Bullet* b = player_->GetBullet(i); // Playerクラスにこのゲッターを追加

        if (b->GetIsActive() && enemy_->GetIsAlive()) {
            if (CheckCollision(b->GetX(), b->GetY(), b->GetRadius(),
                enemy_->GetX(), enemy_->GetY(), enemy_->GetRadius())) {
                enemy_->Kill();
                b->SetIsActive(false);
                nextScene_ = CLEAR;
                changeScene_ = true;
            }
        }
    }
}
void GameScene::Draw() { player_->Draw(); enemy_->Draw(); }

// --- ClearScene ---
void ClearScene::Update(char* keys, char* preKeys) {
    // Rキーでゲーム再開
    if (keys[DIK_R] && !preKeys[DIK_R]) {
        nextScene_ = GAME;
        changeScene_ = true;
    }
    // Enterキーでタイトルへ
    if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
        nextScene_ = TITLE;
        changeScene_ = true;
    }
}
void ClearScene::Draw() {
    Novice::ScreenPrintf(550, 300, "STAGE CLEAR!");
    Novice::ScreenPrintf(510, 350, "PRESS R TO PLAY AGAIN");
    Novice::ScreenPrintf(510, 380, "PRESS ENTER TO TITLE");
}