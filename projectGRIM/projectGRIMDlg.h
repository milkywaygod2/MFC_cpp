
// projectGRIMDlg.h: 헤더 파일
//
#pragma once

// CprojectGRIMDlg 대화 상자
class CprojectGRIMDlg : public CDialogEx {
// 생성입니다.
public:
	CprojectGRIMDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTGRIM_DIALOG };
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

//--- CUSTOM ---//
private:
	CRect m_Orect;
	CImage m_Oimage;
	BOOL validImagePos(int _x, int _y) { return m_Orect.PtInRect( CPoint(_x, _y) ); }
	CBitmapButton* m_pBtnOnOff;
	void initButtons();

protected:

public:
	Cdlgimage* m_pDlgImage;
	Cdlgimage* m_pDlgImageResult;
	int m_iNum;
	int m_iCircleHeight;
	int m_iCircleWidth;

	int iWidth = 640;
	int iHeight = 480;
	int iBpp = 8;
	int iRadius = 10;

	int iColor_Gray = 80;


	int cirX = rand() % iWidth;
	int cirY = rand() % iHeight;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditNum();

	afx_msg void OnBnClickedButtonImage();
	afx_msg void OnBnClickedButtonImageSave();
	afx_msg void OnBnClickedButtonImageLoad();
	afx_msg void OnBnClickedButtonImageMoveRect();

	void updateDC(){
		CClientDC OclientDC(this);
		m_Oimage.Draw(OclientDC, 0, 0);
	}
	void moveRect();
	void drawCircle(unsigned char* _imageBit, int _i, int _j, int _radius, int _color);
	bool isInCircle(int _i, int _j, int _centerX, int _centerY, int _radius);
	void callFunc(int _n);
	int processImage(CRect _rect);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonOnoff();
	afx_msg void OnBnClickedButtonDialog2();
	afx_msg void OnBnClickedButtonLeftRandomPoint();
	afx_msg void OnBnClickedButtonProcess();
	afx_msg void OnBnClickedButtonPattern();
	afx_msg void OnBnClickedButtonGetcenter();

	afx_msg void OnEnChangeEditCircleWidth();
	afx_msg void OnEnChangeEditCheight();
	afx_msg void OnBnClickedButtonRandCircle();
	afx_msg void OnBnClickedButtonProcessthread();
};
