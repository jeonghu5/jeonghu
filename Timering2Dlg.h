
// Timering2Dlg.h : ��� ����
//

#pragma once


// CTimering2Dlg ��ȭ ����
class CTimering2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTimering2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CRect m_Player;
	CRect m_Ball;
	CRect m_Break[50];
	CRect item;
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMERING2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
	int b;
	int c;
	int d;
	int e;
	int f;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int bi;
	int j;
	int hello;
};
