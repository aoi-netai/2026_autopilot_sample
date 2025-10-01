#include "common/StateHeaders.hpp"

void InitState::enter(StateContext& context) {

    // 初期化状態に入るときの初期化処理
    // 変数のリセットなど

}

StateID InitState::update(StateContext& context) {

    // 初期化状態のメインループ処理
    // 例えば、センサーの自己診断や初期設定の確認など

    // エラーが出たらエラーメッセージとともに早期リターンをする

    // 初期化が完了したら、次の状態に遷移
    return StateID::CALIBRATION_STATE;
}

void InitState::exit(StateContext& context) {

    // 初期化状態を出るときのクリーンアップ処理
    // 変数の保存など
    
}