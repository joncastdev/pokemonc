#include <allegro.h>

int main(void) {
    // Initialize the Allegro library
    if (allegro_init() != 0) {
        return 1;
    }

    // Install keyboard handler
    install_keyboard();

    // Show a quick message window
    allegro_message("Allegro is running! Press any key to exit.");

    // Wait for user input
    readkey();

    // Clean up and close Allegro system manually
    allegro_exit();

    return 0;
}
END_OF_MAIN()