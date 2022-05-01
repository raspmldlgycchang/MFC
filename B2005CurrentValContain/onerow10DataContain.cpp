
// MFCApplication8Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication8Dlg 대화 상자



CMFCApplication8Dlg::CMFCApplication8Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication8Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMFCApplication8Dlg 메시지 처리기

BOOL CMFCApplication8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	srand((unsigned int)time(NULL));
	SetTimer(1, 500, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication8Dlg::OnPaint()
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
		CRect r;
		CString str;
		POSITION pos = m_data_list.GetHeadPosition();

		dc.SelectStockObject(DC_BRUSH);
		dc.SetDCBrushColor(RGB(0, 0, 128));
		dc.SetBkColor(RGB(0, 0, 128));
		dc.SetTextColor(RGB(0, 255, 255));
		for (int i = 0; pos != NULL; i++) {
			/* 주소값이 아니라 주소에 저장된 값을 출력해준다-두 번째 수정본 */
			str.Format(L"%d", *(int*)m_data_list.GetNext(pos));
			r.SetRect(10 + i * 65, 10, 70 + i * 65, 40);
			dc.Rectangle(r);
			dc.DrawText(str,r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication8Dlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1) {
		int temp = rand() % 100;
		int*p = new int;
		*p = temp;
		m_data_list.AddTail(p);

		if (m_data_list.GetCount() > 10) {
			delete (int*)m_data_list.GetHead();
			m_data_list.RemoveHead();
		}
		/* SetTimer로 m_data_list에 노드 넣고나서
		m_data_list를 출력하는 OnPaint함수 다시 발생
		시켜야 한다-첫번째 수정본 */
		Invalidate(FALSE);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCApplication8Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	KillTimer(1);

	POSITION pos = m_data_list.GetHeadPosition();
	while (pos != NULL) {
		delete (int*)m_data_list.GetNext(pos);
	}
}
