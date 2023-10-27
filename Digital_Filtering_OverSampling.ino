// This code increases the ADC value, improves the accuracy of the ADC, and applies average filtering.
// Only used 4 bytes of RAM as a buffer

#define OVERSAMPLING_RATIO 500 // This increase the accuracy and average filtering
#define RESOLUTION_INCREASE 10 // This increase the ADC value, in this case from 0-1024 to 0-10240

void setup() {
  Serial.begin(9600);
}

void loop() {

  while (1) {
    
        // Buffer to store the sampling values
        // uint32_t can hold a max of 2147483647, and 500 x 1024 = 512000, so that fits within a 32-bit integer.
        uint32_t oversampledValue = 0; 

        // Perform oversampling
        for (int i = 0; i < OVERSAMPLING_RATIO; i++) {
            uint16_t adcValue = ( analogRead(2) * RESOLUTION_INCREASE); // Read the ADC value and multiply to get higher resolution
            oversampledValue += (uint32_t)adcValue; // Accumulate the values
        }

        // Calculate the average
        uint32_t averagedValue = oversampledValue / OVERSAMPLING_RATIO;

        // Do something with the output value (e.g.,serial out, output to LEDs, etc.)
        Serial.println(averagedValue);

        delay(100); 
  }       
}
