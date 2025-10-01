// PC向けに書き換えた main
// Arduino 依存（timer, IRAM_ATTR, Arduino.h 等）を取り除き、
// std::chrono / std::this_thread を使って 10Hz（周期 100ms）で
// StateManager::Update() を呼び出します。

#include <cstdio>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "StateManager/StateManager.hpp"

int main() {

    // 状態管理クラスのインスタンスを作成（初期状態を指定する）
    StateManager state_manager(StateID::INIT_STATE);

    // ループ周期（10Hz -> 100ms）
    const std::chrono::milliseconds period(100);

    uint32_t iter = 0;
    uint32_t cycles = 10000; // ループ回数制御（テスト用）
    while ( iter < cycles) {

        auto start = std::chrono::steady_clock::now();

        // StateManager の更新
        state_manager.Update();

        // 次周期までスリープ
        std::this_thread::sleep_until(start + period);

        ++iter;
    }

    return 0;
}
