#include <windows.h>

class Mouse
{
public:

	void move( LONG dx, LONG dy )
	{
		input( MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, dx, dy );
	}

	void rightDown()
	{
		input( MOUSEEVENTF_RIGHTDOWN );
	}

	void rightUp()
	{
		input( MOUSEEVENTF_RIGHTUP );
	}

	void leftDown()
	{
		input( MOUSEEVENTF_LEFTDOWN );
	}

	void leftUp()
	{
		input( MOUSEEVENTF_LEFTUP );
	}

private:
	void input( DWORD dwFlags, LONG dx = 0, LONG dy = 0, DWORD mouseData = 0, DWORD time = 0, ULONG_PTR dwExtraInfo = 0 )
	{
	    INPUT input = { INPUT_MOUSE, dx, dy, mouseData, dwFlags, time, dwExtraInfo };
	    ::SendInput( 1, &input, sizeof(INPUT));
	}
};

void main()
{
	Mouse mouse;

	mouse.move( 32768, 32768 );
	::Sleep( 1000 );
	mouse.rightDown();
	::Sleep( 1000 );
	mouse.rightUp();
}
