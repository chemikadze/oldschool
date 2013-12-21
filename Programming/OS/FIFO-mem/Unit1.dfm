object Form1: TForm1
  Left = 421
  Top = 271
  Width = 575
  Height = 274
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 84
    Height = 13
    Caption = #1082#1086#1083'-'#1074#1086' '#1079#1072#1087#1088#1086#1089#1086#1074
  end
  object Label3: TLabel
    Left = 16
    Top = 88
    Width = 92
    Height = 13
    Caption = #1072#1082#1090#1080#1074#1085#1099#1093' '#1089#1090#1088#1072#1085#1080#1094
  end
  object Label4: TLabel
    Left = 16
    Top = 136
    Width = 32
    Height = 13
    Caption = 'Label4'
  end
  object StringGrid1: TStringGrid
    Left = 176
    Top = 16
    Width = 377
    Height = 73
    ColCount = 10
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    ColWidths = (
      30
      30
      30
      30
      30
      30
      30
      30
      30
      30)
  end
  object Edit2: TEdit
    Left = 16
    Top = 64
    Width = 73
    Height = 21
    TabOrder = 1
    Text = '10'
    OnChange = Edit2Change
  end
  object UpDown2: TUpDown
    Left = 89
    Top = 64
    Width = 16
    Height = 21
    Associate = Edit2
    Min = 1
    Position = 10
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 16
    Top = 104
    Width = 81
    Height = 21
    TabOrder = 3
    Text = '3'
    OnChange = Edit3Change
  end
  object UpDown3: TUpDown
    Left = 97
    Top = 104
    Width = 16
    Height = 21
    Associate = Edit3
    Position = 3
    TabOrder = 4
  end
  object Button1: TButton
    Left = 16
    Top = 16
    Width = 145
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082
    TabOrder = 5
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 176
    Top = 96
    Width = 377
    Height = 137
    ColCount = 10
    DefaultColWidth = 30
    FixedCols = 0
    TabOrder = 6
  end
end
