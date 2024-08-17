//// TESTEANDO ESP 32
// Definir el pin donde está conectado el LED
/*

const int ledPin = 2; // El ESP32 tiene un LED en el pin 2

void setup() {
  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Encender el LED
  digitalWrite(ledPin, HIGH);
  delay(1000); // Esperar 1 segundo
  
  // Apagar el LED
  digitalWrite(ledPin, LOW);
  delay(1000); // Esperar 1 segundo
}

*/

//// HOLA MUNDO EN OLED 1306 Adafruit

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir el ancho y alto de la pantalla
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Crear un objeto para representar la pantalla
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Iniciar la comunicación con la pantalla
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Dirección I2C 0x3C
    Serial.println(F("No se encuentra la pantalla OLED"));
    for(;;); // Detener el programa aquí si no se encuentra la pantalla
  }

  // Limpiar el buffer
  display.clearDisplay();

  // Establecer el tamaño del texto
  display.setTextSize(1);
  
  // Establecer el color del texto
  display.setTextColor(SSD1306_WHITE);
  
  // Establecer la posición del cursor
  display.setCursor(0,0);
  
  // Escribir el mensaje en el buffer
  display.println(F("Hola OLED"));

  // Mostrar en pantalla
  display.display();
}

void loop() {
  // No es necesario hacer nada aquí para este ejemplo
}
