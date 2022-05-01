
// MFCApplication7Dlg.h: 헤더 파일
//

#pragma once

#define X_COUNT 19
#define Y_COUNT 19
#define INTERVAL 30
#define H_INTERVAL (INTERVAL/2)

// CMFCApplication7Dlg 대화 상자
class CMFCApplication7Dlg : public CDialogEx
{
private:
	CPen m_grid_pen;
	char m_step = 0;
	char m_dol[Y_COUNT][X_COUNT];
public:
	CMFCApplication7Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION7_DIALOG };
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
