#ifndef FLIGHT_STATE_INTERFACE_HPP
#define FLIGHT_STATE_INTERFACE_HPP

#include "StateID.hpp"
#include "StateContext.hpp"
#include "StateInterface.hpp"

/*
* FlightStateInterface
*
* 飛行状態の状態の基底クラス
* StateInterface を継承している
*
* 飛行中の共通処理をここに実装している
* センサーデータの取得、姿勢・高度推定、PWM信号の生成など
*
* 制御部分（PID計算や目標値の設定など）は各派生クラスで実装する
* getStateID は純粋仮想関数であり、派生クラスへの実装を強制させている
*/
class FlightStateInterface: public StateInterface {

    public:

        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override = 0;
    
    protected:

        virtual void flightControl(StateContext& context) = 0;
        virtual StateID isTransitionState(StateContext& context) = 0;

    private:
        void getImuData(StateContext& context);
        void calcPosition(StateContext& context);
        void pwmGenerate(StateContext& context);
};


#endif  // INC_FLIGHT_STATE_INTERFACE_HPP_