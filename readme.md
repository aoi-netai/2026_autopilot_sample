# StatePatternSample

自動操縦部門のような遷移を書いてみました

飛行中の状態は基本的に、制御ロジック部分のみの変更で簡単に実装できるようにしています

SBUSの受信や外部制御からのフィードバックはwifiやuart割り込みなどを使用して実装してください
（ポーリングするとかなり危険です）

フェイルセーフなどのエラーハンドリングは実装依存なので一切書いていません


## コードの流れを追ってみよう

### 前提知識

1. `main.cpp`で`StateManager`クラスが呼ばれる

2. `StateManager`が現在の状態に合った状態のクラスを呼んで処理をする



### 実際の流れ

1. `main.cpp`で`StateManager::update()`が呼び出される


```cpp
void loop() {

  // 待機フラグの確認（時間管理用なので今回は省略）
  if (loop_manager.GetWaitFlag() == false) {

    // フラグをセット（時間管理用なので今回は省略）
    loop_manager.SetWaitFlag();

    // StateManagerの更新
    state_manager.Update();
  }
}
```

2. `StateManager::update()`が現在の状態クラスの`update()`を呼び出す

3. 状態クラスの`update()`が処理を行い、次の状態をreturnで返す

4. 返ってきた状態が現在と異なる(遷移が発生)した場合は、現在の状態を更新する返ってきた状態が次の状態クラスになる

5. ループの終了（1に戻る）

**StateManagerの実装**
```cpp
void StateManager::Update() {

    if (current_state) {

        // 現在状態の更新処理
        StateID next_state = current_state->update(state_context);

        // 状態遷移が発生した場合
        if (next_state != current_state->getStateID()) {
            
            // 状態を変更
            ChangeState(CreateState(next_state));
        }
    }
}
```

**状態クラスの実装**
```cpp
StateID SampleState::update(StateContext& context) {

    // 実際の処理を行う

    // 状態遷移の判定
    if(condition) {

        // 次の状態に遷移する
        return StateID::NEXT_STATE;
    }

    // 現在の状態を繰り返す
    return StateID::NOW_STATE;
}
```