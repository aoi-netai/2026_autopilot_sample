#include "common/StateHeaders.hpp"

void DisArmState::enter(StateContext& context) {

    // DisArm状態に入るときの初期化処理
    // 例えば、モーターの停止や安全な状態への移行など
}

StateID DisArmState::update(StateContext& context) {

    // DisArm状態のメインループ処理
    // 例えば、DisArm状態の確認や安全な状態の維持など

    // DisArm状態が解除されたら、次の状態に遷移
    return StateID::PRE_FLIGHT_STATE;
}

void DisArmState::exit(StateContext& context) {

    // DisArm状態を出るときのクリーンアップ処理
    // 例えば、変数の保存など
}