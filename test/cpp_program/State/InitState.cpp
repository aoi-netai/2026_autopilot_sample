#include "common/StateHeaders.hpp"

void InitState::enter(StateContext& context) {

    // 初期化状態に入るときの初期化処理
    // 変数のリセットなど

}

StateID InitState::update(StateContext& context) {

    // 初期化状態のメインループ処理
    // 例えば、センサーの自己診断や初期設定の確認など

    // エラーが出たらエラーメッセージとともに早期リターンをする

    // -----サンプルコード 10回ループしたら次の状態に遷移する-----//
    context.loop_count++;

    if(context.loop_count < 10) {

        // 10回ループするまで同じ状態のまま
        return StateID::INIT_STATE;
    }

    // 初期化が完了したら、次の状態に遷移
    context.loop_count = 0; // リセット
    return StateID::CALIBRATION_STATE;
}

void InitState::exit(StateContext& context) {

    // 初期化状態を出るときのクリーンアップ処理
    // 変数の保存など
    
}