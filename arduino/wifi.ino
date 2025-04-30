#include <esp32cam.h>
#include <WebServer.h>
#include <WiFi.h>

#define WIFI_SSID "YOUR_WIFI_SSID_HERE"  // Replace with your WiFi SSID
#define WIFI_PASS "YOUR_WIFI_PASSWORD_HERE"  // Replace with your WiFi password

WebServer server(80);

// Function to handle image capture when /capture.jpg is requested
void handleCapture(){
  auto img = esp32cam::capture();
  if (img == nullptr){
    server.send(500, "","");
    return;
  }
  server.setContentLength(img->size());
  server.send(200, "image/jpeg");
  WiFiClient client = server.client();
  img->writeTo(client);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");

  // Connect to the existing WiFi network
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");

  // Print the assigned IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Camera setup
  auto res = esp32cam::Resolution::find(640,480);
  esp32cam::Config cfg;
  cfg.setPins(esp32cam::pins::AiThinker);
  cfg.setResolution(res);
  cfg.setJpeg(80);
  bool cameraInitialized = esp32cam::Camera.begin(cfg);
  if (!cameraInitialized) {
    Serial.println("Camera initialization failed!");
    return;
  }
  Serial.println("Camera ready!");

  // Start the HTTP server
  server.on("/capture.jpg", handleCapture);
  server.begin();
  Serial.println("HTTP server started!");
}

void loop() {
  server.handleClient();
}
