
// ExamGroupMSG.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamGroupMSG.h"
#include "ExamGroupMSGDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamGroupMSGApp

BEGIN_MESSAGE_MAP(CExamGroupMSGApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamGroupMSGApp 생성

CExamGroupMSGApp::CExamGroupMSGApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamGroupMSGApp 개체입니다.

CExamGroupMSGApp theApp;


// CExamGroupMSGApp 초기화

BOOL CExamGroupMSGApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamGroupMSGDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

