#ifndef __INCLUDE_CORE_FASTCALL_H
#define __INCLUDE_CORE_FASTCALL_H

#define FASTCALLSTUB  \
    DECLSPEC_NAKED    \
    DECLSPEC_NOINLINE \
    NTAPI

VOID
FASTCALLSTUB
KiFastSystemCall(VOID);

ULONG64
FASTCALLSTUB
KiJumpLongMode(
    IN PVOID64 Address
    );

#endif
