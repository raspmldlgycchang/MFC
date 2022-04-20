
// ExamUpdateDataDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamUpdateData.h"
#include "ExamUpdateDataDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamUpdateDataDlg 대화 상자



CExamUpdateDataDlg::CExamUpdateDataDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMUPDATEDATA_DIALOG, pParent)
	, m_my_value(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamUpdateDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_my_value);
}

BEGIN_MESSAGE_MAP(CExamUpdateDataDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ_MSG_BTN, &CExamUpdateDataDlg::OnBnClickedReadMsgBtn)
	ON_BN_CLICKED(IDC_WRITE_MSG_BTN, &CExamUpdateDataDlg::OnBnClickedWriteMsgBtn)
END_MESSAGE_MAP()


// CExamUpdateDataDlg 메시지 처리기

BOOL CExamUpdateDataDlg::OnInitDialog()
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

void CExamUpdateDataDlg::OnPaint()
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
HCURSOR CExamUpdateDataDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamUpdateDataDlg::OnBnClickedReadMsgBtn()
{
	//UpdateData(TRUE);//컨트롤->제어변수(Edit control의 m_my_stirng)로 값을 가져온다

	//CString str, show_str;
	////특정컨트롤 값만 가져올 때 이 함수 좋다
	//GetDlgItemText(IDC_EDIT1, str);//가져올 아이템, 넣어줄 변수의 주소->클래스 멤버메서드에서 동적할당
	//str.Format(L"%d", m_my_value);
	//show_str = L"사용자가 입력한 문자열" + str;

	//int value = GetDlgItemInt(IDC_EDIT1);
	//str.Format(L"%d", value);
	//AfxMessageBox(str);
	  
	wchar_t str[4];//널문자용 1바이트
	CWnd* p = GetDlgItem(IDC_EDIT1);//Cwnd*자료형을 반환
	//int len = p->SendMessage(WM_GETTEXTLENGTH);
	int len = p->GetWindowTextLength();

	if (len > 3) {
		AfxMessageBox(L"너무길게 입력했습니다!");
	}
	else {
		GetDlgItemText(IDC_EDIT1, str, 4);
		AfxMessageBox(str);
	}
}


void CExamUpdateDataDlg::OnBnClickedWriteMsgBtn()
{
	SetDlgItemInt(IDC_EDIT1, 5);
}
