
// ExamListCtrlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ExamListCtrl.h"
#include "ExamListCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamListCtrlDlg 대화 상자



CExamListCtrlDlg::CExamListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXAMLISTCTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_data_list);
}

BEGIN_MESSAGE_MAP(CExamListCtrlDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BTN, &CExamListCtrlDlg::OnBnClickedAddBtn)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_DATA_LIST, &CExamListCtrlDlg::OnLvnItemchangedDataList)
	ON_BN_CLICKED(IDC_MODIFY_BTN, &CExamListCtrlDlg::OnBnClickedModifyBtn)
END_MESSAGE_MAP()


// CExamListCtrlDlg 메시지 처리기

BOOL CExamListCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	LV_COLUMN add_column;

	add_column.mask = LVCF_TEXT | LVCF_WIDTH;//나머지headCtrl구조체요소는 사용안한다
	add_column.pszText = L"이름";
	add_column.cx = 80;
	m_data_list.InsertColumn(0, &add_column);//0번째에 입력한 구조체의 주소를 넘겨준다

	add_column.pszText = L"전화번호";
	add_column.cx = 100;//너비
	m_data_list.InsertColumn(1, &add_column);

	add_column.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;//나머지headCtrl구조체요소는 사용안한다
	add_column.pszText = L"주소";
	add_column.cx = 200;//너비
	add_column.fmt = LVCFMT_CENTER;
	m_data_list.InsertColumn(2, &add_column);

	//매번 입력하기 귀찮을 때 이 방법 사용
	m_data_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	SetDlgItemText(IDC_NAME_EDIT, L"홍길동");
	SetDlgItemText(IDC_PHONE_EDIT, L"010-1111-2222");
	SetDlgItemText(IDC_ADDRESS_EDIT, L"조선 한양");
	OnBnClickedAddBtn();//column을 추가한다

	SetDlgItemText(IDC_NAME_EDIT, L"김성엽");
	SetDlgItemText(IDC_PHONE_EDIT, L"010-3344-5567");
	SetDlgItemText(IDC_ADDRESS_EDIT, L"서울시 마포구");
	OnBnClickedAddBtn();

	SetDlgItemText(IDC_NAME_EDIT, L"이경직");
	SetDlgItemText(IDC_PHONE_EDIT, L"010-6677-7777");
	SetDlgItemText(IDC_ADDRESS_EDIT, L"인천시 부평구");
	OnBnClickedAddBtn();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExamListCtrlDlg::OnPaint()
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
HCURSOR CExamListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/*
void CExamListCtrlDlg::OnBnClickedAddBtn()
{
	CString str;
	GetDlgItemText(IDC_NAME_EDIT, str);

	int index = m_data_list.GetItemCount();
	LV_ITEM add_item;

	add_item.mask = LVIF_TEXT;
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iItem = 0;
	add_item.iSubItem = 0;

	m_data_list.InsertItem(&add_item);

	GetDlgItemText(IDC_PHONE_EDIT, str);
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iSubItem = 1;
	m_data_list.SetItem(&add_item);
}


void CExamListCtrlDlg::OnBnClickedAddBtn()
{
	CString str;
	GetDlgItemText(IDC_NAME_EDIT, str);

	int index = m_data_list.GetItemCount();
	LV_ITEM add_item;

	add_item.mask = LVIF_TEXT;
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iItem = index;

	GetDlgItemText(IDC_NAME_EDIT, str);
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iSubItem = 0;

	m_data_list.InsertItem(&add_item);

	GetDlgItemText(IDC_PHONE_EDIT, str);
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iSubItem = 1;
	m_data_list.SetItem(&add_item);
}
*/

void CExamListCtrlDlg::OnBnClickedAddBtn()
{
	int index = m_data_list.GetItemCount();
	CString str;
	GetDlgItemText(IDC_NAME_EDIT, str);
	LV_ITEM add_item;
	add_item.mask = LVIF_TEXT;
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iItem = index;
	add_item.iSubItem = 0;
	m_data_list.InsertItem(&add_item);

	GetDlgItemText(IDC_PHONE_EDIT, str);
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iSubItem = 1;
	m_data_list.SetItem(&add_item);

	GetDlgItemText(IDC_ADDRESS_EDIT, str);
	/*
	add_item.pszText = (wchar_t*)(const wchar_t*)str;
	add_item.iSubItem = 2;
	m_data_list.SetItem(&add_item);
	*/

	m_data_list.SetItemText(index, 2, str);
}

void CExamListCtrlDlg::OnLvnItemchangedDataList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW p = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	if (p->uNewState & LVIS_SELECTED) {//제대로 선택되었다(다른 인덱스인 것들이 막 선택될 때)
		CString str;
		str=m_data_list.GetItemText(p->iItem, p->iSubItem);//해당객체(headCtrl클래스)의 iItem과 iSubItem요소
		SetDlgItemText(IDC_NAME_EDIT, str);
		SetDlgItemText(IDC_PHONE_EDIT, m_data_list.GetItemText(p->iItem, p->iSubItem));
		SetDlgItemText(IDC_ADDRESS_EDIT, m_data_list.GetItemText(p->iItem, p->iSubItem));
	}
	*pResult = 0;
}


void CExamListCtrlDlg::OnBnClickedModifyBtn()
{
	POSITION pos = m_data_list.GetFirstSelectedItemPosition();
	if (pos != NULL) {
		int index;
		while (pos != NULL) {
			index = m_data_list.GetNextSelectedItem(pos);
			
		}
		CString str;
		GetDlgItemText(IDC_NAME_EDIT, str);
		m_data_list.SetItemText(index, 0, str);
		GetDlgItemText(IDC_PHONE_EDIT, str);
		m_data_list.SetItemText(index, 1, str);
		GetDlgItemText(IDC_ADDRESS_EDIT, str);
		m_data_list.SetItemText(index, 2, str);
	}
}
