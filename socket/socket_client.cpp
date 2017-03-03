#include "socket_client.h"

namespace summit
{
	namespace network
	{
		bool CSocketClient::create_socket(const char* IP, TInt16 Port)
		{
			bool _RetV = CSocket::_CreateSocket();
			if (_RetV != true){ return false; }

			memset(&m_SockAddrIn, 0, sizeof(m_SockAddrIn));
			m_SockAddrIn.sin_family = AF_INET;
			m_SockAddrIn.sin_addr.s_addr = inet_addr(IP);
			m_SockAddrIn.sin_port = htons(Port);

			TInt32 _ConnectRet = ::connect(m_SocketID,
				(sockaddr*)&m_SockAddrIn,
				sizeof(m_SockAddrIn));
			if (_ConnectRet < 0){ return false; }
			return true;
		}
	}
}