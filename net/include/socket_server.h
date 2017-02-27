#ifndef __SOCKET_SERVER_H__
#define __SOCKET_SERVER_H__

#include "socket.h"

namespace summit
{
	namespace network
	{
		class CSocketServer
			: virtual public CSocket
		{
		public:
			bool CreateSocket(TInt16 PortBeg, TInt16 PortEnd);
			TSocket Accept(SOCKADDR_IN& SIN, TInt32& ERR);
		public:
			bool OnBindAndListenOK();
		private:
			bool __ReuseAddr(bool on);
			bool __Listen(TInt32 Back);
			bool __Bind(TInt16 Port, TUInt32 Addr);
		};
	}
}

#endif