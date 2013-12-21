unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, AccessADO, DB, ADODB;

type
  TForm1 = class(TForm)
    DatabaseNameEdit: TEdit;
    OpenButton: TButton;
    OpenDialog: TOpenDialog;
    ADOConn: TADOConnection;
    SaveButton: TButton;
    SaveDialog: TSaveDialog;
    XmlMemo: TMemo;
    XmlFileEdit: TEdit;
    OpenXMLButton: TButton;
    OpenXMLDialog: TOpenDialog;
    procedure OpenButtonClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure SaveButtonClick(Sender: TObject);
    procedure OpenXMLButtonClick(Sender: TObject);

  private
    opened: boolean;
    dbName: string;
    tableNames: TStringList;
    procedure connectToDb(f: string);
    procedure readTables;
    procedure readDataToMemo;
    function fieldTypeToString(t: TFieldType):string;
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.connectToDb(f:string);
begin
    ADOConn.ConnectionString := 'Provider=Microsoft.Jet.OLEDB.4.0'+
                                ';Data Source='+f+
                                ';Persist Security Info=False';
    ADOConn.LoginPrompt := false;
    ADOConn.Connected := true;
end;

procedure TForm1.readTables;
var AdoDS: TADODataset;
    i: integer;
begin
  AdoDS := TADODataset.Create(nil);
  AdoDS.Connection := ADOConn;
  ADOConn.OpenSchema(siTables, EmptyParam, EmptyParam, AdoDS);
  AdoDS.Filter := '(TABLE_TYPE = ''TABLE'')';  // берем только таблицы
  AdoDS.Filtered := true;

  tableNames.Clear;
  AdoDS.First;
  i:=0;
  while not AdoDS.Eof do
  begin
    tableNames.Add(AdoDS.FieldByName('TABLE_NAME').AsString);
    inc(i);
    AdoDS.Next;
  end;
  AdoDS.Destroy;
  ShowMessage('Обнаружены таблицы: ' + #10#13 + tableNames.Text);
end;

/// !!!!!
procedure TForm1.readDataToMemo;
var AdoDS: TADODataSet;
    i, j: integer;
    s: string;
begin
  AdoDS := TADODataset.Create(nil);
  AdoDS.Connection := AdoConn;

  XmlMemo.Lines.Clear;
  XmlMemo.Lines.Add(format('<database path=''%s''>', [dbName]));
  for i:=0 to tableNames.Count-1 do
  begin
    XmlMemo.Lines.Add(format('  <table name=''%s''>', [tableNames[i]]));
    AdoDS.CommandText := 'SELECT * FROM ' + tableNames[i];
    AdoDS.Active:=true;
    AdoDS.First;
    while not AdoDS.Eof do
    begin
      XmlMemo.Lines.Add('    <row>');
      for j:=0 to AdoDS.Fields.Count-1 do
        XmlMemo.Lines.Add( format('       <field name=''%s'' type=''%s''>%s</field>' ,
                           [AdoDS.Fields[j].FieldName, fieldTypeToString(AdoDS.Fields[j].DataType), AdoDS.Fields[j].AsString]) );
      XmlMemo.Lines.Add('    </row>');
      AdoDS.Next;
    end;
    XmlMemo.Lines.Add('  </table>');
    AdoDS.Close;
  end;
  XmlMemo.Lines.Add('</database>');
end;

function TForm1.fieldTypeToString(t: TFieldType):string;
begin
  case t of
  ftUnknown: Result := 'Unknown';
ftString: Result := 'String';
ftSmallint: Result := 'Smallint';
ftInteger: Result := 'Integer';
ftWord: Result := 'Word';
ftBoolean: Result := 'Boolean';
ftFloat: Result := 'Float';
ftCurrency: Result := 'Currency';
ftBCD: Result := 'BCD';
ftDate: Result := 'Date';
ftTime: Result := 'Time';
ftDateTime: Result := 'DateTime';
ftBytes: Result := 'Bytes';
ftVarBytes: Result := 'VarBytes';
ftAutoInc: Result := 'AutoInc';
ftBlob: Result := 'Blob';
ftMemo: Result := 'Memo';
ftGraphic: Result := 'Graphic';
ftFmtMemo: Result := 'FmtMemo';
ftParadoxOle: Result := 'ParadoxOle';
ftDBaseOle: Result := 'DBaseOle';
ftTypedBinary: Result := 'TypedBinary';
ftCursor: Result := 'Cursor';
ftFixedChar: Result := 'FixedChar';
ftWideString: Result := 'WideString';
ftLargeint: Result := 'Largeint';
ftADT: Result := 'ADT';
ftArray: Result := 'Array';
ftReference: Result := 'Reference';
ftDataSet: Result := 'DataSet';
ftOraBlob: Result := 'OraBlob';
ftOraClob: Result := 'OraClob';
ftVariant: Result := 'Variant';
ftInterface: Result := 'Interface';
ftIDispatch: Result := 'IDispatch';
ftGuid: Result := 'Guid';
ftTimeStamp: Result := 'TimeStamp';
ftFMTBcd: Result := 'FMTBcd';
  else
    Result := 'Unknown';
  end;
end;

procedure TForm1.OpenButtonClick(Sender: TObject);
begin
  if (OpenDialog.Execute) then
  begin
    if (opened) then
      AdoConn.Close;
    connectToDb(OpenDialog.FileName);
    dbName := OpenDialog.FileName;
    DatabaseNameEdit.Text := OpenDialog.FileName;
    opened := true;
    readTables;
    readDataToMemo;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  tableNames := TStringList.Create;
  opened := false;
end;

procedure TForm1.SaveButtonClick(Sender: TObject);
begin
  if (SaveDialog.Execute) then
  begin
    XmlMemo.Lines.SaveToFile(SaveDialog.FileName);
    XmlFileEdit.Text := SaveDialog.FileName;
  end;
end;

procedure TForm1.OpenXMLButtonClick(Sender: TObject);
begin
  if (OpenXMLDialog.Execute) then
  begin
    XmlFileEdit.Text:=OpenXMLDialog.FileName;
    XMLMemo.Lines.LoadFromFile(OpenXMLDialog.FileName);
  end;
end;

end.
