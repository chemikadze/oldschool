object Form1: TForm1
  Left = 412
  Top = 303
  Width = 494
  Height = 294
  Caption = 'C-SCAN'
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
    Left = 16
    Top = 64
    Width = 85
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1079#1072#1087#1088#1086#1089#1086#1074
  end
  object Label2: TLabel
    Left = 128
    Top = 64
    Width = 106
    Height = 13
    Caption = #1074#1088#1077#1084#1103' '#1087#1077#1088#1077#1084#1077#1097#1077#1085#1080#1103
    WordWrap = True
  end
  object Label4: TLabel
    Left = 16
    Top = 0
    Width = 98
    Height = 13
    Caption = #1085#1072#1095#1072#1083#1100#1085#1072#1103' '#1087#1086#1079#1080#1094#1080#1103
  end
  object Label5: TLabel
    Left = 128
    Top = 0
    Width = 80
    Height = 13
    Caption = #1082#1086#1083'-'#1074#1086' '#1076#1086#1088#1086#1078#1077#1082
  end
  object Label6: TLabel
    Left = 16
    Top = 240
    Width = 32
    Height = 13
    Caption = 'Label6'
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 104
    Width = 473
    Height = 57
    ColCount = 8
    DefaultColWidth = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 176
    Width = 473
    Height = 57
    ColCount = 8
    DefaultColWidth = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 1
  end
  object Button1: TButton
    Left = 256
    Top = 16
    Width = 57
    Height = 25
    Caption = #1059#1084#1077#1085#1100#1096
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 80
    Width = 81
    Height = 21
    TabOrder = 3
    Text = '8'
  end
  object UpDown1: TUpDown
    Left = 97
    Top = 80
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 1
    Max = 50
    Position = 8
    TabOrder = 4
    OnChangingEx = UpDown1ChangingEx
  end
  object Edit2: TEdit
    Left = 128
    Top = 80
    Width = 113
    Height = 21
    TabOrder = 5
    Text = '1'
  end
  object Edit4: TEdit
    Left = 16
    Top = 16
    Width = 81
    Height = 21
    TabOrder = 6
    Text = '63'
  end
  object Edit5: TEdit
    Left = 128
    Top = 16
    Width = 97
    Height = 21
    TabOrder = 7
    Text = '100'
  end
  object UpDown2: TUpDown
    Left = 97
    Top = 16
    Width = 16
    Height = 21
    Associate = Edit4
    Position = 63
    TabOrder = 8
  end
  object UpDown3: TUpDown
    Left = 225
    Top = 16
    Width = 16
    Height = 21
    Associate = Edit5
    Position = 100
    TabOrder = 9
  end
  object Button2: TButton
    Left = 320
    Top = 16
    Width = 57
    Height = 25
    Caption = #1059#1074#1077#1083#1080#1095
    TabOrder = 10
    OnClick = Button1Click
  end
end
