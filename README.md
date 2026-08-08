# Fire Alarm System Upgrade (Arduino)

An upgraded fire and high-temperature detection system built with Arduino UNO and a DHT11 sensor. This project features real-time temperature monitoring with a threshold trigger and an integrated **Mute button** to temporarily silence the alarm.

---

## 🛠 Hardware Components

* **1x** Arduino UNO R3
* **1x** DHT11 Temperature & Humidity Sensor
* **1x** Buzzer / Sound Trigger
* **1x** Pushbutton Switch (Mute Button)
* **1x** Breadboard
* Jumper Wires & USB Power Cable

---

## 🔌 Pin Connections

Based on `FireAlarmUpgrade.ino`:

| Component | Function / Pin | Arduino Pin |
| :--- | :--- | :--- |
| **DHT11 Sensor** | Data Pin (`temp_read`) | `Digital Pin 7` |
| **Buzzer** | Trigger Pin (`sound_trigger`) | `Digital Pin 13` |
| **Pushbutton** | Mute Switch (`buttonPin`) | `Digital Pin 2` |
| **Power** | `VCC` / `GND` | `5V` / `GND` |

---

## ⚙️ How the Code Works

1. **Temperature Threshold:**
   * Reads ambient temperature in Celsius using the DHT11 library.
   * If temperature exceeds **31°C** (`sensor_signal > 31`), the alarm triggers (**Pin 13 HIGH**).
2. **Mute Functionality:**
   * Pin 2 uses the internal pull-up resistor (`INPUT_PULLUP`).
   * Pressing the button sets `alarmMuted = true`, immediately turning off the buzzer (`sound_trigger LOW`) and applying a **5-second delay**.
3. **Auto-Reset:**
   * When temperature drops back to **31°C or lower**, the buzzer turns off and `alarmMuted` resets to `false` for the next event.

---

## 🚀 How to Run

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/cktang59/FireAlarmUpgrade.git](https://github.com/cktang59/FireAlarmUpgrade.git)
