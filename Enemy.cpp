#include "Enemy.h"
#include <Novice.h>
#include <math.h> 
#include <stdlib.h>

Enemy::Enemy() {
    posX_ = 640;
    baseY_ = 150; 
    posY_ = baseY_;
    speedX_ = 5;
    radius_ = 20;
    isAlive_ = true;
    hp_ = 10;    
    timer_ = 0;
}

void Enemy::Update() {
    if (isAlive_) {
        // --- 左右の移動 ---
        posX_ += speedX_;

        // 壁に当たった時の処理
        if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
            speedX_ *= -1;

            // 跳ね返る時に速度をランダム(4～10)に変更して当てづらくする
            int randomSpeed = (rand() % 7) + 4;
            if (speedX_ > 0) speedX_ = randomSpeed;
            else speedX_ = -randomSpeed;
        }

        // --- 上下のゆらゆら移動 (サイン波) ---
        timer_++;
        // timer_に掛ける数字(0.05)を大きくすると速く、50.0を大きくすると大きく揺れます
        posY_ = baseY_ + (int)(sinf((float)timer_ * 0.05f) * 50.0f);

    } else {
        // リスポーン処理
        posX_ = 640;
        baseY_ = 150;
        posY_ = baseY_;
        isAlive_ = true;
        hp_ = 10;
        timer_ = 0;
    }
}

void Enemy::Draw() {
    if (isAlive_) {
       
        Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);

        // デバッグ用：残りHPを敵の近くに表示
        Novice::ScreenPrintf(posX_ -10, posY_ - 40, "HP:%d", hp_);
    }
}

void Enemy::Kill() {
    isAlive_ = false;
}