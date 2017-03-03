#include "packet_filter.h"
#include "stream_input.h"

namespace summit
{
	namespace network
	{
		TInt32 CPacketFilter::PacketRead(CStreamInput& Input, CPacketFactoryMgr& PacketMgr)
		{
			static const TInt32 _S_PacketHeadLen = sizeof(SPacketHead);
			char _PacketHeadStr[_S_PacketHeadLen];
			if (!Input.Peek(_PacketHeadStr, _S_PacketHeadLen))
			{
				return -1;
			}

			SPacketHead _PacketHead;
			memcpy(&_PacketHead, _PacketHeadStr, _S_PacketHeadLen);

			//PacketMgr.

		}

		CMemStream* CPacketFilter::PacketWrite(CPacket& Packet)
		{

		}

		CPacket* CPacketFilter::GetCachePacket()
		{

		}

	}
}