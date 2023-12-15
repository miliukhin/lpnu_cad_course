#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <thread>
// try using openProcess
int main()
{
    STARTUPINFOW si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    if (!CreateProcess(
        L"C:\\Windows\\System32\\notepad.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        BELOW_NORMAL_PRIORITY_CLASS, // 0 normal
        NULL,
        NULL,
        &si,
        &pi
    ))
    {
        printf("(-) failed to create process: &ld", GetLastError());
        return EXIT_FAILURE;
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
    TerminateProcess(pi.hProcess, 0);
    return 0;
}
