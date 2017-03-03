#ifndef __NET_LISTENER_H__
#define __NET_LISTENER_H__

#include "socket_server.h"
#include "interface.h"
#include "socketer.h"

namespace summit
{
	namespace network
	{
		class CEventDispatcher;

		class CNetListener : public CNetNoticeHandler
		{
		public:
			bool BindAndListen(TInt16 PortBeg, TInt16 PortEnd);
		public:
			virtual void NoticeInput();
			virtual void NoticeOutput();
			virtual void NoticeError();
		public:
			TSocket	SocketID();
			TInt16	ListenPort();
		private:
			CSocketer*	_NewSocketer();
		private:
			virtual void	__ReclaimSocketerObj(CSocketer* Socketer) = 0;
			virtual CSocketer* __NewSocketerObj() = 0;
			virtual	E_NET_TYPE __NewType() = 0;
		private:
			TInt16				m_ListenPort;
			CSocketServer		m_Socket;
			CEventDispatcher&	m_EventDispatacher;
		};
	}
}

#endif