// 启用调试模式
#define DEBUG

#include <IRremote.h>

int PIN_IR_RECEIVER = 9;  // 红外接收器
int PIN_MOTOR_RED = 10;   // 输出到电机红色线的控制端子
int PIN_MOTOR_BLK = 11;   // 输出到电机黑色线的控制端子

int MS_MOTOR_RUN = 1000;  // 电机收回前等待时间 (毫秒 ms)

void setup() {
  /* 初始化红外遥控 */
  IrReceiver.begin(PIN_IR_RECEIVER, ENABLE_LED_FEEDBACK);
  /* 初始化电机控制针脚 */
  pinMode(PIN_MOTOR_RED, OUTPUT);
  pinMode(PIN_MOTOR_BLK, OUTPUT);
#ifdef DEBUG
  /* 调试用串口监视器 */
  Serial.begin(9600);
#endif
}

void loop() {
  if (IrReceiver.decode()) {
    switch (IrReceiver.decodedIRData.command) {
      case 0x0:
#ifdef DEBUG
        Serial.println("Play Button");
#endif
        // 电机正转, 伸出推杆
        digitalWrite(PIN_MOTOR_RED, HIGH);
        delay(MS_MOTOR_RUN);
        // 电机倒转, 收回推杆
        digitalWrite(PIN_MOTOR_RED, LOW);
        digitalWrite(PIN_MOTOR_BLK, HIGH);
        delay(MS_MOTOR_RUN);
        // 电机停转
        digitalWrite(PIN_MOTOR_BLK, LOW);
        break;
      
      default:
#ifdef DEBUG
        Serial.println(IrReceiver.decodedIRData.command);
#endif
        break;
    }
  }
}