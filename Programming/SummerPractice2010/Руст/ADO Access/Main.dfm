object Form1: TForm1
  Left = 300
  Top = 223
  Width = 612
  Height = 338
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    596
    302)
  PixelsPerInch = 96
  TextHeight = 13
  object DatabaseNameEdit: TEdit
    Left = 8
    Top = 8
    Width = 433
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    ReadOnly = True
    TabOrder = 0
  end
  object OpenButton: TButton
    Left = 448
    Top = 8
    Width = 140
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Import from .MDB'
    TabOrder = 1
    OnClick = OpenButtonClick
  end
  object XmlFileEdit: TEdit
    Left = 8
    Top = 40
    Width = 433
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 2
  end
  object SaveButton: TButton
    Left = 448
    Top = 40
    Width = 58
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Save XML'
    TabOrder = 3
    OnClick = SaveButtonClick
  end
  object XmlMemo: TMemo
    Left = 8
    Top = 72
    Width = 582
    Height = 224
    Anchors = [akLeft, akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object OpenXMLButton: TButton
    Left = 512
    Top = 40
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Open XML'
    TabOrder = 5
    OnClick = OpenXMLButtonClick
  end
  object OpenDialog: TOpenDialog
    Filter = 'MS Access|*.mdb|All files|*.*'
    Left = 560
    Top = 8
  end
  object ADOConn: TADOConnection
    Left = 560
    Top = 72
  end
  object SaveDialog: TSaveDialog
    Filter = 'XML File|*.xml|Text file|*.txt|Any file|*.*'
    Left = 480
    Top = 40
  end
  object OpenXMLDialog: TOpenDialog
    Filter = 'XML Files|*.xml|All files|*.*'
    Left = 560
    Top = 40
  end
end
