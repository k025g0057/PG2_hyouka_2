#include "Player.h"
#include <Novice.h>

Player::Player() {
    posX_ = 640;
    posY_ = 600;
    speed_ = 5;
    radius_ = 20;
    shotTimer_ = 0;

    // 20発分のメモリを確保
    for (int i = 0; i < 20; i++) {
        bullets_[i] = new Bullet();
    }
}

Player::~Player() {
    for (int i = 0; i < 20; i++) {
        delete bullets_[i];
    }
}

void Player::Update(char* keys) {
    // 移動
    if (keys[DIK_W]) posY_ -= speed_;
    if (keys[DIK_S]) posY_ += speed_;
    if (keys[DIK_A]) posX_ -= speed_;
    if (keys[DIK_D]) posX_ += speed_;

    // 連射タイマーの更新
    if (shotTimer_ > 0) {
        shotTimer_--;
    }

    // 長押し発射（SPACEキーが押されている間）
    if (keys[DIK_SPACE]) {
        if (shotTimer_ <= 0) {
            // 配列の中から「撃てる（isActiveがfalse）」弾を探す
            for (int i = 0; i < 20; i++) {
                if (bullets_[i]->GetIsActive() == false) {
                    bullets_[i]->Fire(posX_, posY_);
                    shotTimer_ = 10; // 10フレームごとに発射（この値を変えると連射速度が変わる）
                    break; // 1回につき1発撃てばいいのでループを抜ける
                }
            }
        }
    }

    // すべての弾を更新
    for (int i = 0; i < 20; i++) {
        bullets_[i]->Update();
    }
}

void Player::Draw() {
    // すべての弾を描画
    for (int i = 0; i < 20; i++) {
        bullets_[i]->Draw();
    }
    Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
}

void Player::Reset() {
    posX_ = 640;
    posY_ = 600;
    for (int i = 0; i < 20; i++) {
        bullets_[i]->SetIsActive(false);
    }
}