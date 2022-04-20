
// ExamGroupMSGDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamGroupMSG.h"
#include "ExamGroupMSGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamGroupMSGDlg 대화 상자



CExamGroupMSGDlg::CExamGroupMSGDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMGROUPMSG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamGroupMSGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamGroupMSGDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON3, OnSetNumber)
END_MESSAGE_MAP()


// CExamGroupMSGDlg 메시지 처리기

BOOL CExamGroupMSGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExamGroupMSGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExamGroupMSGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}








LRESULT CExamGroupMSGDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	/*
	if (message == WM_COMMAND) {

		UINT ctrl_id = LOWORD(wParam);//눌린 버튼의 아이디를 가져온다
		if (ctrl_id == IDC_BUTTON1 || ctrl_id == IDC_BUTTON2 || ctrl_id == IDC_BUTTON3) {
			SetDlgItemInt(IDC_SHOW_NUM_EDIT, ctrl_id);
		}
		


		if (ctrl_id >= IDC_BUTTON1 && ctrl_id <= IDC_BUTTON3) {
			SetDlgItemInt(IDC_SHOW_NUM_EDIT, ctrl_id - IDC_BUTTON1 + 1);
		}
		
	}
	*/
	return CDialogEx::WindowProc(message, wParam, lParam);
}

//WM_COMMAND메세지 처리하는 함수
BOOL CExamGroupMSGDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	/*
	UINT ctrl_id = LOWORD(wParam);
	if (ctrl_id >= IDC_BUTTON1 && ctrl_id <= IDC_BUTTON3) {
		SetDlgItemInt(IDC_SHOW_NUM_EDIT, ctrl_id - IDC_BUTTON1 + 1);
	}
	*/
	return CDialogEx::OnCommand(wParam, lParam);
}

void CExamGroupMSGDlg::OnSetNumber(UINT a_ctrl_id)
{
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, a_ctrl_id - IDC_BUTTON1 + 1);
}
