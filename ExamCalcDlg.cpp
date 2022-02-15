
// ExamCalcDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamCalc.h"
#include "ExamCalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamCalcDlg 대화 상자



CExamCalcDlg::CExamCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMCALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamCalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CExamCalcDlg::OnBnClickedOk)
	ON_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON9, OnSetNum)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CExamCalcDlg::OnBnClickedClearBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CExamCalcDlg::OnBnClickedBackBtn)
	ON_BN_CLICKED(IDC_OP_CALC_BTN, &CExamCalcDlg::OnBnClickedOpCalcBtn)
END_MESSAGE_MAP()


// CExamCalcDlg 메시지 처리기

BOOL CExamCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	m_font.CreatePointFont(96, L"굴림");
	GetDlgItem(IDC_SHOW_NUM_EDIT)->SetFont(&m_font);//포인터자료형 반환(GetDlgItem함수)

	SetDlgItemInt(IDC_SHOW_NUM_EDIT, 0);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExamCalcDlg::OnPaint()
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
HCURSOR CExamCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExamCalcDlg::OnBnClickedOk()
{
	
	//CDialogEx::OnOK();
}

void CExamCalcDlg::OnSetNum(UINT a_ctrl_id)
{
	int num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
	if (m_reset_mode == 0) {
		SetDlgItemInt(IDC_SHOW_NUM_EDIT, num * 10 + a_ctrl_id - IDC_BUTTON0);

	}

	else
	{
		m_reset_mode = 0;
		SetDlgItemInt(IDC_SHOW_NUM_EDIT, a_ctrl_id - IDC_BUTTON0);

	}
}

void CExamCalcDlg::OnProcNum(UINT a_ctrl_id)
{
	m_op_flags = a_ctrl_id - IDC_OP_ADD_BTN+1;
	m_reset_mode = 1;//연산자누름
	m_first_num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
}

void CExamCalcDlg::OnBnClickedClearBtn()
{
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, 0);
}


void CExamCalcDlg::OnBnClickedBackBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExamCalcDlg::OnBnClickedOpCalcBtn()
{
	int second_num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
	int result = 0;

	switch (m_op_flags) {
	case 1:
		result = m_num + second_num;
		break;
	case 2:
		result = m_num - second_num;
		break;
	case 3:
		result = m_num * second_num;
		break;
	case 4:
		if (second_num != 0) {
			result = m_num / second_num;
		}
		break;

	}
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, result);
	m_reset_mode = 1;
}
