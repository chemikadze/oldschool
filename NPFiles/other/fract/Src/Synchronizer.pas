unit Synchronizer;

interface
uses
  Windows;

type
  TSynchronizer = class(TObject)
  private
    Shared: Integer;
    CS: TRTLCriticalSection;
  public
    procedure Enter;
    procedure Leave;
  end;


implementation

{Swap pointers}
procedure XChg(var Critical, Normal); assembler;
asm
  mov  ecx, [edx]
  xchg [eax], ecx
  mov  [edx], ecx
end;

procedure TSynchronizer.Enter; {Synchronization - enter critical section}
var
  j: Integer;
begin
  j := 1; XChg(Shared, j); if j = 0 then InitializeCriticalSection(CS);
  EnterCriticalSection(CS);
end;

procedure TSynchronizer.Leave; {Synchronization - leave critical section}
begin
  LeaveCriticalSection(CS);
end;


end.
