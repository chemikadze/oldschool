object Form1: TForm1
  Left = 808
  Top = 124
  Width = 399
  Height = 282
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
    Left = 112
    Top = 224
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object UpDown1: TUpDown
    Left = 89
    Top = 192
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 1
    Position = 4
    TabOrder = 0
    OnChangingEx = UpDown1ChangingEx
  end
  object Edit1: TEdit
    Left = 8
    Top = 192
    Width = 81
    Height = 21
    TabOrder = 1
    Text = '4'
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 97
    Height = 177
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 112
    Top = 8
    Width = 273
    Height = 209
    DefaultColWidth = 30
    FixedCols = 0
    RowCount = 6
    TabOrder = 3
  end
  object Button1: TButton
    Left = 16
    Top = 224
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082
    TabOrder = 4
    OnClick = Button1Click
  end
end
