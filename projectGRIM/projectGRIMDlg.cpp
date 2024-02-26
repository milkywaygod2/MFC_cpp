
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
	, m_iCircleHeight(10), m_iCircleWidth(10) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprojectGRIMDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_iNum);
	DDX_Text(pDX, IDC_EDIT_CHEIGHT, m_iCircleHeight);
	DDV_MinMaxInt(pDX, m_iCircleHeight, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT_CIRCLE_WIDTH, m_iCircleWidth);
	DDV_MinMaxInt(pDX, m_iCircleWidth, 1, INT_MAX);
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
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_ONOFF, &CprojectGRIMDlg::OnBnClickedButtonOnoff)
	ON_BN_CLICKED(IDC_BUTTON_DIALOG2, &CprojectGRIMDlg::OnBnClickedButtonDialog2)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_RANDOM_POINT, &CprojectGRIMDlg::OnBnClickedButtonLeftRandomPoint)
	ON_BN_CLICKED(IDC_BUTTON_PROCESS, &CprojectGRIMDlg::OnBnClickedButtonProcess)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN, &CprojectGRIMDlg::OnBnClickedButtonPattern)
	ON_BN_CLICKED(IDC_BUTTON_GETCENTER, &CprojectGRIMDlg::OnBnClickedButtonGetcenter)
	ON_EN_CHANGE(IDC_EDIT_CIRCLE_WIDTH, &CprojectGRIMDlg::OnEnChangeEditCircleWidth)
	ON_EN_CHANGE(IDC_EDIT_CHEIGHT, &CprojectGRIMDlg::OnEnChangeEditCheight)
	ON_BN_CLICKED(IDC_BUTTON_RAND_CIRCLE, &CprojectGRIMDlg::OnBnClickedButtonRandCircle)
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
	initButtons();
	MoveWindow(0, 0, 1280, 960);

	m_pDlgImage = new Cdlgimage;
	m_pDlgImage->Create(IDD_Cdlgimage, this);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);
	m_pDlgImage->ShowWindow(SW_SHOW);

	m_pDlgImageResult = new Cdlgimage;
	m_pDlgImageResult->Create(IDD_Cdlgimage, this);
	m_pDlgImageResult->MoveWindow(640, 0, 640, 480);
	m_pDlgImageResult->ShowWindow(SW_SHOW);

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
void CprojectGRIMDlg::initButtons() {
	CRect rectButton(0, 0, 100, 60);
	GetDlgItem(IDC_BUTTON_ONOFF)->GetWindowRect(&rectButton);
	//GetDlgItem(IDC_BUTTON_ONOFF)->GetClientRect(&rectButton);
	m_pBtnOnOff = new CBitmapButton;
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rectButton, this, IDC_BUTTON_ONOFF);
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF);
	m_pBtnOnOff->SizeToContent();
}

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
	drawCircle(pOimageBits, iStartX, iStartY, iRadius, 0xff);
	drawCircle(pOimageBits, ++iStartX, ++iStartY, iRadius, iColor_Gray);
	updateDC();
}
void CprojectGRIMDlg::OnBnClickedButtonImageMoveRect() {
	for(int i = 0; i < iWidth/2; i++) {
		moveRect();
		Sleep(0.5);
	}
}
bool CprojectGRIMDlg::isInCircle(int _i, int _j, int _centerX, int _centerY, int _radius) {
	double dDistX = _i - _centerX;
	double dDistY = _j - _centerY;
	double dDistPower = dDistX * dDistX + dDistY * dDistY;
	if(dDistPower < _radius * _radius) {
		return true;
	}
	return false;
}
void CprojectGRIMDlg::drawCircle(unsigned char* _imageBit, int _x, int _y, int _radius, int _color) {
	int iCenterX = _x + _radius;
	int iCenterY = _y + _radius;
	int iPitch = m_Oimage.GetPitch();
	unsigned char* pOimageBits = (unsigned char*)m_Oimage.GetBits();
	for(int j = _y; j < _y + _radius *2; j++) {
		for(int i = _x; i < _x + _radius * 2; i++) {
			if(isInCircle(i, j,iCenterX,iCenterY,_radius)) {
				pOimageBits[j * iPitch + i] = iColor_Gray+100;
			}
		}
	}
}
void CprojectGRIMDlg::callFunc(int _n) { 
	cout << _n << endl;
	int nData = _n;
}

BOOL CprojectGRIMDlg::OnEraseBkgnd(CDC* _pDC) {
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CPngImage imageBASE;
	imageBASE.Load(IDB_BASE, nullptr);
	
	CDC dc;
	dc.CreateCompatibleDC(_pDC);
	CBitmap* pOldBitmap = dc.SelectObject(&imageBASE);

	_pDC->BitBlt(0, 0, 640, 480, &dc, 0, 0, SRCCOPY);
	dc.SelectObject(pOldBitmap);
	return TRUE;

	return CDialogEx::OnEraseBkgnd(_pDC);
}
void CprojectGRIMDlg::OnDestroy() {
	CDialogEx::OnDestroy();
	if(m_pBtnOnOff) { delete m_pBtnOnOff; }
	if(m_pDlgImage) { delete m_pDlgImage; }
	if(m_pDlgImageResult) { delete m_pDlgImageResult; }
}
void CprojectGRIMDlg::OnBnClickedButtonOnoff() {
	static bool bOn = false;
	if(bOn) {
		m_pBtnOnOff->LoadBitmaps(IDB_ON);
	} else {
		m_pBtnOnOff->LoadBitmaps(IDB_OFF);
	}
	bOn = !bOn;
}
void CprojectGRIMDlg::OnBnClickedButtonDialog2() {
	/* Cdlgimage dlg; dlg.DoModal(); */
	m_pDlgImage->ShowWindow(SW_SHOW);
}
void CprojectGRIMDlg::OnBnClickedButtonLeftRandomPoint() {
	unsigned char* pDlgimage2Bits = (unsigned char*)m_pDlgImage->m_Oimage2.GetBits();
	int iWidth = m_pDlgImage->m_Oimage2.GetWidth();
	int iHeight = m_pDlgImage->m_Oimage2.GetHeight();
	int pitch = m_pDlgImage->m_Oimage2.GetPitch();
	
	memset(pDlgimage2Bits, 0, iWidth* iHeight);
	for(int k = 0; k < MAX_POINT; k++) {
		int ranX = rand() % iWidth;
		int ranY = rand() % iHeight;
		pDlgimage2Bits[ranY * pitch + ranX] = rand()%0xff;
	}
	
	int sumCount = 0; int idx = 0; int threshold = 100;
	for(int j = 0; j < iHeight; j++) {
		for(int i = 0; i < iWidth; i++) {
			if(pDlgimage2Bits[j*pitch+i] > threshold && idx <= MAX_POINT) {
				m_pDlgImageResult->m_Pdata[idx].x = i;
				m_pDlgImageResult->m_Pdata[idx].y = j;
				m_pDlgImageResult->m_iDataCount = ++idx;

				sumCount++;
				//cout << "(" << i << "," << j << ")" << endl;
			}
		}
	}
	cout << "total point count : " << sumCount << endl;
	//std::for_each(std::begin(m_pDlgImageResult->m_Pdata), std::end(m_pDlgImageResult->m_Pdata), {cout << "(" << CPoint.x << "," << CPoint.y << ")"});@?!

	m_pDlgImage->Invalidate();
	m_pDlgImageResult->Invalidate();
}
void CprojectGRIMDlg::OnBnClickedButtonProcess() {
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	auto chronoStart = chrono::system_clock::now();

	Cprocess Oprocess;
	int ret = Oprocess.getPointInfo(&m_pDlgImage->m_Oimage2);

	auto chronoEnd = chrono::system_clock::now();
	auto chronoMillisec = chrono::duration_cast<chrono::milliseconds>(chronoEnd - chronoStart);

	cout << ret << "\t" << chronoMillisec.count() << " ms" << endl;
}
void CprojectGRIMDlg::OnBnClickedButtonPattern() {
	unsigned char* pDlgimage2Bits = (unsigned char*)m_pDlgImage->m_Oimage2.GetBits();
	int iWidth = m_pDlgImage->m_Oimage2.GetWidth();
	int iHeight = m_pDlgImage->m_Oimage2.GetHeight();
	int pitch = m_pDlgImage->m_Oimage2.GetPitch();

	memset(pDlgimage2Bits, 0, iWidth * iHeight);
	CRect rect(100, 200, 150, 400);
	for(int j = rect.top; j < rect.bottom; j++) {
		for(int i = rect.left; i < rect.right; i++) {
			pDlgimage2Bits[j * pitch + i] = rand()%0xff;
		}
	}
	m_pDlgImage->Invalidate();
}
void CprojectGRIMDlg::OnBnClickedButtonGetcenter() {
	unsigned char* pDlgimage2Bits = (unsigned char*)m_pDlgImage->m_Oimage2.GetBits();
	int iWidth = m_pDlgImage->m_Oimage2.GetWidth();
	int iHeight = m_pDlgImage->m_Oimage2.GetHeight();
	int pitch = m_pDlgImage->m_Oimage2.GetPitch();
	
	int threshold = 0x80;
	CRect rect(0, 0, iWidth, iHeight);
	int sumX, sumY, count;
	sumX = sumY = count = 0;
	for(int j = rect.top; j < rect.bottom; j++) {
		for(int i = rect.left; i < rect.right; i++) {
			if(pDlgimage2Bits[j * pitch + i] > threshold){
				sumX += i;
				sumY += j;
				count++;
			}
		}
	}
		double centerX = (double)sumX / count;
		double centerY = (double)sumY / count;
		cout << "center Point(double, double) is... (" << centerX << ",  " << centerY << ")" << endl;
}



/*과제
* edit box, size설정시 랜덤하게 원이 (아마도 1개) 그려짐, 원의 무게중심 알려주고, 가운데는 십자마크, 외각에는 노랗게 원그리기
*/
void CprojectGRIMDlg::OnEnChangeEditCircleWidth() {

}
void CprojectGRIMDlg::OnEnChangeEditCheight() {

}
void CprojectGRIMDlg::OnBnClickedButtonRandCircle() {
	unsigned char* pDlgimage2Bits = (unsigned char*)m_pDlgImage->m_Oimage2.GetBits();
	int iWidth = m_pDlgImage->m_Oimage2.GetWidth();
	int iHeight = m_pDlgImage->m_Oimage2.GetHeight();
	int pitch = m_pDlgImage->m_Oimage2.GetPitch();
	UpdateData(true); //UpdateData(false);

	memset(pDlgimage2Bits, 0xff, iWidth * iHeight); //memset(pDlgimage2Bits, 0, iWidth * iHeight);

	int cirX = rand() % 640;
	int cirY = rand() % 480;
	//pDlgimage2Bits[cirY * pitch + cirX] = 0xff;
	m_pDlgImageResult->m_PcircleEXAM[0].x = cirX;
	m_pDlgImageResult->m_PcircleEXAM[0].y = cirY;
	m_pDlgImageResult->m_PcircleEXAM[1].x = m_iCircleWidth;
	m_pDlgImageResult->m_PcircleEXAM[1].y = m_iCircleHeight;

	cout << "(" << cirX << "," << cirY << ")" << endl << "과제목표 : edit box로 size설정시 랜덤하게 원 생성(아마도 1개), 원의 무게중심 알려주고, 가운데는 십자마크, 외각에는 노랗게 원그리기"<<endl<<endl;

	m_pDlgImage->Invalidate();
	m_pDlgImageResult->Invalidate();
}
