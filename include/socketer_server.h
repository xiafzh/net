#ifndef __SOCKETER_SERVER_H__
#define __SOCKETER_SERVER_H__

#include "socketer.h"
#include "interface.h"

namespace summit
{
	namespace network
	{
		class CSocketerServer
			: public CSocketer
		{
		private:
			virtual void __OnNetErr(TUInt64 MapKey) = 0;
		public:
			virtual void OnKickOK(TSocket FD);
			virtual bool NoticeError(TSocket FD);
		public:
			bool SetSocketerType(E_SOCKETER_TYPE EST);
			CSocketerServer();
		protected:
			virtual bool _OnNetTimeOut();
		};
	}
}

#endif