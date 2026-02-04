#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
    posX_ = 0;
    posY_ = -100;
    speed_ = 10;
    radius_ = 8;
    isActive_ = false;
}

void Bullet::Fire(int x, int y) {
    if (isActive_ == false) {
        posX_ = x;
        posY_ = y;
        isActive_ = true;
    }
}

void Bullet::Update() {
    if (isActive_ == true) {
        posY_ -= speed_;
        // 画面外に出たら消す
        if (posY_ < -radius_) {
            isActive_ = false;
        }
    }
}

void Bullet::Draw() {
    if (isActive_ == true) {
        Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
    }
}