#include "socketer.h"
#include "interface.h"

namespace summit
{
	namespace network
	{
		bool CSocketer::OnAcceptOk(CSocket FD, SOCKADDR_IN SIN, E_NET_TYPE T)
		{
			//TInt32
			m_ClientPort = ntohs(m_SockAddrIn.sin_port);
			TInt32 _Len = sizeof(m_ClientIP)-1;
			inet_ntop(AF_INET, &(m_SockAddrIn.sin_addr), m_ClientIP, _Len);

			m_SocketStream.Init(1, 1, 1, 1);

			return true;
		}
		/*
		void CSocketer::OnAcceptErr(CSocket FD)
		{
			_CleanUp();
		}

		bool CSocketer::NoticeInput(CSocket FD)
		{

		}

		bool CSocketer::NoticeOutput(CSocket FD)
		{

		}

		bool CSocketer::NoticeError(CSocket FD)
		{

		}

		void CSocketer::OnRegistOK(CEventDispatcher& EventCore)
		{

		}

		void CSocketer::OnDeregistOK()
		{

		}

		void CSocketer::OnSSConnectOK()
		{

		}

		void CSocketer::OnKickOK(CSocket FD)
		{

		}

		bool CSocketer::ProcessCommand()
		{

		}

		bool CSocketer::SendPacketEx(TUInt8 TarMode, TUInt8 Tar, TUInt8 Src, CPacket& Packet)
		{

		}

		bool CSocketer::SendPacket(CPacket& Packet)
		{

		}

		bool CSocketer::MarkSendClose()
		{

		}

		bool CSocketer::SendMemStream(CMemStream& Mem)
		{

		}

		bool CSocketer::_OnOtherTimeOut(TUInt64 TmOut)
		{

		}

		bool CSocketer::_HeartBeat(TUInt32 NowTm)
		{

		}

		bool CSocketer::_OnNetTmOut()
		{

		}
		*/
	}
}