#include <Novice.h>
#include "Scene.h"

const char kWindowTitle[] = "LC1B_23_ハヤシ_テルト_PG評価課題2の道のり";

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    Novice::Initialize(kWindowTitle, 1280, 720);

    IScene* currentScene = new TitleScene(); // 最初のシーン
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

         ///
         /// ↓更新処理ここから
         ///
        currentScene->Update(keys, preKeys);

        // シーン切り替え判定
        if (currentScene->ShouldChangeScene()) {
            SceneType next = currentScene->GetNextScene();
            delete currentScene;

            if (next == GAME) currentScene = new GameScene();
            else if (next == CLEAR) currentScene = new ClearScene();
            else if (next == GAMEOVER) currentScene = new GameOverScene(); // 追加
            else currentScene = new TitleScene();
        }

        ///
        ///↑更新処理ここまで
        /// 


         ///
        ///↓描画処理ここから
        ///

        currentScene->Draw();

        Novice::EndFrame();
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) break;
    }

    delete currentScene;


      ///
      ///↑描画処理ここまで
     ///
    Novice::Finalize();
    return 0;
}