﻿
// ExamSliderCtrl1Dlg.h: 헤더 파일
//

#pragma once


// CExamSliderCtrl1Dlg 대화 상자
class CExamSliderCtrl1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CExamSliderCtrl1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMSLIDERCTRL1_DIALOG };
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
	CSliderCtrl m_my_slider;
	afx_msg void OnNMReleasedcaptureMySlider(NMHDR* pNMHDR, LRESULT* pResult);
	CListBox m_event_list;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
