# ESP32-TEMP-ALERT
 
## Objective

The ESP32-DHT11-Webserver project aims to create a real-time temperature and humidity monitoring system using an ESP32 microcontroller and a DHT11 sensor. The primary goal is to set up a web server hosted on the ESP32 that displays if the alert systems is succesfully working and integrates with IFTTT to send email notifications when the temperature exceeds a certain threshold. This project provides practical experience in IoT development, microcontroller programming, web server creation, sensor integration, and cloud-based event triggering.

### Skills Learned

- Programming the ESP32 using Arduino IDE.
- Wiring and connecting the DHT11 temperature and humidity sensor with the ESP32.
- Hosting a web server on the ESP32.
- Utilizing Wi-Fi capabilities of the ESP32 for network communication.
- Configuring IFTTT Webhooks to send email notifications based on sensor data.
- Monitoring serial output for troubleshooting.


### Tools Used

- ESP32 Development Board(Hardware)
- Jumper Wires(Hardware)
- Breadboard(Hardware)
- DHT11 Sensor(Hardware)
- Arduino IDE(Software)
- IFTTT Webhooks(Software)
## Steps
- Step 1: Hardware Setup
The connectivity between ESP32 and the DHT11 Sensor is fairly easy as it only has three pins. To connect them, plug the VCC and GND of the DHT11 sensor to their respective pins and then we will connect the data pin of the DHT11 sensor to GPIO13(We used Adafruit ESP32 Feather, you might be using a different microcontroller where you might have to use another pin such as D or D2).

![image0 (1)](https://github.com/user-attachments/assets/f1fca494-b1da-4e50-89a9-1a12096ec19c)
- Step 2: Setting up IFTTT (If This Then That)
Here we used a very simple implementation, if we get a web request an alert is sent to us by email.
<img width="957" alt="image" src="https://github.com/user-attachments/assets/aeda1008-e7b5-43ad-a30f-b71da4d1241a">
<img width="959" alt="image" src="https://github.com/user-attachments/assets/8220d3e7-104e-4209-90d8-2268b6a3e683">
- Step 3: Programming the ESP32 board 
 View the attached ino file for full code with comments and try it yourself!
- Step 4: Testing the solution
<img width="718" alt="image" src="https://github.com/user-attachments/assets/2c364822-b287-47e6-9b1e-0278fa0f84b1">

<img width="541" alt="image" src="https://github.com/user-attachments/assets/87444c41-41fa-40df-ad80-09b37a966460">

<img width="920" alt="image" src="https://github.com/user-attachments/assets/4cda3021-a4a1-4e18-bb64-74196d7f0266">
