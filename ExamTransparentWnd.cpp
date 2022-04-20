
// ExamTransparentWnd.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamTransparentWnd.h"
#include "ExamTransparentWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamTransparentWndApp

BEGIN_MESSAGE_MAP(CExamTransparentWndApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamTransparentWndApp 생성

CExamTransparentWndApp::CExamTransparentWndApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamTransparentWndApp 개체입니다.

CExamTransparentWndApp theApp;


// CExamTransparentWndApp 초기화

BOOL CExamTransparentWndApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamTransparentWndDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

