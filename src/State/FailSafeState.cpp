#include "common/StateHeaders.hpp"

void FailSafeState::enter(StateContext& context) {

    // フェイルセーフ状態に入るときの初期化処理
    // 例えば、モーターの停止や安全な状態への移行など
}

StateID FailSafeState::update(StateContext& context) {

    // フェイルセーフ状態のメインループ処理
    // 例えば、フェイルセーフ条件の確認や安全な状態の維持など

    // フェイルセーフ状態が解除されたら、次の状態に遷移
    // 解除されたら、ダメな気がする
    return StateID::PRE_FLIGHT_STATE;
}

void FailSafeState::exit(StateContext& context) {

    // フェイルセーフ状態を出るときのクリーンアップ処理
    // 例えば、変数の保存など
}