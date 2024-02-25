#pragma once

// Cprocess 명령 대상

class Cprocess : public CObject
{
public:
	Cprocess();
	virtual ~Cprocess();

private:

public:
	int getPointInfo(CImage* _pImage, int _iThreshold = 100);
};


