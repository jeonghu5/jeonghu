#include "stdafx.h"
#include "CRectJH.h"


void CRectJH::set4Rect()
{
	rect = CRect(0, 0, 50, 30);
	CRect tmp = CRect(0, 0, 10, 10);
	CRect tmp22 = CRect(0, 0, 30, 10);
	way[6] = way[7] = way[0] = way[1] = way[2] = way[3] = tmp;
	way[4] = way[5] = tmp22;

	way[0].MoveToXY(rect.left, rect.top);
	way[1].MoveToXY(rect.right - way[1].Width(), rect.top);
	way[2].MoveToXY(rect.left, rect.bottom- way[2].Height());
	way[3].MoveToXY(rect.right - way[3].Width(), rect.bottom - way[3].Height());
	way[4].MoveToXY(rect.left+way[0].Width(),rect.top);
	way[5].MoveToXY(rect.left+way[2].Width(),rect.bottom-way[5].Height());
	way[6].MoveToXY(rect.left,rect.top+way[0].Height());
	way[7].MoveToXY(rect.right-way[7].Width(),top+way[1].Height());
}


int CRectJH::Check4Rect(CRect t)
{
	// TODO: 여기에 구현 코드 추가.
	CRect tmp;
	for (int i = 0; i < 8; i++)
	{
		if (tmp.IntersectRect(way[i], t)) {
			return i;
		}
	}

	return -1;
}
