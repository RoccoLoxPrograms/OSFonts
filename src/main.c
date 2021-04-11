#include <fontlibc.h>
#include <graphx.h>
#include <tice.h>

int main(void) {
    int i = 0, x, y = 1;
    fontlib_font_t *font = fontlib_GetFontByIndex("OSLFONT",0);
    fontlib_font_t *fonta = fontlib_GetFontByIndex("OSsfont",0);
    if (!(font && fonta)) {
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
    fontlib_SetFont(font,0);
    fontlib_SetForegroundColor(0);
    gfx_FillScreen(255);
    while (i < 256) {
        for (x = 2; x < 218; x += 12) {
            fontlib_SetCursorPosition(x,y);
            if (i < 256) fontlib_DrawGlyph(i);
            i++;
        }
        y += 16;
    }
    while (!os_GetCSC());
    y = 1;
    i = 0;
    gfx_FillScreen(255);
    fontlib_SetFont(fonta,0);
    while (i < 256) {
        for (x = 2; x < 226; x += 14) {
            fontlib_SetCursorPosition(x,y);
            fontlib_DrawGlyph(i);
            i++;
        }
        y += 15;
    }
    while (!os_GetCSC());
    gfx_End();
}
