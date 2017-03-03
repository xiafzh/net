#ifndef __PACKET_H__
#define __PACKET_H__

#include "platform.h"
#include "socketer.h"

namespace summit
{
	namespace network
	{
		class CPacket
		{
		private:
			friend class CPacketFactory;
			CPacket* __P_NEXT;
		private:
			virtual void CleanUp() = 0;
		public:
			virtual ~CPacket(){};
		public:
			virtual TPacketID PacketID() const = 0;
			virtual TInt32 PacketSize() const = 0;
			virtual TInt32 Execute(CSocketer& Socketer) = 0;
			virtual bool FillPacket(CMemStream& S, TInt32 Len, E_MSG_MODE M);
		};

	}
}
#endif