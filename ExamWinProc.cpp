
// ExamWinProc.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamWinProc.h"
#include "ExamWinProcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamWinProcApp

BEGIN_MESSAGE_MAP(CExamWinProcApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamWinProcApp 생성

CExamWinProcApp::CExamWinProcApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamWinProcApp 개체입니다.

CExamWinProcApp theApp;


// CExamWinProcApp 초기화

BOOL CExamWinProcApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamWinProcDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

