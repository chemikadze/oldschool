object Form1: TForm1
  Left = 128
  Top = 154
  Width = 338
  Height = 444
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
    Left = 16
    Top = 208
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 8
    Width = 305
    Height = 161
    ColCount = 4
    Ctl3D = True
    RowCount = 4
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ParentCtl3D = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 176
    Top = 176
    Width = 75
    Height = 25
    Caption = #1089#1095#1080#1090#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 176
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '3'
    OnChange = Edit1Change
  end
  object UpDown1: TUpDown
    Left = 137
    Top = 176
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 1
    Max = 10
    Position = 3
    TabOrder = 3
  end
  object StringGrid2: TStringGrid
    Left = 16
    Top = 240
    Width = 305
    Height = 169
    DefaultColWidth = 30
    RowCount = 4
    TabOrder = 4
    ColWidths = (
      30
      30
      30
      30
      30)
  end
end
