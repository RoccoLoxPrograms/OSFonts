#include <fontlibc.h>
#include <graphx.h>
#include <tice.h>
#include <keypadc.h>
#include <stdint.h>

#define OS_LARGEFONT true
#define OS_SMALLFONT false

static void displayFont(bool fontDisplayed, fontlib_font_t *fontLarge, fontlib_font_t *fontSmall) {
    int character = 0;
    int fontY = 1;
    int fontXmax = 194;
    int fontYinc = 12;
    fontlib_SetFont(fontSmall, 0);
    if (fontDisplayed == OS_LARGEFONT) {
        fontlib_SetFont(fontLarge, 0);
        fontXmax = 218;
        fontYinc = 16;
    }
    gfx_FillScreen(255);
    while (character < 256) { // display contents of font
        for (uint8_t fontX = 2; fontX < fontXmax; fontX += 12) {
            fontlib_SetCursorPosition(fontX, fontY);
            if (character < 256) fontlib_DrawGlyph(character);
            character++;
        }
        fontY += fontYinc;
    }
}

int main(void) {
    fontlib_font_t *fontLarge = fontlib_GetFontByIndex("OSLFONT", 0);
    fontlib_font_t *fontSmall = fontlib_GetFontByIndex("OSsfont", 0);
    if (!(fontLarge && fontSmall)) { // if the fonts aren't installed
        os_ClrHome();
        os_RunIndicOn();
        os_PutStrFull("This program requires");
        boot_NewLine();
        os_PutStrFull("OSLFONT and OSsfont");
        boot_NewLine();
        os_PutStrFull("to be installed.");
        while (!os_GetCSC());
        exit(0);
    }
    gfx_Begin();
    fontlib_SetTransparency(true);
    bool fontDisplayed = OS_LARGEFONT;
    bool keyPressed;
    displayFont(OS_LARGEFONT, fontLarge, fontSmall);
    while (kb_AnyKey());
    while (!(kb_IsDown(kb_KeyClear))) {
        kb_Scan();
        if (!kb_AnyKey()) keyPressed = true;
        if (kb_IsDown(kb_KeyEnter) && fontDisplayed == OS_SMALLFONT && keyPressed) break;
        if ((kb_Data[7] || kb_IsDown(kb_KeyEnter)) && keyPressed) {
            keyPressed = false;
            if (kb_Data[7]) {
                if ((kb_IsDown(kb_KeyRight) || kb_IsDown(kb_KeyDown)) && fontDisplayed == OS_LARGEFONT) {
                    fontDisplayed = OS_SMALLFONT;
                } else if ((kb_IsDown(kb_KeyLeft) || kb_IsDown(kb_KeyUp)) && fontDisplayed == OS_SMALLFONT) {
                    fontDisplayed = OS_LARGEFONT;
                }
            } else if (kb_IsDown(kb_KeyEnter) && fontDisplayed == OS_LARGEFONT) {
                fontDisplayed = OS_SMALLFONT;
            }
            displayFont(fontDisplayed, fontLarge, fontSmall);
        }
    }
    while (kb_AnyKey());
    gfx_End();
}
