#ifndef __EVENT_DISPATCHER_H__
#define __EVENT_DISPATCHER_H__

#include "base.h"
#include "net_listener.h"

namespace summit
{
	namespace network
	{
		class CEventPoller;

		class CEventDispatcher
		{
		public:
			template<class LISTENER_T>
			bool AddListener(TInt16 PortBeg, TInt16 PortEnd, TInt16& RetPort)
			{
				try
				{
					CNetListener* _NetListener = new CNetListener(*this);
					if (_NetListener->BindAndListen(PortBeg, PortEnd))
					{
						return false;
					}

					m_ServerListener.push_back(_NetListener);
					RetPort = _NetListener->ListenPort();
					return m_EventPoller->RegistListener(m_Socket, _NetListener);
				}
				catch (...)
				{
				}
				return false;
			}

			template<class CONNECTER_T>
			bool ConnectServer(const char* IP, TInt16 Port, CNetConnecter** Connecter)
			{
				try
				{
					if (Connecter != NULL){ *Connecter = NULL; }
					CNetConnecter* _P_CONNECTER = new CONNECTER_T();
					if (NULL == _P_CONNECTER){ return false; }

					bool _StateConn = _P_CONNECTER->Connect(IP, Port);
					if (_StateConn != NULL)
					{
						return false;
					}

					if (Connecter != NULL){ *Connecter = _P_CONNECTER; }
					
					TUInt64 _MapKey = _P_CONNECTER->MapKeyID();

					_P_CONNECTER->OnRegistOK(*this);
					_P_CONNECTER->OnConnectOk();
					return m_EventPoller->RegistHandler(m_Socket, _P_CONNECTER);
				}
				catch (...)
				{
				}
			}
		private:
			typedef std::vector<CNetListener*>	TServerListenerVec;

		private:
			CSocket						m_Socket;
			CEventPoller*				m_EventPoller;
			TServerListenerVec			m_ServerListener;
		};
	}
}

#endif