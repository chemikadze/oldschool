unit Solver;

interface

uses
  Math, SysUtils;

type
  PStack = ^TStack;
  TStack = record
    Next, Prev: PStack;
    Token: Byte;
    Number: Extended;
    Func: String[20];
  end;

  TSolver = class(TObject)
  private
    FError: Byte;
    FStack: PStack;
    FTokenStackTail: PStack;
    FTokenStackHead: PStack;
    FPrevToken: Byte;
    FRPNText: String;
    FRPNResult: Extended;
    FInput: String;
    function PriorityToken(Token: Byte): Integer;
    procedure PushStack(Token: Byte);
    procedure PopStack;
    procedure PushToken;
    procedure PushTokenNumber(Value: Extended);
    procedure FreeStack;
    procedure FreeTokenStack;
    procedure Tokenize(const Value: String);
    procedure ProcessTokens;
  public
    function TokenToStr(P: PStack): String;
    procedure Solve(const Value: String);
    procedure SolveGraph(const Value: String; X: Extended);
    property Input: String read FInput;
    property RPNText: String read FRPNText;
    property RPNResult: Extended read FRPNResult;
    property Error: Byte read FError;
  end;

const
  E_NOERROR     = 0;    {No Error}
  E_EMPTY       = 1;    {Empty expression}
  E_EXPR        = 2;    {Error in expression}
  E_SOLVE       = 3;    {Could not solve}
  E_DIV_BY_ZERO = 4;    {Division by zero}
  E_FUNC        = 5;    {Error in function}
  E_FUNC_NOT_FOUND = 6; {There's no such function}

  function SolverErrorToStr(Solver: TSolver): String;
  function SolverErrorToStrRus(Solver: TSolver): String;

implementation

const
  TOKEN_UNKNOWN = Byte(-1);
  TOKEN_NUMBER  = 0;
  TOKEN_FUNC    = 1;
  TOKEN_BOPEN   = 2;
  TOKEN_BCLOSE  = 3;
  TOKEN_PLUS    = 4;
  TOKEN_MINUS   = 5;
  TOKEN_MUL     = 6;
  TOKEN_DIVR    = 7;
  TOKEN_POW     = 8;

function TSolver.PriorityToken(Token: Byte): Integer;
begin
  case Token of
    TOKEN_BOPEN:                Result := 0;
    TOKEN_BCLOSE:               Result := 1;
    TOKEN_PLUS, TOKEN_MINUS:    Result := 2;
    TOKEN_MUL, TOKEN_DIVR:      Result := 3;
    TOKEN_POW:                  Result := 4;
    TOKEN_FUNC:                 Result := 5;
  else
    Result := -1;
  end;
end;

procedure TSolver.PushStack(Token: Byte);
var
  P: PStack;
begin
  New(P);
  P.Next := FStack;
  P.Token := Token;
  FStack := P;
end;

procedure TSolver.PopStack;
var
  P: PStack;
begin
  P := FStack;
  FStack := FStack.Next;
  Dispose(P);
end;

procedure TSolver.PushToken;
begin
  if FTokenStackHead = nil then begin
    New(FTokenStackHead);
    FTokenStackTail := FTokenStackHead;
    FTokenStackTail.Prev := nil;
  end else begin
    New(FTokenStackTail.Next);
    FTokenStackTail.Next.Prev := FTokenStackTail;
    FTokenStackTail := FTokenStackTail.Next;
  end;
  FTokenStackTail.Next := nil;

  FTokenStackTail.Token := FStack.Token;
  if FStack.Token = TOKEN_FUNC then
    FTokenStackTail.Func := FStack.Func;
end;

procedure TSolver.PushTokenNumber(Value: Extended);
begin
  if FTokenStackHead = nil then begin
    New(FTokenStackHead);
    FTokenStackTail := FTokenStackHead;
    FTokenStackTail.Prev := nil;
  end else begin
    New(FTokenStackTail.Next);
    FTokenStackTail.Next.Prev := FTokenStackTail;
    FTokenStackTail := FTokenStackTail.Next;
  end;
  FTokenStackTail.Next := nil;

  FTokenStackTail.Token := TOKEN_NUMBER;
  FTokenStackTail.Number := Value;
end;

function TSolver.TokenToStr(P: PStack): String;
begin
  case P.Token of
    TOKEN_NUMBER:       Result := FloatToStr(P.Number);
    TOKEN_FUNC:         Result := P.Func;
    TOKEN_BOPEN:        Result := '(';
    TOKEN_BCLOSE:       Result := ')';
    TOKEN_PLUS:         Result := '+';
    TOKEN_MINUS:        Result := '-';
    TOKEN_MUL:          Result := '*';
    TOKEN_DIVR:         Result := '/';
    TOKEN_POW:          Result := '^';
  else
    Result := 'UNK';
  end;
  Result := Result + ' ';
end;

procedure TSolver.FreeStack;
var
  P: PStack;
begin
  while FStack <> nil do begin
    P := FStack.Next;
    Dispose(FStack);
    FStack := P;
  end;
end;

procedure TSolver.FreeTokenStack;
var
  P: PStack;
begin
  while FTokenStackHead <> nil do begin
    P := FTokenStackHead.Next;
    Dispose(FTokenStackHead);
    FTokenStackHead := P;
  end;
end;

procedure TSolver.Tokenize(const Value: String);
  procedure HandleToken(const Value: String);
  var
    Token: Byte;
  begin
    {Convert Value into Token}
    case Value[1] of
      '0'..'9',
      ',':      Token := TOKEN_NUMBER;
      '(':      Token := TOKEN_BOPEN;
      ')':      Token := TOKEN_BCLOSE;
      '+':      Token := TOKEN_PLUS;
      '-':      Token := TOKEN_MINUS;
      '*':      Token := TOKEN_MUL;
      '/':      Token := TOKEN_DIVR;
      '^':      Token := TOKEN_POW;
      ' ':      Exit;
      'a'..'z': Token := TOKEN_FUNC;
    else
      begin
        FError := E_EXPR;
        Exit;
      end;
    end;
    if Token <> TOKEN_NUMBER then begin
      if FStack = nil then begin
        if (Token = TOKEN_MINUS) and (FPrevToken <> TOKEN_NUMBER) and (FPrevToken <> TOKEN_BCLOSE) then
          PushTokenNumber(0.0);
        PushStack(Token);
        if Token = TOKEN_FUNC then
          FStack.Func := Value;
      end else
        case Token of
        TOKEN_BOPEN:
          PushStack(TOKEN_BOPEN);
        TOKEN_BCLOSE: begin
          while (FStack <> nil) and (FStack.Token <> TOKEN_BOPEN) do begin
            PushToken;
            PopStack;
          end;
          if (FStack <> nil) and (FStack.Token = TOKEN_BOPEN) then
            PopStack;
        end else begin
          if (FPrevToken = TOKEN_BOPEN) and (Token = TOKEN_MINUS) then
            PushTokenNumber(0.0);
          while (FStack <> nil) and (PriorityToken(FStack.Token) >= PriorityToken(Token)) do begin
            PushToken;
            PopStack;
          end;
          PushStack(Token);
          if Token = TOKEN_FUNC then
            FStack.Func := Value;
        end;
      end;
    end else
      PushTokenNumber(StrToFloat(Value));
    FPrevToken := Token;
  end;

  procedure HandleRemainder;
  begin
    while (FStack <> nil) do begin
      if (FStack.Token <> TOKEN_BCLOSE) and (FStack.Token <> TOKEN_BOPEN) then
        PushToken;
      PopStack;
    end;
  end;
var
  i, Operation, PrevOperation: Word;
  S: String;
begin
  Operation := $FFFF;
  FPrevToken := TOKEN_UNKNOWN;
  FTokenStackHead := nil; FTokenStackTail := nil; FStack := nil;
  S := '';
  for i := 1 to Length(Value) do begin
    PrevOperation := Operation;
    {Extract Numbers, Functions, Operators}
    case Value[i] of
      '0'..'9', ',': Operation := 0; {Numbers}
      'a'..'z':      Operation := 1; {Functions}
    else             Operation := 2; {Operators}
    end;
    if (PrevOperation = 0) and ((Value[i] = 'E') or (Value[i] = 'e'))  then Operation := 0;
    if ((PrevOperation <> Operation) and (PrevOperation <> $FFFF)) or (Operation = 2) then begin
      if Length(S) > 0 then begin
        HandleToken(S);
        if FError <> E_NOERROR then
          Exit;
      end;
      S := '';
    end;
    S := S + Value[i];
  end;
  if Length(S) > 0 then begin
    HandleToken(S);
    if FError <> E_NOERROR then Exit;
  end;
  HandleRemainder;
end;

procedure TSolver.ProcessTokens;
var
  P, P1, P2: PStack;
begin
  if FTokenStackHead = nil then begin
    FError := E_EMPTY;
    Exit;
  end;

  P := FTokenStackHead;
  while P <> nil do begin
    FRPNText := FRPNText + TokenToStr(P) + ' ';
    P := P.Next;
  end;

  P := FTokenStackHead;
  while FTokenStackHead.Next <> nil do begin
    if P = nil then begin
      FError := E_EXPR;
      Exit;
    end;
    case P.Token of
      TOKEN_NUMBER:
        P := P.Next;
      TOKEN_FUNC:
        begin
          P1 := P.Prev;  {a}
          if P1 = nil then begin
            FError := E_EXPR;
            Exit;
          end;
          if P.Func = 'sin' then
            P1.Number := sin(P1.Number)
          else if P.Func = 'cos' then
            P1.Number := cos(P1.Number)
          else if P.Func = 'abs' then
            P1.Number := abs(P1.Number)
          else if P.Func = 'sqr' then
            P1.Number := sqr(P1.Number)
          else if P.Func = 'tan' then begin
            if cos(P1.Number) = 0 then begin
              FError := E_FUNC;
              Exit;
            end else
              P1.Number := sin(P1.Number) / cos(P1.Number);
          end else if P.Func = 'sqrt' then begin
            if P1.Number < 0 then begin
              FError := E_FUNC;
              Exit;
            end else
              P1.Number := sqrt(P1.Number)
          end else begin
            FError := E_FUNC_NOT_FOUND;
            Exit;
          end;
          P1.Next := P.Next;
          if P.Next <> nil then
            P.Next.Prev := P.Prev;
          Dispose(P);
          P := P1;
        end;
      else
        begin
          P1 := P.Prev;  {b}
          if P1 = nil then begin
            FError := E_EXPR;
            Exit;
          end;
          P2 := P1.Prev; {a}
          if P2 = nil then begin
            FError := E_EXPR;
            Exit;
          end;
          case P.Token of
            TOKEN_PLUS:   P2.Number := P2.Number + P1.Number;
            TOKEN_MINUS:  P2.Number := P2.Number - P1.Number;
            TOKEN_MUL:    P2.Number := P2.Number * P1.Number;
            TOKEN_DIVR:
              if P1.Number = 0 then begin
                FError := E_DIV_BY_ZERO;
                Exit;
              end else
                P2.Number := P2.Number / P1.Number;
            TOKEN_POW:
              if (P2.Number = 0) and (P1.Number < 0) then begin
                FError := E_DIV_BY_ZERO;
                Exit;
              end else
              if (P2.Number < 0) and (Frac(P1.Number) <> 0) then begin
                FError := E_SOLVE;
                Exit;
              end else
                P2.Number := Power(P2.Number, P1.Number);
          end;
          P2.Next := P.Next;
          if P.Next <> nil then
            P.Next.Prev := P1.Prev;
          Dispose(P); Dispose(P1);
          P := P2;
        end;
    end;
  end;
  if FTokenStackHead.Token <> TOKEN_NUMBER then begin
    FError := E_EXPR;
    Exit;
  end;
  FRPNResult := FTokenStackHead.Number;
  Dispose(FTokenStackHead); FTokenStackHead := nil;
end;

procedure TSolver.Solve(const Value: String);
begin
  FRPNResult := 0; FRPNText := ''; FError := E_NOERROR;
  FInput := Value;
  if Length(Value) = 0 then begin
    FError := E_EMPTY;
    Exit;
  end;
  Tokenize(Value);
  if FError = E_NOERROR then begin
    ProcessTokens;
    if FError <> E_NOERROR then
      FreeTokenStack;
  end else begin
    FreeStack;
    FreeTokenStack;
  end;
end;

procedure TSolver.SolveGraph(const Value: String; X: Extended);
begin
  Solve(StringReplace(Value, 'x', '(' + FloatToStr(X) + ')', [rfReplaceAll]));
end;

function SolverErrorToStr(Solver: TSolver): String;
begin
  case Solver.Error of
    E_NOERROR:          Result := 'No error';
    E_EMPTY:            Result := 'Empty expression';
    E_EXPR:             Result := 'Error in expression';
    E_SOLVE:            Result := 'Could not solve expression';
    E_DIV_BY_ZERO:      Result := 'Division by zero';
    E_FUNC:             Result := 'Error in function';
    E_FUNC_NOT_FOUND:   Result := 'Function not found';
  else
    Result := 'Unknown error';
  end;
end;

function SolverErrorToStrRus(Solver: TSolver): String;
begin
  case Solver.Error of
    E_NOERROR:          Result := 'Нет ошибки';
    E_EMPTY:            Result := 'Пустое выражение';
    E_EXPR:             Result := 'Ошибка в выражении';
    E_SOLVE:            Result := 'Невозможно решить выражение';
    E_DIV_BY_ZERO:      Result := 'Деление на ноль';
    E_FUNC:             Result := 'Ошибка при вычислении функции';
    E_FUNC_NOT_FOUND:   Result := 'Функция не найдена';
  else
    Result := 'Неизвестная ошибка';
  end;
end;


end.
