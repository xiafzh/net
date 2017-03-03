#include "socket_server.h"

namespace summit
{
	namespace network
	{
		bool CSocketServer::CreateSocket(TInt16 PortBeg, TInt16 PortEnd)
		{
			__ENTER_FUNCTION;
			bool _Flag = _CreateSocket();
			if (!_Flag){ return false; }

			_Flag = __ReuseAddr(false);
			if (!_Flag){ return false; }

			bool _IsFindPort = false;
			if (PortBeg == PortEnd)
			{
				if (__Bind(PortBeg, INADDR_ANY)){
					_IsFindPort = true;
				}
			}
			else
			{
				for (TInt16 _Port = PortBeg; _Port < PortEnd; ++_Port)
				{
					if (__Bind(_Port, INADDR_ANY))
					{
						_IsFindPort = true;
						break;
					}
				}
			}

			if (!_IsFindPort){ return false; }

			TUInt8 _ListenNum = 20;
			return __Listen(_ListenNum);
			__LEAVE_FUNCTION;
			return false;
		}

		TSocket CSocketServer::Accept(SOCKADDR_IN& SIN, TInt32& ERR)
		{
			__ENTER_FUNCTION;
			sockaddr* _Addr = (sockaddr*)(&SIN);
			memset(&SIN, 0, sizeof(SIN));
			TSockLen _Len = (TSockLen)sizeof(SIN);
			TSocket _FD = ::accept(m_SocketID, _Addr, &_Len);
	
			return _FD;
			__LEAVE_FUNCTION;
			return INVALID_SOCKET;
		}

		bool CSocketServer::OnBindAndListenOK()
		{
			__ENTER_FUNCTION;
			m_ClientPort = ntohs(m_SockAddrIn.sin_port);

			TInt32 _Len = sizeof(m_ClientIP) - 1;
			inet_ntop(AF_INET, &(m_SockAddrIn.sin_addr), m_ClientIP, _Len);
			__LEAVE_FUNCTION;
			return true;
		}

		bool CSocketServer::__ReuseAddr(bool on)
		{
			__ENTER_FUNCTION;
			TInt32 _Opt = on ? 1 : 0;

			TInt32 _RetV = ::setsockopt(m_SocketID, 
				SOL_SOCKET, 
				SO_REUSEADDR, 
				(char*)&_Opt, 
				sizeof(_Opt));
			return (_RetV >= 0);
			__LEAVE_FUNCTION;
			return false;
		}

		bool CSocketServer::__Listen(TInt32 Back)
		{
			__ENTER_FUNCTION;
			TInt32 _RetV = ::listen(m_SocketID, Back);
			return (_RetV >= 0);
			__LEAVE_FUNCTION;
			return false;
		}

		bool CSocketServer::__Bind(TInt16 Port, TUInt32 Addr)
		{
			__ENTER_FUNCTION;
			memset(&m_SockAddrIn, 0, sizeof(m_SockAddrIn));
			m_SockAddrIn.sin_family = AF_INET;
			m_SockAddrIn.sin_addr.s_addr = htonl(Addr);
			m_SockAddrIn.sin_port = htons(Port);

			TInt32 _Flag = ::bind(m_SocketID,
				(const sockaddr*)&m_SockAddrIn,
				sizeof(m_SockAddrIn));
			return (_Flag == 0);
			__LEAVE_FUNCTION;
			return false;
		}
	}
}
