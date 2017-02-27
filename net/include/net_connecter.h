#ifndef __NET_CONNECTER_H__
#define __NET_CONNECTER_H__

#include "socket_client.h"
#include "socketer.h"

namespace summit
{
	namespace network
	{
		class CNetConnecter :
			public CSocketer, protected CSocketClient
		{
		public:
			bool Connect(const char* IP, TInt16 Port);
		public:
			virtual void OnSSConnectOK();
			virtual void OnConnectOK();
		public:
			virtual bool NoticeError();
			virtual void OnKickOK();
		protected:
			virtual void _OnReconnectOK();
			virtual void _OnReconnectFailed();
			virtual void _CloseConnect();
			virtual bool _OnNetTimeOut();
		private:
			bool __Reconnect();
			bool __DoConnect();
		public:
			CNetConnecter();
		private:
			CNetConnecter(CONST CNetConnecter&);
		private:

		};
	}
}

#endif