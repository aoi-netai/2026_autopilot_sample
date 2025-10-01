/* StateHeaders.hpp
*
*  Created on: 2025/10/1
*  Author: aoi-netai
*/

#ifndef STATEHEADERS_HPP
#define STATEHEADERS_HPP

#include "StateInterface.hpp"
#include "FlightStateInterface.hpp"
#include "StateID.hpp"

// 電源起動時の初期化状態
class InitState : public StateInterface {

    public:
        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override { return StateID::INIT_STATE; }
};

// センサーのキャリブレーション
class CalibrationState : public StateInterface {

    public:
        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override { return StateID::CALIBRATION_STATE; }
};

// 飛行待機処理
class PreFlightState : public StateInterface {

    public:
        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override { return StateID::PRE_FLIGHT_STATE; }
};

class DisArmState : public StateInterface {

    public:
        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override { return StateID::DISARM_STATE; }
};

class FailSafeState : public StateInterface {

    public:
        StateID update(StateContext& context) override;
        void enter(StateContext& context) override;
        void exit(StateContext& context) override;
        const StateID getStateID() const override { return StateID::FAIL_SAFE_STATE; }
};

// 手動操縦
class ManualFlightState : public FlightStateInterface {

    public:
        
        void flightControl(StateContext& context) override;
        StateID isTransitionState(StateContext& context) override;
        const StateID getStateID() const override { return StateID::MANUAL_FLIGHT_STATE; }
};

// 自動操縦: 水平旋回
class LevelTurnState : public FlightStateInterface {

    public:
        
        void flightControl(StateContext& context) override;
        StateID isTransitionState(StateContext& context) override;
        const StateID getStateID() const override { return StateID::LEVEL_TURN_STATE; }
};

// 自動操縦: 上昇旋回
class ClimbingTurnState : public FlightStateInterface {

    public:
        
        void flightControl(StateContext& context) override;
        StateID isTransitionState(StateContext& context) override;
        const StateID getStateID() const override { return StateID::CLIMBING_TURN_STATE; }
};

// 自動操縦: 8の字飛行
class FigureEightState : public FlightStateInterface {

    public:
        
        void flightControl(StateContext& context) override;
        StateID isTransitionState(StateContext& context) override;
        const StateID getStateID() const override { return StateID::FIGURE_EIGHT_STATE; }
};

// 自動操縦: 離陸・投下・着陸
class AutoFlightState : public FlightStateInterface {

    public:
        
        void flightControl(StateContext& context) override;
        StateID isTransitionState(StateContext& context) override;
        const StateID getStateID() const override { return StateID::AUTO_FLIGHT_STATE; }
};

#endif // STATEHEADERS_HPP 