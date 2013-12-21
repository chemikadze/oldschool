object Form1: TForm1
  Left = 464
  Top = 259
  Width = 548
  Height = 376
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
    Left = 24
    Top = 136
    Width = 56
    Height = 13
    Caption = #1055#1088#1086#1094#1077#1089#1089#1086#1074
  end
  object Label2: TLabel
    Left = 312
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 312
    Top = 32
    Width = 76
    Height = 13
    Caption = #1088#1072#1079#1084#1077#1088' '#1082#1074#1072#1085#1090#1072
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 8
    Width = 289
    Height = 161
    ColCount = 3
    Ctl3D = True
    DefaultColWidth = 50
    RowCount = 4
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ParentCtl3D = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 312
    Top = 72
    Width = 75
    Height = 25
    Caption = #1089#1095#1080#1090#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 312
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '3'
    OnChange = Edit1Change
  end
  object UpDown1: TUpDown
    Left = 432
    Top = 8
    Width = 17
    Height = 21
    Associate = Edit1
    Min = 1
    Max = 10
    Position = 3
    TabOrder = 3
  end
  object StringGrid2: TStringGrid
    Left = 16
    Top = 176
    Width = 513
    Height = 161
    DefaultColWidth = 36
    RowCount = 4
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 312
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '1'
  end
  object UpDown2: TUpDown
    Left = 433
    Top = 48
    Width = 16
    Height = 21
    Associate = Edit2
    Min = 1
    Position = 1
    TabOrder = 6
  end
end
