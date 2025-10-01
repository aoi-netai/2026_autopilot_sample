#include "common/StateHeaders.hpp"

void CalibrationState::enter(StateContext& context) {

    // キャリブレーション状態に入るときの初期化処理
    // 例えば、センサーのキャリブレーションの開始など
}

StateID CalibrationState::update(StateContext& context) {

    // キャリブレーション状態のメインループ処理
    // 例えば、センサーのデータ取得やキャリブレーションの進捗確認など

    // キャリブレーションが完了したら、次の状態に遷移
    return StateID::PRE_FLIGHT_STATE;
}

void CalibrationState::exit(StateContext& context) {

    // キャリブレーション状態を出るときのクリーンアップ処理
    // 例えば、キャリブレーションデータの保存など
}