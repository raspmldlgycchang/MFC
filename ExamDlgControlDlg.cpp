
// ExamDlgControlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamDlgControl.h"
#include "ExamDlgControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamDlgControlDlg 대화 상자



CExamDlgControlDlg::CExamDlgControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMDLGCONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamDlgControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamDlgControlDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_MSG_BTN, &CExamDlgControlDlg::OnBnClickedShowMsgBtn)
END_MESSAGE_MAP()


// CExamDlgControlDlg 메시지 처리기

BOOL CExamDlgControlDlg::OnInitDialog()
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

void CExamDlgControlDlg::OnPaint()
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
HCURSOR CExamDlgControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamDlgControlDlg::OnBnClickedShowMsgBtn()
{
	//wchar_t str[64];//128바이트, wide char형
	//대화상자 아이템의 박스에서 텍스트(Text)를 얻는다
	//GetDlgItemText(1001, str, 64);
	//GetDlgItemText(IDC_INPUT_MSG_EDIT, str, 64);와동일함
	//매개변수: 가져올 아이템 아이디혹은 아이디번호, 저장할 주소(배열은 배열명이 시작주소), 가져올 바이트수
	
	CString str, show_str;
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str);//str길이만큼 동적메모리할당을 한뒤 문자열복사를 하고 동적메모리해제까지 
	//CWnd클래스의 GetDlgItemText멤버메소드가 내부적으로 구현
	
	//show_str.Format(L"사용자가 입력한 문자열 : %s", str);//Cstring클래스에 정의된 멤버변수show_str에 지정
	
	//CString클래스에 덧셈 operator에 대한 오버로딩이 되어있어서 +로 printf가 가능하다
	show_str = L"사용자가 입력한 문자열 : " + str;
	//MFC가 제공하는 클래스 함수 사용
	AfxMessageBox(show_str);
}
