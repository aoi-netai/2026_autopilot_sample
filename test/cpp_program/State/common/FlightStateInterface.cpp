#include "FlightStateInterface.hpp"
#include <cstdio>
void FlightStateInterface::enter(StateContext& context) {

    // 飛行状態に入るときの初期化処理
    // 例えば、センサーの初期化や変数のリセットなど
}

StateID FlightStateInterface::update(StateContext& context) {

    // 状態遷移の確認（isTransitionState は副作用を持つ可能性があるため
    // 一度だけ呼び出して結果を使う）
    StateID next = isTransitionState(context);
    if (next != getStateID()) {
        return next;
    }

    // IMUデータの取得
    getImuData(context);

    // 位置計算
    calcPosition(context);

    // 派生クラスで制御処理を実装
    flightControl(context);

    // PWM信号の生成
    pwmGenerate(context);

    uint8_t static count = 0;
    if(count++ % 10 == 0)
    printf("FlightStateCommon:\n");

    // 現在の状態IDを返す（状態遷移は派生クラスで実装）
    return getStateID();
}

void FlightStateInterface::exit(StateContext& context) {

    // 飛行状態を出るときのクリーンアップ処理
    // 例えば、モーターの停止や変数の保存など
}

void FlightStateInterface::getImuData(StateContext& context) {

    // IMUセンサーからデータを取得し、contextに保存する処理
    // とりあえず仮データを入れる
    context.accel[0] = 0.0f;
    context.accel[1] = 0.0f;
    context.accel[2] = 9.81f; // 重力加速度

    context.gyro[0] = 0.0f;
    context.gyro[1] = 0.0f;
    context.gyro[2] = 0.0f;
}

void FlightStateInterface::calcPosition(StateContext& context) {

    // センサーデータから姿勢角と高度を計算し、contextに保存する処理
    // とりあえず仮データを入れる
    context.angle[0] = 0.0f; // Roll
    context.angle[1] = 0.0f; // Pitch
    context.angle[2] = 0.0f; // Yaw

    context.altitude = 1.0f; // 仮の高度
}

void FlightStateInterface::pwmGenerate(StateContext& context) {

    // PID制御の結果からPWM信号を生成し、モーターに出力する処理
    // ピン設定があるので空にしておく
}