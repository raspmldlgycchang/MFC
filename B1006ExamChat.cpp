
// B1006ExamChat.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "B1006ExamChat.h"
#include "B1006ExamChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CB1006ExamChatApp

BEGIN_MESSAGE_MAP(CB1006ExamChatApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CB1006ExamChatApp 생성

CB1006ExamChatApp::CB1006ExamChatApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CB1006ExamChatApp 개체입니다.

CB1006ExamChatApp theApp;


// CB1006ExamChatApp 초기화

BOOL CB1006ExamChatApp::InitInstance()
{
	CWinApp::InitInstance();

	CB1006ExamChatDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

