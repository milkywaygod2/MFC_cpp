
// projectGRIMDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "projectGRIM.h"
#include "projectGRIMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
class CAboutDlg : public CDialogEx {
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
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) { CDialogEx::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CprojectGRIMDlg 대화 상자
/*생성자*/CprojectGRIMDlg::CprojectGRIMDlg(CWnd* pParent /*=nullptr*/) 
	: CDialogEx(IDD_PROJECTGRIM_DIALOG, pParent), 
	m_iNum(100)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprojectGRIMDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_iNum);
}

BEGIN_MESSAGE_MAP(CprojectGRIMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CprojectGRIMDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CprojectGRIMDlg::OnEnChangeEditNum)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE, &CprojectGRIMDlg::OnBnClickedButtonImage)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE_SAVE, &CprojectGRIMDlg::OnBnClickedButtonImageSave)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE_LOAD, &CprojectGRIMDlg::OnBnClickedButtonImageLoad)
	ON_BN_CLICKED(IDC_BUTTON_IMAGE_MOVE_RECT, &CprojectGRIMDlg::OnBnClickedButtonImageMoveRect)
END_MESSAGE_MAP()

// CprojectGRIMDlg 메시지 처리기
BOOL CprojectGRIMDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CprojectGRIMDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는 프레임워크에서 이 작업을 자동으로 수행합니다.
void CprojectGRIMDlg::OnPaint() {
	if (IsIconic())	{
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
	else {
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서 이 함수를 호출합니다.
HCURSOR CprojectGRIMDlg::OnQueryDragIcon() { return static_cast<HCURSOR>(m_hIcon); }

//--- CUSTOM ---//
void CprojectGRIMDlg::OnBnClickedButton1() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("hellow window"));
	UpdateData(true);
	int iTest = 0;
	for(int i = 0; i < m_iNum; i++) {
		iTest += i+1;
		cout << " add : " << i+1 << ", accumulate : " << iTest << endl;
	}
	m_iNum = iTest;
	UpdateData(false);

}
void CprojectGRIMDlg::OnEnChangeEditNum() {
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은 CDialogEx::OnInitDialog() 함수를 재지정하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 
	// CRichEditCtrl().SetEventMask()를 호출하지 않으면 이 알림 메시지를 보내지 않습니다.

}

void CprojectGRIMDlg::OnBnClickedButtonImage() {
	if(m_Oimage != NULL) { m_Oimage.Destroy(); }
	m_Oimage.Create(iWidth, -iHeight, iBpp);
	if(iBpp == 8) {
		static RGBQUAD rgb[256];
		for(int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i; }
		m_Oimage.SetColorTable(0, 256, rgb);
	}
	int iPitch = m_Oimage.GetPitch();
	unsigned char* pOimageBits = (unsigned char*)m_Oimage.GetBits();

	memset(pOimageBits, 0xff, iWidth * iHeight);
	for(int j = 0; j < iHeight; j++) {
		for(int i = 0; i < iWidth; i++) {
			pOimageBits[j * iPitch + i] = (j/2) % iHeight;
		}
	}
	pOimageBits[iHeight / 2 * iPitch + iWidth/2] = 255;

	updateDC();
}

CString g_strFileImage = _T("C:\\Users\\user\\Downloads\\test.bmp");
void CprojectGRIMDlg::OnBnClickedButtonImageSave() {
	m_Oimage.Save(g_strFileImage);
}
void CprojectGRIMDlg::OnBnClickedButtonImageLoad() {
	if(m_Oimage != NULL) { m_Oimage.Destroy(); }
	m_Oimage.Load(g_strFileImage); 
	updateDC();
}

void CprojectGRIMDlg::moveRect() {
	static int iStartX = 0;
	static int iStartY = 0;
	int iPitch = m_Oimage.GetPitch();
	unsigned char* pOimageBits = (unsigned char*)m_Oimage.GetBits();
	m_Orect = CRect(0, 0, iWidth, iHeight);

	memset(pOimageBits, 0xff, iWidth * iHeight);
	for(int j = iStartY; j < iStartY + iHeight/10; j++) {
		for(int i = iStartX; i < iStartX + iWidth/10; i++) {
			if(validImagePos(i, j)) {
				pOimageBits[j * iPitch + i] = iColor_Gray;

			}
		}
	}
	iStartX++;
	iStartY++;
	updateDC();
}
void CprojectGRIMDlg::OnBnClickedButtonImageMoveRect() {
	for(int i = 0; i < 100; i++) {
		moveRect();
		Sleep(10);
	}
}
