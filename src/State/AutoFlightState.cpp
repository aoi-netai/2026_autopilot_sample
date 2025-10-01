#include "common/StateHeaders.hpp"

void AutoFlightState::flightControl(StateContext& context) {

    // 自動操縦状態の制御処理
    // 共通処理で、センサーのデータ取得が行われ、3軸の姿勢角と高度が計算されてcontextに保存されている

    // ここでは目標値を設定し、PID制御を行う

    // この後の共通処理で、各軸のPIDの結果と高度の結果からPWM信号が生成される
}