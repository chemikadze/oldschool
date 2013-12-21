object Form1: TForm1
  Left = 649
  Top = 286
  Width = 429
  Height = 212
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 0
    Width = 94
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1086#1073#1088#1072#1097#1077#1085#1080#1081
  end
  object Label2: TLabel
    Left = 152
    Top = 0
    Width = 100
    Height = 13
    Caption = #1053#1072#1095#1072#1083#1100#1085#1072#1103' '#1087#1086#1079#1080#1094#1080#1103
  end
  object Label3: TLabel
    Left = 8
    Top = 160
    Width = 32
    Height = 13
    Caption = 'Label3'
  end
  object Edit1: TEdit
    Left = 8
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '8'
  end
  object Button1: TButton
    Left = 280
    Top = 16
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 48
    Width = 409
    Height = 49
    ColCount = 8
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    ColWidths = (
      30
      30
      30
      30
      30
      30
      30
      29)
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 104
    Width = 409
    Height = 49
    ColCount = 9
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 3
    ColWidths = (
      30
      29
      30
      30
      30
      30
      30
      30
      30)
  end
  object UpDown1: TUpDown
    Left = 129
    Top = 16
    Width = 16
    Height = 21
    Associate = Edit1
    Position = 8
    TabOrder = 4
    OnChangingEx = UpDown1ChangingEx
  end
  object Edit2: TEdit
    Left = 152
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '62'
  end
end
