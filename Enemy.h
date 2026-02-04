#pragma once

class Enemy {
private:
    // 敵の座標・属性
    int posX_;
    int posY_;
    int speedX_;
    int radius_;

    // 生存フラグ（リスポーン管理用）
    bool isAlive_;

public:
    Enemy();

    // 更新処理（自動移動とリスポーン）
    void Update();

    // 描画処理
    void Draw();

    // 撃破された時の処理
    void Kill();

    // --- ゲッター (アクセッサ) ---
    int GetX() const { return posX_; }
    int GetY() const { return posY_; }
    int GetRadius() const { return radius_; }
    bool GetIsAlive() const { return isAlive_; }
};