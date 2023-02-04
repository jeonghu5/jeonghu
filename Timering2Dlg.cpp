
// Timering2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Timering2.h"
#include "Timering2Dlg.h"
#include "afxdialogex.h"
#include "CRectJH.h"

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


// CTimering2Dlg 메시지 처리기

BOOL CTimering2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 50, NULL);
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

	for (int i = 0; i < 50; i++)//벽돌에 닿았을때
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

	if (holly == 1)//아이템 생성
	{
		
	    dc.SelectObject(&green);
	    dc.Ellipse(item);
	    item.OffsetRect(0, 5);
	}
    

	if (IntersectRect(&hi, &m_Player, &item))//아이템 먹었을때
	{
		item.SetRectEmpty();
		KillTimer(1);
		SetTimer(2, 35, NULL);
	}

	c = (m_Player.right + m_Player.left) / 2;
	d = (m_Ball.right + m_Ball.left) / 2;
	if (m_Ball.bottom==m_Player.top)//조작바에 닿았을때
	{
		if (m_Ball.right <= m_Player.right+7 && m_Ball.left >= m_Player.left-7)
		{
			if (c + 5 < d)//오른쪽으로
			{
				x = 10; y = -10;
			}
			else if (c - 5 > d)//왼쪽으로
			{
				x = -10; y = -10;
			}
			else//위쪽으로
			{
				x = 0; y = -10;
			}
		}
	}

	if (m_Ball.top ==0)//위쪽벽
	{
		y = 10;
	}
	if (m_Ball.left ==0)//왼쪽벽
	{
		x = -x;
	}
	if  (m_Ball.right ==500)//오른쪽 벽
	{
		x = -x;
	}
	if (m_Ball.bottom > 350)//게임오버
	{
		OnOK();
	}

	if (a == 1)//공 움직임 시작(스페이스바)
	{
		m_Ball.OffsetRect(x, y);
	}

    if (bi >= 2)//1라운드 성공
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
