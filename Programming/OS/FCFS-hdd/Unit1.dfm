object Form1: TForm1
  Left = 396
  Top = 145
  Width = 695
  Height = 237
  Caption = 'FIFO'
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
    Top = 80
    Width = 85
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1079#1072#1087#1088#1086#1089#1086#1074
  end
  object Label2: TLabel
    Left = 288
    Top = 80
    Width = 97
    Height = 26
    Caption = #1074#1088#1077#1084#1103' '#1087#1077#1088#1077#1093#1086#1076#1072' '#1085#1072' '#1076#1088#1091#1075#1102' '#1076#1086#1088#1086#1078#1082#1091
    WordWrap = True
  end
  object Label3: TLabel
    Left = 16
    Top = 8
    Width = 326
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1085#1072#1095#1072#1083#1100#1085#1086#1077' '#1087#1086#1083#1086#1078#1077#1085#1080#1077' '#1080' '#1087#1086#1089#1083#1077#1076#1086#1074#1072#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1079#1072#1087#1088#1086#1089#1086#1074
  end
  object Label4: TLabel
    Left = 416
    Top = 88
    Width = 32
    Height = 13
    Caption = 'Label4'
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 24
    Width = 665
    Height = 57
    ColCount = 9
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 144
    Width = 673
    Height = 57
    ColCount = 9
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 1
  end
  object Button1: TButton
    Left = 152
    Top = 112
    Width = 121
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '9'
  end
  object UpDown1: TUpDown
    Left = 129
    Top = 112
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 1
    Max = 50
    Position = 9
    TabOrder = 4
    OnChangingEx = UpDown1ChangingEx
  end
  object Edit2: TEdit
    Left = 288
    Top = 112
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '1'
  end
end
