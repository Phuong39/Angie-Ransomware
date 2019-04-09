#ifndef __INCLUDE_DLOG_H
#define __INCLUDE_DLOG_H

#define DEBUG_LEVEL_NO_LOG      0
#define DEBUG_LEVEL_CASUAL      1 // log just what is doing
#define DEBUG_LEVEL_INFORMATIVE 2 // prints additional information
#define DEBUG_LEVEL_EVERYTHING  3 // programmers love to log things

#define DLG_ATT_PROCNAME_ALIGN(X) ((X & 0xFF) << 24)

typedef enum _$DLOGTYPE {
    DLG_ATT_COLOURS  = 0x00010000,
    DLG_ATT_TICKS    = 0x00020000,
    DLG_ATT_ADDRESS  = 0x00040000,
    DLG_ATT_PROCNAME = 0x00080000,

    #if DEBUG_LEVEL > DEBUG_LEVEL_INFORMATIVE  // DEBUG_LEVEL_EVERYTHING
        #define DEBUG_STATIC_MASK (DLG_ATT_PROCNAME_ALIGN(SCFG_DLOG_LARGEST_PROC_NAME) | 0x000F0000) // DLG_ATT_COLOURS | DLG_ATT_TICKS | DLG_ATT_ADDRESS | DLG_ATT_PROCNAME
    #elif DEBUG_LEVEL > DEBUG_LEVEL_CASUAL     // DEBUG_LEVEL_INFORMATIVE
        #define DEBUG_STATIC_MASK (DLG_ATT_PROCNAME_ALIGN(SCFG_DLOG_LARGEST_PROC_NAME) | 0x000D0000) // DLG_ATT_COLOURS | DLG_ATT_ADDRESS | DLG_ATT_PROCNAME
    #elif   DEBUG_LEVEL > DEBUG_LEVEL_NO_LOG   // DEBUG_LEVEL_CASUAL
        #define DEBUG_STATIC_MASK (DLG_ATT_PROCNAME_ALIGN(SCFG_DLOG_LARGEST_PROC_NAME) | 0x00090000) // DLG_ATT_COLOURS | DLG_ATT_PROCNAME
    #else 
        #define DEBUG_STATIC_MASK 0x00010000
    #endif

    DLG_FLT_DEFAULT   = 0 | DEBUG_STATIC_MASK,
    DLG_FLT_INFO      = 1 | DEBUG_STATIC_MASK,
    DLG_FLT_WARNING   = 2 | DEBUG_STATIC_MASK,
    DLG_FLT_ERROR     = 3 | DEBUG_STATIC_MASK,
    DLG_FLT_CRITICAL  = 4 | DEBUG_STATIC_MASK,
    DLG_FLT_SUCCESS   = 5 | DEBUG_STATIC_MASK,
    DLG_FLT_HIGHLIGHT = 6 | DEBUG_STATIC_MASK,
    DLG_FILTER_COUNT

    #undef DEBUG_STATIC_MASK
} $DLOGTYPE, *$PDLOGTYPE;

#ifdef DEBUG
    #define DLOGAPI  __fastcall
    #define DLOGAPIX __cdecl

    VOID
    DLOGAPIX
    $DLogSendEx(
        IN $DLOGTYPE Type,
        IN PSTR      szFunctioName,
        IN PCSTR     szFormat,
        IN ...
        );

    VOID
    DLOGAPIX
    $DLogSend(
        IN PCSTR szFormat,
        IN ...
        );

    VOID
    DLOGAPI
    $DLogDestroy(VOID);

    VOID
    DLOGAPI
    $DLogInitialize(
        IN PUNICODE_STRING MasterPipeName,
        IN ULONG_PTR dwWriteBufferSize
        );

    #undef DLOGAPI
    #undef DLOGAPIX
#endif

#if DEBUG_LEVEL > DEBUG_LEVEL_NO_LOG      // DEBUG_LEVEL_CASUAL
    #define $DLOGRAW0(FORMAT, ...)    $DLogSend(FORMAT, __VA_ARGS__)
    #define $DLOG0(TYPE, FORMAT, ...) $DLogSendEx(TYPE, __FUNCTION__, FORMAT, __VA_ARGS__)
#else
    #define $DLOGRAW0 __noop
    #define $DLOG0    __noop
#endif

#if DEBUG_LEVEL > DEBUG_LEVEL_CASUAL      // DEBUG_LEVEL_INFORMATIVE
    #define $DLOGRAW1(FORMAT, ...)    $DLogSend(FORMAT, __VA_ARGS__)
    #define $DLOG1(TYPE, FORMAT, ...) $DLogSendEx(TYPE, __FUNCTION__, FORMAT, __VA_ARGS__)
#else
    #define $DLOGRAW1 __noop
    #define $DLOG1    __noop
#endif

#if DEBUG_LEVEL > DEBUG_LEVEL_INFORMATIVE // DEBUG_LEVEL_EVERYTHING
    #define $DLOGRAW2(FORMAT, ...)    $DLogSend(FORMAT, __VA_ARGS__)
    #define $DLOG2(TYPE, FORMAT, ...) $DLogSendEx(TYPE, __FUNCTION__, FORMAT, __VA_ARGS__)
#else
    #define $DLOGRAW2 __noop
    #define $DLOG2    __noop
#endif

#ifdef DEBUG_C_ASSERT
    #define $DLOG_C_ASSERT(X)                         \
        PRAGMA_WARNING_SUPPRESS(344)                  \
        typedef char __$DLOG_C_ASSERT__[(X) ? 1 : -1]
#else
    #define $DLOG_C_ASSERT(X)
#endif

#undef SCFG_DLOG_LARGEST_PROC_NAME

#endif
