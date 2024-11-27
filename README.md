# Laser-Activated Cat Deterrent System

This project uses a laser distance sensor and a sprinkler system to detect movement (e.g., from a cat) and activate the sprinkler for 5 seconds. It provides a humane and non-harmful method to discourage cats from entering specific areas.

---

## Features

- **Laser Distance Sensor**: Detects significant changes in distance to identify movement.
- **Sprinkler Activation**: Triggers a sprinkler for 5 seconds upon detecting movement.
- **Humane Solution**: Designed to keep cats away without causing harm.
- **Adjustable Threshold**: Fine-tune the sensitivity of movement detection.

---

## Components Used

1. **Arduino Board** (e.g., Arduino Uno)
2. **VL53L0X Laser Distance Sensor**
3. **Relay Module** (to control the sprinkler)
4. **Sprinkler System**
5. **Jumper Wires**
6. **Power Supply**

---

## Circuit Diagram

1. Connect the **VL53L0X sensor** to the Arduino using the I2C interface (SDA and SCL).
2. Attach the **relay module** to pin 3 of the Arduino for sprinkler control.
3. Wire the sprinkler system to the relay as per the relay's specifications.
4. Ensure proper grounding between all components.

---

## Code Overview

The code initializes the VL53L0X sensor and continuously measures distance. It detects significant changes in distance (as defined by the `threshold` variable) and activates the sprinkler via a relay. The sprinkler remains on for 5 seconds (`sprinklerOnDuration`) and then turns off.

### Key Code Sections:
- **Threshold for Movement Detection**: Change `threshold` to adjust sensitivity.
- **Sprinkler Duration**: Modify `sprinklerOnDuration` to set the activation time.
- **Safety Measures**: Prevents rapid toggling of the sprinkler system.

---

## Setup Instructions

1. **Upload the Code**:
   - Connect your Arduino to your computer.
   - Open the Arduino IDE and upload the provided sketch.

2. **Assemble the Circuit**:
   - Connect the components as outlined in the circuit diagram.

3. **Test the System**:
   - Power the setup and simulate movement within the sensor's range to ensure the sprinkler activates for 5 seconds.

---

## Usage

Place the system in an area where you want to deter cats. The laser sensor will detect movement, and the sprinkler will activate briefly to scare off the animal without causing harm.

---

## Future Improvements

- Add a solar-powered battery system for outdoor use.
- Include an LED indicator to show when the system is active.
- Use a water flow sensor to monitor the sprinkler's performance.
- Integrate with a smartphone app for remote control and monitoring.

---

## License

This project is open-source and free to use for personal and educational purposes. Contributions and improvements are welcome.

---

Enjoy your humane and effective cat deterrent system!
