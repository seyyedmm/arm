
#include "lm016.h"

void send_command(unsigned char data)
{
  HAL_Delay(40);
  HAL_GPIO_WritePin(GPIOB,(1<<rs_port),GPIO_PIN_RESET);
  //HAL_GPIO_WritePin(CTRL_PORT,(1<<rw_port),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,(0xFF<<data_ports[0]),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,(data<<data_ports[0]),GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB,(1<<en_port),GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB,(1<<en_port),GPIO_PIN_RESET);
}

void lcd_putchar(lcd_t * lcd, uint8_t character)
{
  HAL_Delay(5);
  HAL_GPIO_WritePin(GPIOB,(1<<rs_port),GPIO_PIN_SET);
  //HAL_GPIO_WritePin(CTRL_PORT,(1<<rw_port),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,(0xFF<<data_ports[0]),GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,(character<<data_ports[0]),GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB,(1<<en_port),GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB,(1<<en_port),GPIO_PIN_RESET);
}

void lcd_init(lcd_t * lcd)
{
  HAL_Delay(5);
  send_command(0x38);
  send_command(0x06);
  send_command(0x0c);
}

void lcd_puts(lcd_t * lcd, char *str)
{
  HAL_Delay(5);
  while(*str != 0)
  {
    lcd_putchar(*str);
    str++;
  }
}

void lcd_set_curser(lcd_t * lcd, uint16_t row, uint16_t col)
{
  HAL_Delay(5);
 
    switch(col){
    case 0:
      send_command( 0x80 + row );
    break;
    case 1:
      send_command( 0xC0 + row );
      break;
    case 2:
      send_command( 0x94 + row );
      break;
    case 3:
      send_command( 0xD4 + row );
  }
}

void lcd_clear(lcd_t * lcd)
{
  HAL_Delay(5);
  send_command(0x01);
  send_command(0x02);
}

int main (void)
{
 lcd_t lcd;
 lcd.en_pin = GPIOB_PIN_0;
 lcd.rs_pin = GPIOB_PIN_1;
 lcd.data_pins = GPIOA_PIN;

  send_command();
  lcd_putchar(lcd_t * lcd, uint8_t character)

}