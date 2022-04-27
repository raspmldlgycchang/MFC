
// MFCApplication4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4Dlg 대화 상자



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CMFCApplication4Dlg 메시지 처리기

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	m_rect.SetRect(10, 10, 100,100);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication4Dlg::OnPaint()
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
		dc.Rectangle(m_rect);
		/*CDialogEx::OnPaint()*/;
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication4Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	/* 사각형 영역에 있지 않은데도 계속 그릴 수 있는 조건을 제시한 건가?
	사각형 영역 내에 있을 때에만 하도록 PtInRect를 걸었다? -2번째 수정본
	*/
	if (m_rect.PtInRect(point)) {
		m_prev_pos = point;
		m_is_clicked = 1;
		SetCapture();
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication4Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_is_clicked = 0;
	ReleaseCapture();

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CMFCApplication4Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	/*
	if(m_ret.left<=point.x && m_rect.right>=point.x && m_rect.bottom>=point.y && m_rect.top<=point.y)
	*/
	if (m_is_clicked) {
		/* m_rect.PtInRect는 필요없다(사각형을 잡고 이동하니까?)? -3번째 수정본 */
		//if (m_rect.PtInRect(point)) {
		m_is_clicked = 1;
		CPoint move_pos = point - m_prev_pos;
		m_rect = m_rect + move_pos;
		/*
		m_rect.left += move_pos.x; m_rect.right += move_pos.x;
		m_rect.top += move_pos.y; m_rect.bottom+= move_pos.y;
		*/

		/* Mouse Down될 때 m_prev_pos를 갱신 후에
		mousemove메세지 발생동안 계속 m_prev_pos갱신이 필요하다 -1번째 수정본 */
		m_prev_pos = point;
		/* Invalidate(FALSE)가 아니라 Invalidate(TRUE);로 하니까
		계속 move하는동안 그려지는 것이 사라졌다-4번째 수정본 */
		Invalidate();

		//}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}