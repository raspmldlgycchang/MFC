﻿
// ExamTransparentWndDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamTransparentWnd.h"
#include "ExamTransparentWndDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamTransparentWndDlg 대화 상자



CExamTransparentWndDlg::CExamTransparentWndDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMTRANSPARENTWND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamTransparentWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamTransparentWndDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CExamTransparentWndDlg 메시지 처리기

BOOL CExamTransparentWndDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//투명도를 100으로 준다
	SetLayeredWindowAttributes(0,100,LWA_ALPHA);
	//SetLayeredWindowAttributes(RGB(255, 1, 7), 0, LWA_COLORKEY);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExamTransparentWndDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{

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
		dc.FillSolidRect(10,10,200,200,RGB(255, 1, 7));

		 
		//CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExamTransparentWndDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamTransparentWndDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	//현재좌표받아와서(중심좌표, 중심좌표기준으로 양쪽으로 너비,채울색깔)
	dc.FillSolidRect(point.x - 10, point.y-10, 20, 20, RGB(255, 1, 7));

	int wnd_style = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
	if (!(wnd_style & WS_EX_LAYERED)) {
		::SetWindowLong(m_hWnd, GWL_EXSTYLE, wnd_style | WS_EX_LAYERED);
	}

	SetLayeredWindowAttributes(RGB(255, 1, 7), 0, LWA_COLORKEY);
	CDialogEx::OnLButtonDown(nFlags, point);
}
