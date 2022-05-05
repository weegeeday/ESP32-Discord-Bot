#include <WiFi.h>
#include <WebServer.h>

/*Put your SSID & Password*/
const char* ssid = " YourNetworkName";  // Enter SSID here
const char* password = " YourPassword";  //Enter Password here
// Set your Static IP address This will help for settings.py it should serial print the data.
// make sure to uncomment the code when you get the data. here and in SETUP
//IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
//IPAddress gateway(192, 168, 1, 1);

//IPAddress subnet(255, 255, 0, 0);
//IPAddress primaryDNS(8, 8, 8, 8);   // optional
//IPAddress secondaryDNS(8, 8, 4, 4); // optional

WebServer server(80);

uint8_t Ppin = 26;
bool lshorts = 0;
bool mshorts = 0;
bool hshorts = 0;
bool llongs = 0;
bool mlongs = 0;
bool hlongs = 0;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(Ppin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);
  //WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS) //read above
  //connect to your local wi-fi network
  WiFi.begin(ssid, password);
  
  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("save this and use it in the fixed wifi ips things: ");  Serial.println(WiFi.localIP());
  Serial.println(WiFi.get.config())
  Serial.print("if you didnt get the ips you need, use ipconfig or similar and use the ip given.")

  server.on("/", handle_OnConnect);
  server.on("/lshort", handle_lshort);
  server.on("/mshort", handle_mshort);
  server.on("/hshort", handle_hshort);
  server.on("/llong", handle_llong);
  server.on("/mlong", handle_llong);
  server.on("/hlong", handle_llong);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(lshorts)
  {analogWrite(Ppin, 70);}
  else
  {analogWrite(Ppin, 0);}
  
  if(mshorts)
  {analogWrite(Ppin, 150);}
  else
  {analogWrite(Ppin, 0);}
    
  if(hshorts)
  {analogWrite(Ppin, 230);}
  else
  {analogWrite(Ppin, 0);}
    
  if(llongs)
  {analogWrite(Ppin, 70);}
  else
  {analogWrite(Ppin, 0);}
    
  if(mlongs)
  {analogWrite(Ppin, 150);}
  else
  {analogWrite(Ppin, 0);}
      
  if(hlongs)
  {analogWrite(Ppin, 230);}
  else
  {analogWrite(Ppin, 0);}
}

void handle_OnConnect() {
  lshorts = 0;
  mshorts = 0;
  hshorts = 0;
  llongs = 0;
  mlongs = 0;
  hlongs = 0;
  server.send(200, "text/html", SendHTML(lshorts,mshorts,hshorts,llongs,mlongs,hl)); 
}

void handle_lshort() {
  lshorts = 1;
  Serial.println("lshorts Status: ON");
  server.send(200, "text/html", SendHTML(true,lshorts));
  delay(1500);
  lshorts = 0;
  Serial.println("lshorts Status: OFF");
  server.send(200, "text/html", SendHTML(false,lshorts)); 
}

void handle_mshort() {
  mshorts = 1;
  Serial.println("mshorts Status: ON");
  server.send(200, "text/html", SendHTML(true,mshorts));
  delay(1500);
  mshorts = 0;
  Serial.println("mshorts Status: OFF");
  server.send(200, "text/html", SendHTML(false,mshorts));  
}

void handle_hshort() { //copy this and edit it for lshort,mshort,etc.
  hshorts = 1;
  Serial.println("hshorts Status: ON");
  server.send(200, "text/html", SendHTML(true,hshorts));
  delay(1500);
  hshorts = 0;
  Serial.println("hshorts Status: OFF");
  server.send(200, "text/html", SendHTML(false,hshorts));  
}

void handle_llong() {
  llongs = 1;
  Serial.println("llong Status: ON");
  server.send(200, "text/html", SendHTML(true,llongs));
  delay(3500);
  llongs = 0;
  Serial.println("llongs Status: OFF");
  server.send(200, "text/html", SendHTML(false,llongs));  
}

void handle_mlong() {
  mlongs = 1;
  Serial.println("mlong Status: ON");
  server.send(200, "text/html", SendHTML(true,mlongs));
  delay(3500);
  mlongs = 0;
  Serial.println("mlongs Status: OFF");
  server.send(200, "text/html", SendHTML(false,mlongs)); 
}

void handle_hlong() {
  hlongs = 1;
  Serial.println("hlong Status: ON");
  server.send(200, "text/html", SendHTML(true,hlongs));
  delay(3500);
  hlongs = 0;
  Serial.println("hlongs Status: OFF");
  server.send(200, "text/html", SendHTML(false,hlongs)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
void handle_d(){
  delay(500);
}

String SendHTML(uint8_t lshorts,uint8_t mshorts,uint8_t hshorts,uint8_t llongs,uint8_t mlongs,uint8_t hlongs){ //add more buttons, change names, make sure to add void names to this line!
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Device</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-ls {background-color: #3498db;}\n";
  ptr +=".button-ls:active {background-color: #2980b9;}\n";
  ptr +=".button-ms {background-color: #34495e;}\n";
  ptr +=".button-ms:active {background-color: #2c3e50;}\n";
  ptr +=".button-hs {background-color: #34495e;}\n";
  ptr +=".button-hs:active {background-color: #2c3e50;}\n";
  ptr +=".button-ll {background-color: #34495e;}\n";
  ptr +=".button-ll:active {background-color: #2c3e50;}\n";
  ptr +=".button-ml {background-color: #34495e;}\n";
  ptr +=".button-ml:active {background-color: #2c3e50;}\n";
  ptr +=".button-hl {background-color: #34495e;}\n";
  ptr +=".button-hl:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
    ptr +="<h3>Using Station(STA) Mode</h3>\n";
  
   if(lshorts)
  {ptr +="<p>LED1 Status: ON</p><a class=\"button button-ls\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>LED1 Status: OFF</p><a class=\"button button-ls\" href=\"/lshort\">ON</a>\n";}

  if(mshorts)
  {ptr +="<p>mshorts Status: ON</p><a class=\"button button-ms\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>mshorts Status: OFF</p><a class=\"button button-ms\" href=\"/mshort\">ON</a>\n";}
  
  if(hshorts)
  {ptr +="<p>mshorts Status: ON</p><a class=\"button button-hs\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>mshorts Status: OFF</p><a class=\"button button-hs\" href=\"/hshort\">ON</a>\n";}
  
  if(llongs)
  {ptr +="<p>mshorts Status: ON</p><a class=\"button button-ll\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>mshorts Status: OFF</p><a class=\"button button-ll\" href=\"/llong\">ON</a>\n";}
  
  if(mlongs)
  {ptr +="<p>mshorts Status: ON</p><a class=\"button button-ml\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>mshorts Status: OFF</p><a class=\"button button-ml\" href=\"/mlong\">ON</a>\n";}
  
  if(hlongs)
  {ptr +="<p>mshorts Status: ON</p><a class=\"button button-hl\" href=\"/d\">OFF</a>\n";}
  else
  {ptr +="<p>mshorts Status: OFF</p><a class=\"button button-hl\" href=\"/hlong\">ON</a>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}