#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// WiFi credentials
const char* ssid = "SID_NAME";
const char* password = "PWD_NAME";

// MQTT Broker settings
const char* mqtt_server = "176.168.45.34";
const int mqtt_port = 1883;
const char* mqtt_topic = "home/temperature";

// DHT settings
#define DHTPIN 4     // GPIO pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT11 or DHT22

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  String payload = "{\"temperature\": ";
  payload += temperature;
  payload += ", \"humidity\": ";
  payload += humidity;
  payload += ", \"sensor\": \"";
  payload += "sensor_A1_Hillo";
  payload += "\"}";

  Serial.print("Publishing data: ");
  Serial.println(payload);

  client.publish(mqtt_topic, payload.c_str());
  delay(2000);  // Wait 2 seconds between readings
}
