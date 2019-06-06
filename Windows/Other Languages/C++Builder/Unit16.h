//---------------------------------------------------------------------------

#ifndef Unit16H
#define Unit16H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "HPSocket4C.h"
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *btn1;
	TButton *btn2;
	TTimer *Timer1;
	TMemo *mmout;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btn1Click(TObject *Sender);
	void __fastcall btn2Click(TObject *Sender);
private:	// User declarations
//	 En_HP_HandleResult __stdcall OnPrepareListen(HP_Server pSender, SOCKET soListen);
//	 En_HP_HandleResult __stdcall OnAccept(HP_Server pSender, HP_CONNID dwConnID, SOCKET soClient);
//	 En_HP_HandleResult __stdcall OnSend(HP_Server pSender, HP_CONNID dwConnID, const BYTE* pData, int iLength);
//	 En_HP_HandleResult __stdcall OnReceive(HP_Server pSender, HP_CONNID dwConnID, int iLength);
//	 En_HP_HandleResult __stdcall OnClose(HP_Server pSender, HP_CONNID dwConnID, En_HP_SocketOperation enOperation, int iErrorCode);
//	 En_HP_HandleResult __stdcall OnShutdown(HP_Server pSender);
public:		// User declarations
	HP_TcpServer m_pServer;
	HP_TcpServerListener m_pListener;
	__fastcall TfrmMain(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
