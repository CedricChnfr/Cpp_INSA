#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <sstream>
#include "Arduino.h"
#include "Affichage.h"
class WiFiLEDServer
{
private:
  const char *ssid;
  const char *password;
  ESP8266WebServer server;

public:
  int choix = 0;
  WiFiLEDServer(const char *ssid, const char *password)
      : ssid(ssid), password(password), server(80) {}

  void handleRoot()
  {
    MonContenu contenu("Projet Gamelle Connecte par Cedric et Simon");

    String html = R"=====(
  <html>
  <body>
    <button id="onButton" onclick="handleChoix1()">Choix 1</button>
    <button id="offButton" onclick="handleChoix2()">Choix 2</button>
    <div id="terminal">)=====" + String(contenu.texte.c_str()) + R"=====(
    </div>
    <br>
    <script>
      function handleChoix1() {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/Choix1", true);
        xhr.send();
        document.getElementById('terminal').innerHTML += 'Choix 1 selectionne<br>';
      }

      function handleChoix2() {
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/Choix2", true);
        xhr.send();
        document.getElementById('terminal').innerHTML += 'Choix 2 selectionne<br>';
      }
    </script>
  </body>
  </html>
  )=====";
    server.send(200, "text/html", html);
  }

  ~WiFiLEDServer() { server.close(); }

  void handleChoix1()
  {
    choix = 1; // Mettez à jour la variable choix
  }

  void handleChoix2()
  {
    choix = 2; // Mettez à jour la variable choix
  }

  void handleNoButtonPressed()
  {
    choix = 0; // Remet la variable choix à 0
  }

  void setup()
  {
    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    // Attendez jusqu'à 30 secondes pour la connexion
    for (int i = 0; i < 300; ++i)
    {
      if (WiFi.status() == WL_CONNECTED)
      {
        // La connexion a réussi, sortez de la boucle
        break;
      }
      delay(100); // Attendez 100 ms avant la prochaine vérification
    }

    // Vérifiez si la connexion a réussi
    if (WiFi.status() != WL_CONNECTED)
    {
      // La connexion a échoué, lancez une exception
      Serial.println("La connexion WiFi a échoué");
      throw "La connexion WiFi a échoué";
    }

    // Configure and start the web server
    server.on("/", std::bind(&WiFiLEDServer::handleRoot, this));

    server.on("/Choix1", std::bind(&WiFiLEDServer::handleChoix1, this));
    server.on("/Choix2", std::bind(&WiFiLEDServer::handleChoix2, this));
    server.begin(); // Actually start the server
    Serial.println("HTTP server started");
  }

  void loop()
  {
    server.handleClient(); // Handle client requests
  }
};
