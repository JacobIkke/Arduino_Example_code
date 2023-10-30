// The Simple average filter.

// Filter defines
#define SAMPLE_NUMBER 256  // Number of samples to average

// Initialize variables for the filter
uint32_t filterValues2;

void setup() {
    Serial.begin(9600);
}

void loop() {
    
    // Calculate the average
    for (uint16_t i = 0; i < SAMPLE_NUMBER; i++) {
        filterValues2 = filterValues2 + analogRead(2);
    }
    filterValues2 = filterValues2 / SAMPLE_NUMBER;
    
    // Do something with the filtered value (e.g., output to LEDs, etc.)
    Serial.println(filterValues2);
    
    // Delay for a short time
    _delay_ms(100);
   
}
