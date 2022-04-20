
// B2003Dlg.h: 헤더 파일
//

#pragma once


// CB2003Dlg 대화 상자
class CB2003Dlg : public CDialogEx
{
private:
	CImage m_image;
	CImage star_image;
	int m_cx_margin;
	int m_cy_margin;
	int m_zoom_level;
	int m_star_zoom_level;
	CRect m_rect;
	CBrush m_my_brush;
	CPoint m_prev_pos;
public:
	CB2003Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_B2003_DIALOG };
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
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
};
