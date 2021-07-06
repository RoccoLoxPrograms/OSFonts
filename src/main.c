#include <fontlibc.h>
#include <graphx.h>
#include <tice.h>
#include <keypadc.h>
#include <stdint.h>

void largeFont(fontlib_font_t *font) {
    int16_t i = 0, y = 1;
    gfx_FillScreen(255);
    fontlib_SetFont(font,0);
    while (i < 256) { // display contents of font
        for (uint8_t x = 2; x < 218; x += 12) {
            fontlib_SetCursorPosition(x,y);
            if (i < 256) fontlib_DrawGlyph(i);
            i++;
        }
        y += 16;
    }
}

void smallFont(fontlib_font_t *fonta) {
    int16_t i = 0, y = 1;
    gfx_FillScreen(255);
    fontlib_SetFont(fonta,0);
    while (i < 256) { // display contents of font
        for (uint8_t x = 2; x < 226; x += 14) {
            fontlib_SetCursorPosition(x,y);
            fontlib_DrawGlyph(i);
            i++;
        }
        y += 15;
    }
}

int main(void) {
    fontlib_font_t *font = fontlib_GetFontByIndex("OSLFONT",0);
    fontlib_font_t *fonta = fontlib_GetFontByIndex("OSsfont",0);
    if (!(font && fonta)) { // if the fonts aren't installed
        os_ClrHomeFull();
        os_RunIndicOn();
        os_PutStrLine("This program requires");
        boot_NewLine();
        os_PutStrLine("OSLFONT and OSsfont");
        boot_NewLine();
        os_PutStrLine("to be installed.");
        boot_NewLine();
        boot_NewLine();
        os_PutStrLine("Please install them to run");
        boot_NewLine();
        os_PutStrLine("this program.");
        while (!os_GetCSC());
        exit(0);
    }
    gfx_Begin();
    fontlib_SetForegroundColor(0);
    int8_t displayedFont = 0, displayedClone = 0;
    bool press;
    largeFont(font); // start with the OS large font
    while (kb_AnyKey());
    while (!(kb_Data[6] & kb_Clear)) {
        kb_Scan();
        if (!kb_AnyKey()) press = true;
        if (kb_Data[6] & kb_Enter && displayedFont && press) break;
        if ((kb_Data[7] || kb_Data[6] & kb_Enter) && press) {
            if (kb_Data[7] & kb_Down || kb_Data[7] & kb_Right || kb_Data[6] & kb_Enter) displayedFont = 1; // change displayed font
            if (kb_Data[7] & kb_Up || kb_Data[7] & kb_Left) displayedFont = 0; // change displayed font
            // display the correct font
            if (displayedFont && displayedFont != displayedClone) smallFont(fonta);
            else if (!displayedFont && displayedClone != displayedFont) largeFont(font);
            press = false;
            displayedClone = displayedFont;
        }
    }
    while (kb_AnyKey());
    gfx_End();
}
