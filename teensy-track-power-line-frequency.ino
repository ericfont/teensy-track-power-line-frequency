volatile uint32_t firstfallmicros1 = 0;
volatile uint32_t lastfallmicros1 = 0;
volatile uint32_t lastpeak1 = 0;
volatile uint32_t count1 = 0;
volatile uint32_t waitforrising1 = 0;

volatile uint32_t firstfallmicros2 = 0;
volatile uint32_t lastfallmicros2 = 0;
volatile uint32_t lastpeak2 = 0;
volatile uint32_t count2 = 0;
volatile uint32_t waitforrising2 = 0;

void pinMode_INPUT_PULLUP_100K(uint8_t pin)
{
  const struct digital_pin_bitband_and_config_table_struct *p;

  if (pin >= CORE_NUM_DIGITAL) return;
  p = digital_pin_to_info_PGM + pin;
  *(p->reg + 1) &= ~(p->mask); // TODO: atomic
  *(p->pad) = IOMUXC_PAD_DSE(7) | IOMUXC_PAD_PKE | IOMUXC_PAD_PUE | IOMUXC_PAD_PUS(2) | IOMUXC_PAD_HYS;
  *(p->mux) = 5 | 0x10;
}

void setup() {
  ARM_DEMCR |= ARM_DEMCR_TRCENA;
  ARM_DWT_CTRL |= ARM_DWT_CTRL_CYCCNTENA;
  
  pinMode_INPUT_PULLUP_100K(23);
  attachInterrupt(digitalPinToInterrupt(23), pinFallingInterrupt1, FALLING);
  
  pinMode_INPUT_PULLUP_100K(22);
  attachInterrupt(digitalPinToInterrupt(22), pinFallingInterrupt2, FALLING);
  
  pinMode_INPUT_PULLUP_100K(21);
  
  Serial.begin(12000000);
}

void loop() {
  
  noInterrupts ();
  uint32_t mycount1 = count1;
  uint32_t mycount2 = count2;
  uint32_t duration1 = lastfallmicros1 - firstfallmicros1;
  uint32_t duration2 = lastfallmicros2 - firstfallmicros2;
  waitforrising1 = 0;
  waitforrising2 = 0;
  count1 = -1;
  count2 = -1;
  interrupts ();
  
  Serial.print((1000000.0f * mycount1 / duration1 - 60.0f) * 100.0f / 60.0f, 6);
  Serial.print("\t");
  Serial.print((1000000.0f * mycount2 / duration2 - 60.0f) * 100.0f / 60.0f, 6);
  Serial.print("\n");
  
/*
  Serial.print("Count1 = ");
  Serial.print(mycount1);
  Serial.print(" in ");
  Serial.print(duration1);
  Serial.print(" microseconds for rate of ");
  Serial.print((float) duration1 / mycount1);
  Serial.println(" teensy microseconds per cycle.");
  
  Serial.print("Count2 = ");
  Serial.print(mycount2);
  Serial.print(" in ");
  Serial.print(duration2);
  Serial.print(" microseconds for rate of ");
  Serial.print((float) duration2 / mycount2);
  Serial.println(" teensy microseconds per cycle.");
*/
  delay(1000);
}

void pinFallingInterrupt1() {
  uint32_t currMicros = micros();
  
  if( currMicros < waitforrising1 )
    return;
    
  if( count1 == -1 ) {
    firstfallmicros1 = currMicros;
  }
  count1++;
  lastfallmicros1 = currMicros;
  waitforrising1 = currMicros + 8000;
}

void pinFallingInterrupt2() {
  uint32_t currMicros = micros();
  
  if( currMicros < waitforrising2 )
    return;
    
  if( count2 == -1 ) {
    firstfallmicros2 = currMicros;
  }
  count2++;
  lastfallmicros2 = currMicros;
  waitforrising2 = currMicros + 8000;
}
