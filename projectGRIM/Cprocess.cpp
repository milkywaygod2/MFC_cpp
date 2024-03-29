﻿// Cprocess.cpp: 구현 파일
//

#include "pch.h"
#include "projectGRIM.h"
#include "Cprocess.h"


// Cprocess

Cprocess::Cprocess()
{
}

Cprocess::~Cprocess()
{
}

int Cprocess::getPointInfo(CImage* _pImage, int _iThreshold) {
	unsigned char* pImageBits = (unsigned char*)_pImage->GetBits();
	int width = _pImage->GetWidth();
	int height = _pImage->GetHeight();
	int pitch = _pImage->GetPitch();

	int sum = 0;
	for(int k = 0; k < width*height; k++) {
		if(pImageBits[k] > _iThreshold) {
			sum++;
		}
	}
	return sum;
}

int Cprocess::getPointInfo(CImage* _pImage, int _iThreshold, CRect _rect) {
	unsigned char* pImageBits = (unsigned char*)_pImage->GetBits();
	int width = _pImage->GetWidth();
	int height = _pImage->GetHeight();
	int pitch = _pImage->GetPitch();

	int sum = 0;
	for(int j = _rect.top; j < _rect.bottom; j++) {
		for(int i = _rect.left; i < _rect.right; i++) {
			if(pImageBits[j*pitch+i] > _iThreshold) {
				sum++;
			}
		}
	}
	return sum;
}


// Cprocess 멤버 함수
