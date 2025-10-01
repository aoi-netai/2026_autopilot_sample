/* StateInterface.hpp
*
*/

#ifndef INC_STATE_INTERFACE_HPP_
#define INC_STATE_INTERFACE_HPP_

#include "StateID.hpp"
#include "StateContext.hpp"

class StateManager;

/*
* StateInterface
*
* すべての状態の基底クラス
* update, enter, exit, getStateID の4つの仮想関数を持つ
*
* enter: 状態に入るときの初期化処理を行う
* update: 状態のメインループ処理を行い、次の状態IDを返す
* exit: 状態を出るときのクリーンアップ処理を行う
* getStateID: 現在の状態のIDを返す
*
* update, getStateID は純粋仮想関数であり、派生クラスへの実装を強制させている
*/

class StateInterface {

    public:

    virtual ~StateInterface() = default;

    // 状態更新用
    virtual StateID update(StateContext& context) = 0;

    // 状態に入るときの処理（起動や初期化など）
    virtual void enter(StateContext& context) {}

    // 状態を出るときの処理（リセットやクリーンアップなど）
    virtual void exit(StateContext& context) {}

    // 状態IDの取得
    virtual const StateID getStateID() const = 0;
};

#endif /* INC_STATE_INTERFACE_HPP_ */