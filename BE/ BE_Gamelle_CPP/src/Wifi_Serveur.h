#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <sstream>
#include "Arduino.h"
#include "Affichage.h"

// Classe pour le serveur web
class WifiServer
{
// Création des objets privés
private:
  const char *ssid;
  const char *password;
  ESP8266WebServer server;

public:
  int choix = 0;
  // Constructeur pour initialiser les variables privées
  WifiServer(const char *ssid, const char *password)
      : ssid(ssid), password(password), server(80) {}

  // Méthode pour afficher la page web
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

  // Destructeur pour fermer le serveur
  ~WifiServer() { server.close(); }

  // Méthode pour gérer le choix 1
  void handleChoix1()
  {
    choix = 1;
  }

  // Méthode pour gérer le choix 2
  void handleChoix2()
  {
    choix = 2;
  }

  // Méthode pour gérer le choix 0
  void handleNoButtonPressed()
  {
    choix = 0;
  }

// Méthode pour se connecter au réseau WiFi
  void setup()
  {
    // Connexion au réseau WiFi
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    // Commencez par connecter un réseau WiFi
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
    server.on("/", std::bind(&WifiServer::handleRoot, this));

    server.on("/Choix1", std::bind(&WifiServer::handleChoix1, this));
    server.on("/Choix2", std::bind(&WifiServer::handleChoix2, this));
    server.begin(); // Actually start the server
    Serial.println("HTTP server started");
  }

  // Méthode pour gérer les requêtes du serveur
  void loop()
  {
    server.handleClient(); // Handle client requests
  }
};
