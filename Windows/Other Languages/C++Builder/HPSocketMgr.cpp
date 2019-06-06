//---------------------------------------------------------------------------


#pragma hdrstop

#include "HPSocketMgr.h"
#include "Unit16.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void AddMsg(String msg)
{
	frmMain->mmout->Lines->Add(msg);
}

En_HP_HandleResult __stdcall OnPrepareListen(HP_Server pSender, SOCKET soListen)
{
//	TCHAR szAddress[50];
//	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
//	USHORT usPort;
//
//	::HP_Server_GetListenAddress(pSender, szAddress, &iAddressLen, &usPort);
   //	::PostOnPrepareListen(szAddress, usPort);
	return HR_OK;
}
String m_In;


En_HP_HandleResult __stdcall OnAccept(HP_Server pSender, HP_CONNID dwConnID, SOCKET soClient)
{

	char* ip;
	int* ipLength;
	Word* port;
	if (HP_Server_GetRemoteAddress(pSender, dwConnID, ip, ipLength, port))
	{
	  AddMsg("连接上线 -> "+String(ip) +":");
	}else {
        AddMsg("取连接信息失败 ->");
	}
	m_In="";
	return HR_OK;
}
En_HP_HandleResult __stdcall OnSend(HP_Server pSender, HP_CONNID dwConnID, const BYTE* pData, int iLength)
{
	return HR_OK;
}
En_HP_HandleResult __stdcall OnReceive(HP_Server pSender, HP_CONNID dwConnID, const BYTE* pData, int iLength)
{

	AddMsg("OnReceive -> ");
	String sIn= (char*)(BYTE*)pData;;
	m_In=m_In+sIn;
	AddMsg(sIn);
   if (sIn.Pos("</business>")>0) {
	   AnsiString sOut;
	   sOut=m_In+"<test>马克11212abced</test>";
	   AddMsg("sOut:"+sOut);
	 //	sOut="2323";
		int nOutLen=sOut.Length()+iLength;
		if (HP_Server_Send(m_pServer, dwConnID, (BYTE*)sOut.c_str(), nOutLen))
		{
			return HR_OK;
		}else {
			return HR_OK;
		}

   }

	return HR_OK;
}
En_HP_HandleResult __stdcall OnCloseEx(HP_Server pSender, HP_CONNID dwConnID, En_HP_SocketOperation enOperation, int iErrorCode)
{
	return HR_OK;
}
En_HP_HandleResult __stdcall OnShutdown(HP_Server pSender)
{
	return HR_OK;
}

void CreateHP()
{
	// 创建监听器对象
	m_pListener	= ::Create_HP_TcpServerListener();
	// 创建 Socket 对象
	m_pServer		= ::Create_HP_TcpServer(m_pListener);
	// 设置 Socket 监听器回调函数
	::HP_Set_FN_Server_OnPrepareListen(m_pListener, OnPrepareListen);
	::HP_Set_FN_Server_OnAccept(m_pListener, OnAccept);
	::HP_Set_FN_Server_OnSend(m_pListener, OnSend);
	::HP_Set_FN_Server_OnReceive(m_pListener, OnReceive);
	::HP_Set_FN_Server_OnClose(m_pListener, OnCloseEx);
	::HP_Set_FN_Server_OnShutdown(m_pListener, OnShutdown);	
}

bool Start(String AIP,int Port)
{
	try {
	if(HP_Server_Start(m_pServer, AIP.c_str(), Port))
	{
		return true;
	}
	else
	{
		return false;
	}
	} catch (...) {
    	return false;
	}
}
void Stop()
{
	try {
		HP_Server_Stop(m_pServer);
	} catch (...) {
	}

}
