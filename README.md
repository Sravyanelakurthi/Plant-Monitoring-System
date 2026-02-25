# Smart Plant Monitoring System

An Arduino-based automated plant monitoring and irrigation system.

## Overview
This system monitors soil moisture, temperature, and humidity using sensors. 
When soil moisture drops below a threshold, the water pump is automatically activated.

## Components Used
- Arduino Uno
- Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- LCD Display
- Water Pump
- Jumper Wires

## Working Principle
1. Moisture sensor reads soil moisture level.
2. DHT11 reads temperature & humidity.
3. Data is displayed on LCD.
4. Pump turns ON when moisture is below 30%.
5. Serial monitor logs sensor data.

## Future Scope
- IoT Cloud Monitoring
- Mobile App Integration
- Automatic fertilizer control
