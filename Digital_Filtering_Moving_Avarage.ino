// The moving average filter.

// Filter defines
#define FILTER_SIZE 4  // Number of samples to average

// Initialize variables for the filter
uint16_t filterValues[FILTER_SIZE];
uint8_t filterIndex = 0;
uint16_t filteredValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Main loop
  while (1) {
    
      // Read an ADC value
      uint16_t adcValue = analogRead(2);

      // Update the filter values array
      filterValues[filterIndex] = adcValue;
      filterIndex = (filterIndex + 1) % FILTER_SIZE;

      // Calculate the moving average
      filteredValue = 0;
      for (uint8_t i = 0; i < FILTER_SIZE; i++) {
          filteredValue += filterValues[i];
      }
      filteredValue /= FILTER_SIZE;

      // Do something with the filtered value (e.g., output to LEDs, etc.)
      Serial.println(filteredValue);
      
      // Delay for a short time
      _delay_ms(100);
  }      
}
