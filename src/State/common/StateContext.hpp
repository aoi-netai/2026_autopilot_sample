#ifndef STATECONTEXT_HPP
#define STATECONTEXT_HPP

#include <cstdint>

// SBUSデータ構造体
struct SbusData {

    uint8_t raw_sbus[25] = {}; // Raw SBUS data
    uint16_t channels[16] = {}; // 16 channels
    bool failsafe = false;      // Failsafe status
    bool lost_frame = false;    // Frame lost status
};

// 状態間で共有する変数やインスタンス
struct StateContext {

    uint32_t loop_count = 0; // デバック用 実装の際には各状態のメンバーで持ってください

    float accel[3] = {};
    float gyro[3] = {};
    float mag[3] = {};
    float pressure = 0.0f;
    float temperature = 0.0f;
    float tof_distance = 0.0f;

    float angle[3] = {}; // Roll, Pitch, Yaw
    float rate[3] = {};  // Angular velocity around Roll, Pitch, Yaw
    float altitude = 0.0f; // Altitude from ground level

    SbusData sbus_data;

    // PIDやPWM、場合によってはシリアルやセンサーのインスタンスを追加して共有しておく
};


#endif // STATECONTEXT_HPP
