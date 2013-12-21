object Form1: TForm1
  Left = 424
  Top = 251
  Width = 575
  Height = 319
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
  object Label1: TLabel
    Left = 32
    Top = 96
    Width = 77
    Height = 13
    Caption = #1082#1086#1083'-'#1074#1086' '#1089#1090#1088#1072#1085#1080#1094
  end
  object Label2: TLabel
    Left = 120
    Top = 96
    Width = 84
    Height = 13
    Caption = #1082#1086#1083'-'#1074#1086' '#1079#1072#1087#1088#1086#1089#1086#1074
  end
  object Label3: TLabel
    Left = 224
    Top = 96
    Width = 92
    Height = 13
    Caption = #1072#1082#1090#1080#1074#1085#1099#1093' '#1089#1090#1088#1072#1085#1080#1094
  end
  object Label4: TLabel
    Left = 408
    Top = 248
    Width = 32
    Height = 13
    Caption = 'Label4'
  end
  object StringGrid1: TStringGrid
    Left = 24
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
  object Edit1: TEdit
    Left = 24
    Top = 112
    Width = 65
    Height = 21
    TabOrder = 1
    Text = '6'
  end
  object Edit2: TEdit
    Left = 120
    Top = 112
    Width = 73
    Height = 21
    TabOrder = 2
    Text = '10'
    OnChange = Edit2Change
  end
  object UpDown1: TUpDown
    Left = 89
    Top = 112
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 1
    Position = 6
    TabOrder = 3
  end
  object UpDown2: TUpDown
    Left = 193
    Top = 112
    Width = 16
    Height = 21
    Associate = Edit2
    Min = 1
    Position = 10
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 224
    Top = 112
    Width = 81
    Height = 21
    TabOrder = 5
    Text = '3'
    OnChange = Edit3Change
  end
  object UpDown3: TUpDown
    Left = 305
    Top = 112
    Width = 16
    Height = 21
    Associate = Edit3
    Position = 3
    TabOrder = 6
  end
  object Button1: TButton
    Left = 408
    Top = 16
    Width = 145
    Height = 225
    Caption = #1047#1072#1087#1091#1089#1082
    TabOrder = 7
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 24
    Top = 144
    Width = 377
    Height = 137
    ColCount = 10
    DefaultColWidth = 30
    FixedCols = 0
    TabOrder = 8
  end
end
