# PressBot

一个对 [FingerBot](https://www.adaprox.io/product-page/fingerbot) 的拙劣模仿之作（



## 零件

- Arduino（我自己用的国产的 Arduino UNO 兼容板）
- CHQ1838 红外接收器
- L293D 电机控制 IC
- 红外遥控器
- 伸缩电机



## 接线

详见 `./assets/Sketch.fzz`。

### Arduino

| Arduino 端 | 另一端                     |
| ---------- | -------------------------- |
| 9          | 红外: DATA                 |
| 10         | 2（L293D）                 |
| 11         | 7（L293D）                 |
| 5 V        | 1, 8, 16（L293D）红外: +5V |
| GND        | 4（L293D）红外: GND        |

### L293D

| L293D | 电机 |
| ----- | ---- |
| 3     | +    |
| 6     | -    |

