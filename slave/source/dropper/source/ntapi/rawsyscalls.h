
#define NONE 0xFFFFFFFF

#ifdef __INTELLISENSE__
    #define NTDLL_SYSCALL(n, xp, v, w7, w8, w81, w10, w11, w12, w13, w14, w15, w16)
#endif

#ifdef _AMD64_
    NTDLL_SYSCALL("NtClose"                            , 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F, 0x0000000F)
    NTDLL_SYSCALL("NtAllocateVirtualMemory"            , 0x00000015, 0x00000015, 0x00000015, 0x00000016, 0x00000017, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018)
    NTDLL_SYSCALL("NtFreeVirtualMemory"                , 0x0000001B, 0x0000001B, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E)
    NTDLL_SYSCALL("NtWriteVirtualMemory"               , 0x00000037, 0x00000037, 0x00000037, 0x00000038, 0x00000039, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A)
    NTDLL_SYSCALL("NtFlushInstructionCache"            , 0x00000098, 0x000000BF, 0x000000C2, 0x000000D4, 0x000000D6, 0x000000D9, 0x000000DA, 0x000000DC, 0x000000DF, 0x000000E0, 0x000000E1, 0x000000E2)
    NTDLL_SYSCALL("NtCreateThreadEx"                   , NONE      , 0x000000A5, 0x000000A5, 0x000000AF, 0x000000B0, 0x000000B3, 0x000000B4, 0x000000B6, 0x000000B9, 0x000000BA, 0x000000BB, 0x000000BC)
    NTDLL_SYSCALL("NtOpenProcess"                      , 0x00000023, 0x00000023, 0x00000023, 0x00000024, 0x00000025, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026)
    NTDLL_SYSCALL("NtQuerySystemInformation"           , 0x00000033, 0x00000033, 0x00000033, 0x00000034, 0x00000035, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036)
    NTDLL_SYSCALL("NtQueryInformationProcess"          , 0x00000016, 0x00000016, 0x00000016, 0x00000017, 0x00000018, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019)
    NTDLL_SYSCALL("NtWriteFile"                        , 0x00000005, 0x00000005, 0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000008, 0x00000008, 0x00000008, 0x00000008, 0x00000008, 0x00000008)
    NTDLL_SYSCALL("NtReadFile"                         , 0x00000003, 0x00000003, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000006, 0x00000006, 0x00000006, 0x00000006, 0x00000006, 0x00000006)
    NTDLL_SYSCALL("NtCreateFile"                       , 0x00000052, 0x00000052, 0x00000052, 0x00000053, 0x00000054, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055)
    NTDLL_SYSCALL("NtQueryDirectoryFile"               , 0x00000032, 0x00000032, 0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035)
#else
    #if SCFG_DROPPER_NTAPI_STUB_X86_USE_WOW64 == ON
        NTDLL_SYSCALL("NtClose"                            , 0x0000000C, 0x0000000C, 0x0000000C, 0x0000000D, 0x0003000E, 0x0003000F, 0x0003000F, 0x0003000F, 0x0003000F, 0x0003000F, 0x0003000F, 0x0003000F)
        NTDLL_SYSCALL("NtAllocateVirtualMemory"            , 0x00000015, 0x00000015, 0x00000015, 0x00000016, 0x00000017, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018, 0x00000018)
        NTDLL_SYSCALL("NtFreeVirtualMemory"                , 0x0000001B, 0x0000001B, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E, 0x0000001E)
        NTDLL_SYSCALL("NtWriteVirtualMemory"               , 0x00000037, 0x00000037, 0x00000037, 0x00000038, 0x00000039, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A, 0x0000003A)
        NTDLL_SYSCALL("NtFlushInstructionCache"            , 0x00000098, 0x000000BF, 0x000000C2, 0x000C00D4, 0x000C00D6, 0x000C00D9, 0x000C00DA, 0x000C00DC, 0x000C00DF, 0x000C00E0, 0x000C00E1, 0x000C00E2)
        NTDLL_SYSCALL("NtCreateThreadEx"                   , NONE      , 0x000000A5, 0x000000A5, 0x000000AF, 0x000000B0, 0x000000B3, 0x000000B4, 0x000000B6, 0x000000B9, 0x000000BA, 0x000000BB, 0x000000BC)
        NTDLL_SYSCALL("NtOpenProcess"                      , 0x00000023, 0x00000023, 0x00000023, 0x00000024, 0x00000025, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026, 0x00000026)
        NTDLL_SYSCALL("NtQuerySystemInformation"           , 0x00000033, 0x00000033, 0x00000033, 0x00000034, 0x00000035, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036, 0x00000036)
        NTDLL_SYSCALL("NtQueryInformationProcess"          , 0x00000016, 0x00000016, 0x00000016, 0x00000017, 0x00000018, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019, 0x00000019)
        NTDLL_SYSCALL("NtWriteFile"                        , 0x00000005, 0x00000005, 0x00000005, 0x001A0006, 0x001A0007, 0x001A0008, 0x001A0008, 0x001A0008, 0x001A0008, 0x001A0008, 0x001A0008, 0x001A0008)
        NTDLL_SYSCALL("NtReadFile"                         , 0x00000003, 0x00000003, 0x00000003, 0x001A0004, 0x001A0005, 0x001A0006, 0x001A0006, 0x001A0006, 0x001A0006, 0x001A0006, 0x001A0006, 0x001A0006)
        NTDLL_SYSCALL("NtCreateFile"                       , 0x00000052, 0x00000052, 0x00000052, 0x00000053, 0x00000054, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055, 0x00000055)
        NTDLL_SYSCALL("NtQueryDirectoryFile"               , 0x00000032, 0x00000032, 0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035)
    #else
        NTDLL_SYSCALL("NtClose"                            , 0x00000019, 0x00000030, 0x00000032, 0x00000174, 0x00000179, 0x00000180, 0x00000183, 0x00000185, 0x0000018A, 0x0000018D, 0x0000018D, 0x0000018D)
        NTDLL_SYSCALL("NtAllocateVirtualMemory"            , 0x00000011, 0x00000012, 0x00000013, 0x00000196, 0x0000019B, 0x000001A3, 0x000001A6, 0x000001A8, 0x000001AD, 0x000001B1, 0x000001B1, 0x000001B1)
        NTDLL_SYSCALL("NtFreeVirtualMemory"                , 0x00000053, 0x00000093, 0x00000083, 0x00000118, 0x0000011C, 0x00000121, 0x00000123, 0x00000125, 0x00000128, 0x0000012B, 0x0000012B, 0x0000012A)
        NTDLL_SYSCALL("NtWriteVirtualMemory"               , 0x00000115, 0x00000166, 0x0000018F, 0x00000002, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000004)
        NTDLL_SYSCALL("NtFlushInstructionCache"            , 0x0000004E, 0x0000008D, 0x0000007D, 0x0000011E, 0x00000122, 0x00000127, 0x00000129, 0x0000012B, 0x0000012E, 0x00000131, 0x00000131, 0x00000130)
        NTDLL_SYSCALL("NtCreateThreadEx"                   , NONE      , 0x0000017E, 0x00000058, 0x0000014C, 0x00000150, 0x00000156, 0x00000158, 0x0000015A, 0x0000015D, 0x00000160, 0x00000160, 0x0000015F)
        NTDLL_SYSCALL("NtOpenProcess"                      , 0x0000007A, 0x000000C2, 0x000000BE, 0x000000DD, 0x000000E0, 0x000000E3, 0x000000E3, 0x000000E5, 0x000000E7, 0x000000E9, 0x000000E9, 0x000000E9)
        NTDLL_SYSCALL("NtQuerySystemInformation"           , 0x000000AD, 0x000000F8, 0x00000105, 0x00000095, 0x00000098, 0x0000009A, 0x0000009A, 0x0000009B, 0x0000009C, 0x0000009D, 0x0000009D, 0x0000009D)
        NTDLL_SYSCALL("NtQueryInformationProcess"          , 0x0000009A, 0x000000E4, 0x000000EA, 0x000000B0, 0x000000B3, 0x000000B5, 0x000000B5, 0x000000B7, 0x000000B8, 0x000000B9, 0x000000B9, 0x000000B9)
        NTDLL_SYSCALL("NtWriteFile"                        , 0x00000112, 0x00000163, 0x0000018C, 0x00000005, 0x00000006, 0x00000007, 0x00000007, 0x00000007, 0x00000007, 0x00000007, 0x00000007, 0x00000007)
        NTDLL_SYSCALL("NtReadFile"                         , 0x000000B7, 0x00000102, 0x00000111, 0x00000087, 0x0000008A, 0x0000008C, 0x0000008C, 0x0000008D, 0x0000008D, 0x0000008E, 0x0000008E, 0x0000008E)
        NTDLL_SYSCALL("NtCreateFile"                       , 0x00000025, 0x0000003C, 0x00000042, 0x00000163, 0x00000168, 0x0000016E, 0x00000170, 0x00000172, 0x00000175, 0x00000178, 0x00000178, 0x00000178)
        NTDLL_SYSCALL("NtQueryDirectoryFile"               , 0x00000091, 0x000000DA, 0x000000DF, 0x000000BB, 0x000000BE, 0x000000C0, 0x000000C0, 0x000000C2, 0x000000C4, 0x000000C5, 0x000000C5, 0x000000C5)
    #endif
#endif
