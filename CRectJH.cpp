#include "stdafx.h"
#include "CRectJH.h"


void CRectJH::set4Rect()
{
	CRect tmp = CRect(0, 0, 10, 10);

	way[0] = way[1] = way[2] = way[3] = tmp;

	way[0].MoveToXY(rect.left, rect.top);
	way[1].MoveToXY(rect.right - way[1].Width(), rect.top);
	way[2].MoveToXY(rect.left, rect.bottom- way[2].Height());
	way[3].MoveToXY(rect.right - way[3].Width(), rect.bottom - way[3].Height());
}


int CRectJH::Check4Rect(CRect t)
{
	// TODO: 여기에 구현 코드 추가.
	CRect tmp;
	for (int i = 0; i < 4; i++)
	{
		if (tmp.IntersectRect(way[i], t)) {
			return i;
		}
	}

	return -1;
}
