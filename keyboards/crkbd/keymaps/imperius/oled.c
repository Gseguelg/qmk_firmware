#pragma once

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (!is_keyboard_master()) {
//         return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//     }

//     return rotation;
// }

// void oled_render_boot(bool bootloader) {
//     oled_clear();
//     for (int i = 0; i < 16; i++) {
//         oled_set_cursor(0, i);
//         if (bootloader) {
//             oled_write_P(PSTR("Awaiting New Firmware "), false);
//         } else {
//             oled_write_P(PSTR("Rebooting "), false);
//         }
//     }
//     oled_render_dirty(true);
// }

// bool shutdown_user(bool jump_to_bootloader) {
//     oled_render_boot(jump_to_bootloader);
//     return false;
// }



bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        // Título / estado de capa
        oled_write_P(PSTR("Capa: "), false);
        switch (get_highest_layer(layer_state)) {
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _FLECHASNUM:
                oled_write_P(PSTR("FlechaNum\n"), false);
                break;
            case _FUNSYM:
                oled_write_P(PSTR("FunSym\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Config\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
    }

    return false;
}