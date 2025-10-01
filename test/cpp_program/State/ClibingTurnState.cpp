#include "common/StateHeaders.hpp"

void ClimbingTurnState::flightControl(StateContext& context) {

    // 上昇旋回状態の制御処理
    // 共通処理で、センサーのデータ取得が行われ、3軸の姿勢角と高度が計算されてcontextに保存されている

    // ここでは目標値を設定し、PID制御を行う

    // この後の共通処理で、各軸のPIDの結果と高度の結果からPWM信号が生成される
}

StateID ClimbingTurnState::isTransitionState(StateContext& context) {

    // 上昇旋回状態からの遷移条件を確認し、必要に応じて次の状態IDを返す
    // 例えば、手動操縦モードへの切り替え条件やフェイルセーフ条件など

    // 条件が満たされない場合は、現在の状態IDを返す
    return StateID::CLIMBING_TURN_STATE;
}