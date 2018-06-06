#include <windows.h> // ���������� ��� ������ � WIN API-���������    1, 21
#include <iostream>
#include  <fstream>
#include  <string>
#include <iostream>
// ���������� ������� ��������� ��������� ��

using namespace std;
int *arr = new int;
int *yrr = new int;
ifstream fin("perem.txt"); // ������� ���� ��� ������
///////////////////////////////
        LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
        char szClassName[] = "CG_WAPI_Template"; //���������� ���������� ������
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
				" lab11-��319-�05-�������� �.", // ����� ��������� 
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
        LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
		{
			// ����������� ���������� 
			PAINTSTRUCT ps;
			HDC hdc;
			static RECT Rect; //������� ���������
			static HBITMAP hBmp;
			HBRUSH brush;
		    static int xc, yc; //����� ������� ���������
			static int w, h; //������, ������ ��.���.
			//���������� ���������
            int x1 = 20, y1 = 10; 
			int x2 = 20, y2 = 540;

			int x01 = 10, y01 = 280;
			int x02 = 570, y02 = 280;

			int xt1, yt1;
			int xt2, yt2;
			//���������� ����������
			int u = 0;
			int r = 1;
			int a = 0;
			int b = 0;
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
				/////////////////////
				//��� ���������
				//��� Y
                POINT pt;
				MoveToEx(hdc, x1+5, y1, &pt);
				LineTo(hdc, x2+5, y2);
				TextOut(hdc, x1, y1, "Y", 1);
				//��� Y
				MoveToEx(hdc, x01, y01, &pt);
				LineTo(hdc, x02, y02);
				TextOut(hdc, x02, y02, "K", 4);
				/////////////////////
				POINT aa;//����� �� ��� Y
				MoveToEx(hdc, 15, 80, &aa);
				LineTo(hdc, 35, 80);
                
				MoveToEx(hdc, 15, 130, &aa);
				LineTo(hdc, 35, 130);

				MoveToEx(hdc, 15, 180, &aa);
				LineTo(hdc, 35, 180);

				MoveToEx(hdc, 15, 230, &aa);
				LineTo(hdc, 35, 230);
				
                MoveToEx(hdc, 15, 330, &aa);
				LineTo(hdc, 35, 330);

				MoveToEx(hdc, 15, 380, &aa);
				LineTo(hdc, 35, 380);

				MoveToEx(hdc, 15, 430, &aa);
				LineTo(hdc, 35, 430);

				MoveToEx(hdc, 15, 480, &aa);
				LineTo(hdc, 35, 480);
				//��������
				TextOut(hdc, x02-495, y02+10, "1", 1); 
				TextOut(hdc, x02-440, y02 + 10, "2", 1);
				TextOut(hdc, x02-385, y02 + 10, "3", 1);
				TextOut(hdc, x02-330, y02 + 10, "4", 1);
				TextOut(hdc, x02-275, y02 + 10, "5", 1);
				TextOut(hdc, x02-220, y02 + 10, "6", 1);
				TextOut(hdc, x02-170, y02 + 10, "7", 1);
				TextOut(hdc, x02-115, y02 + 10, "8", 1);
				TextOut(hdc, x02 - 60, y02 + 10, "9", 1);
				//TextOut(hdc, x02-65, y02 + 10, "10", 2);
				//�������
				TextOut(hdc, 5 , y02 -67, "50", 2);
				TextOut(hdc, 1 , y02 -117, "100", 3);
				TextOut(hdc, 1, y02 - 167, "150", 3);
				TextOut(hdc, 1 , y02 -217, "200", 3);
				TextOut(hdc, 5, y02 + 10, "0", 1);
				TextOut(hdc, 5, y02+33 , "50", 2);
				TextOut(hdc, 0, y02 +83, "100", 3);
				TextOut(hdc, 0, y02+133 , "150", 3);
				TextOut(hdc, 0, y02 + 183, "200", 3);

				do {                   //���� do while 
					if (r % 2 == 0) {  // ������������� if
                        fin >> arr[a]; //Y
                        a++;
					}
					else               // ������������� else 
					{
                        fin >> yrr[b]; //K
						b++;
					}
					r++;
				} while (r < 21);
			    fin.close();
				xt1 = 25;
				xt2 = 80;
				//��������� �������� �� ��� ���������
				do {                   //���� do while 
					yt2 = 280- arr[u+1];
					yt1 = 280 -arr[u ];
                    POINT pee;
					MoveToEx(hdc, xt1, yt1, &pee);
					LineTo(hdc, xt2, yt2);
					xt1 = xt1 + 55;
					xt2 = xt2 + 55;
					u++;
					MoveToEx(hdc, xt1, 270, &pt);
					LineTo(hdc, xt1, 290);
				} while (u < 9);
			
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
	

	

