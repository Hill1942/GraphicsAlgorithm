
int Clip_Line(int &x1, int &y1, int &x2, int &y2)
{
#define CLIP_CODE_C  0x0000
#define CLIP_CODE_N  0x0008
#define CLIP_CODE_S  0x0004
#define CLIP_CODE_E  0x0002
#define CLIP_CODE_W  0x0001
					 
#define CLIP_CODE_NE 0x000a
#define CLIP_CODE_SE 0x0006
#define CLIP_CODE_NW 0x0009
#define CLIP_CODE_SW 0x0005

	int xc1 = x1;
	int yc1 = y1;
	int xc2 = x2;
	int yc2 = y2;

	int directCode1 = 0;
	int directCode2 = 0;

	if (y1 < minClipY)
		directCode1 |= CLIP_CODE_N;
	else if (y1 > maxClipY)
		directCode1 |= CLIP_CODE_S;

	if (x1 < minClipX)
		directCode1 |= CLIP_CODE_W;
	else if (x1 > maxClipX)
		directCode1 |= CLIP_CODE_E;

	if (y2 < minClipY)
		directCode2 |= CLIP_CODE_N;
	else if (y2 > maxClipY)
		directCode2 |= CLIP_CODE_S;

	if (x2 < minClipX)
		directCode2 |= CLIP_CODE_W;
	else if (x2 > maxClipX)
		directCode2 |= CLIP_CODE_E;

	//totally out
	if ((directCode1 & directCode2))
		return 0;

	//totoally in
	if (directCode1 == 0 && directCode2 == 0)
		return 1;

	switch (directCode1)
	{
	case CLIP_CODE_C:
		break;

	case CLIP_CODE_N:
		xc1 = 0.5 + x1 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = minClipY;
		break;

	case CLIP_CODE_S:
		xc1 = 0.5 + x1 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = maxClipY;
		break;

	case CLIP_CODE_W:
		xc1 = minClipX;
		yc1 = 0.5 + y1 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		break;

	case CLIP_CODE_E:
		xc1 = maxClipX;
		yc1 = 0.5 + y1 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		break;

	case CLIP_CODE_NE:
		xc1 = 0.5 + x1 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = minClipY;
		if (xc1 < minClipX || xc1 > maxClipX)
		{
			xc1 = maxClipX;
			yc1 = 0.5 + y1 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	case CLIP_CODE_SE:
		xc1 = 0.5 + x1 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = maxClipY;
		if (xc1 < minClipX || xc1 > maxClipX)
		{
			xc1 = maxClipX;
			yc1 = 0.5 + y1 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	case CLIP_CODE_NW:
		xc1 = 0.5 + x1 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = minClipY;
		if (xc1 < minClipX || xc1 > maxClipX)
		{
			xc1 = minClipX;
			yc1 = 0.5 + y1 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		}

	case CLIP_CODE_SW:
		xc1 = 0.5 + x1 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc1 = maxClipY;
		if (xc1 < minClipX || xc1 > maxClipX)
		{
			xc1 = minClipX;
			yc1 = 0.5 + y1 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	default:
		break;
	}

	switch (directCode2)
	{
	case CLIP_CODE_C:
		break;

	case CLIP_CODE_N:
		xc2 = 0.5 + x2 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = minClipY;
		break;

	case CLIP_CODE_S:
		xc2 = 0.5 + x2 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = maxClipY;
		break;

	case CLIP_CODE_W:
		xc2 = minClipX;
		yc2 = 0.5 + y2 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		break;

	case CLIP_CODE_E:
		xc2 = maxClipX;
		yc2 = 0.5 + y2 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		break;

	case CLIP_CODE_NE:
		xc2 = 0.5 + x2 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = minClipY;
		if (xc2 < minClipX || xc2 > maxClipX)
		{
			xc2 = maxClipX;
			yc2 = 0.5 + y2 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	case CLIP_CODE_SE:
		xc2 = 0.5 + x2 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = maxClipY;
		if (xc2 < minClipX || xc2 > maxClipX)
		{
			xc2 = maxClipX;
			yc2 = 0.5 + y2 + (maxClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	case CLIP_CODE_NW:
		xc2 = 0.5 + x2 + (minClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = minClipY;
		if (xc2 < minClipX || xc2 > maxClipX)
		{
			xc2 = minClipX;
			yc2 = 0.5 + y2 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		}

	case CLIP_CODE_SW:
		xc2 = 0.5 + x2 + (maxClipY - y1) * (x2 - x1) / (y2 - y1);
		yc2 = maxClipY;
		if (xc2 < minClipX || xc2 > maxClipX)
		{
			xc2 = minClipX;
			yc2 = 0.5 + y2 + (minClipX - x1) * (y2 - y1) / (x2 - x1);
		}
		break;

	default:
		break;
	}

	if ((xc1 < minClipX) || (xc1 > maxClipX) ||
		(yc1 < minClipY) || (yc1 > maxClipY) ||
		(xc2 < minClipX) || (xc2 > maxClipX) ||
		(yc2 < minClipY) || (yc2 > maxClipY) )
	    return 0;

	x1 = xc1;
	y1 = yc1;
	x2 = xc2;
	y2 = yc2;

	return 1;
}