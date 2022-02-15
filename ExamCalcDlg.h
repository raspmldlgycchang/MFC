
// ExamCalcDlg.h: 헤더 파일
//

#pragma once


// CExamCalcDlg 대화 상자
class CExamCalcDlg : public CDialogEx
{
private:
	CFont m_font;
	char m_op_flags = 0;
	char m_reset_mode = 1;
	char m_first_num;
public:
	CExamCalcDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMCALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void OnSetNum(UINT a_ctrl_id);
	void OnProcNum(UINT a_ctrl_id);
	afx_msg void OnBnClickedClearBtn();
	afx_msg void OnBnClickedBackBtn();
	afx_msg void OnBnClickedOpCalcBtn();
};
