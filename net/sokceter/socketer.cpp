#include "socketer.h"

#ifndef __SOCKETER_H__
#define __SOCKETER_H__

#include "socket.h"
#include "socket_stream.h"

namespace summit
{
	namespace network
	{
		class CEventDispatcher;

		class CSocketer : virtual protected CSocket,
			public CNetNoticeHandler
		{
		public:

		private:
			TUInt64				m_MapKeyID;
			CEventDispatcher*	m_Dispatcher;
			CSocketStream		m_SocketStream;
		};
	}
}

#endif