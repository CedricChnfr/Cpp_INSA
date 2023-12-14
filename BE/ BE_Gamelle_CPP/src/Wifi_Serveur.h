#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Arduino.h"

class WiFiLEDServer {
private:
  const char* ssid;
  const char* password;
  const int ledPin;
  ESP8266WebServer server;

public:
int choix=0;
  WiFiLEDServer(const char* ssid, const char* password, int ledPin)
    : ssid(ssid), password(password), ledPin(ledPin), server(80) {}

  void handleRoot() {
    String html = R"=====(
    <html>
    <body>
      <button id="onButton" onclick="handleChoix1()">Choix 1</button>
      <button id="offButton" onclick="handleChoix2()">Choix 2</button>
      <script>
        function handleChoix1() {
          var xhr = new XMLHttpRequest();
          xhr.open("GET", "/Choix1", true);
          xhr.send();
        }

        function handleChoix2() {
          var xhr = new XMLHttpRequest();
          xhr.open("GET", "/Choix2", true);
          xhr.send();
        }
      </script>
    </body>
    </html>
    )=====";
    server.send(200, "text/html", html);
}


void handleLEDOn() {
  digitalWrite(ledPin, HIGH);   // Turn the LED on
}


void handleLEDOff() {
  digitalWrite(ledPin, LOW);    // Turn the LED off
}

void handleChoix1() {
  choix = 1;  // Mettez à jour la variable choix
}

void handleChoix2() {
  choix = 2;  // Mettez à jour la variable choix
}

void handleNoButtonPressed() {
  choix = 0;  // Remet la variable choix à 0
}


  void setup() {
    pinMode(ledPin, OUTPUT);      // Initialize the LED pin as an output
    digitalWrite(ledPin, LOW);    // Turn the LED off by making the voltage HIGH
    Serial.begin(115200);         // Initialize serial communication

    delay(10);

    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  // Print the IP address

    // Configure and start the web server
    server.on("/", std::bind(&WiFiLEDServer::handleRoot, this));
    //server.on("/LEDOn", std::bind(&WiFiLEDServer::handleLEDOn, this));
    //server.on("/LEDOff", std::bind(&WiFiLEDServer::handleLEDOff, this));
    server.on("/Choix1", std::bind(&WiFiLEDServer::handleChoix1, this));
    server.on("/Choix2", std::bind(&WiFiLEDServer::handleChoix2, this));
    server.onNotFound(std::bind(&WiFiLEDServer::handleNoButtonPressed, this)); // Handle when no button is pressed
    server.begin();                  // Actually start the server
    Serial.println("HTTP server started");
  }

  void loop() {
    server.handleClient();           // Handle client requests
  }
};