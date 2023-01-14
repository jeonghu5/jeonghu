
// Timering2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Timering2.h"
#include "Timering2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CTimering2Dlg 대화 상자



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


// CTimering2Dlg 메시지 처리기

BOOL CTimering2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	x = 0;
	y = -10;
	srand((unsigned int)time(NULL));
	hello = rand()%10+40;
	m_Player = CRect(210, 300, 280, 310);
	m_Ball = CRect(240, 290, 250, 300);
	int v = 0;
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
	item = CRect(0, 0, 20, 20);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTimering2Dlg::OnPaint()
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
HCURSOR CTimering2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTimering2Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	SetTimer(1, 50, NULL);
}



void CTimering2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect hi;
	dc.Rectangle(0, 0, 500, 500);

	CBrush red;
	red.CreateSolidBrush(RGB(200, 0, 0));
	dc.SelectObject(&red); 
	dc.Ellipse(m_Ball);
	dc.Rectangle(m_Player);
	

	int j, zzz = 250;
	CBrush blue[5];
	for (j = 0; j<5; j++)
	{
		blue[j].CreateSolidBrush(RGB(0, 0, zzz));
		dc.SelectObject(&blue[j]);
		for (int i = 0; i < 10; i++)
		{
			dc.Rectangle(m_Break[10*j+i]);
		}
		zzz = zzz - 40;
	}

	if (a == 1)
	{
		m_Ball.OffsetRect(x, y);
	}
	
	for (int i = 0; i < 50; i++)
	{
		
	    if (IntersectRect(&hi, &m_Ball, &m_Break[i]))
	    {
			m_Break[i].DeflateRect(25, 0);
			if (hi.bottom == m_Break[i].bottom || hi.top == m_Break[i].top)
			{
				m_Ball.OffsetRect(-x, -y);
				y = -y;
				m_Ball.OffsetRect(x, y);

			}
			else
			{ 
				m_Ball.OffsetRect(-x,-y);
				x = -x;
				m_Ball.OffsetRect(x, y);
			}

			bi++;

			if (i == hello)
			{item.MoveToXY(m_Break[hello].CenterPoint().x, m_Break[hello].CenterPoint().y);
	    
				holly = 1;
			}
	    }
    }

	if (holly == 1)
	{
		CBrush green;
		green.CreateSolidBrush(RGB(0, 240, 0));
		dc.SelectObject(&green);
		dc.Ellipse(item);
		item.OffsetRect(0, 5);
	}
    
	if (IntersectRect(&hi, &m_Player, &item))
	{
		item.DeflateRect(10, 0);
		KillTimer(1);
		SetTimer(2, 35, NULL);
	}

	c = (m_Player.right + m_Player.left) / 2;
	d = (m_Ball.right + m_Ball.left) / 2;
	if (IntersectRect(&hi, &m_Ball, &m_Player))
	{
		if (c + 5 < d)//오른쪽으로
		{
			m_Ball.OffsetRect( -x, -y);
			x = 10;y = -10;
			m_Ball.OffsetRect(x, y);
		}
		else if (c-5 > d)//왼쪽으로
		{
			m_Ball.OffsetRect(-x , -y);
			x = -10;y = -10;
			m_Ball.OffsetRect(x, y);
		}
		else
		{
			m_Ball.OffsetRect(-x,-y);
			x = 0;y = -10;
			m_Ball.OffsetRect(x, y);
		}
	}

	

	if (m_Ball.top ==0)
	{
		y = 10;
	}
	if (m_Ball.left ==0)
	{
		x = -x;
	}
	if  (m_Ball.right ==500)
	{
		x = -x;
	}
	if (m_Ball.bottom > 350)
	{
		OnOK();
	}


    if (bi == 50)
	{
		OnOK();
	}

    
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CTimering2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	e = point.x - 35;
	m_Player.MoveToX(e);
	CDialogEx::OnMouseMove(nFlags, point);
}
