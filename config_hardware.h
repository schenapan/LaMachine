#ifndef CONFIG_HARDWARE_H
#define CONFIG_HARDWARE_H

/***********************************
 * Configuration Hardware
 */

// RFID
#define RST_PIN 9
#define SS_PIN 10

// LEDs
#define NB_LED  3
extern unsigned char led_tbl[NB_LED];

#define LED_LEVEL_ON  HIGH
#define LED_LEVEL_OFF LOW

// MP3
#define MP3_SOFT_TX_PIN 2
#define MP3_SOFT_RX_PIN 3
#define MP3_DEFAULT_SOUND_LEVEL 0x1E // range is 0x00 to 0x1E
#define MP3_DEFAULT_DEVICE  2 // SD card
#define MP3_UART_SPEED  9600

// Relay
#define EXT_RELAY_PIN 4
#define EXT_RELAY_DELAY_MS 10000 // time to close relay in ms


#endif // CONFIG_HARDWARE_H
