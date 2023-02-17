
// Timering2Dlg.h : 헤더 파일
//

#pragma once
#include "CRectJH.h"

// CTimering2Dlg 대화 상자
class CTimering2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CTimering2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CRectJH m_jhBreak[50];
	CRect m_Player;
	CRect m_Ball;
	CRect m_Break[50];
	CRect item;
	CRect m_Ball1;
	int second;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMERING2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int a;
//	int b;
	int c;
	int d;
	int e;
//	int f;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int bi;
	int j;
	int hello;
	int holly;
//	int speed;
//	int test;
	int x;
	int y;
	int round;
};
