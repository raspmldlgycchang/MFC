
// ExamUpdateData.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamUpdateData.h"
#include "ExamUpdateDataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamUpdateDataApp

BEGIN_MESSAGE_MAP(CExamUpdateDataApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamUpdateDataApp 생성

CExamUpdateDataApp::CExamUpdateDataApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamUpdateDataApp 개체입니다.

CExamUpdateDataApp theApp;


// CExamUpdateDataApp 초기화

BOOL CExamUpdateDataApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamUpdateDataDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

