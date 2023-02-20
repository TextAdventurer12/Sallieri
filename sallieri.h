#ifndef SALLIERI_H
#define SALLIERI_H

// STEAL THIS CODE: https://curl.se/libcurl/c/httpcustomheader.html

#include "sal_gpt.h"    // handles communication with gpt3 (will be updated for chatGPT when api is released)
#include "sal_utau.h"   // handles creation of mp3s using open utau (will probably need some connecting code using c#)
#include <stdio.h>

FILE *sal_converse(char *prompt); // returns a pointer to the mp3 file containing the reply

#ifdef SAL_DISPLAY
#include "sal_display.h"    // this might never be implemented
#endif