#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "socket.h"
#include "socket_stream.h"

namespace summit
{
	namespace network
	{
		class CNetNoticeHandler
		{
		protected:
			virtual void NoticeInput() = 0;
			virtual void NoticeOutput() = 0;
			virtual void NoticeError() = 0;
		public:
			~CNetNoticeHandler() {};
		};

		enum E_NET_TYPE
		{
			INTERVAL,
			EXTERVAL,
		};

		enum E_SOCKETER_TYPE{

		};
	}
}

#endif