#include <stdio.h>
#include <stdint.h>

// Structure to represent individual LED settings
typedef struct {
    uint8_t state;      // 1 for ON, 0 for OFF
    uint8_t brightness; // 0 to 255
    uint32_t color;     // RGB color value
} LEDSettings;

// Structure to represent a group of LEDs
typedef struct {
    LEDSettings singleLED; // Individual LED settings
    uint8_t groupState;    // 1 for all ON, 0 for all OFF
    uint8_t groupBrightness; // Group brightness adjustment
} LEDGroup;

// Function to initialize LED Group
void initLEDGroup(LEDGroup *group) {
    group->singleLED.state = 0;
    group->singleLED.brightness = 0;
    group->singleLED.color = 0;
    group->groupState = 0;
    group->groupBrightness = 0;
}

// Function to update LED Group Settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness,
                            uint8_t state, uint8_t brightness, uint32_t color) {
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;
}

// Function to display LED Group Status
void displayLEDGroupStatus(const LEDGroup *group) {
    printf("Individual LED Status:\n");
    printf("  State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("  Brightness: %d\n", group->singleLED.brightness);
    printf("  Color (RGB): 0x%06X\n", group->singleLED.color);
    
    printf("Group Status:\n");
    printf("  Group State: %s\n", group->groupState ? "ALL ON" : "ALL OFF");
    printf("  Group Brightness: %d\n", group->groupBrightness);
}

// Main function for testing
int main() {
    LEDGroup myLEDGroup;
    
    // Initialize the LED group
    initLEDGroup(&myLEDGroup);
    printf("Initial LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);
    
    printf("\nUpdating LED Group Settings...\n");
    // Update LED group settings
    updateLEDGroupSettings(&myLEDGroup, 1, 200, 1, 255, 0xFF0000);
    
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);
    
    return 0;
}
