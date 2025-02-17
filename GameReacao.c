
#include "Adafruit_SSD1306.h"
#include "pico/stdlib.h"
#include <hardware/i2c.h>      

#define SCREEN_HEIGHT 64
#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5


#define BUTTON_PIN_1  10  
#define BUTTON_PIN_2  11  


unsigned long startMillis;
unsigned long reactionTime;
bool gameStarted = false;
bool buttonPressed = false;

void init_i2c() {
    i2c_init(I2C_PORT, 100000); 
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
}

void setup() {
  
  stdio_init_all();
  

  init_i2c();
  pico_oled_init();  
  pico_oled_clear(); 
  pico_oled_set_text_size(1); 
  pico_oled_set_text_color(WHITE); 

  gpio_init(BUTTON_PIN_1);
  gpio_set_dir(BUTTON_PIN_1, GPIO_IN);
  gpio_pull_up(BUTTON_PIN_1);
  
  gpio_init(BUTTON_PIN_2);
  gpio_set_dir(BUTTON_PIN_2, GPIO_IN);
  gpio_pull_up(BUTTON_PIN_2);
}

void loop() {

  if (!gameStarted && gpio_get(BUTTON_PIN_1) == 0) {
    gameStarted = true;
    pico_oled_clear();
    pico_oled_set_cursor(0, 0);
    pico_oled_write("Prepare-se...", false); 
    pico_oled_display();  
    sleep_ms(1000);  
    startMillis = to_ms_since_boot(get_absolute_time());  
    pico_oled_clear();
  }
  
  if (gameStarted) {
   
    if (gpio_get(BUTTON_PIN_2) == 0 && !buttonPressed) {
      reactionTime = to_ms_since_boot(get_absolute_time()) - startMillis;
      buttonPressed = true;
      
      pico_oled_clear();
      pico_oled_set_cursor(0, 0);
      pico_oled_write("Tempo de Reacao: ", false);
      pico_oled_write(itoa(reactionTime), false);  
      pico_oled_write(" ms", false);
      pico_oled_display();  

      sleep_ms(2000);  
      gameStarted = false;
      buttonPressed = false;
    }
  }
}

int main() {
  setup();
  while (1) {
    loop();
  }
}
