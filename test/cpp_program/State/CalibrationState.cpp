#include "common/StateHeaders.hpp"

void CalibrationState::enter(StateContext& context) {

    // キャリブレーション状態に入るときの初期化処理
    // 例えば、センサーのキャリブレーションの開始など
}

StateID CalibrationState::update(StateContext& context) {

    // キャリブレーション状態のメインループ処理
    // 例えば、センサーのデータ取得やキャリブレーションの進捗確認など

    // -----サンプルコード 10回ループしたら次の状態に遷移する-----//
    context.loop_count++;

    if(context.loop_count < 10) {

        // 10回ループするまで初期化中のまま
        return StateID::CALIBRATION_STATE;
    }

    // キャリブレーションが完了したら、次の状態に遷移
    context.loop_count = 0; // リセット
    return StateID::PRE_FLIGHT_STATE;
}

void CalibrationState::exit(StateContext& context) {

    // キャリブレーション状態を出るときのクリーンアップ処理
    // 例えば、キャリブレーションデータの保存など
}