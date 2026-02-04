#pragma once
#include "Bullet.h"

class Player {
private:
    int posX_, posY_;
    int speed_;
    int radius_;

    // 弾の配列（包含）
    Bullet* bullets_[20];
    int shotTimer_;

public:
    Player();
    ~Player();
    void Update(char* keys);
    void Draw();
    void Reset();

    // --- ゲッター ---
    int GetX() const { return posX_; }
    int GetY() const { return posY_; }
    int GetRadius() const { return radius_; }

    // ★重要：i番目の弾オブジェクトをまるごと返す
    Bullet* GetBullet(int index) {
        if (index >= 0 && index < 20) {
            return bullets_[index];
        }
        return nullptr;
    }
};