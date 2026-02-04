#include "Enemy.h"
#include <Novice.h>

// コンストラクタ
Enemy::Enemy() {
    posX_ = 640;
    posY_ = 150;
    speedX_ = 5;
    radius_ = 20;
    isAlive_ = true;
}

// 更新処理
void Enemy::Update() {
    if (isAlive_) {
        // --- 自動移動 ---
        posX_ += speedX_;

        
        if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
            speedX_ *= -1;
        }
    } else {
        // --- リスポーン処理 ---
     
        posX_ = 640;
        posY_ = 150;
        isAlive_ = true;
    }
}

// 描画処理
void Enemy::Draw() {
    if (isAlive_) {
   
        Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
    }
}

// 敵を倒した時に呼ばれる
void Enemy::Kill() {
    isAlive_ = false;
}