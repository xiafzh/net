#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "base.h"

namespace summit
{
	namespace network
	{
		class CSocket
		{
		public:
			TInt32 Send(void *Buf, TInt32 Len, TInt32 F = 0);
			TInt32 Recv(void *Buf, TInt32 Len);
		public:
			void	CloseSocket();
		protected:
			bool	_CreateSocket();
		public:
			inline TSocket		SocketID();
			inline TInt16		ClientPort();
			inline const char*	ClientIP();
		public:
			CSocket();
			virtual ~CSocket();
		protected:
			TSocket	m_SocketID;
			SOCKADDR_IN	m_SockAddrIn;

			TInt16	m_ClientPort;
			char	m_ClientIP[IP_SIZE];
		};


		TSocket CSocket::SocketID()
		{
			return m_SocketID;
		}

		TInt16 CSocket::ClientPort()
		{
			return m_ClientPort;
		}

		const char* CSocket::ClientIP()
		{
			return m_ClientIP;
		}

	}
}

#endif