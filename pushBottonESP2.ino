// Used libraries
#include <ESP8266WiFi.h>

//Defining variables.
#define botao_1 D1
#define botao_2 D2
#define botao_3 D0
#define botao_4 D5
#define ssid "TP-LINK_89AC"
#define password "70796889"

const uint16_t port = 65432;
const char * host = "10.32.0.68";

// P is the value that will be send to 'Server'

// We set up our serial port, and use a while loop to wait until it begins. Since this code will trigger after pressing the reset button, we print “Button Pressed” to the serial monitor.
//Then, we tell the NodeMCU to go into deep sleep until the button connecting the wakePin to the RST pin is pressed.
void setup() {

  pinMode(botao_1, INPUT);
  pinMode(botao_2, INPUT);
  pinMode(botao_3, INPUT);
  pinMode(botao_4, INPUT);

  Serial.begin(9600);
  while (!Serial) {
  }
  connectToWifi(); // Calling the function to connect
}

// Create a function for connecting to your Wi-Fi network
void connectToWifi() {
  Serial.print("Connecting to: NAME ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  Serial.println(" ");
  Serial.print("Attempting to connect: ");

  //Warning while you don't connect on the internet
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("No internet connection yet... ");
    Serial.println(" ");

  }

  //print a positive connection result
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected.");
    Serial.println(" ");
    Serial.print("NodeMCU ip address: ");
    Serial.println(WiFi.localIP());
    Serial.println(" ");
  }
}

// Function to send the post to our Server in Python
void sendPost(int p) {
  Serial.println(p);
  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println(" ");
    Serial.println("Post not sent! ERROR!!");
    Serial.println(" ");
    delay(1000);

  }
  else {
    Serial.println(" ");
    Serial.println("Connected to server successful!");
    client.print(p);
    Serial.println("Post sent!" );
    client.stop();
    Serial.println(" ");
    delay(1000);
  }
}

void loop() {
  WiFiClient client;

  if (digitalRead(botao_1) == HIGH) {
    sendPost(1);
  }
  else if (digitalRead(botao_2) == HIGH) {
    sendPost(2);
  }
  else if (digitalRead(botao_3) == HIGH) {
    sendPost(3);
  }
  else if (digitalRead(botao_4) == HIGH) {
    sendPost(4);
  }
}
