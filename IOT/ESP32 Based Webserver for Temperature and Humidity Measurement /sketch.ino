#include <WiFi.h>
#include <Wire.h>
#include <DHT.h>

// DHT Sensor Type and Pin
#define DHTTYPE DHT11 
#define DHTPin 13 // GPIO13, compatible with Adafruit Feather ESP32

DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;

// Wi-Fi credentials
const char* ssid = "Abdul-Rafeh sin iPhone";
const char* password = "passord12";

// IFTTT Webhook settings
const char* host = "maker.ifttt.com";
const char* privateKey = "dLyyd1rss987kgOeINdfCy";

// Initialize Server
WiFiServer Server(80);

void setup() {
  Serial.begin(115200);
  pinMode(DHTPin, INPUT);
  dht.begin();

  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi Network: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nSuccessfully connected to WiFi.");
  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.localIP());
  Server.begin();
}

void loop() {
  // Read temperature and humidity
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();

  // Debugging output for DHT values
  Serial.print("Temperature: ");
  Serial.println(Temperature);
  Serial.print("Humidity: ");
  Serial.println(Humidity);

  // Send IFTTT event if temperature exceeds threshold
  if (Temperature >= 20) {
    send_event("temp_event");
  }

  // Web Server to display values
  WiFiClient client = Server.available();
  if (client) {
    Serial.println("Web Client connected");

    // Build HTTP response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println("Refresh: 10"); // Page auto-refresh

    // HTML content
    client.println("<!DOCTYPE HTML><html><style>html {font-family: Arial; text-align: center;}</style><body>");
    client.println("<h1>ESP32 with DHT11</h1>");
    client.print("<p>Temperature: "); client.print(Temperature); client.println(" °C</p>");
    client.print("<p>Humidity: "); client.print(Humidity); client.println(" %</p>");
    client.println("</body></html>");
    delay(2000); // Reduce delay to minimize blocking
  }
}

// Send data to IFTTT
void send_event(const char* event) {
  WiFiClient client;

  // Connect to IFTTT
  Serial.print("Connecting to ");
  Serial.println(host);

  if (!client.connect(host, 80)) {
    Serial.println("Connection to IFTTT failed");
    return;
  } else {
    Serial.println("Connected to IFTTT.");
  }

  // Prepare the URL for triggering the event
  String url = "/trigger/" + String(event) + "/with/key/" + privateKey;
  Serial.print("Requesting URL: ");
  Serial.println(url);

  // Send the request
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Process response
  while (client.connected()) {
    if (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    } else {
      delay(50);
    }
  }

  Serial.println("Closing connection");
  client.stop();
}
