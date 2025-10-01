#include "common/StateHeaders.hpp"

void ManualFlightState::flightControl(StateContext& context) {

    // 手動操縦状態の制御処理
    // 共通処理で、センサーのデータ取得が行われ、3軸の姿勢角と高度が計算されてcontextに保存されている

    // ここでは目標値を設定し、PID制御を行う

    // この後の共通処理で、各軸のPIDの結果と高度の結果からPWM信号が生成される

    uint8_t static count = 0;

    if(count++ % 10 == 0)
    printf("ManualFlightState: angle=(%.2f, %.2f, %.2f), altitude=%.2f\n",context.angle[0], context.angle[1], context.angle[2], context.altitude);
}

StateID ManualFlightState::isTransitionState(StateContext& context) {

    // 手動操縦状態からの遷移条件を確認し、必要に応じて次の状態IDを返す
    // 例えば、手動操縦モードへの切り替え条件やフェイルセーフ条件など

    // 条件が満たされない場合は、現在の状態IDを返す

    context.loop_count++;

    if(context.loop_count < 100) {

        // 100回ループするまで同じ状態のまま
        return StateID::MANUAL_FLIGHT_STATE;
    }
    
    context.loop_count = 0; // リセット
    return StateID::LEVEL_TURN_STATE;
}