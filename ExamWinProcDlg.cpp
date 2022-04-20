
// ExamWinProcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamWinProc.h"
#include "ExamWinProcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamWinProcDlg 대화 상자



CExamWinProcDlg::CExamWinProcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMWINPROC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamWinProcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamWinProcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_EN_CHANGE(IDC_EDIT1, &CExamWinProcDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CExamWinProcDlg 메시지 처리기

BOOL CExamWinProcDlg::OnInitDialog()
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

void CExamWinProcDlg::OnPaint()
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
HCURSOR CExamWinProcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CExamWinProcDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_LBUTTONDOWN) {
		CClientDC dc(this);
		int x = lParam & 0x0000FFFF;
		int y = (lParam >> 16) & 0x0000FFFF;
		if (wParam & MK_CONTROL) {
			dc.Ellipse(x-30, y-30, x+30, y+30);
		}
		else
		{
			dc.Rectangle(x - 30, y - 30, x + 30, y + 30);

		}
	}
	//CDC* p_dc = GetDC();
	//p_dc->Rectangle(10, 10, 100, 100);
	//ReleaseDC(p_dc);
	
	return CDialogEx::WindowProc(message, wParam, lParam);
}


void CExamWinProcDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//point.x,point.y로 포인터배열이 CPoint클래스에 들어있다
	//따라서 비트연산자로 구별할 필요없이 클래스멤버변수로 가져오면 된다
	
	//WndProc를 오버라이딩하지 않고 마우스 왼쪽버튼 처리를 할 수 있다
	CClientDC dc(this);
	if (nFlags & MK_CONTROL) {
		dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30);
	}
	else
	{
		dc.Rectangle(point.x - 30, point.y - 30, point.x + 30, point.y + 30);

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CExamWinProcDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
