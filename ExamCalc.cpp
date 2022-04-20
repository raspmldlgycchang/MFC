
// ExamCalc.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ExamCalc.h"
#include "ExamCalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamCalcApp

BEGIN_MESSAGE_MAP(CExamCalcApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamCalcApp 생성

CExamCalcApp::CExamCalcApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamCalcApp 개체입니다.

CExamCalcApp theApp;


// CExamCalcApp 초기화

BOOL CExamCalcApp::InitInstance()
{
	CWinApp::InitInstance();

	CExamCalcDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

