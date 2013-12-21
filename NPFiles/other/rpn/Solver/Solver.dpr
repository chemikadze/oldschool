program WindowEX;

uses
  Windows, Messages, Solver in '..\RPN\Solver.pas', SysUtils;

var
  hInput: HWND;
  hOutput: HWND;
  MySolver: TSolver;

function GetText(Control: HWND): String;
begin
  SetString(Result, nil, SendMessage(Control, WM_GETTEXTLENGTH, 0, 0) + 1);
  SendMessage(Control, WM_GETTEXT, Length(Result), Integer(@Result[1]));
  Delete(Result, Length(Result), 1);
end;

procedure SetText(Control: HWND; const Value: String);
begin
  SendMessage(Control, WM_SETTEXT, Length(Value), Integer(@Value[1]));
end;

procedure UpdateSolver;
begin
  try
    MySolver.Solve(GetText(hInput));
    if MySolver.Error = E_NOERROR then
      SetText(hOutput, 'Result: ' + FloatToStr(MySolver.RPNResult))
    else
      SetText(hOutput, 'Error: ' + SolverErrorToStr(MySolver));
  except
      SetText(hOutput, 'Error: unknown');
  end;
end;


function WndProc(hwnd, wmsg, wParam, lParam: HWND): Integer; stdcall;
var
  rcDlg: TRect;
begin
  Result := 0;
  case wmsg Of
    WM_DESTROY: begin
      MySolver.Free;
      PostQuitMessage(0);
    end;
    WM_COMMAND:
    begin
      if (lParam = hInput) and (HIWORD(wParam) = EN_CHANGE) then
        UpdateSolver;
    end;
    WM_CREATE:
    begin
      MySolver := TSolver.Create;
      GetClientRect(hwnd, rcDlg);
      hInput := CreateWindow('EDIT', '(1+2)^2', WS_VISIBLE or WS_CHILD or WS_BORDER, (rcDlg.Right - rcDlg.Left) div 2 - 100,
        40, 200, 20, hwnd, 0, hInstance, nil);
      hOutput := CreateWindow('EDIT', '', WS_VISIBLE or WS_CHILD or WS_BORDER or ES_MULTILINE, (rcDlg.Right - rcDlg.Left) div 2 - 100,
        70, 200, 150, hwnd, 0, hInstance, nil);
      UpdateSolver;
      SetFocus(hInput);      
    end else
      Result := DefWindowProc(hwnd, wmsg, wparam, lparam);
  end;
end;


var
  wClass: TWndClassEx;
  Msg: TMsg;

begin
  FillChar(wClass, SizeOf(wClass), 0);
  wClass.cbSize := SizeOf(wclass);
  wClass.style := cs_hredraw or cs_vredraw;
  wClass.lpfnWndProc := @WndProc;
  wClass.cbClsExtra := 0;
  wClass.hbrBackground := COLOR_BTNFACE + 1;
  wClass.hInstance := hInstance;
  wClass.hCursor := LoadCursor(0, idc_arrow);
  wClass.lpszClassName := 'MainWndClass';
  RegisterClassEx(wClass);

  CreateWindowEx(WS_EX_TOPMOST,
    'MainWndClass',
    'Solver',
    WS_SYSMENU or WS_VISIBLE or WS_MINIMIZEBOX or WS_SYSMENU,
    Integer(CW_USEDEFAULT),
    Integer(CW_USEDEFAULT),
    300,
    300,
    0,
    0,
    hInstance,
    nil);

  while GetMessage(Msg, 0, Integer(True), 0) do
  begin
    TranslateMessage(Msg);
    DispatchMessage(Msg);
  end;
end.
