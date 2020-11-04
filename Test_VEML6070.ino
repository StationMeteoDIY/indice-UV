#include <Wire.h>
#include "Adafruit_VEML6070.h"
// inclure librairie VEML6070 depuis le gestionnaire de library, ou via : https://github.com/adafruit/Adafruit_VEML6070

Adafruit_VEML6070 uv = Adafruit_VEML6070();

void setup() {
  Serial.begin(115200);
  Serial.println("VEML6070 Test");
  uv.begin(VEML6070_1_T);  // passer dans la constante de temps d'intégration
}


void loop() {
  uint16_t valeur = uv.readUV();
  String color="";
  String risque="";

  // On vérifie le niveau de risque
  if (valeur < 3) {
    color="Vert"; risque="Faible";
  } else if (valeur < 6) {
    color="Jaune"; risque="Moyen";
  } else if (valeur < 8) {
    color="Orange"; risque="Elevé";
  } else if (valeur < 11) {
    color="Rouge"; risque="Très élevé";
  } else if (valeur >= 11) {
    color="Violet"; risque="Extrémement élevé";
  }
  
  Serial.print("UV light level : "); 
  Serial.println(valeur);
  Serial.print("Identification : "); 
  Serial.print(color);
  Serial.print(", Risque : "); 
  Serial.println(risque);
  
  delay(1000);
} 