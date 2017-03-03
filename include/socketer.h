#ifndef __SOCKETER_H__
#define __SOCKETER_H__

#include "socket.h"
#include "socket_stream.h"
#include "packet_filter.h"

namespace summit
{
	namespace network
	{
		class CEventDispatcher;

		class CSocketer : virtual protected CSocket,
			public CNetNoticeHandler
		{
		public:
			bool	OnAcceptOk(CSocket FD, SOCKADDR_IN SIN, E_NET_TYPE T);
			void	OnAcceptErr(CSocket FD);
		public:
			virtual	bool	NoticeInput(CSocket FD);
			virtual bool	NoticeOutput(CSocket FD);
			virtual bool	NoticeError(CSocket FD);
		public:
			virtual void	OnRegistOK(CEventDispatcher& EventCore);
			virtual void	OnDeregistOK();
			virtual	void	OnSSConnectOK();
			virtual	void	OnKickOK(CSocket FD);
		public:
			bool	ProcessCommand();
		public:
			virtual bool	SendPacketEx(TUInt8 TarMode, TUInt8 Tar, TUInt8 Src, CPacket& Packet);
			bool	SendPacket(CPacket& Packet);
			bool	MarkSendClose();
			bool	SendMemStream(CMemStream& Mem);
		protected:
			virtual	bool	_OnOtherTimeOut(TUInt64 TmOut);
			virtual	bool	_HeartBeat(TUInt32 NowTm);
			virtual bool	_OnNetTmOut();
			virtual	bool	_IsTeller() const;
		protected:
			void	_CleanUp();
		protected:
			CSocketer();
		private:
			CSocketer(const CSocketer& O);
		public:
			~CSocketer();
		private:
			TUInt64				m_MapKeyID;
			CEventDispatcher*	m_Dispatcher;
			CSocketStream		m_SocketStream;
			CPacketFilter		m_PacketFilter;
			TUInt32				m_LastNetTime;
		};
	}
}

#endif