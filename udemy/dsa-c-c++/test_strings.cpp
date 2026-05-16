#include <iostream>
#include <string>
#include <cstdint>

// Windows API for process memory info
#include <windows.h>
#include <psapi.h>

using namespace std;

/**
 * @brief Demonstrates C++ string memory profiling using:
 *   - Direct address inspection (stack vs heap detection)
 *   - SSO (Small String Optimization) detection
 *   - Windows API: GetProcessMemoryInfo (working set, page faults, etc.)
 *
 * @returns 0 on successful execution
 */

// ---------- helpers ---------------------------------------------------------

/// Print process memory counters via Windows PSAPI
void printProcessMemory(const char* label) {
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        cout << "\n--- Process Memory (" << label << ") ---\n";
        cout << "  Working Set Size      : " << pmc.WorkingSetSize / 1024       << " KB\n";
        cout << "  Peak Working Set      : " << pmc.PeakWorkingSetSize / 1024   << " KB\n";
        cout << "  Page Fault Count      : " << pmc.PageFaultCount              << "\n";
        cout << "  Pagefile Usage        : " << pmc.PagefileUsage / 1024        << " KB\n";
        cout << "  Peak Pagefile Usage   : " << pmc.PeakPagefileUsage / 1024    << " KB\n";
    } else {
        cerr << "  GetProcessMemoryInfo failed (error " << GetLastError() << ")\n";
    }
}

/// Detect whether a string's character buffer lives inside the object (SSO) or on the heap.
/// Works by checking if the data pointer falls within the address range of the object itself.
bool isSSO(const string& s) {
    const void* objStart = &s;
    const void* objEnd   = reinterpret_cast<const char*>(&s) + sizeof(s);
    const void* dataPtr  = s.data();
    return (dataPtr >= objStart && dataPtr < objEnd);
}

/// Dump detailed info about one std::string variable
void inspectString(const char* name, const string& s) {
    cout << "\n  [" << name << "]\n";
    cout << "    sizeof(string)     : " << sizeof(s)      << " bytes  (object size on stack)\n";
    cout << "    length()           : " << s.length()      << "\n";
    cout << "    capacity()         : " << s.capacity()    << "\n";
    cout << "    Object address     : " << (const void*)&s << "  (stack)\n";
    cout << "    Data pointer (.data): " << (const void*)s.data() << "\n";
    cout << "    SSO active?        : " << (isSSO(s) ? "YES (data inside object — stack)" 
                                                      : "NO  (data on HEAP)")           << "\n";
    if (!isSSO(s)) {
        cout << "    Heap bytes used    : " << s.capacity() + 1 << " (capacity + null terminator)\n";
    }
}

// ---------- main ------------------------------------------------------------

int main()
{
    printProcessMemory("before any strings");

    // --- basic string ops (from original code) ---
    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + " " + str2;
    cout << "\nstr3: " << str3 << endl;

    string str4 = "Hello";
    string str5 = "Hello";
    cout << "str4 == str5: " << (str4 == str5) << endl;

    // Large string — definitely exceeds SSO
    string str6 = "HelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHello";

    // --- memory inspection ---
    cout << "\n========== STRING MEMORY INSPECTION ==========\n";
    inspectString("str1 (\"Hello\")", str1);
    inspectString("str3 (\"Hello World\")", str3);
    inspectString("str6 (1180-char string)", str6);

    // --- stack layout ---
    cout << "\n========== STACK LAYOUT ==========\n";
    cout << "  &str1 = " << (void*)&str1 << "\n";
    cout << "  &str2 = " << (void*)&str2 << "\n";
    cout << "  &str3 = " << (void*)&str3 << "\n";
    cout << "  &str4 = " << (void*)&str4 << "\n";
    cout << "  &str5 = " << (void*)&str5 << "\n";
    cout << "  &str6 = " << (void*)&str6 << "\n";
    cout << "  Stack span (str1..str6): "
         << abs((intptr_t)&str1 - (intptr_t)&str6) + sizeof(string) << " bytes\n";

    // --- process memory after allocations ---
    printProcessMemory("after all strings");

    return 0;
}
