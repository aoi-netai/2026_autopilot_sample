#include "common/StateHeaders.hpp"

void PreFlightState::enter(StateContext& context) {

    // 飛行待機状態に入るときの初期化処理
    // 例えば、センサーの初期化や変数のリセットなど
}

StateID PreFlightState::update(StateContext& context) {

    // 飛行待機状態のメインループ処理
    // 例えば、離陸条件の確認やセンサーのデータ取得など

    // 離陸条件が満たされたら、次の状態に遷移
    // 自動操縦ボタンが入っていたら、直接自動操縦（投下するミッション）に遷移する

    // -----サンプルコード 10回ループしたら次の状態に遷移する-----//
    context.loop_count++;

    if(context.loop_count < 10) {

        // 10回ループするまで同じ状態のまま
        return StateID::PRE_FLIGHT_STATE;
    }
    
    context.loop_count = 0; // リセット
    return StateID::MANUAL_FLIGHT_STATE;
}

void PreFlightState::exit(StateContext& context) {

    // 飛行待機状態を出るときのクリーンアップ処理
    // 例えば、変数の保存など
}