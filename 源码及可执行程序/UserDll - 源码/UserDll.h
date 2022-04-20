#pragma once
#ifndef _MINIFILTER_H_
#define _MINIFILTER_H_

#include <windows.h>
#include <stdio.h>
#include <FltUser.h>
#pragma comment(lib, "fltLib.lib")


extern HANDLE g_hPort;
#define MIN_PORT_NAME  L"\\MiniPort"

#ifdef  MINI_EXPORTS
#define MINI_API _declspec(dllexport)
#else
#define MINI_API _declspec(dllexport)
#endif // NPMINI_EXPORTS

extern "C" MINI_API int  InitialCommuicationPort(void);
extern "C" MINI_API int  NPSendMessage(PVOID InputBuffer);
extern "C" MINI_API int  NPGetMessage(PVOID InputBuffer);

typedef enum _MINI_COMMAND {
    ENUM_BLOCK = 0,
    ENUM_PASS,
    ENUM_RULE
}MIN_COMMAND;

typedef struct _OperationInfo
{
    char time[32];
    short operation_type;
    int process_id;
    char user[256];
    char path[256];
} OperationInfo;

typedef struct _SCANNER_MESSAGE
{
    FILTER_MESSAGE_HEADER MessageHeader;
    OperationInfo info;
    OVERLAPPED Ovlp;
} SCANNER_MESSAGE, * PSCANNER_MESSAGE;

typedef struct Rule
{
    char user[256];
    char path[256];
}Rule;


typedef struct _COMMAND_MESSAGE
{
    MIN_COMMAND  Command;
    Rule rule[5];
} COMMAND_MESSAGE, *PCOMMAND_MESSAGE;

#endif