#include "socket.h"

namespace summit
{
	namespace network
	{
		TInt32 CSocket::Send(void *Buf, TInt32 Len, TInt32 F /*= 0*/)
		{
			TInt32 _RetV = ::send(m_SocketID, (char*)Buf, Len, F);
#ifdef __WINDOWS__

#else

#endif
			return _RetV;
		}

		TInt32 CSocket::Recv(void *Buf, TInt32 Len)
		{
			TInt32 _RetV = ::recv(m_SocketID, (char*)Buf, Len, 0);

#ifdef __WINDOWS__

#else

#endif
			return _RetV;
		}

		void CSocket::CloseSocket()
		{
			try
			{
#ifdef __WINDOWS__
				::closesocket(m_SocketID);
#else
				::close(m_SocketID);
#endif
			}
			catch (...)
			{
			}
		}

		bool CSocket::_CreateSocket()
		{
			m_SocketID = ::socket(AF_INET, SOCK_STREAM, 0);
			if (m_SocketID == INVALID_SOCKET){
				return false;
			}
			return true;
		}
	}
}