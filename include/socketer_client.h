#ifndef __SOCKETER_CLIENT_H__
#define __SOCKETER_CLIENT_H__

#include "socketer.h"

namespace summit
{
	namespace network
	{
		class CSocketerClient
			: public CSocketer
		{
		public:
			static void ReclaimObj(CSocketerClient* Obj);
			static CSocketerClient* CreateObj();
		public:
			void DoReclaim();
		public:
			virtual void OnKickOK(TSocket FD);
			virtual bool NoticeError(TSocket FD);
		protected:
		private:
			CSocketerClient(const CSocketerClient&);
		};
	}
}

#endif
