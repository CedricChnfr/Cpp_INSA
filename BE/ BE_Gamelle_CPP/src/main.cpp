#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Arduino.h"

const char* ssid     = "Redmi Note 10 Pro";
const char* password = "totototo";

const int ledPin = 15;

ESP8266WebServer server(80);   // Create a webserver object that listens for HTTP request on port 80

void handleRoot() {
  String html = R"=====(
  <html>
  <body>
    <button id="onButton">Turn On</button>
    <button id="offButton">Turn Off</button>
    <script>
      document.getElementById("onButton").addEventListener("click", function() {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/LEDOn", true);
        xhr.send();
      });
      document.getElementById("offButton").addEventListener("click", function() {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/LEDOff", true);
        xhr.send();
      });
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
  server.on("/", handleRoot);      // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/LEDOn", handleLEDOn);
  server.on("/LEDOff", handleLEDOff);
  server.begin();                  // Actually start the server
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();           // Handle client requests
}
