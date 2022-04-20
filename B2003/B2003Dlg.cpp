﻿
// B2003Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "B2003.h"
#include "B2003Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CB2003Dlg 대화 상자



CB2003Dlg::CB2003Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_B2003_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CB2003Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CB2003Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, &CB2003Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CB2003Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CB2003Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CB2003Dlg 메시지 처리기

BOOL CB2003Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	SetBackgroundColor(RGB(255, 255, 0));

	m_image.Load(L"temp.png");
	star_image.Load(L"star.png");
	m_zoom_level = 1;
	CRect win_rect, client_rect;
	GetWindowRect(win_rect);
	GetClientRect(client_rect);
	m_cx_margin = win_rect.Width() - client_rect.Width()+4;
	m_cy_margin = win_rect.Height() - client_rect.Height()+4;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin, SWP_NOMOVE);
	GetClientRect(m_rect);

	CBitmap apple_bmp;
	apple_bmp.LoadBitmap(IDB_BITMAP3);

	m_my_brush.CreatePatternBrush(&apple_bmp);

	apple_bmp.DeleteObject();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CB2003Dlg::OnPaint()
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
		m_image.Draw(dc, 2, 2, m_image.GetWidth()*m_zoom_level, m_image.GetHeight()*m_zoom_level);//4배확대
		if(m_prev_pos.x && m_prev_pos.y)
			star_image.Draw(dc, m_prev_pos.x, m_prev_pos.y, star_image.GetWidth()*m_star_zoom_level, star_image.GetHeight()*m_star_zoom_level);
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CB2003Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CB2003Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	m_rect.right = cx;
	m_rect.bottom = cy;

	Invalidate(FALSE);
}


void CB2003Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{

	CClientDC dc(this);
	CGdiObject *p_old_pen = dc.SelectStockObject(NULL_PEN);
	CBrush*p_old_brush = dc.SelectObject(&m_my_brush);
	dc.Ellipse(point.x - 100, point.y - 100, point.x + 100, point.y + 100);
	dc.SelectObject(p_old_brush);
	dc.SelectObject(p_old_pen);
	m_prev_pos = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CB2003Dlg::OnBnClickedButton2()
{
	m_zoom_level = 2;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin, SWP_NOMOVE);
	m_star_zoom_level = 1.2;
	Invalidate();
	
}


void CB2003Dlg::OnBnClickedButton4()
{
	m_zoom_level = 4;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin, SWP_NOMOVE);
	m_star_zoom_level = 2.5;
	Invalidate();
}


void CB2003Dlg::OnBnClickedButton8()
{
	m_zoom_level = 8;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin, SWP_NOMOVE);
	m_star_zoom_level = 4;
	Invalidate();
}
