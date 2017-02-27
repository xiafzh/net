#ifndef __EVENT_POLLER_H__
#define __EVENT_POLLER_H__

#include "socket.h"
#include "socket_stream.h"
#include "interface.h"

namespace summit
{
	namespace network
	{
		class CNetNoticeHandler;
		class CSocketer;

		class CEventPoller : virtual CSocket
		{
		public:
			bool RegistHandler(TSocket FD, CNetNoticeHandler* Handler);
			bool RegistListener(TSocket FD, CNetNoticeHandler* Handler);
			bool UnregHandler(TSocket FD);
		protected:
			void _TriggerRead(TSocket FD);
			void _TriggerWrite(TSocket FD);
			void _TriggerError(TSocket FD);
		private:
			virtual void __ReclaimObj(CSocketer* Socketer) = 0;
			virtual CSocketer* __NewSocketer() = 0;
			virtual	E_NET_TYPE __NetType() = 0;
		public:
			~CEventPoller() {}
		private:
			typedef std::map<TSocket, CNetNoticeHandler*> TMapFDHandler;
		private:
			TMapFDHandler	m_FDHandlerMap;
		};
	}
}

#endif