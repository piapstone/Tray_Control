#ifndef Capstone_h
#define Capstone_h

#include "Arduino.h"
#include "Adafruit_VEML7700.h"
#include "dht11.h"

#define STEP_PIN 33
#define DIR_PIN 32
#define ENABLE_PIN 25
#define BACK_LIMIT_PIN 39
#define FRONT_LIMIT_PIN 36
#define BACK_DHT_PIN 16
#define FRONT_DHT_PIN 17
#define SDA_PIN 21
#define SCL_PIN 22
#define ESTOP_PIN 27
#define CURRENT_SENSOR_PIN 26
#define GROWLIGHT_PIN 13
#define STATUSLIGHT_PIN 19
#define NUM_LED 20

class Tray
{
public:
    void begin();
    bool move(int target_pos, int spd = DEFAULT_TRAY_SPEED);
    bool resetFront(int spd = DEFAULT_TRAY_SPEED);
    bool resetBack(int spd = DEFAULT_TRAY_SPEED);
    float *readLuxs();
    void disableTray();
    float readTempFront();
    float readTempBack();
    float readHumiFront();
    float readHumiBack();
    bool eStopPressed();
    //bool resetPressed();
    void setRedWhiteLight(int strip_index, int brightness = DEFAULT_BRIGHTNESS);
    void setColor(int strip_index, int r, int g, int b, int brightness = DEFAULT_BRIGHTNESS);
    void offLight(int strip_index);
    void updatePower();
    void setStatusLight(int r, int g, int b, int brightness = DEFAULT_BRIGHTNESS);
    bool sendI2C(int address, String message);

    int current_pos = 0;
    float power_consumption = 0.0;
    float current_consumption = 0.0;

private:
    // Parameters
    static const int DEFAULT_TRAY_SPEED = 10;
    static const int DEFAULT_BRIGHTNESS = 50;
    static const int MAX_BRIGHTNESS = 127;

    static constexpr float GEAR_DIAMETER = 19.15;
    static const int STEPS_PER_REV = 1600;
    static const int STROKE_LENGTH = 760;
    static const int MIN_DELAY = 100;
    static const int MAX_DELAY = 1100;
    static const int NUM_LIGHT_SENSOR = 6;
    static const int LIGHT_LOW_THRESHOLD = 10000;
    static const int LIGHT_HIGH_THRESHOLD = 20000;
    static const bool LIGHT_INTERRUPT_ENABLE = true;
    static const int NUM_READINGS_CURRENT = 20;
    static const int NUM_READINGS_LIGHT = 2;
    static constexpr float STEPS_PER_MM = STEPS_PER_REV / (3.1415 * GEAR_DIAMETER); // calculate the number of steps per mm

    int stepPin;    
    int dirPin;
    int backlimit;
    int frontlimit;
    long timer;

    Adafruit_VEML7700 light_sensor[NUM_LIGHT_SENSOR];
    dht11 frontDHT11;
    dht11 backDHT11;

    void tcaselect(uint8_t i);
    int speedToDelay(int spd);
};
#endif
