
// Timering2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Timering2.h"
#include "Timering2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTimering2Dlg ��ȭ ����



CTimering2Dlg::CTimering2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TIMERING2_DIALOG, pParent)
	, a(0)
	, b(0)
	, c(0)
	, d(0)
	, e(0)
	, f(0)
	, bi(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimering2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTimering2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTimering2Dlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CTimering2Dlg �޽��� ó����

BOOL CTimering2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	b = -10;
	f = 0;
	m_Player = CRect(210, 300, 280, 310);
	m_Ball = CRect(240, 290, 250, 300);
	int j = 0;
	for (int i = 0; i <10; i++)
	{
		m_Break[i] = CRect(j, 0, j+50, 20);
		j = j + 50;
	}
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTimering2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTimering2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTimering2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTimering2Dlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetTimer(1, 50, NULL);
}


void CTimering2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRect hi;
	dc.Rectangle(0, 0, 500, 500);

	CBrush ba;
	ba.CreateSolidBrush(RGB(255, 0, 0));
	dc.SelectObject(&ba);
	dc.Ellipse(m_Ball);
	dc.Rectangle(m_Player);

	CBrush br;
	br.CreateSolidBrush(RGB(0, 0, 200));
	dc.SelectObject(&br);
	for (int i = 0; i < 10; i++)
	{
		dc.Rectangle(m_Break[i]);
	}

    if (a == 1)
	{
		m_Ball.OffsetRect(f, b);
	}
	  
	for (int i = 0; i < 10; i++)
	{
	    if (IntersectRect(&hi, &m_Ball, &m_Break[i]))
	    {
			m_Break[i].DeflateRect(25, 0);
			b = 10; 
			m_Ball.OffsetRect(f, b); m_Ball.OffsetRect( 0, b);
			bi++;
	    }
    }

	

	c = (m_Player.right + m_Player.left) / 2;
	d = (m_Ball.right + m_Ball.left) / 2;
	if (IntersectRect(&hi, &m_Ball, &m_Player))
	{
		b = -10;
		if (c+5 < d)
		{
			 f = 10;m_Ball.OffsetRect(f,b-10);
			 
		}
		else if (c-5 > d)
		{
			f = -10;m_Ball.OffsetRect(f,b-10);
		}
		else
		{
			m_Ball.OffsetRect(-f,b-10);
			f = 0;
		}
	}

	if (m_Ball.top ==0)
	{
		b = 10;
	}
	if (m_Ball.left ==0)
	{
		f = -f;
	}
	if (m_Ball.right ==500)
	{
		f = -f;
	}
	if (m_Ball.bottom > 350)
	{
		OnOK();
	}

    
    if (bi == 10)
	{
        CBrush old;
	    old.CreateSolidBrush(RGB(255, 255, 255));
		dc.SelectObject(&old);
		dc.Rectangle(0, 0, 600, 600);
	}

	CDialogEx::OnTimer(nIDEvent);
}


BOOL CTimering2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN)
	{
	    if (pMsg->wParam == VK_RIGHT)
		{
			m_Player.OffsetRect(10, 0);
		}
        if (pMsg->wParam == VK_LEFT)
		{
			m_Player.OffsetRect(-10, 0);
		}
		if (pMsg->wParam == VK_SPACE)
		{
			a = 1;
		}
		if (pMsg->wParam == VK_DELETE)
		{
			bi = 10;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTimering2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	e = point.x - 35;
	m_Player.MoveToX(e);
	CDialogEx::OnMouseMove(nFlags, point);
}
