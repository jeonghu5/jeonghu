#pragma once
#include <atltypes.h>
class CRectJH : public CRect
{
public:
	CRect rect;
	//CRect tl, tr, bl, br;
	CRect way[8]; // 0 :tl, 1:tr, 2:bl, 3:br, 4:tm, 5:bm, 6:ml, 7:mr 

	void set4Rect();
	int Check4Rect(CRect t);
	CRectJH & operator=(const CRect& rc) {
		this->rect = rc;
		return *this;
	}
};

