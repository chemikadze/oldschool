object Form1: TForm1
  Left = 258
  Top = 156
  Width = 268
  Height = 380
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    260
    346)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 66
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1088#1086#1082
  end
  object Label2: TLabel
    Left = 136
    Top = 8
    Width = 84
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1086#1083#1073#1094#1086#1074
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 56
    Width = 247
    Height = 121
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 3
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 217
    Width = 247
    Height = 121
    Anchors = [akLeft, akRight, akBottom]
    ColCount = 3
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 1
  end
  object SpinEdit1: TSpinEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 22
    MaxValue = 10
    MinValue = 1
    TabOrder = 2
    Value = 2
    OnChange = SpinEdit1Change
  end
  object SpinEdit2: TSpinEdit
    Left = 135
    Top = 24
    Width = 121
    Height = 22
    MaxValue = 10
    MinValue = 1
    TabOrder = 3
    Value = 3
    OnChange = SpinEdit2Change
  end
  object Button1: TButton
    Left = 96
    Top = 186
    Width = 70
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 4
    OnClick = Button1Click
  end
end
