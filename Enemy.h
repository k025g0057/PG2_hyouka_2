#pragma once

class Enemy {
private:
    int posX_;
    int posY_;
    int baseY_;    // 基準となるY座標
    int speedX_;
    int radius_;
    bool isAlive_;
    int hp_;       // 体力
    int timer_;    // 動きを計算するための時間

public:
    Enemy();

    void Update();
    void Draw();
    void Kill();

    // ダメージ処理
    void OnDamage() { hp_--; }

    // ゲッター
    int GetX() const { return posX_; }
    int GetY() const { return posY_; }
    int GetRadius() const { return radius_; }
    bool GetIsAlive() const { return isAlive_; }
    int GetHp() const { return hp_; }
};