
// MFCApplication6Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6Dlg 대화 상자



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent), m_grid_pen(PS_SOLID, 1, RGB(255, 0, 0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	/*ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()*/
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_LEFT_COLOR_BTN, &CMFCApplication6Dlg::OnBnClickedLeftColorBtn)
	ON_BN_CLICKED(IDC_RIGHT_COLOR_BTN, &CMFCApplication6Dlg::OnBnClickedRightColorBtn)
END_MESSAGE_MAP()


// CMFCApplication6Dlg 메시지 처리기

BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	CRect rect;
	GetClientRect(rect);
	m_image.Create(rect.Width(), rect.Height(), 32);
	m_image_dc.Attach(m_image.GetDC());

	m_left_color = RGB(255,255,255);

	GetDlgItem(IDC_LEFT_COLOR_BTN)->GetWindowRect(m_left_rect);
	m_left_rect.left -= 20;
	m_left_rect.right = m_left_rect.left + 5;
	m_left_rect.top -= 40;
	m_left_rect.bottom -=40;

	m_right_color = RGB(0,255,0);

	GetDlgItem(IDC_RIGHT_COLOR_BTN)->GetWindowRect(m_right_rect);
	m_right_rect.left -= 20;
	m_right_rect.right = m_right_rect.left + 5;
	m_right_rect.top -= 40;
	m_right_rect.bottom -= 40;
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication6Dlg::OnPaint()
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
		m_image_dc.SetBkMode(TRANSPARENT);
		m_image_dc.SelectStockObject(DC_BRUSH);
		CPen *p_old_pen = m_image_dc.SelectObject(&m_grid_pen);
		m_image_dc.SetDCBrushColor(m_left_color);
		m_image_dc.Rectangle(m_left_rect);
		m_image_dc.SetDCBrushColor(m_right_color);
		m_image_dc.Rectangle(m_right_rect);
			for (int y = 0; y < Y_COUNT; y++) {
				for (int x = 0; x < X_COUNT; x++) {
					m_image_dc.SetDCBrushColor(m_color_table[y][x]);
					m_image_dc.Rectangle(5 + x * INTERVAL, 5 + y * INTERVAL, 5 + INTERVAL + 1 + x * INTERVAL, 5 + INTERVAL + 1 + y * INTERVAL);
				}
			}
		m_image_dc.SelectObject(p_old_pen);
		m_image.Draw(dc, 0, 0);
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_grid_pen.DeleteObject();
	m_image_dc.Detach();
	m_image.ReleaseDC();

}


//void CMFCApplication6Dlg::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	m_is_clicked = 1;
//	int x = point.x / INTERVAL;
//	int y = point.y / INTERVAL;
//
//	m_color_table[y][x] = m_left_color;
//
//
//	CDialogEx::OnLButtonDown(nFlags, point);
//}
//
//
//void CMFCApplication6Dlg::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	m_is_clicked = 0;
//
//
//	CDialogEx::OnLButtonUp(nFlags, point);
//}
//
//
//void CMFCApplication6Dlg::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	m_is_clicked = 1;
//	int x = point.x / INTERVAL;
//	int y = point.y / INTERVAL;
//
//	m_color_table[y][x] = m_right_color;
//	CDialogEx::OnRButtonDown(nFlags, point);
//}
//
//
//void CMFCApplication6Dlg::OnRButtonUp(UINT nFlags, CPoint point)
//{
//	m_is_clicked = 0;
//	CDialogEx::OnRButtonUp(nFlags, point);
//}


void CMFCApplication6Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	//if (m_is_clicked) {
	if(nFlags&MK_LBUTTON || nFlags&MK_RBUTTON){
		int x = point.x / INTERVAL;
		int y = point.y / INTERVAL;
		if (x < X_COUNT && y < Y_COUNT) {
			CGdiObject *p_old_brush = dc.SelectStockObject(DC_BRUSH);
			CPen*p_old_pen = dc.SelectObject(&m_grid_pen);

			if (nFlags&MK_LBUTTON) {
				dc.SetDCBrushColor(m_left_color);
				m_color_table[y][x] = m_left_color;

			}
			if (nFlags&MK_RBUTTON) {
				dc.SetDCBrushColor(m_right_color);
				m_color_table[y][x] = m_right_color;
			}
			dc.Rectangle(5 + x * INTERVAL, 5 + y * INTERVAL, 5 + INTERVAL + 1 + x * INTERVAL, 5 + INTERVAL + 1 + y * INTERVAL);
			dc.SelectObject(p_old_pen);
			dc.SelectObject(p_old_brush);
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCApplication6Dlg::OnBnClickedLeftColorBtn()
{
	CColorDialog ins_dlg;
	ins_dlg.m_cc.Flags = ins_dlg.m_cc.Flags | CC_FULLOPEN | CC_RGBINIT;
	ins_dlg.m_cc.rgbResult = m_left_color;

	if (IDOK == ins_dlg.DoModal())
	{
		m_left_color = ins_dlg.GetColor();
		InvalidateRect(m_left_rect, FALSE);
	}
}

void CMFCApplication6Dlg::OnBnClickedRightColorBtn()
{
	CColorDialog ins_dlg;
	ins_dlg.m_cc.Flags = ins_dlg.m_cc.Flags | CC_FULLOPEN | CC_RGBINIT;
	ins_dlg.m_cc.rgbResult = m_right_color;

	if (IDOK == ins_dlg.DoModal())
	{
		m_right_color = ins_dlg.GetColor();
		InvalidateRect(m_right_rect, FALSE);
	}
}
