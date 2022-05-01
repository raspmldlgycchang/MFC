
// MFCApplication7Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication7.h"
#include "MFCApplication7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7Dlg 대화 상자

CMFCApplication7Dlg::CMFCApplication7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION7_DIALOG, pParent), m_grid_pen(PS_SOLID, 1, RGB(144,90,40))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	memset(m_dol, 0, sizeof(m_dol));
}

void CMFCApplication7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication7Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CMFCApplication7Dlg 메시지 처리기

BOOL CMFCApplication7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	SetBackgroundColor(RGB(244, 176, 77));


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication7Dlg::OnPaint()
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
		CGdiObject *p_old_brush = dc.SelectStockObject(NULL_BRUSH);

		CPen*p_old_pen = dc.SelectObject(&m_grid_pen);
		for (int y = 0; y < Y_COUNT; y++) {
			for (int x = 0; x < X_COUNT; x++) {
				dc.Rectangle(x*INTERVAL, y*INTERVAL, INTERVAL + 1 + x * INTERVAL, INTERVAL + 1 + y * INTERVAL);
		
			}
		}
		for (int y = 0; y < Y_COUNT; y++) {
			for (int x = 0; x < X_COUNT; x++) {
				if (m_dol[y][x] == 1) {
					dc.SelectStockObject(BLACK_BRUSH);
					dc.Ellipse(x*H_INTERVAL, y*H_INTERVAL, x*H_INTERVAL + INTERVAL, y*H_INTERVAL + INTERVAL);
					dc.SelectObject(p_old_brush);
					dc.SelectObject(p_old_pen);
				}
				else if (m_dol[y][x] == 2) {
					dc.SelectStockObject(WHITE_BRUSH);
					dc.Ellipse(x*H_INTERVAL , y*H_INTERVAL , x*H_INTERVAL + INTERVAL, y*H_INTERVAL + INTERVAL);
					dc.SelectObject(p_old_brush);
					dc.SelectObject(p_old_pen);
				}

			}
		}
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication7Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int x = point.x / H_INTERVAL;
	int y = point.y / H_INTERVAL;
	if (x < X_COUNT&& y < Y_COUNT) {
	//if(x<X_COUNT && y<Y_COUNT && m_dol[y][x]==0){

	CClientDC dc(this);
	CGdiObject*p_old_brush;
	CPen *p_old_pen = dc.SelectObject(&m_grid_pen);
		if (m_step == 0)	p_old_brush = dc.SelectStockObject(BLACK_BRUSH);
		else {
			p_old_brush = dc.SelectStockObject(WHITE_BRUSH);
		}
			dc.Ellipse(x*H_INTERVAL, y*H_INTERVAL, x*H_INTERVAL + INTERVAL, y*H_INTERVAL + INTERVAL);
		m_step = !m_step;
		m_dol[y][x] = m_step + 1;
		dc.SelectObject(p_old_brush);
		dc.SelectObject(p_old_pen);
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication7Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonUp(nFlags, point);
}
