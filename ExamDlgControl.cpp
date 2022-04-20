
// ExamDlgControl.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamDlgControl.h"
#include "ExamDlgControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamDlgControlApp

BEGIN_MESSAGE_MAP(CExamDlgControlApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamDlgControlApp 생성

CExamDlgControlApp::CExamDlgControlApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamDlgControlApp 개체입니다.

CExamDlgControlApp theApp;


// CExamDlgControlApp 초기화

BOOL CExamDlgControlApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamDlgControlDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

