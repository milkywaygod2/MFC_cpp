// Cdlgimage.cpp: 구현 파일
//

#include "pch.h"
#include "projectGRIM.h"
#include "afxdialogex.h"
#include "Cdlgimage.h"


// Cdlgimage 대화 상자

IMPLEMENT_DYNAMIC(Cdlgimage, CDialogEx)
Cdlgimage::Cdlgimage(CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_Cdlgimage, pParent) { m_pParent = pParent; }
Cdlgimage::~Cdlgimage(){}

void Cdlgimage::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cdlgimage, CDialogEx)
	ON_BN_CLICKED(IDC_OTHERDLG_PUSH, &Cdlgimage::OnBnClickedOtherdlgPush)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Cdlgimage 메시지 처리기


//--- CUSTOM ---//
void Cdlgimage::OnBnClickedOtherdlgPush() {
	static int n = 100;
	CprojectGRIMDlg* pParentDlg = (CprojectGRIMDlg*)m_pParent;
	pParentDlg->callFunc(n++);
}
BOOL Cdlgimage::OnInitDialog() {
	CDialogEx::OnInitDialog();
	MoveWindow(0, 0, 640, 480);
	initImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void Cdlgimage::OnPaint() {
	CPaintDC dc(this); // device context for painting
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if(m_Oimage2) { m_Oimage2.Draw(dc, 0, 0); }
	drawData(&dc);
	drawExam(&dc);
	
}
void Cdlgimage::drawData(CDC* _pDC) {
	CPen curPen;
	curPen.CreatePen(PS_SOLID, 1, COLOR_RED);
	CPen* pOldPen = _pDC->SelectObject(&curPen);

	CRect guideRect(0, 0, 640, 480);
	for(int i = 0; i < m_iDataCount; i++) {
		guideRect.SetRect(m_Pdata[i], m_Pdata[i]);
		guideRect.InflateRect(5, 5);
		_pDC->Ellipse(guideRect);
	}
	_pDC->SelectObject(pOldPen);
}
void Cdlgimage::drawExam(CDC* _pDC) {
	CPen redPen, ylwPen;
	ylwPen.CreatePen(PS_SOLID, 1, COLOR_YELLOW);
	redPen.CreatePen(PS_SOLID, 1, COLOR_RED);
	
	CPen* pOldPen = _pDC->SelectObject(&ylwPen);
	CRect guideRect(0, 0, 640, 480);
	guideRect.SetRect(m_PcircleEXAM[0], m_PcircleEXAM[0]);
	guideRect.InflateRect(m_PcircleEXAM[1].x, m_PcircleEXAM[1].y);
	_pDC->Ellipse(guideRect);
	_pDC->SelectObject(pOldPen);

	_pDC->SelectObject(&redPen);
	CRect crossRectH(0, 0, 640, 480);
	CRect crossRectV(0, 0, 640, 480);
	crossRectH.SetRect(m_PcircleEXAM[0], m_PcircleEXAM[0]);
	crossRectV.SetRect(m_PcircleEXAM[0], m_PcircleEXAM[0]);
	crossRectH.InflateRect(m_PcircleEXAM[1].x, 1);
	crossRectV.InflateRect(1, m_PcircleEXAM[1].y);
	_pDC->Rectangle(crossRectH);
	_pDC->Rectangle(crossRectV);
	_pDC->SelectObject(pOldPen);
	
}
void Cdlgimage::initImage() {
	int width = 4096*4;
	int height = 4096*4;
	int bpp = 8;
	m_Oimage2.Create(width, -height, bpp);
	if(bpp == 8) {
		static RGBQUAD rgb[256];
		for(int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_Oimage2.SetColorTable(0, 256, rgb);
	}
	int pitch = m_Oimage2.GetPitch();
	unsigned char* pOimage2Bits = (unsigned char*)m_Oimage2.GetBits();
	memset(pOimage2Bits, 0xff, width * height);
}
