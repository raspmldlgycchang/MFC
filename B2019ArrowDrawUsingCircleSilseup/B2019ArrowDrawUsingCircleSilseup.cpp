
// MFCApplication2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Dlg 대화 상자



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CMFCApplication2Dlg 메시지 처리기

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	GetClientRect(m_rect);
	m_image.Create(m_rect.Width(), m_rect.Height(), 32, 0);
	m_image_dc.Attach(m_image.GetDC());

	m_green_pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_green_brush.CreateSolidBrush(RGB(0, 255, 0));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication2Dlg::OnPaint()
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
		m_image.Draw(dc, 0, 0);
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_green_pen.DeleteObject();
	m_green_brush.DeleteObject();
	m_image_dc.Detach();
	m_image.ReleaseDC();
}


void CMFCApplication2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_is_clicked = 1;
	m_start_pos = point;
	SetCapture();

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_is_clicked = 0;
	ReleaseCapture();

	CDialogEx::OnLButtonUp(nFlags, point);
}

#include<math.h>
#define PI	3.141592
void CMFCApplication2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	double radian;
	CPoint pos_list[3];
	CBrush*p_old_brush = m_image_dc.GetCurrentBrush();
	CPen*p_old_pen=NULL;
	if (m_is_clicked) {
		/* m_is_clicked=0;코드를 없앴다 -4번째 수정본 */
		/* m_is_clicked=0으로 초기화를 시켰기에 밖에서
		pos_list[0]을 지정하면 아무 좌표나 pos_list[0]에 들어와서
		start_pos를 내가 클릭하는 위치를 잡지 못한다 -3번째 수정본 */
		pos_list[0] = point;

		/* m_rect영역에 색을 채운다 -1번째 수정본 */
		m_image_dc.FillSolidRect(m_rect, RGB(0, 0, 0));
		m_image_dc.SelectObject(&m_green_brush);
		p_old_pen = m_image_dc.SelectObject(&m_green_pen);
		m_image_dc.MoveTo(m_start_pos);
		m_image_dc.LineTo(point);
		radian = atan2(m_start_pos.y - point.y, point.x - m_start_pos.x);
		/* point.x, point.y만큼 이동시켜야 한다 -2번쨰 수정본*/
		/* 화살표 그리는 Polygon이 찌그러져서 좌표가 제대로 나오지 않는다
		소수점으로 계산되도록 분모, 분자 모두 소수점으로 해준다 -5번째 수정본 */
		pos_list[1].x = (int)(cos(radian + PI * 5.0 / 6.0)*50)+point.x;
		pos_list[1].y = (int)(-sin(radian + PI * 5.0 / 6.0)*50)+point.y;
		pos_list[2].x = (int)(cos(radian + PI * 7.0 / 6.0)*50)+point.x;
		pos_list[2].y = (int)(-sin(radian + 7.0 / 6.0 * PI)*50)+point.y;
		m_image_dc.Polygon(pos_list, 3);

	}
	m_image_dc.SelectObject(p_old_pen);
	m_image_dc.SelectObject(p_old_brush);
	Invalidate(FALSE);
	CDialogEx::OnMouseMove(nFlags, point);
}
