// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: December 2019
// Splashscreen and fade for the GameBoy

#include <stdio.h>
#include <gb/gb.h>
#include "menu_data.c"
#include "menu_map.c"

void performantdelay(UINT8 numloops) {
    UINT8 ii;
    for (ii = 0; ii < numloops; ii++) {
        wait_vbl_done();
    }
}

void fadeout() {
    int i;
    for (i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xE4;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xFE;
                break;
            case 3:
                BGP_REG = 0xFF;
                break;
        }
    performantdelay(100);
    }
}

void fadein() {
    int i;
    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xFE;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xE4;
                break;
        }
    performantdelay(100);
    }
}

void main() {
    // Splash screen on the GameBoy

    set_bkg_data(0, 39, menu_data);
    set_bkg_tiles(0, 0, 20, 18, menu_map);

    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);

    fadeout();
    printf("Faded");
    fadein();
}
