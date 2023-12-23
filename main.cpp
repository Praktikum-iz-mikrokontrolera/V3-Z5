#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C magistrala(PB_14, PB_13);
Adafruit_SSD1306_I2c ekran(magistrala, PA_13, 0x78, 64, 128);


int main() {
	while(true) {
		ekran.clearDisplay();
		ekran.setTextCursor(0, 0);
		int randomBroj = rand() % 10;
		ekran.printf("Bilo koja poruka %d \n", randomBroj);
		ekran.drawRect(0, 16, 128, 32, WHITE);
		ekran.fillRect(0, 16, 128, 32, WHITE);

		ekran.drawCircle(64, 32, 8, BLACK);
		ekran.fillCircle(64, 32, 8, BLACK);
		ekran.drawTriangle(0, 0, 128, 0, 64, 64, WHITE);
		ekran.display();
		ThisThread::sleep_for(5s);
	}
	return 0;
}
