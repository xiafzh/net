#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef __WINDOWS__
#pragma warning(disable:4996)

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Winsock2.h>
#include <MSWSock.h>
#include <WS2tcpip.h>
#include <direct.h>
#include <unordered_map>

#else

#endif

#include "vector"
#include "queue"
#include "map"
#include "set"


#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef FD_SETSIZE
#define FD_SETSIZE      4096
#else
#undef FD_SETSIZE
#define FD_SETSIZE      4096
#endif

typedef int					TInt32;
typedef short				TInt16;
typedef char				TInt8;
typedef unsigned int		TUInt32;
typedef unsigned short		TUInt16;
typedef unsigned char		TUInt8;


#ifdef __WINDOWS__
typedef __int64				TInt64;
typedef unsigned __int64	TUInt64;
#else
typedef long long			TInt64;
typedef unsigned long long	TUInt64;

typedef	sockaddr_in			SOCKADDR_IN;
typedef fd_set				FD_SET;
#endif

typedef TInt32				TSocket;
typedef TUInt64				TThreadID;

#ifdef __WINDOWS__
typedef TInt32				TSockLen;
#else
typedef TUInt32				TSockLen;
#endif

typedef std::vector<char>		TVecChar;
typedef std::vector<TInt8>		TVecInt8;
typedef std::vector<TInt16>		TVecInt16;
typedef std::vector<TInt32>		TVecInt32;
typedef std::vector<TInt64>		TVecInt64;
typedef std::vector<TUInt8>		TVecUInt8;
typedef std::vector<TUInt16>	TVecUInt16;
typedef std::vector<TUInt32>	TVecUInt32;
typedef std::vector<TUInt64>	TVecUInt64;

enum E_MSG_MODE
{
	EMM_WRITE			= 0,		//写消息包到输出流
	EMM_READ,						//读输入流到消息包
};

#define __ENTER_FUNCTION try{
#define __LEAVE_FUNCTION }catch(...){};



#endif