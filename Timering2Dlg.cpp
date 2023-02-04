
// Timering2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Timering2.h"
#include "Timering2Dlg.h"
#include "afxdialogex.h"
#include "CRectJH.h"

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
	, c(0)
	, d(0)
	, e(0)
	, bi(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	j = 0;
	hello = 0;
	holly = 0;
	//  speed = 0;
	//  test = 0;
	x = 0;
	y = 0;
	round = 0;
}

void CTimering2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTimering2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CTimering2Dlg �޽��� ó����

BOOL CTimering2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 50, NULL);
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
	x = 0;
	y = -10;
	round = 1;
	srand((unsigned int)time(NULL));
	hello = rand()%10+40;
	m_Player = CRect(210, 300, 280, 310);
	m_Ball = CRect(240, 280, 250, 290);
	int v = 0;

	CRect tmp;

	for (int y = 0; y < 5; y++)
	{
		tmp = CRect(0, 0, 50, 30);
		tmp.MoveToXY(0, 50 * y);
		for (int x = 0; x < 10; x++)
		{
			m_Break[y * 10 + x] = tmp;
			m_jhBreak[y * 10 + x] = tmp;
			m_jhBreak[y * 10 + x].set4Rect();

			tmp.OffsetRect(50, 0);
		}
	}



	for (int i = 0; i <5; i++)
	{
		for(int k=0;k<10;k++)
		{ 
		m_Break[10*i+k] = CRect(j, v, j+50, v+30);
		j = j + 50;
		}
		v = v + 30;
		j = 0;
	}
	v = 0;
	for (int i = 0; i <5; i++)
	{
		for(int k=0;k<10;k++)
		{ 
		m_Break2[10*i+k] = CRect(j, v, j+50, v+30);
		j = j + 50;
		}
		v = v + 30;
		j = 0;
	}
	item = CRect(0, 0, 20, 20);
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

	CBrush red;
	red.CreateSolidBrush(RGB(200, 0, 0));
	
	CBrush white;
	white.CreateSolidBrush(RGB(255,255, 255));

    CBrush green;
	green.CreateSolidBrush(RGB(0, 240, 0));

	CBrush blue1;
	blue1.CreateSolidBrush(RGB(0, 0, 200));

	CBrush blue[5];
    int j, zzz = 250;

	if (round == 1)
	{
		for (j = 0; j < 5; j++)
		{
			blue[j].CreateSolidBrush(RGB(0, 0, zzz));
			dc.SelectObject(&blue[j]);
			for (int i = 0; i < 10; i++)
			{
				dc.Rectangle(m_Break[10 * j + i]);
			}
			zzz = zzz - 40;
		}
	}
	else if (round == 2)
	{
		dc.SelectObject(&blue1);
		for (int k=0;k<20;k++)
		{
			dc.Rectangle(m_Break[k]);
		}
	}

	for (int i = 0; i < 50; i++)//������ �������
	{
		if (x == 10 || x == -10)
		{
			if (m_Ball.top == m_Break[i].bottom || m_Ball.bottom == m_Break[i].top)
			{
				if (m_Ball.right <= m_Break[i].right && m_Ball.left >= m_Break[i].left)
				{
					if (i == hello)
					{
						item.right = m_Break[i].right; item.top = m_Break[i].top;
						item.left = m_Break[i].left; item.bottom = m_Break[i].bottom;
						holly = 1;
					}
					m_Break[i].SetRectEmpty();
					y = -y; bi++; 
				}
				else if (y == -10)
				{
					if (m_Ball.right == m_Break[i].left || m_Ball.left == m_Break[i].right)
					{
						if (i == hello)
						{
							item.right = m_Break[i].right; item.top = m_Break[i].top;
							item.left = m_Break[i].left; item.bottom = m_Break[i].bottom;
							holly = 1;
						}
						m_Break[i].SetRectEmpty();
						x = -x; y = -y; bi++;
					}
				}
			}
			else if (m_Ball.left == m_Break[i].right || m_Ball.right == m_Break[i].left)
			{
				if (m_Ball.bottom <= m_Break[i].bottom && m_Ball.top >= m_Break[i].top)
				{
					if (i == hello)
					{
						item.right = m_Break[i].right; item.top = m_Break[i].top;
						item.left = m_Break[i].left; item.bottom = m_Break[i].bottom;
						holly = 1;
					}
					m_Break[i].SetRectEmpty();
					x = -x; bi++;
				}
			} 
		}
		else if (x == 0)
		{
			if (m_Ball.top == m_Break[i].bottom || m_Ball.bottom == m_Break[i].top)
			{
				if (m_Ball.right <= m_Break[i].right && m_Ball.left >= m_Break[i].left)
				{
					if (i == hello)
					{
						item.right = m_Break[i].right; item.top = m_Break[i].top;
						item.left = m_Break[i].left; item.bottom = m_Break[i].bottom;
						holly = 1;
					}
					m_Break[i].SetRectEmpty();
					y = -y; bi++;
				}
			}
		}
	}

	if (holly == 1)//������ ����
	{
		
	    dc.SelectObject(&green);
	    dc.Ellipse(item);
	    item.OffsetRect(0, 5);
	}
    

	if (IntersectRect(&hi, &m_Player, &item))//������ �Ծ�����
	{
		item.SetRectEmpty();
		KillTimer(1);
		SetTimer(2, 35, NULL);
	}

	c = (m_Player.right + m_Player.left) / 2;
	d = (m_Ball.right + m_Ball.left) / 2;
	if (m_Ball.bottom==m_Player.top)//���۹ٿ� �������
	{
		if (m_Ball.right <= m_Player.right+7 && m_Ball.left >= m_Player.left-7)
		{
			if (c + 5 < d)//����������
			{
				x = 10; y = -10;
			}
			else if (c - 5 > d)//��������
			{
				x = -10; y = -10;
			}
			else//��������
			{
				x = 0; y = -10;
			}
		}
	}

	if (m_Ball.top ==0)//���ʺ�
	{
		y = 10;
	}
	if (m_Ball.left ==0)//���ʺ�
	{
		x = -x;
	}
	if  (m_Ball.right ==500)//������ ��
	{
		x = -x;
	}
	if (m_Ball.bottom > 350)//���ӿ���
	{
		OnOK();
	}

	if (a == 1)//�� ������ ����(�����̽���)
	{
		m_Ball.OffsetRect(x, y);
	}

    if (bi >= 2)//1���� ����
	{
		dc.SelectObject(&white);
		dc.Rectangle(0, 0, 500, 500);
		round = 2;
		for (int i = 0; i < 50; i++)
		{
			m_Break[i].SetRectEmpty();
		}
		m_Break[0] = CRect(100, 0, 150, 30);
		m_Break[1] = CRect(300, 0, 350, 30);
		m_Break[2] = CRect(50,30 ,100 ,60 );
		m_Break[3] = CRect(150,30 ,200 ,60 );
		m_Break[4] = CRect(250, 30, 300,60 );
		m_Break[5] = CRect(350, 30,400 ,60 );
		m_Break[6] = CRect(0, 60, 50,90 );
		m_Break[7] = CRect(200, 60,250 ,90 );
		m_Break[8] = CRect(400,60 ,450 , 90);
		m_Break[9] = CRect(0,90 , 50,120 );
		m_Break[10] = CRect(400,90 ,450 ,120 );
		m_Break[11] = CRect(0, 120,50 ,150 );
		m_Break[12] = CRect(400, 120,450 ,150 );
		m_Break[13] = CRect(50, 150,100 ,180 );
		m_Break[14] = CRect(350, 150,400 ,180 );
		m_Break[15] = CRect(100, 180,150 ,210 );
		m_Break[16] = CRect(300,180 ,350 ,210 );
		m_Break[17] = CRect(150,210 ,200 ,240 );
		m_Break[18] = CRect(250,210 , 300,240 );
		m_Break[19] = CRect(200, 240,250 ,270 );
		bi = -1000;
	}

    dc.SelectObject(&red); 	
	dc.Rectangle(m_Player);
    dc.Ellipse(m_Ball);
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
