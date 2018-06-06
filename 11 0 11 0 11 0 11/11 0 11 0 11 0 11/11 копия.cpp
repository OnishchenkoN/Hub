#include <windows.h> // ���������� ��� ������ � WIN API-���������    1, 21

// ���������� ������� ��������� ��������� ��
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "CG_WAPI_Template"; //���������� ���������� ������

										 //�������� �������  ~main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��������� ���������� - �������
	HWND hWnd;  // �������� ���� ����������
	MSG lpMsg;  // ���������
	WNDCLASS wc; // ���������� ����

				 // ��������� ��������� ������ ����
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	// ������������ ����� ����
	if (!RegisterClass(&wc)) // ���� ������
	{
		MessageBox(NULL, "�� ���� ���������������� ����� ����!", "������", MB_OK);
		return 0;
	}

	// ������� �������� ���� ����������
	hWnd = CreateWindow(
		szClassName,                // ��� ������
		"������ WinAPI ����������", // ����� ��������� 
		WS_OVERLAPPEDWINDOW,        // ����� ����
		50, 50,                   // ������� ������ �������� ����
		600, 600,                  // ������ � ������ ����
		(HWND)NULL,                // ��������� �� ������������ ���� NULL
		(HMENU)NULL,               // ������������ ���� ������ ����
		(HINSTANCE)hInstance,       // ��������� �� ������� ����������
		NULL);         // ���������� � �������� lParam � ������� WM_CREATE
	if (!hWnd) // ���� ������
	{
		MessageBox(NULL, "�� ������� ������� ������� ����!", "������", MB_OK);
		return 0;
	}

	// ���������� ���� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// ��������� ���� ��������� ��������� �� �������� ����������
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return (lpMsg.wParam);
}

//���������� ������� ��������� ��������� ��
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	// ����������� ���������� 
	PAINTSTRUCT ps;
	HDC hdc;
	static RECT Rect; //������� ���������
	static HBITMAP hBmp;
	HBRUSH brush, hBrush;
	HFONT hFont;
	HPEN hPen; //������ ����

	static int xc, yc; //����� ������� ���������
	static int w, h; //������, ������ ��.���.
	int a = 450;
	int x0 = 320, y0 = 150;
	int b = 450;
	int x1 = 370, y1 = 200;
	int c = 450;
	int x2 =420, y2 = 250;

/////////////////////////
	int nxTL=50; // ���������� x �������� ������ ����
		int nyTL=50; // ���������� y �������� ������ ����
	int nxBR=550; // ���������� x ������� ������� ����
	int nyBR=500;// ���������� y ������� ������� ����
	int nxEllipse=50; // ������ �������
		int nyEllipse=50; // ������ �������

					 // ��������� ��������� ��
	switch (messg)
	{
	case WM_CREATE:
		hBmp = (HBITMAP)LoadImage(NULL, "desktop.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		break;
	case WM_SIZE:
		GetClientRect(hWnd, &Rect);
		w = Rect.right - Rect.left;
		h = Rect.bottom - Rect.top;
		xc = Rect.left + w / 2;
		yc = Rect.top + h / 2;
		break;

	case WM_PAINT: // ����������� ����
		hdc = BeginPaint(hWnd, &ps);


		brush = CreatePatternBrush(hBmp);

		FillRect(hdc, &Rect, brush);

		
		

		// ����� ������ �� ��������� hDC 
		/////////////////////////////////////
		//cub
		
		RoundRect(hdc, nxTL,nyTL, nxBR, nyBR, nxEllipse, nyEllipse);
		
		
		
		RECT r; //��������� ��������� ���������
				//RECT - ���������� ��������������
		r.left = y0+120; //����� ������� ����
		r.top = x0-60;
		r.bottom = 150;//������ ������
		r.right = x0 - a / 2;

		//��������� �������������
		FillRect(hdc, &r,(HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
	
		TextOut(hdc, x0 -200, y0 + 10, "red", 3);///
		/////////////////////////////////////////////////
		
		
		RECT e; //��������� ��������� ���������
				//RECT - ���������� ��������������
		e.left = y1+120; //����� ������� ����
		e.top = x1-60;
		e.right =  x1 - b / 2;
		e.bottom = 200;
		//��������� �������������
		FillRect(hdc, &e,(HBRUSH)CreateSolidBrush(RGB(0, 255, 0)));
		
		TextOut(hdc, x1 -200, y1 + 10, "green", 5);////////
		///////////////////////////////////////////////////////////
		
        
		
		RECT w; //��������� ��������� ���������
				//RECT - ���������� ��������������
		w.left = x2-50; //����� ������� ����
		w.top = x2-57;
		w.right =  x2 - c / 2;
		w.bottom = 250;

		//��������� �������������
		FillRect(hdc, &w,(HBRUSH)CreateSolidBrush(RGB(0, 0, 255)));
		TextOut(hdc, x2-200, y2 + 10, "blue", 4);/////
		
		
		
		/////////////////////////////////////					      

		// ������� �������� ��������� �������
		//DeleteObject(hFont);
		//DeleteObject(hBrush);
		//DeleteObject(brush);

		EndPaint(hWnd, &ps);
		break;

case WM_DESTROY: // �������� ����
		PostQuitMessage(0);
		break;

	default: // ������ ���������
		return (DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return (0);
}




// �������� ������� ������
//brush = CreateSolidBrush(RGB(200, 200, 200));
//FillRect(hdc, &Rect, brush);
//hBmp = (HBITMAP)LoadImage(NULL, "desktop.bmp", IMAGE_BITMAP, 0, 0,
//LR_LOADFROMFILE | LR_CREATEDIBSECTION)