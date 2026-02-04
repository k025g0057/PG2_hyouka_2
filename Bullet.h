#pragma once

class Bullet {
private:
    int posX_;
    int posY_;
    int speed_;
    int radius_;
    bool isActive_;

public:
    Bullet();
    void Update();
    void Draw();

    // 弾を発射する時に呼ぶ
    void Fire(int x, int y);

    // アクセッサ
    int GetX() const { return posX_; }
    int GetY() const { return posY_; }
    int GetRadius() const { return radius_; }
    bool GetIsActive() const { return isActive_; }
    void SetIsActive(bool active) { isActive_ = active; }
};