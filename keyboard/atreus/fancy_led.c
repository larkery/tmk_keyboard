#include <avr/io.h>
#include <util/delay.h>

// Outputs on PB1-3, all together.
// what's the right design for this
// want to do something in the main loop after keys are processed.

#define SET_LOW() (PORTB &= ~(1 << PB1));
#define SET_HIGH() (PORTB |= (1 << PB1)); // doesn't really matter which pin we use
#define WAVE(d1, d2) {_delay_us(d1); SET_LOW(); _delay_us(d2); SET_HIGH();}
#define WRITE_BIT(b)  {if (b) WAVE(0.349, 1.359) else WAVE(1.359, 0.349);}
#define WRITE_BYTE(b) {WRITE_BIT(b&(1<<0)); WRITE_BIT(b&(1<<1)); WRITE_BIT(b&(1<<2)); WRITE_BIT(b&(1<<3)); \
                       WRITE_BIT(b&(1<<4)); WRITE_BIT(b&(1<<5)); WRITE_BIT(b&(1<<6)); WRITE_BIT(b&(1<<7)); }

void fancy_led_set(uint8_t r, uint8_t g, uint8_t b) {
  // this needs to be cycle-accurate, and it's not at the mo

  // clock out each colour
  // they are designed to be chained, so it is a 1-wire system
  // 50us low resets
  // high maintains
  // 0.35us high, 1.36us low -> 0
  // 1.36us high, 0.35 us low -> 1

  // send reset code
  SET_LOW();
  _delay_us(55);
  SET_HIGH();
  WRITE_BYTE(r);
  WRITE_BYTE(g);
  WRITE_BYTE(b);

  // leave pin high until next time
}
