
/*:
����: ����~��*_^��~
ʱ��:   2017-11-20
Email:  ztcjn@qq.com
ע��:   ����в�������ĵط����뼰ʱ�������ң�лл��
���ܣ�Hp-Socket delphi��Ԫ������Ҫ�����иĳ��ࡣ
*/
#ifndef HPSocketSDKUnitH
#define HPSocketSDKUnitH


#include <System.hpp>

#include <windows.hpp>
#include "HPTypeDef.h"
#include <sysutils.hpp>
#include <dateutils.hpp>
#include <strutils.hpp>



//struct WSABUF;
//typedef unsigned char unsignedchar;
//typedef unsigned int unsigned int;


const char HPSocketDLL[] = "HPSocket4C.dll";


/*$Z4*/
//typedef void* SOCKET;
//
//struct WSABUF {
//  int len; /* the length of the buffer */
//  Char* buf; /* the pointer to the buffer */
//}; /* WSABUF */


typedef WSABUF* PWSABUF;
typedef PWSABUF LPWSABUF;
typedef DynamicArray< WSABUF > WSABUFArray;
typedef int* PInteger;
typedef WORD* PUShort;

  /* /************************************************************************
    ���ƣ����� Socket ����ָ�����ͱ���
    �������� Socket ����ָ�붨��Ϊ��ֱ�۵ı���
	************************************************************************/
typedef int HP_Object;
typedef HP_Object HP_Server;
typedef HP_Object HP_Agent;
typedef HP_Object HP_Client;
typedef HP_Object HP_TcpServer;
typedef HP_Object HP_TcpAgent;
typedef HP_Object HP_TcpClient;
typedef HP_Object HP_PullSocket;
typedef HP_Object HP_PullClient;
typedef HP_Object HP_TcpPullServer;
typedef HP_Object HP_TcpPullAgent;
typedef HP_Object HP_TcpPullClient;
typedef HP_Object HP_PackSocket;
typedef HP_Object HP_PackClient;
typedef HP_Object HP_TcpPackServer;
typedef HP_Object HP_TcpPackAgent;
typedef HP_Object HP_TcpPackClient;
typedef HP_Object HP_UdpServer;
typedef HP_Object HP_UdpClient;
typedef HP_Object HP_UdpCast;
typedef HP_Object HP_Listener;
typedef HP_Object HP_ServerListener;
typedef HP_Object HP_AgentListener;
typedef HP_Object HP_ClientListener;
typedef HP_Object HP_TcpServerListener;
typedef HP_Object HP_TcpAgentListener;
typedef HP_Object HP_TcpClientListener;
typedef HP_Object HP_PullSocketListener;
typedef HP_Object HP_PullClientListener;
typedef HP_Object HP_TcpPullServerListener;
typedef HP_Object HP_TcpPullAgentListener;
typedef HP_Object HP_TcpPullClientListener;
typedef HP_Object HP_PackSocketListener;
typedef HP_Object HP_PackClientListener;
typedef HP_Object HP_TcpPackServerListener;
typedef HP_Object HP_TcpPackAgentListener;
typedef HP_Object HP_TcpPackClientListener;
typedef HP_Object HP_UdpServerListener;
typedef HP_Object HP_UdpClientListener;
typedef HP_Object HP_UdpCastListener;
typedef HP_Object HP_Http;
typedef HP_Object HP_HttpServer;
typedef HP_Object HP_HttpAgent;
typedef HP_Object HP_HttpClient;
typedef HP_Object HP_HttpSyncClient;
typedef HP_Object HP_HttpServerListener;
typedef HP_Object HP_HttpAgentListener;
typedef HP_Object HP_HttpClientListener;

//*****************************************************************************************************************************************************/
//****************************************************************** TCP/UDP Exports ******************************************************************/
//*****************************************************************************************************************************************************/

//****************************************************/
//***************** TCP/UDP �ص����� ******************/

//* Server �ص����� */

typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnPrepareListen )( HP_Server, void* );
// ���Ϊ TCP ���ӣ�pClientΪ SOCKET ��������Ϊ UDP ���ӣ�pClientΪ SOCKADDR_IN ָ�룻

typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnAccept )( HP_Server, HP_CONNID, void* );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnHandShake )( HP_Server, HP_CONNID );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnSend )( HP_Server, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnReceive )( HP_Server, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnPullReceive )( HP_Server, HP_CONNID, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnClose )( HP_Server, HP_CONNID, En_HP_SocketOperation, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Server_OnShutdown )( HP_Server );

//* Agent �ص����� */

typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnPrepareConnect )( HP_Agent, HP_CONNID, void* );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnConnect )( HP_Agent, HP_CONNID );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnHandShake )( HP_Agent, HP_CONNID );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnSend )( HP_Agent, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnReceive )( HP_Agent, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnPullReceive )( HP_Agent, HP_CONNID, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnClose )( HP_Agent, HP_CONNID, En_HP_SocketOperation, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Agent_OnShutdown )( HP_Agent );

//* Client �ص����� */

typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnPrepareConnect )( HP_Client, HP_CONNID, void* );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnConnect )( HP_Client, HP_CONNID );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnHandShake )( HP_Client, HP_CONNID );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnSend )( HP_Client, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnReceive )( HP_Client, HP_CONNID, const void*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnPullReceive )( HP_Client, HP_CONNID, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Client_OnClose )( HP_Client, HP_CONNID, En_HP_SocketOperation, int );

//* HTTP �ص����� */

typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnMessageBegin )( HP_Http, HP_CONNID );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnRequestLine )( HP_Http, HP_CONNID, Char*, Char* );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnStatusLine )( HP_Http, HP_CONNID, WORD, Char* );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnHeader )( HP_Http, HP_CONNID, Char*, Char* );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnHeadersComplete )( HP_Http, HP_CONNID );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnBody )( HP_Http, HP_CONNID, const void*, int );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnChunkHeader )( HP_Http, HP_CONNID, int );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnChunkComplete )( HP_Http, HP_CONNID );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnMessageComplete )( HP_Http, HP_CONNID );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnUpgrade )( HP_Http, HP_CONNID, En_HP_HttpUpgradeType );
typedef En_HP_HttpParseResult __stdcall ( * HP_FN_Http_OnParseError )( HP_Http, HP_CONNID, int, Char* );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Http_OnWSMessageHeader )( HP_Http, HP_CONNID, BOOL, Char*, Char*, const Char*, unsigned int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Http_OnWSMessageBody )( HP_Http, HP_CONNID, const Char*, int );
typedef En_HP_HandleResult __stdcall ( * HP_FN_Http_OnWSMessageComplete )( HP_Http, HP_CONNID );

//****************************************************/
//*************** TCP/UDP ���󴴽����� ****************/

// ���� HP_TcpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpServer __stdcall Create_HP_TcpServer( HP_TcpServerListener pListener );
// ���� HP_TcpAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpAgent __stdcall Create_HP_TcpAgent( HP_TcpAgentListener pListener );
// ���� HP_TcpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpClient __stdcall Create_HP_TcpClient( HP_TcpClientListener pListener );
// ���� HP_TcpPullServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullServer __stdcall Create_HP_TcpPullServer( HP_TcpPullServerListener pListener );
// ���� HP_TcpPullAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullAgent __stdcall Create_HP_TcpPullAgent( HP_TcpPullAgentListener pListener );
// ���� HP_TcpPullClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullClient __stdcall Create_HP_TcpPullClient( HP_TcpPullClientListener pListener );
// ���� HP_TcpPackServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackServer __stdcall Create_HP_TcpPackServer( HP_TcpServerListener pListener );
// ���� HP_TcpPackAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackAgent __stdcall Create_HP_TcpPackAgent( HP_TcpAgentListener pListener );
// ���� HP_TcpPackClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackClient __stdcall Create_HP_TcpPackClient( HP_TcpClientListener pListener );
// ���� HP_UdpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpServer __stdcall Create_HP_UdpServer( HP_UdpServerListener pListener );
// ���� HP_UdpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpClient __stdcall Create_HP_UdpClient( HP_UdpClientListener pListener );
// ���� HP_UdpCast ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpCast __stdcall Create_HP_UdpCast( HP_UdpCastListener pListener );

// ���� HP_TcpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpServer( HP_TcpServer pServer );
// ���� HP_TcpAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpAgent( HP_TcpAgent pAgent );
// ���� HP_TcpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpClient( HP_TcpClient pClient );
// ���� HP_TcpPullServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullServer( HP_TcpPullServer pServer );
// ���� HP_TcpPullAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullAgent( HP_TcpPullAgent pAgent );
// ���� HP_TcpPullClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullClient( HP_TcpPullClient pClient );
// ���� HP_TcpPackServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackServer( HP_TcpPackServer pServer );
// ���� HP_TcpPackAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackAgent( HP_TcpPackAgent pAgent );
// ���� HP_TcpPackClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackClient( HP_TcpPackClient pClient );
// ���� HP_UdpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpServer( HP_UdpServer pServer );
// ���� HP_UdpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpClient( HP_UdpClient pClient );
// ���� HP_UdpCast ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpCast( HP_UdpCast pCast );

// ���� HP_TcpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpServerListener __stdcall Create_HP_TcpServerListener( );
// ���� HP_TcpAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpAgentListener __stdcall Create_HP_TcpAgentListener( );
// ���� HP_TcpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpClientListener __stdcall Create_HP_TcpClientListener( );
// ���� HP_TcpPullServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullServerListener __stdcall Create_HP_TcpPullServerListener( );
// ���� HP_TcpPullAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullAgentListener __stdcall Create_HP_TcpPullAgentListener( );
// ���� HP_TcpPullClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPullClientListener __stdcall Create_HP_TcpPullClientListener( );
// ���� HP_TcpPackServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackServerListener __stdcall Create_HP_TcpPackServerListener( );
// ���� HP_TcpPackAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackAgentListener __stdcall Create_HP_TcpPackAgentListener( );
// ���� HP_TcpPackClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_TcpPackClientListener __stdcall Create_HP_TcpPackClientListener( );
// ���� HP_UdpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpServerListener __stdcall Create_HP_UdpServerListener( );
// ���� HP_UdpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpClientListener __stdcall Create_HP_UdpClientListener( );
// ���� HP_UdpCastListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_UdpCastListener __stdcall Create_HP_UdpCastListener( );

// ���� HP_TcpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpServerListener( HP_TcpServerListener pListener );
// ���� HP_TcpAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpAgentListener( HP_TcpAgentListener pListener );
// ���� HP_TcpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpClientListener( HP_TcpClientListener pListener );
// ���� HP_TcpPullServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullServerListener( HP_TcpPullServerListener pListener );
// ���� HP_TcpPullAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullAgentListener( HP_TcpPullAgentListener pListener );
// ���� HP_TcpPullClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPullClientListener( HP_TcpPullClientListener pListener );
// ���� HP_TcpPackServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackServerListener( HP_TcpPackServerListener pListener );
// ���� HP_TcpPackAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackAgentListener( HP_TcpPackAgentListener pListener );
// ���� HP_TcpPackClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_TcpPackClientListener( HP_TcpPackClientListener pListener );
// ���� HP_UdpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpServerListener( HP_UdpServerListener pListener );
// ���� HP_UdpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpClientListener( HP_UdpClientListener pListener );
// ���� HP_UdpCastListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_UdpCastListener( HP_UdpCastListener pListener );

//**********************************************************************************/
//***************************** Server �ص��������÷��� *****************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnPrepareListen( HP_ServerListener pListener, HP_FN_Server_OnPrepareListen fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnAccept( HP_ServerListener pListener, HP_FN_Server_OnAccept fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnHandShake( HP_ServerListener pListener, HP_FN_Server_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnSend( HP_ServerListener pListener, HP_FN_Server_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnReceive( HP_ServerListener pListener, HP_FN_Server_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnPullReceive( HP_ServerListener pListener, HP_FN_Server_OnPullReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnClose( HP_ServerListener pListener, HP_FN_Server_OnClose fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Server_OnShutdown( HP_ServerListener pListener, HP_FN_Server_OnShutdown fn );

//**********************************************************************************/
//****************************** Agent �ص��������÷��� *****************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnPrepareConnect( HP_AgentListener pListener, HP_FN_Agent_OnPrepareConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnConnect( HP_AgentListener pListener, HP_FN_Agent_OnConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnHandShake( HP_AgentListener pListener, HP_FN_Agent_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnSend( HP_AgentListener pListener, HP_FN_Agent_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnReceive( HP_AgentListener pListener, HP_FN_Agent_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnPullReceive( HP_AgentListener pListener, HP_FN_Agent_OnPullReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnClose( HP_AgentListener pListener, HP_FN_Agent_OnClose fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Agent_OnShutdown( HP_AgentListener pListener, HP_FN_Agent_OnShutdown fn );

//**********************************************************************************/
//***************************** Client �ص��������÷��� *****************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnPrepareConnect( HP_ClientListener pListener, HP_FN_Client_OnPrepareConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnConnect( HP_ClientListener pListener, HP_FN_Client_OnConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnHandShake( HP_ClientListener pListener, HP_FN_Client_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnSend( HP_ClientListener pListener, HP_FN_Client_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnReceive( HP_ClientListener pListener, HP_FN_Client_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnPullReceive( HP_ClientListener pListener, HP_FN_Client_OnPullReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_Client_OnClose( HP_ClientListener pListener, HP_FN_Client_OnClose fn );

//**************************************************************************/
//***************************** Server �������� *****************************/

/*//*
* ���ƣ�����ͨ�����
* ���������������ͨ�������������ɺ�ɿ�ʼ���տͻ������Ӳ��շ�����
*        
* ������        lpszBindAddress    -- ������ַ
*            usPort            -- �����˿�
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Server_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_Start( HP_Server pServer, Char* lpszBindAddress, WORD usPort );

/*//*
* ���ƣ��ر�ͨ�����
* �������رշ����ͨ��������ر���ɺ�Ͽ����пͻ������Ӳ��ͷ�������Դ
*        
* ������    
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Server_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_Stop( HP_Server pServer );

/*//*
* ���ƣ���������
* ��������ָ�����ӷ�������
*        
* ������        dwConnID    -- ���� ID
*            pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_Send( HP_Server pServer, HP_CONNID dwConnID, const void* pBuffer, int iLength );

/*//*
* ���ƣ���������
* ��������ָ�����ӷ�������
*        
* ������        dwConnID    -- ���� ID
*            pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
*            iOffset        -- ���ͻ�����ָ��ƫ����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_SendPart( HP_Server pServer, HP_CONNID dwConnID, const void* pBuffer, int iLength, int iOffset );

/*//*
* ���ƣ����Ͷ�������
* ��������ָ�����ӷ��Ͷ�������
*        TCP - ˳�����������ݰ� 
*        UDP - ���������ݰ���ϳ�һ�����ݰ����ͣ����ݰ����ܳ��Ȳ��ܴ������õ� UDP ����󳤶ȣ� 
*        
* ������        dwConnID    -- ���� ID
*            pBuffers    -- ���ͻ���������
*            iCount        -- ���ͻ�������Ŀ
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_SendPackets( HP_Server pServer, HP_CONNID dwConnID, const WSABUFArray& pBuffers, int iCount );

/*/*
* ���ƣ���ͣ/�ָ�����
* ��������ͣ/�ָ�ĳ�����ӵ����ݽ��չ���
*
* ������        dwConnID    -- ���� ID
*            bPause        -- TRUE - ��ͣ, FALSE - �ָ�
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_PauseReceive( HP_Server pServer, HP_CONNID dwConnID, BOOL bPause );

/*//*
* ���ƣ��Ͽ�����
* �������Ͽ���ĳ���ͻ��˵�����
*        
* ������        dwConnID    -- ���� ID
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_Disconnect( HP_Server pServer, HP_CONNID dwConnID, BOOL bForce );

/*//*
* ���ƣ��Ͽ���ʱ����
* �������Ͽ�����ָ��ʱ��������
*        
* ������        dwPeriod    -- ʱ�������룩
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_DisconnectLongConnections( HP_Server pServer, WORD dwPeriod, BOOL bForce );

/*//*
* ���ƣ��Ͽ���Ĭ����
* �������Ͽ�����ָ��ʱ���ľ�Ĭ����
*        
* ������        dwPeriod    -- ʱ�������룩
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_DisconnectSilenceConnections( HP_Server pServer, WORD dwPeriod, BOOL bForce );

//******************************************************************************/
//***************************** Server ���Է��ʷ��� *****************************/

/*//*
* ���ƣ��������ӵĸ�������
* �������Ƿ�Ϊ���Ӱ󶨸������ݻ��߰�ʲô�������ݣ�����Ӧ�ó���ֻ�����
*        
* ������        dwConnID    -- ���� ID
*            pv            -- ����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���Ч������ ID��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_SetConnectionExtra( HP_Server pServer, HP_CONNID dwConnID, void* pExtra );

/*//*
* ���ƣ���ȡ���ӵĸ�������
* �������Ƿ�Ϊ���Ӱ󶨸������ݻ��߰�ʲô�������ݣ�����Ӧ�ó���ֻ�����
*        
* ������        dwConnID    -- ���� ID
*            ppv            -- ����ָ��
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���Ч������ ID��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetConnectionExtra( HP_Server pServer, HP_CONNID dwConnID, void* ppExtra );

//* ���ͨ������Ƿ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_HasStarted( HP_Server pServer );
//* �鿴ͨ�������ǰ״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_ServiceState __stdcall HP_Server_GetState( HP_Server pServer );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_SocketError __stdcall HP_Server_GetLastError( HP_Server pServer );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_Server_GetLastErrorDesc( HP_Server pServer );
//* ��ȡ������δ�������ݵĳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetPendingDataLength( HP_Server pServer, HP_CONNID dwConnID, void* piPending );
//* ��ȡ���ӵ����ݽ���״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_IsPauseReceive( HP_Server pServer, HP_CONNID dwConnID, PBOOL& pbPaused );
//* ��ȡ�ͻ��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetConnectionCount( HP_Server pServer );
//* ��ȡ�������ӵ� HP_CONNID */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetAllConnectionIDs( HP_Server pServer, HP_CONNIDArray pIDs, void* pdwCount );
//* ��ȡĳ���ͻ�������ʱ�������룩 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetConnectPeriod( HP_Server pServer, HP_CONNID dwConnID, void* pdwPeriod );
//* ��ȡĳ�����Ӿ�Ĭʱ�䣨���룩 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetSilencePeriod( HP_Server pServer, HP_CONNID dwConnID, void* pdwPeriod );
//* ��ȡ���� Socket �ĵ�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetListenAddress( HP_Server pServer, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
//* ��ȡĳ�����ӵı��ص�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetLocalAddress( HP_Server pServer, HP_CONNID dwConnID, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
//* ��ȡĳ�����ӵ�Զ�̵�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_GetRemoteAddress( HP_Server pServer, HP_CONNID dwConnID, Char* lpszAddress, int& piAddressLen, WORD& pusPort );

//* �������ݷ��Ͳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetSendPolicy( HP_Server pServer, En_HP_SendPolicy enSendPolicy );
//* ���� Socket �����������ʱ�䣨���룬�������ڼ�� Socket ��������ܱ���ȡʹ�ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetFreeSocketObjLockTime( HP_Server pServer, WORD dwFreeSocketObjLockTime );
//* ���� Socket ����ش�С��ͨ������Ϊƽ���������������� 1/3 - 1/2�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetFreeSocketObjPool( HP_Server pServer, WORD dwFreeSocketObjPool );
//* �����ڴ�黺��ش�С��ͨ������Ϊ Socket ����ش�С�� 2 - 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetFreeBufferObjPool( HP_Server pServer, WORD dwFreeBufferObjPool );
//* ���� Socket ����ػ��շ�ֵ��ͨ������Ϊ Socket ����ش�С�� 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetFreeSocketObjHold( HP_Server pServer, WORD dwFreeSocketObjHold );
//* �����ڴ�黺��ػ��շ�ֵ��ͨ������Ϊ�ڴ�黺��ش�С�� 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetFreeBufferObjHold( HP_Server pServer, WORD dwFreeBufferObjHold );
//* ���������������������������ֵԤ�����ڴ棬�����Ҫ����ʵ��������ã����˹���*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetMaxConnectionCount( HP_Server pServer, WORD dwMaxConnectionCount );
//* ���ù����߳�������ͨ������Ϊ 2 * CPU + 2�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetWorkerThreadCount( HP_Server pServer, WORD dwWorkerThreadCount );
//* �����Ƿ��Ǿ�Ĭʱ�䣨����Ϊ TRUE ʱ DisconnectSilenceConnections() �� GetSilencePeriod() ����Ч��Ĭ�ϣ�TRUE�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Server_SetMarkSilence( HP_Server pServer, BOOL bMarkSilence );

//* ��ȡ���ݷ��Ͳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_SendPolicy __stdcall HP_Server_GetSendPolicy( HP_Server pServer );
//* ��ȡ Socket �����������ʱ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetFreeSocketObjLockTime( HP_Server pServer );
//* ��ȡ Socket ����ش�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetFreeSocketObjPool( HP_Server pServer );
//* ��ȡ�ڴ�黺��ش�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetFreeBufferObjPool( HP_Server pServer );
//* ��ȡ Socket ����ػ��շ�ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetFreeSocketObjHold( HP_Server pServer );
//* ��ȡ�ڴ�黺��ػ��շ�ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetFreeBufferObjHold( HP_Server pServer );
//* ��ȡ��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetMaxConnectionCount( HP_Server pServer );
//* ��ȡ�����߳����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Server_GetWorkerThreadCount( HP_Server pServer );
//* ����Ƿ��Ǿ�Ĭʱ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Server_IsMarkSilence( HP_Server pServer );

//**********************************************************************************/
//******************************* TCP Server �������� *******************************/

/*//*
* ���ƣ�����С�ļ�
* ��������ָ�����ӷ��� 4096 KB ���µ�С�ļ�
*        
* ������        dwConnID        -- ���� ID
*            lpszFileName    -- �ļ�·��
*            pHead            -- ͷ����������
*            pTail            -- β����������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_TcpServer_SendSmallFile( HP_Server pServer, HP_CONNID dwConnID, Char* lpszFileName, const LPWSABUF& pHead, const LPWSABUF& pTail );

//**********************************************************************************/
//***************************** TCP Server ���Է��ʷ��� *****************************/

//* ���ü��� Socket �ĵȺ���д�С�����ݲ������������������ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpServer_SetSocketListenQueue( HP_TcpServer pServer, WORD dwSocketListenQueue );
//* ���� Accept ԤͶ�����������ݸ��ص������ã�Accept ԤͶ������Խ����֧�ֵĲ�����������Խ�ࣩ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpServer_SetAcceptSocketCount( HP_TcpServer pServer, WORD dwAcceptSocketCount );
//* ����ͨ�����ݻ�������С������ƽ��ͨ�����ݰ���С�������ã�ͨ������Ϊ 1024 �ı����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpServer_SetSocketBufferSize( HP_TcpServer pServer, WORD dwSocketBufferSize );
//* ����������������������룬0 �򲻷�����������Ĭ�ϣ�30 * 1000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpServer_SetKeepAliveTime( HP_TcpServer pServer, WORD dwKeepAliveTime );
//* �����쳣��������������룬0 ����������������Ĭ�ϣ�10 * 1000������������ɴ� [Ĭ�ϣ�WinXP 5 ��, Win7 10 ��] ��ⲻ������ȷ�ϰ�����Ϊ�Ѷ��ߣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpServer_SetKeepAliveInterval( HP_TcpServer pServer, WORD dwKeepAliveInterval );

//* ��ȡ Accept ԤͶ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpServer_GetAcceptSocketCount( HP_TcpServer pServer );
//* ��ȡͨ�����ݻ�������С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpServer_GetSocketBufferSize( HP_TcpServer pServer );
//* ��ȡ���� Socket �ĵȺ���д�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpServer_GetSocketListenQueue( HP_TcpServer pServer );
//* ��ȡ������������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpServer_GetKeepAliveTime( HP_TcpServer pServer );
//* ��ȡ�쳣��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpServer_GetKeepAliveInterval( HP_TcpServer pServer );

//**********************************************************************************/
//***************************** UDP Server ���Է��ʷ��� *****************************/

//* �������ݱ�����󳤶ȣ������ھ����������²����� 1472 �ֽڣ��ڹ����������²����� 548 �ֽڣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpServer_SetMaxDatagramSize( HP_UdpServer pServer, WORD dwMaxDatagramSize );
//* ��ȡ���ݱ�����󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpServer_GetMaxDatagramSize( HP_UdpServer pServer );

//* ���� Receive ԤͶ�����������ݸ��ص������ã�Receive ԤͶ������Խ���򶪰�����ԽС�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpServer_SetPostReceiveCount( HP_UdpServer pServer, WORD dwPostReceiveCount );
//* ��ȡ Receive ԤͶ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpServer_GetPostReceiveCount( HP_UdpServer pServer );

//* ���ü������Դ�����0 �򲻷��ͼ�������������������Դ�������Ϊ�Ѷ��ߣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpServer_SetDetectAttempts( HP_UdpServer pServer, WORD dwDetectAttempts );
//* ���ü������ͼ�����룬0 �����ͼ����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpServer_SetDetectInterval( HP_UdpServer pServer, WORD dwDetectInterval );
//* ��ȡ���������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpServer_GetDetectAttempts( HP_UdpServer pServer );
//* ��ȡ��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpServer_GetDetectInterval( HP_UdpServer pServer );

//**************************************************************************/
//***************************** Agent �������� *****************************/

//*
/** ���ƣ�����ͨ�����
* ����������ͨ�Ŵ��������������ɺ�ɿ�ʼ����Զ�̷�����
*        
* ������        lpszBindAddress    -- �󶨵�ַ��Ĭ�ϣ�nullptr���� 0.0.0.0��
*            bAsyncConnect    -- �Ƿ�����첽 Connect
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Agent_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_Start( HP_Agent pAgent, Char* lpszBindAddress, BOOL bAsyncConnect );

/*//*
* ���ƣ��ر�ͨ�����
* �������ر�ͨ��������ر���ɺ�Ͽ��������Ӳ��ͷ�������Դ
*        
* ������    
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Agent_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_Stop( HP_Agent pAgent );

/*//*
* ���ƣ����ӷ�����
* ���������ӷ����������ӳɹ��� IAgentListener ����յ� OnConnect() / OnHandShake() �¼�
*        
* ������        lpszRemoteAddress    -- ����˵�ַ
*            usPort                -- ����˶˿�
*            pdwConnID            -- ���� ID��Ĭ�ϣ�nullptr������ȡ���� ID��
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ������ SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_Connect( HP_Agent pAgent, Char* lpszRemoteAddress, WORD usPort, PInteger pdwConnID );

/*//*
* ���ƣ����ӷ�����
* ���������ӷ����������ӳɹ��� IAgentListener ����յ� OnConnect() / OnHandShake() �¼�
*        
* ������        lpszRemoteAddress    -- ����˵�ַ
*            usPort                -- ����˶˿�
*            pdwConnID            -- ���� ID��Ĭ�ϣ�nullptr������ȡ���� ID��
*            pExtra                -- ���Ӹ������ݣ�Ĭ�ϣ�nullptr��
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ������ SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_ConnectWithExtra( HP_Agent pAgent, Char* lpszRemoteAddress, WORD usPort, PInteger pdwConnID, void* pExtra );


/*//*
* ���ƣ���������
* ��������ָ�����ӷ�������
*        
* ������        dwConnID    -- ���� ID
*            pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_Send( HP_Agent pAgent, HP_CONNID dwConnID, const void* pBuffer, int iLength );

/*//*
* ���ƣ���������
* ��������ָ�����ӷ�������
*        
* ������        dwConnID    -- ���� ID
*            pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
*            iOffset        -- ���ͻ�����ָ��ƫ����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_SendPart( HP_Agent pAgent, HP_CONNID dwConnID, const void* pBuffer, int iLength, int iOffset );

/*//*
* ���ƣ����Ͷ�������
* ��������ָ�����ӷ��Ͷ�������
*        TCP - ˳�����������ݰ� 
*        UDP - ���������ݰ���ϳ�һ�����ݰ����ͣ����ݰ����ܳ��Ȳ��ܴ������õ� UDP ����󳤶ȣ� 
*        
* ������        dwConnID    -- ���� ID
*            pBuffers    -- ���ͻ���������
*            iCount        -- ���ͻ�������Ŀ
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_SendPackets( HP_Agent pAgent, HP_CONNID dwConnID, const WSABUFArray& pBuffers, int iCount );

/*//*
* ���ƣ���ͣ/�ָ�����
* ��������ͣ/�ָ�ĳ�����ӵ����ݽ��չ���
*        
* ������        dwConnID    -- ���� ID
*            bPause        -- TRUE - ��ͣ, FALSE - �ָ�
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_PauseReceive( HP_Agent pAgent, HP_CONNID dwConnID, BOOL bPause );

/*//*
* ���ƣ��Ͽ�����
* �������Ͽ�ĳ������
*        
* ������        dwConnID    -- ���� ID
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_Disconnect( HP_Agent pAgent, HP_CONNID dwConnID, BOOL bForce );

/*//*
* ���ƣ��Ͽ���ʱ����
* �������Ͽ�����ָ��ʱ��������
*        
* ������        dwPeriod    -- ʱ�������룩
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_DisconnectLongConnections( HP_Agent pAgent, WORD dwPeriod, BOOL bForce );

/*//*
* ���ƣ��Ͽ���Ĭ����
* �������Ͽ�����ָ��ʱ���ľ�Ĭ����
*        
* ������        dwPeriod    -- ʱ�������룩
*            bForce        -- �Ƿ�ǿ�ƶϿ�����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_DisconnectSilenceConnections( HP_Agent pAgent, WORD dwPeriod, BOOL bForce );

//******************************************************************************/
//***************************** Agent ���Է��ʷ��� *****************************/

/*//*
* ���ƣ��������ӵĸ�������
* �������Ƿ�Ϊ���Ӱ󶨸������ݻ��߰�ʲô�������ݣ�����Ӧ�ó���ֻ�����
*        
* ������        dwConnID    -- ���� ID
*            pv            -- ����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���Ч������ ID��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_SetConnectionExtra( HP_Agent pAgent, HP_CONNID dwConnID, void* pExtra );

/*//*
* ���ƣ���ȡ���ӵĸ�������
* �������Ƿ�Ϊ���Ӱ󶨸������ݻ��߰�ʲô�������ݣ�����Ӧ�ó���ֻ�����
*        
* ������        dwConnID    -- ���� ID
*            ppv            -- ����ָ��
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���Ч������ ID��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetConnectionExtra( HP_Agent pAgent, HP_CONNID dwConnID, void* ppExtra );

//* ���ͨ������Ƿ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_HasStarted( HP_Agent pAgent );
//* �鿴ͨ�������ǰ״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_ServiceState __stdcall HP_Agent_GetState( HP_Agent pAgent );
//* ��ȡ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetConnectionCount( HP_Agent pAgent );
//* ��ȡ�������ӵ� HP_CONNID */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetAllConnectionIDs( HP_Agent pAgent, HP_CONNIDArray pIDs, void* pdwCount );
//* ��ȡĳ������ʱ�������룩 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetConnectPeriod( HP_Agent pAgent, HP_CONNID dwConnID, void* pdwPeriod );
//* ��ȡĳ�����Ӿ�Ĭʱ�䣨���룩 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetSilencePeriod( HP_Agent pAgent, HP_CONNID dwConnID, void* pdwPeriod );
//* ��ȡĳ�����ӵı��ص�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetLocalAddress( HP_Agent pAgent, HP_CONNID dwConnID, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
//* ��ȡĳ�����ӵ�Զ�̵�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetRemoteAddress( HP_Agent pAgent, HP_CONNID dwConnID, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
//* ��ȡĳ�����ӵ�Զ��������Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetRemoteHost( HP_Agent pAgent, HP_CONNID dwConnID, Char* lpszHost, int& piHostLen, WORD& Integer );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_SocketError __stdcall HP_Agent_GetLastError( HP_Agent pAgent );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_Agent_GetLastErrorDesc( HP_Agent pAgent );
//* ��ȡ������δ�������ݵĳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_GetPendingDataLength( HP_Agent pAgent, HP_CONNID dwConnID, void* piPending );
//* ��ȡ���ӵ����ݽ���״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_IsPauseReceive( HP_Agent pAgent, HP_CONNID dwConnID, PBOOL& pbPaused );

//* �������ݷ��Ͳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetSendPolicy( HP_Agent pAgent, En_HP_SendPolicy enSendPolicy );
//* ���� Socket �����������ʱ�䣨���룬�������ڼ�� Socket ��������ܱ���ȡʹ�ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetFreeSocketObjLockTime( HP_Agent pAgent, WORD dwFreeSocketObjLockTime );
//* ���� Socket ����ش�С��ͨ������Ϊƽ���������������� 1/3 - 1/2�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetFreeSocketObjPool( HP_Agent pAgent, WORD dwFreeSocketObjPool );
//* �����ڴ�黺��ش�С��ͨ������Ϊ Socket ����ش�С�� 2 - 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetFreeBufferObjPool( HP_Agent pAgent, WORD dwFreeBufferObjPool );
//* ���� Socket ����ػ��շ�ֵ��ͨ������Ϊ Socket ����ش�С�� 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetFreeSocketObjHold( HP_Agent pAgent, WORD dwFreeSocketObjHold );
//* �����ڴ�黺��ػ��շ�ֵ��ͨ������Ϊ�ڴ�黺��ش�С�� 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetFreeBufferObjHold( HP_Agent pAgent, WORD dwFreeBufferObjHold );
//* ���������������������������ֵԤ�����ڴ棬�����Ҫ����ʵ��������ã����˹���*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetMaxConnectionCount( HP_Agent pAgent, WORD dwMaxConnectionCount );
//* ���ù����߳�������ͨ������Ϊ 2 * CPU + 2�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetWorkerThreadCount( HP_Agent pAgent, WORD dwWorkerThreadCount );
//* �����Ƿ��Ǿ�Ĭʱ�䣨����Ϊ TRUE ʱ DisconnectSilenceConnections() �� GetSilencePeriod() ����Ч��Ĭ�ϣ�TRUE�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Agent_SetMarkSilence( HP_Agent pAgent, BOOL bMarkSilence );

//* ��ȡ���ݷ��Ͳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_SendPolicy __stdcall HP_Agent_GetSendPolicy( HP_Agent pAgent );
//* ��ȡ Socket �����������ʱ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetFreeSocketObjLockTime( HP_Agent pAgent );
//* ��ȡ Socket ����ش�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetFreeSocketObjPool( HP_Agent pAgent );
//* ��ȡ�ڴ�黺��ش�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetFreeBufferObjPool( HP_Agent pAgent );
//* ��ȡ Socket ����ػ��շ�ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetFreeSocketObjHold( HP_Agent pAgent );
//* ��ȡ�ڴ�黺��ػ��շ�ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetFreeBufferObjHold( HP_Agent pAgent );
//* ��ȡ��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetMaxConnectionCount( HP_Agent pAgent );
//* ��ȡ�����߳����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Agent_GetWorkerThreadCount( HP_Agent pAgent );
//* ����Ƿ��Ǿ�Ĭʱ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Agent_IsMarkSilence( HP_Agent pAgent );

//**********************************************************************************/
//******************************* TCP Agent �������� *******************************/

//*
/** ���ƣ�����С�ļ�
* ��������ָ�����ӷ��� 4096 KB ���µ�С�ļ�
*        
* ������        dwConnID        -- ���� ID
*            lpszFileName    -- �ļ�·��
*            pHead            -- ͷ����������
*            pTail            -- β����������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_TcpAgent_SendSmallFile( HP_Agent pAgent, HP_CONNID dwConnID, Char* lpszFileName, const LPWSABUF& pHead, const LPWSABUF& pTail );

//**********************************************************************************/
//***************************** TCP Agent ���Է��ʷ��� *****************************/

//* �����Ƿ����õ�ַ���û��ƣ�Ĭ�ϣ������ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpAgent_SetReuseAddress( HP_TcpAgent pAgent, BOOL bReuseAddress );
//* ����Ƿ����õ�ַ���û��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_TcpAgent_IsReuseAddress( HP_TcpAgent pAgent );

//* ����ͨ�����ݻ�������С������ƽ��ͨ�����ݰ���С�������ã�ͨ������Ϊ 1024 �ı����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpAgent_SetSocketBufferSize( HP_TcpAgent pAgent, WORD dwSocketBufferSize );
//* ����������������������룬0 �򲻷�����������Ĭ�ϣ�30 * 1000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpAgent_SetKeepAliveTime( HP_TcpAgent pAgent, WORD dwKeepAliveTime );
//* �����쳣��������������룬0 ����������������Ĭ�ϣ�10 * 1000������������ɴ� [Ĭ�ϣ�WinXP 5 ��, Win7 10 ��] ��ⲻ������ȷ�ϰ�����Ϊ�Ѷ��ߣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpAgent_SetKeepAliveInterval( HP_TcpAgent pAgent, WORD dwKeepAliveInterval );

//* ��ȡͨ�����ݻ�������С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpAgent_GetSocketBufferSize( HP_TcpAgent pAgent );
//* ��ȡ������������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpAgent_GetKeepAliveTime( HP_TcpAgent pAgent );
//* ��ȡ�쳣��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpAgent_GetKeepAliveInterval( HP_TcpAgent pAgent );

//******************************************************************************/
//***************************** Client ����������� *****************************/

//*
/** ���ƣ�����ͨ�����
* �����������ͻ���ͨ����������ӷ���ˣ�������ɺ�ɿ�ʼ�շ�����
*        
* ������        lpszRemoteAddress    -- ����˵�ַ
*            usPort                -- ����˶˿�
*            bAsyncConnect        -- �Ƿ�����첽 Connect
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Client_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_Start( HP_Client pClient, Char* lpszRemoteAddress, WORD usPort, BOOL bAsyncConnect );

/*//*
* ���ƣ�����ͨ���������ָ���󶨵�ַ��
* �����������ͻ���ͨ����������ӷ���ˣ�������ɺ�ɿ�ʼ�շ�����
*        
* ������        lpszRemoteAddress    -- ����˵�ַ
*            usPort                -- ����˶˿�
*            bAsyncConnect        -- �Ƿ�����첽 Connect
*            lpszBindAddress        -- �󶨵�ַ��Ĭ�ϣ�nullptr��TcpClient/UdpClient -> ��ִ�а󶨲�����UdpCast �� -> 0.0.0.0��
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Client_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_StartWithBindAddress( HP_Client pClient, Char* lpszRemoteAddress, WORD usPort, BOOL bAsyncConnect, Char* lpszBindAddress );

/*//*
* ���ƣ��ر�ͨ�����
* �������رտͻ���ͨ��������ر���ɺ�Ͽ������˵����Ӳ��ͷ�������Դ
*        
* ������    
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� HP_Client_GetLastError() ��ȡ�������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_Stop( HP_Client pClient );

/*//*
* ���ƣ���������
* �����������˷�������
*        
* ������        pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_Send( HP_Client pClient, const void* pBuffer, int iLength );

/*//*
* ���ƣ���������
* �����������˷�������
*        
* ������        pBuffer        -- ���ͻ�����
*            iLength        -- ���ͻ���������
*            iOffset        -- ���ͻ�����ָ��ƫ����
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_SendPart( HP_Client pClient, const void* pBuffer, int iLength, int iOffset );

/*//*
* ���ƣ����Ͷ�������
* �����������˷��Ͷ�������
*        TCP - ˳�����������ݰ� 
*        UDP - ���������ݰ���ϳ�һ�����ݰ����ͣ����ݰ����ܳ��Ȳ��ܴ������õ� UDP ����󳤶ȣ� 
*        
* ������        pBuffers    -- ���ͻ���������
*            iCount        -- ���ͻ�������Ŀ
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_SendPackets( HP_Client pClient, const WSABUFArray& pBuffers, int iCount );

/*//*
* ���ƣ���ͣ/�ָ�����
* ��������ͣ/�ָ�ĳ�����ӵ����ݽ��չ���
*        
*            bPause    -- TRUE - ��ͣ, FALSE - �ָ�
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_PauseReceive( HP_Client pClient, BOOL bPause );

//******************************************************************************/
//***************************** Client ���Է��ʷ��� *****************************/

//* �������ӵĸ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Client_SetExtra( HP_Client pClient, void* pExtra );
//* ��ȡ���ӵĸ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void* __stdcall HP_Client_GetExtra( HP_Client pClient );

//* ���ͨ������Ƿ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_HasStarted( HP_Client pClient );
//* �鿴ͨ�������ǰ״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_ServiceState __stdcall HP_Client_GetState( HP_Client pClient );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_SocketError __stdcall HP_Client_GetLastError( HP_Client pClient );
//* ��ȡ���һ��ʧ�ܲ����Ĵ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_Client_GetLastErrorDesc( HP_Client pClient );
//* ��ȡ�������������� ID */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_CONNID __stdcall HP_Client_GetConnectionID( HP_Client pClient );
//* ��ȡ Client Socket �ĵ�ַ��Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_GetLocalAddress( HP_Client pClient, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
//* ��ȡ���ӵ�Զ��������Ϣ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_GetRemoteHost( HP_Client pClient, Char* lpszHost, int& piHostLen, WORD& pusPort );
//* ��ȡ������δ�������ݵĳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_GetPendingDataLength( HP_Client pClient, int& piPending );
//* ��ȡ���ӵ����ݽ���״̬ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_Client_IsPauseReceive( HP_Client pClient, PBOOL& pbPaused );
//* �����ڴ�黺��ش�С��ͨ������Ϊ -> PUSH ģ�ͣ�5 - 10��PULL ģ�ͣ�10 - 20 �� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Client_SetFreeBufferPoolSize( HP_Client pClient, WORD dwFreeBufferPoolSize );
//* �����ڴ�黺��ػ��շ�ֵ��ͨ������Ϊ�ڴ�黺��ش�С�� 3 ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Client_SetFreeBufferPoolHold( HP_Client pClient, WORD dwFreeBufferPoolHold );
//* ��ȡ�ڴ�黺��ش�С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Client_GetFreeBufferPoolSize( HP_Client pClient );
//* ��ȡ�ڴ�黺��ػ��շ�ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_Client_GetFreeBufferPoolHold( HP_Client pClient );

//**********************************************************************************/
//******************************* TCP Client �������� *******************************/

//*
/** ���ƣ�����С�ļ�
* �����������˷��� 4096 KB ���µ�С�ļ�
*        
* ������        lpszFileName    -- �ļ�·��
*            pHead            -- ͷ����������
*            pTail            -- β����������
* ����ֵ��    TRUE    -- �ɹ�
*            FALSE    -- ʧ�ܣ���ͨ�� SYS_GetLastError() ��ȡ Windows �������
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_TcpClient_SendSmallFile( HP_Client pClient, Char* lpszFileName, const LPWSABUF& pHead, const LPWSABUF& pTail );

//**********************************************************************************/
//***************************** TCP Client ���Է��ʷ��� *****************************/

//* ����ͨ�����ݻ�������С������ƽ��ͨ�����ݰ���С�������ã�ͨ������Ϊ��(N * 1024) - sizeof(TBufferObj)�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpClient_SetSocketBufferSize( HP_TcpClient pClient, WORD dwSocketBufferSize );
//* ����������������������룬0 �򲻷�����������Ĭ�ϣ�30 * 1000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpClient_SetKeepAliveTime( HP_TcpClient pClient, WORD dwKeepAliveTime );
//* �����쳣��������������룬0 ����������������Ĭ�ϣ�10 * 1000������������ɴ� [Ĭ�ϣ�WinXP 5 ��, Win7 10 ��] ��ⲻ������ȷ�ϰ�����Ϊ�Ѷ��ߣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpClient_SetKeepAliveInterval( HP_TcpClient pClient, WORD dwKeepAliveInterval );

//* ��ȡͨ�����ݻ�������С */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpClient_GetSocketBufferSize( HP_TcpClient pClient );
//* ��ȡ������������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpClient_GetKeepAliveTime( HP_TcpClient pClient );
//* ��ȡ�쳣��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpClient_GetKeepAliveInterval( HP_TcpClient pClient );

//**********************************************************************************/
//***************************** UDP Client ���Է��ʷ��� *****************************/

//* �������ݱ�����󳤶ȣ������ھ����������²����� 1472 �ֽڣ��ڹ����������²����� 548 �ֽڣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpClient_SetMaxDatagramSize( HP_UdpClient pClient, WORD dwMaxDatagramSize );
//* ��ȡ���ݱ�����󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpClient_GetMaxDatagramSize( HP_UdpClient pClient );

//* ���ü������Դ�����0 �򲻷��ͼ�������������������Դ�������Ϊ�Ѷ��ߣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpClient_SetDetectAttempts( HP_UdpClient pClient, WORD dwDetectAttempts );
//* ���ü������ͼ�����룬0 �����ͼ����� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpClient_SetDetectInterval( HP_UdpClient pClient, WORD dwDetectInterval );
//* ��ȡ���������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpClient_GetDetectAttempts( HP_UdpClient pClient );
//* ��ȡ��������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpClient_GetDetectInterval( HP_UdpClient pClient );

//**********************************************************************************/
//****************************** UDP Cast ���Է��ʷ��� ******************************/

//* �������ݱ�����󳤶ȣ������ھ����������²����� 1472 �ֽڣ��ڹ����������²����� 548 �ֽڣ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpCast_SetMaxDatagramSize( HP_UdpCast pCast, WORD dwMaxDatagramSize );
//* ��ȡ���ݱ�����󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_UdpCast_GetMaxDatagramSize( HP_UdpCast pCast );
//* ��ȡ��ǰ���ݱ���Զ�̵�ַ��Ϣ��ͨ���� OnReceive �¼��е��ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_UdpCast_GetRemoteAddress( HP_UdpCast pCast, const Char* const* lpszAddress, int lpszAddress_maxidx, void* piAddressLen, void* pusPort );
//* �����Ƿ����õ�ַ���û��ƣ�Ĭ�ϣ������ã� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpCast_SetReuseAddress( HP_UdpCast pCast, BOOL bReuseAddress );
//* ����Ƿ����õ�ַ���û��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_UdpCast_IsReuseAddress( HP_UdpCast pCast );
//* ���ô���ģʽ���鲥��㲥�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpCast_SetCastMode( HP_UdpCast pCast, En_HP_CastMode enCastMode );
//* ��ȡ����ģʽ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_CastMode __stdcall HP_UdpCast_GetCastMode( HP_UdpCast pCast );
//* �����鲥���ĵ� TTL��0 - 255�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpCast_SetMultiCastTtl( HP_UdpCast pCast, int iMCTtl );
//* ��ȡ�鲥���ĵ� TTL */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall HP_UdpCast_GetMultiCastTtl( HP_UdpCast pCast );
//* �����Ƿ������鲥��·��TRUE or FALSE�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_UdpCast_SetMultiCastLoop( HP_UdpCast pCast, BOOL bMCLoop );
//* ����Ƿ������鲥��· */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_UdpCast_IsMultiCastLoop( HP_UdpCast pCast );

//***************************************************************************************/
//***************************** TCP Pull Server ����������� *****************************/

//*
/** ���ƣ�ץȡ����
* �������û�ͨ���÷����� Socket �����ץȡ����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ץȡ������
*            iLength        -- ץȡ���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullServer_Fetch( HP_TcpPullServer pServer, HP_CONNID dwConnID, void* pData, int iLength );

/*//*
* ���ƣ���̽���ݣ������Ƴ����������ݣ�
* �������û�ͨ���÷����� Socket ����п�̽����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ��̽������
*            iLength        -- ��̽���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullServer_Peek( HP_TcpPullServer pServer, HP_CONNID dwConnID, void* pData, int iLength );

//***************************************************************************************/
//***************************** TCP Pull Server ���Է��ʷ��� *****************************/

//***************************************************************************************/
//***************************** TCP Pull Agent ����������� *****************************/

/*//*
* ���ƣ�ץȡ����
* �������û�ͨ���÷����� Socket �����ץȡ����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ץȡ������
*            iLength        -- ץȡ���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullAgent_Fetch( HP_TcpPullAgent pAgent, HP_CONNID dwConnID, void* pData, int iLength );

/*//*
* ���ƣ���̽���ݣ������Ƴ����������ݣ�
* �������û�ͨ���÷����� Socket ����п�̽����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ��̽������
*            iLength        -- ��̽���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullAgent_Peek( HP_TcpPullAgent pAgent, HP_CONNID dwConnID, void* pData, int iLength );

//***************************************************************************************/
//***************************** TCP Pull Agent ���Է��ʷ��� *****************************/

//***************************************************************************************/
//***************************** TCP Pull Client ����������� *****************************/

/*//*
* ���ƣ�ץȡ����
* �������û�ͨ���÷����� Socket �����ץȡ����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ץȡ������
*            iLength        -- ץȡ���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullClient_Fetch( HP_TcpPullClient pClient, void* pData, int iLength );

/*//*
* ���ƣ���̽���ݣ������Ƴ����������ݣ�
* �������û�ͨ���÷����� Socket ����п�̽����
*        
* ������        dwConnID    -- ���� ID
*            pData        -- ��̽������
*            iLength        -- ��̽���ݳ���
* ����ֵ��    En_HP_FetchResult
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_FetchResult __stdcall HP_TcpPullClient_Peek( HP_TcpPullClient pClient, void* pData, int iLength );

//***************************************************************************************/
//***************************** TCP Pull Client ���Է��ʷ��� *****************************/

//***************************************************************************************/
//***************************** TCP Pack Server ����������� *****************************/

//***************************************************************************************/
//***************************** TCP Pack Server ���Է��ʷ��� *****************************/

//* �������ݰ���󳤶ȣ���Ч���ݰ���󳤶Ȳ��ܳ��� 4194303/0x3FFFFF �ֽڣ�Ĭ�ϣ�262144/0x40000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackServer_SetMaxPackSize( HP_TcpPackServer pServer, WORD dwMaxPackSize );
//* ���ð�ͷ��ʶ����Ч��ͷ��ʶȡֵ��Χ 0 ~ 1023/0x3FF������ͷ��ʶΪ 0 ʱ��У���ͷ��Ĭ�ϣ�0�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackServer_SetPackHeaderFlag( HP_TcpPackServer pServer, WORD usPackHeaderFlag );

//* ��ȡ���ݰ���󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackServer_GetMaxPackSize( HP_TcpPackServer pServer );
//* ��ȡ��ͷ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackServer_GetPackHeaderFlag( HP_TcpPackServer pServer );

//***************************************************************************************/
//***************************** TCP Pack Agent ����������� *****************************/

//***************************************************************************************/
//***************************** TCP Pack Agent ���Է��ʷ��� *****************************/

//* �������ݰ���󳤶ȣ���Ч���ݰ���󳤶Ȳ��ܳ��� 4194303/0x3FFFFF �ֽڣ�Ĭ�ϣ�262144/0x40000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackAgent_SetMaxPackSize( HP_TcpPackAgent pAgent, WORD dwMaxPackSize );
//* ���ð�ͷ��ʶ����Ч��ͷ��ʶȡֵ��Χ 0 ~ 1023/0x3FF������ͷ��ʶΪ 0 ʱ��У���ͷ��Ĭ�ϣ�0�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackAgent_SetPackHeaderFlag( HP_TcpPackAgent pAgent, WORD usPackHeaderFlag );

//* ��ȡ���ݰ���󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackAgent_GetMaxPackSize( HP_TcpPackAgent pAgent );
//* ��ȡ��ͷ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackAgent_GetPackHeaderFlag( HP_TcpPackAgent pAgent );

//***************************************************************************************/
//***************************** TCP Pack Client ����������� *****************************/

//***************************************************************************************/
//***************************** TCP Pack Client ���Է��ʷ��� *****************************/

//* �������ݰ���󳤶ȣ���Ч���ݰ���󳤶Ȳ��ܳ��� 4194303/0x3FFFFF �ֽڣ�Ĭ�ϣ�262144/0x40000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackClient_SetMaxPackSize( HP_TcpPackClient pClient, WORD dwMaxPackSize );
//* ���ð�ͷ��ʶ����Ч��ͷ��ʶȡֵ��Χ 0 ~ 1023/0x3FF������ͷ��ʶΪ 0 ʱ��У���ͷ��Ĭ�ϣ�0�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_TcpPackClient_SetPackHeaderFlag( HP_TcpPackClient pClient, WORD usPackHeaderFlag );

//* ��ȡ���ݰ���󳤶� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackClient_GetMaxPackSize( HP_TcpPackClient pClient );
//* ��ȡ��ͷ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_TcpPackClient_GetPackHeaderFlag( HP_TcpPackClient pClient );

//*****************************************************************************************************************************************************/
//******************************************************************** HTTP Exports *******************************************************************/
//*****************************************************************************************************************************************************/

//****************************************************/
//******************* HTTP �ص����� *******************/


  /*/* HTTP Server �ص����� */ */
typedef HP_FN_Http_OnMessageBegin HP_FN_HttpServer_OnMessageBegin;
typedef HP_FN_Http_OnRequestLine HP_FN_HttpServer_OnRequestLine;
typedef HP_FN_Http_OnHeader HP_FN_HttpServer_OnHeader;
typedef HP_FN_Http_OnHeadersComplete HP_FN_HttpServer_OnHeadersComplete;
typedef HP_FN_Http_OnBody HP_FN_HttpServer_OnBody;
typedef HP_FN_Http_OnChunkHeader HP_FN_HttpServer_OnChunkHeader;
typedef HP_FN_Http_OnChunkComplete HP_FN_HttpServer_OnChunkComplete;
typedef HP_FN_Http_OnMessageComplete HP_FN_HttpServer_OnMessageComplete;
typedef HP_FN_Http_OnUpgrade HP_FN_HttpServer_OnUpgrade;
typedef HP_FN_Http_OnParseError HP_FN_HttpServer_OnParseError;
typedef HP_FN_Http_OnWSMessageHeader HP_FN_HttpServer_OnWSMessageHeader;
typedef HP_FN_Http_OnWSMessageBody HP_FN_HttpServer_OnWSMessageBody;
typedef HP_FN_Http_OnWSMessageComplete HP_FN_HttpServer_OnWSMessageComplete;
typedef HP_FN_Server_OnPrepareListen HP_FN_HttpServer_OnPrepareListen;
typedef HP_FN_Server_OnAccept HP_FN_HttpServer_OnAccept;
typedef HP_FN_Server_OnHandShake HP_FN_HttpServer_OnHandShake;
typedef HP_FN_Server_OnReceive HP_FN_HttpServer_OnReceive;
typedef HP_FN_Server_OnSend HP_FN_HttpServer_OnSend;
typedef HP_FN_Server_OnClose HP_FN_HttpServer_OnClose;
typedef HP_FN_Server_OnShutdown HP_FN_HttpServer_OnShutdown;

  /*/* HTTP Agent �ص����� */ */
typedef HP_FN_Http_OnMessageBegin HP_FN_HttpAgent_OnMessageBegin;
typedef HP_FN_Http_OnStatusLine HP_FN_HttpAgent_OnStatusLine;
typedef HP_FN_Http_OnHeader HP_FN_HttpAgent_OnHeader;
typedef HP_FN_Http_OnHeadersComplete HP_FN_HttpAgent_OnHeadersComplete;
typedef HP_FN_Http_OnBody HP_FN_HttpAgent_OnBody;
typedef HP_FN_Http_OnChunkHeader HP_FN_HttpAgent_OnChunkHeader;
typedef HP_FN_Http_OnChunkComplete HP_FN_HttpAgent_OnChunkComplete;
typedef HP_FN_Http_OnMessageComplete HP_FN_HttpAgent_OnMessageComplete;
typedef HP_FN_Http_OnUpgrade HP_FN_HttpAgent_OnUpgrade;
typedef HP_FN_Http_OnParseError HP_FN_HttpAgent_OnParseError;
typedef HP_FN_Http_OnWSMessageHeader HP_FN_HttpAgent_OnWSMessageHeader;
typedef HP_FN_Http_OnWSMessageBody HP_FN_HttpAgent_OnWSMessageBody;
typedef HP_FN_Http_OnWSMessageComplete HP_FN_HttpAgent_OnWSMessageComplete;
typedef HP_FN_Agent_OnPrepareConnect HP_FN_HttpAgent_OnPrepareConnect;
typedef HP_FN_Agent_OnConnect HP_FN_HttpAgent_OnConnect;
typedef HP_FN_Agent_OnHandShake HP_FN_HttpAgent_OnHandShake;
typedef HP_FN_Agent_OnReceive HP_FN_HttpAgent_OnReceive;
typedef HP_FN_Agent_OnSend HP_FN_HttpAgent_OnSend;
typedef HP_FN_Agent_OnClose HP_FN_HttpAgent_OnClose;
typedef HP_FN_Agent_OnShutdown HP_FN_HttpAgent_OnShutdown;

  /*/* HTTP Client �ص����� */ */
typedef HP_FN_Http_OnMessageBegin HP_FN_HttpClient_OnMessageBegin;
typedef HP_FN_Http_OnStatusLine HP_FN_HttpClient_OnStatusLine;
typedef HP_FN_Http_OnHeader HP_FN_HttpClient_OnHeader;
typedef HP_FN_Http_OnHeadersComplete HP_FN_HttpClient_OnHeadersComplete;
typedef HP_FN_Http_OnBody HP_FN_HttpClient_OnBody;
typedef HP_FN_Http_OnChunkHeader HP_FN_HttpClient_OnChunkHeader;
typedef HP_FN_Http_OnChunkComplete HP_FN_HttpClient_OnChunkComplete;
typedef HP_FN_Http_OnMessageComplete HP_FN_HttpClient_OnMessageComplete;
typedef HP_FN_Http_OnUpgrade HP_FN_HttpClient_OnUpgrade;
typedef HP_FN_Http_OnParseError HP_FN_HttpClient_OnParseError;
typedef HP_FN_Http_OnWSMessageHeader HP_FN_HttpClient_OnWSMessageHeader;
typedef HP_FN_Http_OnWSMessageBody HP_FN_HttpClient_OnWSMessageBody;
typedef HP_FN_Http_OnWSMessageComplete HP_FN_HttpClient_OnWSMessageComplete;
typedef HP_FN_Client_OnPrepareConnect HP_FN_HttpClient_OnPrepareConnect;
typedef HP_FN_Client_OnConnect HP_FN_HttpClient_OnConnect;
typedef HP_FN_Client_OnHandShake HP_FN_HttpClient_OnHandShake;
typedef HP_FN_Client_OnReceive HP_FN_HttpClient_OnReceive;
typedef HP_FN_Client_OnSend HP_FN_HttpClient_OnSend;
typedef HP_FN_Client_OnClose HP_FN_HttpClient_OnClose;

//****************************************************/
//***************** HTTP ���󴴽����� *****************/

// ���� HP_HttpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpServer __stdcall Create_HP_HttpServer( HP_HttpServerListener pListener );
// ���� HP_HttpAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpAgent __stdcall Create_HP_HttpAgent( HP_HttpAgentListener pListener );
// ���� HP_HttpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpClient __stdcall Create_HP_HttpClient( HP_HttpClientListener pListener );
// ���� HP_HttpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpSyncClient __stdcall Create_HP_HttpSyncClient( HP_HttpClientListener pListener );

// ���� HP_HttpServer ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpServer( HP_HttpServer pServer );
// ���� HP_HttpAgent ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpAgent( HP_HttpAgent pAgent );
// ���� HP_HttpClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpClient( HP_HttpClient pClient );
// ���� HP_HttpSyncClient ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpSyncClient( HP_HttpSyncClient pClient );

// ���� HP_HttpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpServerListener __stdcall Create_HP_HttpServerListener( );
// ���� HP_HttpAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpAgentListener __stdcall Create_HP_HttpAgentListener( );
// ���� HP_HttpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
HP_HttpClientListener __stdcall Create_HP_HttpClientListener( );

// ���� HP_HttpServerListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpServerListener( HP_HttpServerListener pListener );
// ���� HP_HttpAgentListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpAgentListener( HP_HttpAgentListener pListener );
// ���� HP_HttpClientListener ����
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall Destroy_HP_HttpClientListener( HP_HttpClientListener pListener );

//**********************************************************************************/
//*************************** HTTP Server �ص��������÷��� **************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnMessageBegin( HP_HttpServerListener pListener, HP_FN_HttpServer_OnMessageBegin fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnRequestLine( HP_HttpServerListener pListener, HP_FN_HttpServer_OnRequestLine fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnHeader( HP_HttpServerListener pListener, HP_FN_HttpServer_OnHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnHeadersComplete( HP_HttpServerListener pListener, HP_FN_HttpServer_OnHeadersComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnBody( HP_HttpServerListener pListener, HP_FN_HttpServer_OnBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnChunkHeader( HP_HttpServerListener pListener, HP_FN_HttpServer_OnChunkHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnChunkComplete( HP_HttpServerListener pListener, HP_FN_HttpServer_OnChunkComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnMessageComplete( HP_HttpServerListener pListener, HP_FN_HttpServer_OnMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnUpgrade( HP_HttpServerListener pListener, HP_FN_HttpServer_OnUpgrade fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnParseError( HP_HttpServerListener pListener, HP_FN_HttpServer_OnParseError fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnWSMessageHeader( HP_HttpServerListener pListener, HP_FN_HttpServer_OnWSMessageHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnWSMessageBody( HP_HttpServerListener pListener, HP_FN_HttpServer_OnWSMessageBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnWSMessageComplete( HP_HttpServerListener pListener, HP_FN_HttpServer_OnWSMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnPrepareListen( HP_HttpServerListener pListener, HP_FN_HttpServer_OnPrepareListen fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnAccept( HP_HttpServerListener pListener, HP_FN_HttpServer_OnAccept fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnHandShake( HP_HttpServerListener pListener, HP_FN_HttpServer_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnReceive( HP_HttpServerListener pListener, HP_FN_HttpServer_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnSend( HP_HttpServerListener pListener, HP_FN_HttpServer_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnClose( HP_HttpServerListener pListener, HP_FN_HttpServer_OnClose fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpServer_OnShutdown( HP_HttpServerListener pListener, HP_FN_HttpServer_OnShutdown fn );

//**********************************************************************************/
//**************************** HTTP Agent �ص��������÷��� **************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnMessageBegin( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnMessageBegin fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnStatusLine( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnStatusLine fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnHeader( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnHeadersComplete( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnHeadersComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnBody( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnChunkHeader( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnChunkHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnChunkComplete( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnChunkComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnMessageComplete( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnUpgrade( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnUpgrade fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnParseError( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnParseError fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnWSMessageHeader( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnWSMessageHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnWSMessageBody( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnWSMessageBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnWSMessageComplete( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnWSMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnPrepareConnect( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnPrepareConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnConnect( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnHandShake( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnReceive( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnSend( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnClose( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnClose fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpAgent_OnShutdown( HP_HttpAgentListener pListener, HP_FN_HttpAgent_OnShutdown fn );

//**********************************************************************************/
//*************************** HTTP Client �ص��������÷��� **************************/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnMessageBegin( HP_HttpClientListener pListener, HP_FN_HttpClient_OnMessageBegin fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnStatusLine( HP_HttpClientListener pListener, HP_FN_HttpClient_OnStatusLine fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnHeader( HP_HttpClientListener pListener, HP_FN_HttpClient_OnHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnHeadersComplete( HP_HttpClientListener pListener, HP_FN_HttpClient_OnHeadersComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnBody( HP_HttpClientListener pListener, HP_FN_HttpClient_OnBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnChunkHeader( HP_HttpClientListener pListener, HP_FN_HttpClient_OnChunkHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnChunkComplete( HP_HttpClientListener pListener, HP_FN_HttpClient_OnChunkComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnMessageComplete( HP_HttpClientListener pListener, HP_FN_HttpClient_OnMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnUpgrade( HP_HttpClientListener pListener, HP_FN_HttpClient_OnUpgrade fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnParseError( HP_HttpClientListener pListener, HP_FN_HttpClient_OnParseError fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnWSMessageHeader( HP_HttpClientListener pListener, HP_FN_HttpClient_OnWSMessageHeader fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnWSMessageBody( HP_HttpClientListener pListener, HP_FN_HttpClient_OnWSMessageBody fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnWSMessageComplete( HP_HttpClientListener pListener, HP_FN_HttpClient_OnWSMessageComplete fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnPrepareConnect( HP_HttpClientListener pListener, HP_FN_HttpClient_OnPrepareConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnConnect( HP_HttpClientListener pListener, HP_FN_HttpClient_OnConnect fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnHandShake( HP_HttpClientListener pListener, HP_FN_HttpClient_OnHandShake fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnReceive( HP_HttpClientListener pListener, HP_FN_HttpClient_OnReceive fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnSend( HP_HttpClientListener pListener, HP_FN_HttpClient_OnSend fn );
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_Set_FN_HttpClient_OnClose( HP_HttpClientListener pListener, HP_FN_HttpClient_OnClose fn );

//**************************************************************************/
//***************************** Server �������� *****************************/

//*
/** ���ƣ��ظ�����
* ��������ͻ��˻ظ� HTTP ����
*        
* ������        dwConnID        -- ���� ID
*            usStatusCode    -- HTTP ״̬��
*            lpszDesc        -- HTTP ״̬����
*            lpHeaders        -- �ظ�����ͷ
*            iHeaderCount    -- �ظ�����ͷ����
*            pData            -- �ظ�������
*            iLength            -- �ظ������峤��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_SendResponse( HP_HttpServer pServer, HP_CONNID dwConnID, WORD usStatusCode, Char* lpszDesc, const TNVPair lpHeaders, int iHeaderCount, const void* pData, int iLength );

/*//*
* ���ƣ����ͱ����ļ�
* ��������ָ�����ӷ��� 4096 KB ���µ�С�ļ�
*        
* ������        dwConnID        -- ���� ID
*            lpszFileName    -- �ļ�·��
*            usStatusCode    -- HTTP ״̬��
*            lpszDesc        -- HTTP ״̬����
*            lpHeaders        -- �ظ�����ͷ
*            iHeaderCount    -- �ظ�����ͷ����
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_SendLocalFile( HP_HttpServer pServer, HP_CONNID dwConnID, Char* lpszFileName, WORD usStatusCode, Char* lpszDesc, const TNVPair lpHeaders, int iHeaderCount );
/*/*
* ���ƣ����� WebSocket ��Ϣ
* ��������Զ˶˷��� WebSocket ��Ϣ
*        
* ������        dwConnID        -- ���� ID
*            bFinal            -- �Ƿ����֡
*            iReserved        -- RSV1/RSV2/RSV3 �� 1 λ
*            iOperationCode    -- �����룺0x0 - 0xF
*            lpszMask        -- ���루nullptr �� 4 �ֽ����룬���Ϊ nullptr ��û�����룩
*            pData            -- ��Ϣ�����ݻ�����
*            iLength            -- ��Ϣ�����ݳ���
*            ullBodyLen        -- ��Ϣ�ܳ���
*                                 ullBodyLen = 0         -> ��Ϣ�ܳ���Ϊ iLength
*                                 ullBodyLen = iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen
*                                 ullBodyLen > iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen��������Ϣ�峤��Ϊ ullBOdyLen - iLength��������Ϣ��ͨ���ײ㷽�� Send() / SendPackets() ����
*                                 ullBodyLen < iLength -> �������������ʧ��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_SendWSMessage( HP_HttpServer pServer, HP_CONNID dwConnID, BOOL bFinal, Char* iReserved, Char* iOperationCode, const Char* lpszMask, Char* pData, int iLength, unsigned int ullBodyLen );

/*//*
* ���ƣ��ͷ�����
* �����������ӷ����ͷŶ��У��ȴ�ĳ��ʱ�䣨ͨ�� SetReleaseDelay() ���ã��ر�����
*        
* ������        dwConnID        -- ���� ID
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_Release( HP_HttpServer pServer, HP_CONNID dwConnID );

//******************************************************************************/
//***************************** Server ���Է��ʷ��� *****************************/

//* ���������ͷ���ʱ��Ĭ�ϣ�3000 ���룩 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpServer_SetReleaseDelay( HP_HttpServer pServer, WORD dwReleaseDelay );
//* ��ȡ�����ͷ���ʱ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpServer_GetReleaseDelay( HP_HttpServer pServer );
//* ��ȡ������ URL �����루URL ��ο���EnHttpUrlField�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpServer_GetUrlFieldSet( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡĳ�� URL ��ֵ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetUrlField( HP_HttpServer pServer, HP_CONNID dwConnID, En_HP_HttpUrlField enField );
//* ��ȡ���󷽷� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetMethod( HP_HttpServer pServer, HP_CONNID dwConnID );

//* ���ñ���Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpServer_SetLocalVersion( HP_HttpServer pServer, En_HP_HttpVersion usVersion );
//* ��ȡ����Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpVersion __stdcall HP_HttpServer_GetLocalVersion( HP_HttpServer pServer );

//* ����Ƿ�����Э�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_IsUpgrade( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ����Ƿ��� Keep-Alive ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_IsKeepAlive( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡЭ��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpServer_GetVersion( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetHost( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ���ݳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall HP_HttpServer_GetContentLength( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ�������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetContentType( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ���ݱ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetContentEncoding( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpServer_GetTransferEncoding( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡЭ���������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpUpgradeType __stdcall HP_HttpServer_GetUpgradeType( HP_HttpServer pServer, HP_CONNID dwConnID );
//* ��ȡ����������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpServer_GetParseErrorCode( HP_HttpServer pServer, HP_CONNID dwConnID, Char* lpszErrorDesc );

//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetHeader( HP_HttpServer pServer, HP_CONNID dwConnID, Char* lpszName, Char* lpszValue );
//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetHeaders( HP_HttpServer pServer, HP_CONNID dwConnID, Char* lpszName, const Char* const* lpszValue, int lpszValue_maxidx, void* pdwCount );
//* ��ȡ��������ͷ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetAllHeaders( HP_HttpServer pServer, HP_CONNID dwConnID, TNVPair lpHeaders, void* pdwCount );
//* ��ȡ��������ͷ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetAllHeaderNames( HP_HttpServer pServer, HP_CONNID dwConnID, const Char* const* lpszName, int lpszName_maxidx, void* pdwCount );

//* ��ȡ Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetCookie( HP_HttpServer pServer, HP_CONNID dwConnID, Char* lpszName, Char* lpszValue );
//* ��ȡ���� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetAllCookies( HP_HttpServer pServer, HP_CONNID dwConnID, TNVPair lpCookies, void* pdwCount );
//* ��ȡ��ǰ WebSocket ��Ϣ״̬������ nullptr �򲻻�ȡ��Ӧ�ֶ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpServer_GetWSMessageState( HP_HttpServer pServer, HP_CONNID dwConnID, BOOL lpbFinal, Char* lpiReserved, Char* lpiOperationCode, Char* lpszMask, unsigned int lpullBodyLen, unsigned int lpullBodyRemain );

//**************************************************************************/
//***************************** Agent �������� ******************************/

//*
/** ���ƣ���������
* �����������˷��� HTTP ����
*        
* ������        dwConnID        -- ���� ID
*            lpszMethod        -- ���󷽷�
*            lpszPath        -- ����·��
*            lpHeaders        -- ����ͷ
*            iHeaderCount    -- ����ͷ����
*            pBody            -- ������
*            iLength            -- �����峤��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendRequest( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszMethod, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pData, int iLength );

/*//*
* ���ƣ����ͱ����ļ�
* ��������ָ�����ӷ��� 4096 KB ���µ�С�ļ�
*        
* ������        dwConnID        -- ���� ID
*            lpszFileName    -- �ļ�·��
*            lpszMethod        -- ���󷽷�
*            lpszPath        -- ����·��
*            lpHeaders        -- ����ͷ
*            iHeaderCount    -- ����ͷ����
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendLocalFile( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszFileName, Char* lpszMethod, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );

//* ���� POST ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendPost( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� PUT ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendPut( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� PATCH ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendPatch( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� GET ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendGet( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� DELETE ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendDelete( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� HEAD ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendHead( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� TRACE ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendTrace( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� OPTIONS ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendOptions( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� CONNECT ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendConnect( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszHost, const TNVPair lpHeaders, int iHeaderCount );
/*/*
* ���ƣ����� WebSocket ��Ϣ
* ��������Զ˶˷��� WebSocket ��Ϣ
*        
* ������        dwConnID        -- ���� ID
*            bFinal            -- �Ƿ����֡
*            iReserved        -- RSV1/RSV2/RSV3 �� 1 λ
*            iOperationCode    -- �����룺0x0 - 0xF
*            lpszMask        -- ���루nullptr �� 4 �ֽ����룬���Ϊ nullptr ��û�����룩
*            pData            -- ��Ϣ�����ݻ�����
*            iLength            -- ��Ϣ�����ݳ���
*            ullBodyLen        -- ��Ϣ�ܳ���
*                                 ullBodyLen = 0         -> ��Ϣ�ܳ���Ϊ iLength
*                                 ullBodyLen = iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen
*                                 ullBodyLen > iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen��������Ϣ�峤��Ϊ ullBOdyLen - iLength��������Ϣ��ͨ���ײ㷽�� Send() / SendPackets() ����
*                                 ullBodyLen < iLength -> �������������ʧ��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_SendWSMessage( HP_HttpAgent pAgent, HP_CONNID dwConnID, BOOL bFinal, Char* iReserved, Char* iOperationCode, const unsignedchar lpszMask, Char* pData, int iLength, unsigned int ullBodyLen );

//******************************************************************************/
//***************************** Agent ���Է��ʷ��� ******************************/

//* ��ȡ HTTP ״̬�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpAgent_GetStatusCode( HP_HttpAgent pAgent, HP_CONNID dwConnID );

//* ���ñ���Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpAgent_SetLocalVersion( HP_HttpAgent pAgent, En_HP_HttpVersion usVersion );
//* ��ȡ����Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpVersion __stdcall HP_HttpAgent_GetLocalVersion( HP_HttpAgent pAgent );

//* ����Ƿ�����Э�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_IsUpgrade( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ����Ƿ��� Keep-Alive ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_IsKeepAlive( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡЭ��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpAgent_GetVersion( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡ���ݳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall HP_HttpAgent_GetContentLength( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡ�������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpAgent_GetContentType( HP_HttpAgent pAgent, HP_CONNID dwConnID );

//* ��ȡЭ���������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpUpgradeType __stdcall HP_HttpAgent_GetUpgradeType( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡ����������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpAgent_GetParseErrorCode( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszErrorDesc );
//* ��ȡ���ݱ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpAgent_GetContentEncoding( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpAgent_GetTransferEncoding( HP_HttpAgent pAgent, HP_CONNID dwConnID );
//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetHeader( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszName, Char* lpszValue );
//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetHeaders( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszName, const Char* const* lpszValue, int lpszValue_maxidx, void* pdwCount );
//* ��ȡ��������ͷ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetAllHeaders( HP_HttpAgent pAgent, HP_CONNID dwConnID, TNVPair lpHeaders, void* pdwCount );
//* ��ȡ��������ͷ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetAllHeaderNames( HP_HttpAgent pAgent, HP_CONNID dwConnID, const Char* const* lpszName, int lpszName_maxidx, void* pdwCount );

//* ��ȡ Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetCookie( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszName, Char* lpszValue );
//* ��ȡ���� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetAllCookies( HP_HttpAgent pAgent, HP_CONNID dwConnID, TNVPair lpCookies, void* pdwCount );
//* ��� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_AddCookie( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszName, Char* lpszValue, BOOL bRelpace );
//* ɾ�� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_DeleteCookie( HP_HttpAgent pAgent, HP_CONNID dwConnID, Char* lpszName );
//* ɾ������ Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_DeleteAllCookies( HP_HttpAgent pAgent, HP_CONNID dwConnID );
 //* ��ȡ��ǰ WebSocket ��Ϣ״̬������ nullptr �򲻻�ȡ��Ӧ�ֶ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpAgent_GetWSMessageState( HP_HttpAgent pAgent, HP_CONNID dwConnID, BOOL lpbFinal, Char* lpiReserved, Char* lpiOperationCode, Char* lpszMask, unsigned int lpullBodyLen, unsigned int lpullBodyRemain );


//**************************************************************************/
//***************************** Client �������� *****************************/

//*
/** ���ƣ���������
* �����������˷��� HTTP ����
*        
* ������        lpszMethod        -- ���󷽷�
*            lpszPath        -- ����·��
*            lpHeaders        -- ����ͷ
*            iHeaderCount    -- ����ͷ����
*            pBody            -- ������
*            iLength            -- �����峤��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendRequest( HP_HttpClient pClient, Char* lpszMethod, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );

/*//*
* ���ƣ����ͱ����ļ�
* ��������ָ�����ӷ��� 4096 KB ���µ�С�ļ�
*        
* ������        dwConnID        -- ���� ID
*            lpszFileName    -- �ļ�·��
*            lpszMethod        -- ���󷽷�
*            lpszPath        -- ����·��
*            lpHeaders        -- ����ͷ
*            iHeaderCount    -- ����ͷ����
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendLocalFile( HP_HttpClient pClient, Char* lpszFileName, Char* lpszMethod, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );

//* ���� POST ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendPost( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� PUT ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendPut( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� PATCH ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendPatch( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount, const void* pBody, int iLength );
//* ���� GET ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendGet( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� DELETE ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendDelete( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� HEAD ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendHead( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� TRACE ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendTrace( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� OPTIONS ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendOptions( HP_HttpClient pClient, Char* lpszPath, const TNVPair lpHeaders, int iHeaderCount );
//* ���� CONNECT ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendConnect( HP_HttpClient pClient, Char* lpszHost, const TNVPair lpHeaders, int iHeaderCount );
/*/*
* ���ƣ����� WebSocket ��Ϣ
* ��������Զ˶˷��� WebSocket ��Ϣ
*        
* ������        bFinal            -- �Ƿ����֡
*            iReserved        -- RSV1/RSV2/RSV3 �� 1 λ
*            iOperationCode    -- �����룺0x0 - 0xF
*            lpszMask        -- ���루nullptr �� 4 �ֽ����룬���Ϊ nullptr ��û�����룩
*            pData            -- ��Ϣ�����ݻ�����
*            iLength            -- ��Ϣ�����ݳ���
*            ullBodyLen        -- ��Ϣ�ܳ���
*                                 ullBodyLen = 0         -> ��Ϣ�ܳ���Ϊ iLength
*                                 ullBodyLen = iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen
*                                 ullBodyLen > iLength -> ��Ϣ�ܳ���Ϊ ullBodyLen��������Ϣ�峤��Ϊ ullBOdyLen - iLength��������Ϣ��ͨ���ײ㷽�� Send() / SendPackets() ����
*                                 ullBodyLen < iLength -> �������������ʧ��
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_SendWSMessage( HP_HttpClient pClient, BOOL bFinal, Char* iReserved, Char* iOperationCode, const unsignedchar lpszMask, Char* pData, int iLength, unsigned int ullBodyLen );

//******************************************************************************/
//***************************** Client ���Է��ʷ��� *****************************/

//* ��ȡ HTTP ״̬�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpClient_GetStatusCode( HP_HttpClient pClient );

//* ���ñ���Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpClient_SetLocalVersion( HP_HttpClient pClient, En_HP_HttpVersion usVersion );
//* ��ȡ����Э��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpVersion __stdcall HP_HttpClient_GetLocalVersion( HP_HttpClient pClient );

//* ����Ƿ�����Э�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_IsUpgrade( HP_HttpClient pClient );
//* ����Ƿ��� Keep-Alive ��ʶ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_IsKeepAlive( HP_HttpClient pClient );
//* ��ȡЭ��汾 */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpClient_GetVersion( HP_HttpClient pClient );
//* ��ȡ���ݳ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall HP_HttpClient_GetContentLength( HP_HttpClient pClient );
//* ��ȡ�������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpClient_GetContentType( HP_HttpClient pClient );
//* ��ȡ���ݱ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpClient_GetContentEncoding( HP_HttpClient pClient );
//* ��ȡ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_HttpClient_GetTransferEncoding( HP_HttpClient pClient );
//* ��ȡЭ���������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
En_HP_HttpUpgradeType __stdcall HP_HttpClient_GetUpgradeType( HP_HttpClient pClient );
//* ��ȡ����������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall HP_HttpClient_GetParseErrorCode( HP_HttpClient pClient, Char* lpszErrorDesc );

//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetHeader( HP_HttpClient pClient, Char* lpszName, Char* lpszValue );
//* ��ȡĳ������ͷ����ֵ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetHeaders( HP_HttpClient pClient, Char* lpszName, const Char* const* lpszValue, int lpszValue_maxidx, void* pdwCount );
//* ��ȡ��������ͷ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetAllHeaders( HP_HttpClient pClient, TNVPair lpHeaders, void* pdwCount );
//* ��ȡ��������ͷ���� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetAllHeaderNames( HP_HttpClient pClient, const Char* const* lpszName, int lpszName_maxidx, void* pdwCount );

//* ��ȡ Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetCookie( HP_HttpClient pClient, Char* lpszName, Char* lpszValue );
//* ��ȡ���� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetAllCookies( HP_HttpClient pClient, TNVPair lpCookies, void* pdwCount );
//* ��� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_AddCookie( HP_HttpClient pClient, Char* lpszName, Char* lpszValue, BOOL bRelpace );
//* ɾ�� Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_DeleteCookie( HP_HttpClient pClient, Char* lpszName );
//* ɾ������ Cookie */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_DeleteAllCookies( HP_HttpClient pClient );
//* ��ȡ��ǰ WebSocket ��Ϣ״̬������ nullptr �򲻻�ȡ��Ӧ�ֶ� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpClient_GetWSMessageState( HP_HttpClient pClient, BOOL lpbFinal, Char* lpiReserved, Char* lpiOperationCode, Char* lpszMask, unsigned int lpullBodyLen, unsigned int lpullBodyRemain );

/*/**************************************************************************/
/************************ HTTP Sync Client �������� ************************/
/*/*
* ���ƣ����� URL ����
* �����������˷��� HTTP URL ����
*        
* ������        lpszMethod        -- ���󷽷�
*            lpszUrl            -- ���� URL
*            lpHeaders        -- ����ͷ
*            iHeaderCount    -- ����ͷ����
*            pBody            -- ������
*            iLength            -- �����峤��
*            bForceReconnect    -- ǿ���������ӣ�Ĭ�ϣ�FALSE�������� URL �������Ͷ˿�����������һ��ʱ�������������ӣ�
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpSyncClient_OpenUrl( HP_HttpSyncClient pClient, Char* lpszMethod, Char* lpszUrl, const TNVPair lpHeaders, int iHeaderCount, const Char* pBody, int iLength, BOOL bForceReconnect );
/*/*
* ���ƣ����������
* �����������һ���������Ӧͷ����Ӧ��Ƚ����Ϣ���÷�������ÿ�η�������ǰ�Զ����ã�
*
* ������        
* ����ֵ��    TRUE            -- �ɹ�
*            FALSE            -- ʧ��
*/
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpSyncClient_CleanupRequestResult( HP_HttpSyncClient pClient );

/*/******************************************************************************/
/************************ HTTP Sync Client ���Է��ʷ��� ************************/

//* �������ӳ�ʱ�����룬0��ϵͳĬ�ϳ�ʱ��Ĭ�ϣ�5000�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpSyncClient_SetConnectTimeout( HP_HttpSyncClient pClient, unsigned int dwConnectTimeout );
//* ��������ʱ�����룬0�����޵ȴ���Ĭ�ϣ�10000�� */                                                     
extern "C" __declspec(dllimport) /*# HPSocketDLL */
void __stdcall HP_HttpSyncClient_SetRequestTimeout( HP_HttpSyncClient pClient, unsigned int dwRequestTimeout );

//* ��ȡ���ӳ�ʱ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall HP_HttpSyncClient_GetConnectTimeout( HP_HttpSyncClient pClient );
//* ��ȡ����ʱ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall HP_HttpSyncClient_GetRequestTimeout( HP_HttpSyncClient pClient );

//* ��ȡ��Ӧ�� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall HP_HttpSyncClient_GetResponseBody( HP_HttpSyncClient pClient, Char* lpszBod, void* piLength );

//*****************************************************************************************************************************************************/
//*************************************************************** Global Function Exports *************************************************************/
//*****************************************************************************************************************************************************/
// ��ȡ HPSocket �汾�ţ�4 ���ֽڷֱ�Ϊ�����汾�ţ��Ӱ汾�ţ������汾�ţ�������ţ�
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall HP_GetHPSocketVersion( );

//* ��ȡ���������ı� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
Char* __stdcall HP_GetSocketErrorDesc( En_HP_SocketError enCode );
//* ����ϵͳ�� GetLastError() ������ȡϵͳ������� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
WORD __stdcall SYS_GetLastError( );
// ����ϵͳ�� WSAGetLastError() ������ȡϵͳ�������
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_WSAGetLastError( );
// ����ϵͳ�� setsockopt()
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SetSocketOption( SOCKET sock, int level, int name, void* val, int len );
// ����ϵͳ�� getsockopt()
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_GetSocketOption( SOCKET sock, int level, int name, void* val, void* len );
// ����ϵͳ�� ioctlsocket()
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_IoctlSocket( SOCKET sock, int cmd, unsigned int arg );
// ����ϵͳ�� WSAIoctl()
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_WSAIoctl( SOCKET sock, WORD dwIoControlCode, void* lpvInBuffer, WORD cbInBuffer, void* lpvOutBuffer, WORD cbOutBuffer, LPDWORD lpcbBytesReturned );

// ���� socket ѡ�IPPROTO_TCP -> TCP_NODELAY
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_NoDelay( SOCKET sock, BOOL bNoDelay );
// ���� socket ѡ�SOL_SOCKET -> SO_DONTLINGER
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_DontLinger( SOCKET sock, BOOL bDont );
// ���� socket ѡ�SOL_SOCKET -> SO_LINGER
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_Linger( SOCKET sock, WORD l_onoff, WORD l_linger );
// ���� socket ѡ�SOL_SOCKET -> SO_RCVBUF
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_RecvBuffSize( SOCKET sock, int size );
// ���� socket ѡ�SOL_SOCKET -> SO_SNDBUF
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_SendBuffSize( SOCKET sock, int size );
// ���� socket ѡ�SOL_SOCKET -> SO_REUSEADDR
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_SSO_ReuseAddress( SOCKET sock, BOOL bReuse );

// ��ȡ SOCKET ���ص�ַ��Ϣ
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_GetSocketLocalAddress( SOCKET SOCKET, Char* lpszAddress, int& piAddressLen, WORD& pusPort );
// ��ȡ SOCKET Զ�̵�ַ��Ϣ
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_GetSocketRemoteAddress( SOCKET SOCKET, Char* lpszAddress, int& piAddressLen, WORD& pusPort );

//* ö������ IP ��ַ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_EnumHostIPAddresses( Char* lpszHost, En_HP_IPAddrType enType, HP_TIPAddr& lpppIPAddr, int& piIPAddrCount );
//* �ͷ� HP_LPTIPAddr* */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_FreeHostIPAddresses( HP_TIPAddr& lppIPAddr );

//* ����ַ����Ƿ���� IP ��ַ��ʽ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_IsIPAddress( Char* lpszAddress, En_HP_IPAddrType& penType );
//* ͨ����������ȡ IP ��ַ */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_GetIPAddress( Char* lpszHost, Char* lpszIP, int& piIPLenth, En_HP_IPAddrType& penType );


//* 64 λ�����ֽ���ת�����ֽ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_NToH64( unsigned int value );
//* 64 λ�����ֽ���ת�����ֽ��� */
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_HToN64( unsigned int value );

//===================================�����Ǳ��뺯��
// CP_XXX -> UNICODE
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_CodePageToUnicode( int iCodePage, const Char** szSrc, int szSrc_maxidx, const WideString* szDest, int szDest_maxidx, void* piDestLength );
// UNICODE -> CP_XXX
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_UnicodeToCodePage( int iCodePage, const WideString* szSrc, int szSrc_maxidx, const Char* const* szDest, int szDest_maxidx, void* piDestLength );
// GBK -> UNICODE
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_GbkToUnicode( const Char** szSrc, int szSrc_maxidx, const WideString* szDest, int szDest_maxidx, void* piDestLength );
// UNICODE -> GBK
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_UnicodeToGbk( const WideString* szSrc, int szSrc_maxidx, const Char* const* szDest, int szDest_maxidx, void* piDestLength );
// UTF8 -> UNICODE
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_Utf8ToUnicode( const Char** szSrc, int szSrc_maxidx, const WideString* szDest, int szDest_maxidx, void* piDestLength );
// UNICODE -> UTF8
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_UnicodeToUtf8( const WideString* szSrc, int szSrc_maxidx, const Char* const* szDest, int szDest_maxidx, void* piDestLength );
// GBK -> UTF8
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_GbkToUtf8( const Char** szSrc, int szSrc_maxidx, const WideString* szDest, int szDest_maxidx, void* piDestLength );
// UTF8 -> GBK
extern "C" __declspec(dllimport) /*# HPSocketDLL */
BOOL __stdcall SYS_Utf8ToGbk( const Char** szSrc, int szSrc_maxidx, const Char* const* szDest, int szDest_maxidx, void* piDestLength );

// ��ͨѹ��
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_Compress( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// �߼�ѹ����Ĭ��ֵ��iLevel -> -1��iMethod -> 8��iWindowBits -> 15��iMemLevel -> 8��iStrategy -> 0��
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_CompressEx( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen, int iLevel, int iMethod, int iWindowBits, int iMemLevel, int iStrategy );
// ��ͨ��ѹ
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_Uncompress( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// �߼���ѹ��Ĭ��ֵ��iWindowBits -> 15��
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_UncompressEx( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen, int iWindowBits );
// �Ʋ�ѹ���������
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GuessCompressBound( unsigned int dwSrcLen, BOOL bGZip );

// Gzip ѹ��
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_GZipCompress( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// Gzip ��ѹ
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_GZipUncompress( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// �Ʋ� Gzip ��ѹ������ȣ�������� 0 �򲻺���ֵ��˵���������ݲ�����Ч�� Gzip ��ʽ��
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GZipGuessUncompressBound( const Char* lpszSrc, unsigned int dwSrcLen );

// ���� Base64 ����󳤶�
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GuessBase64EncodeBound( unsigned int dwSrcLen );
// ���� Base64 ����󳤶�
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GuessBase64DecodeBound( const Char* lpszSrc, unsigned int dwSrcLen );
// Base64 ���루����ֵ��0 -> �ɹ���-3 -> �������ݲ���ȷ��-5 -> ������������㣩
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_Base64Encode( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// Base64 ���루����ֵ��0 -> �ɹ���-3 -> �������ݲ���ȷ��-5 -> ������������㣩
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_Base64Decode( const Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );

// ���� URL ����󳤶�
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GuessUrlEncodeBound( const Char* lpszSrc, unsigned int dwSrcLen );
// ���� URL ����󳤶�
extern "C" __declspec(dllimport) /*# HPSocketDLL */
unsigned int __stdcall SYS_GuessUrlDecodeBound( const Char* lpszSrc, unsigned int dwSrcLen );
// URL ���루����ֵ��0 -> �ɹ���-3 -> �������ݲ���ȷ��-5 -> ������������㣩
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_UrlEncode( Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );
// URL ���루����ֵ��0 -> �ɹ���-3 -> �������ݲ���ȷ��-5 -> ������������㣩
extern "C" __declspec(dllimport) /*# HPSocketDLL */
int __stdcall SYS_UrlDecode( Char* lpszSrc, unsigned int dwSrcLen, Char* lpszDest, unsigned int pdwDestLen );

#endif //  HPSocketSDKUnitH
