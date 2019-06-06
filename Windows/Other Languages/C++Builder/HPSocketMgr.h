//---------------------------------------------------------------------------

#ifndef HPSocketMgrH
#define HPSocketMgrH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "HPSocket4C.h"
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
HP_TcpServer m_pServer;
HP_TcpServerListener m_pListener;

void CreateHP();
bool Start(String AIP,int Port);
void Stop();
#endif
