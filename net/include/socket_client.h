#ifndef __SOCKET_CLIENT_H__
#define __SOCKET_CLIENT_H__

#include "socket.h"

namespace summit
{
	namespace network
	{
		class CSocketClient 
			: virtual public CSocket
		{
		public:
			bool create_socket(const char* IP, TInt16 Port);
		};
	}
}

#endif