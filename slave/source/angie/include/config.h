#ifndef CONFIG_INCLUDED
#define CONFIG_INCLUDED

/* copy of core/config.h */

typedef struct _CONFIG {
    struct {
        BOOL bHV;
        BOOL bSSE5; // SSE4.2
        BOOL bSSE4; // SSE4.1
        BOOL bSSE3;
        BOOL bAES;
    } Features;

    struct {
        BOOL bIntel;
        BOOL bAmd;
        BOOL bUnderWow64;
    } Cpu;

    struct {
        union {
            struct {
                BOOLEAN     bMicrosoft;
                BOOLEAN     bVmware;
                BOOLEAN NON bPadding;
                BOOLEAN     bParallels;
            };

            BOOL bEnabled;
        };
    } HyperVisor;

    struct {
        NTVERSION Major;
        NTVERSION Minor;
        NTVERSION Build;
        BOOL      bIsDeprecated;
        ULONG     dwCommonIndex;
    } NtVersion;
} CONFIG, *PCONFIG;

extern DECLSPEC_DLLEXPORT CONFIG Config;

#endif
