object ChangeForm: TChangeForm
  Left = 317
  Top = 241
  BorderStyle = bsDialog
  Caption = 'ChangeForm'
  ClientHeight = 177
  ClientWidth = 280
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Button2: TButton
    Left = 40
    Top = 144
    Width = 75
    Height = 25
    Caption = '��'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 136
    Top = 144
    Width = 75
    Height = 25
    Caption = '������'
    ModalResult = 2
    TabOrder = 1
  end
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 265
    Height = 129
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = '�������'
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 101
        Height = 13
        Caption = '������� (��� y=...)'
      end
      object Label2: TLabel
        Left = 8
        Top = 48
        Width = 228
        Height = 39
        Caption = 
          '��������� ��������: +, -, *, /, ^ (��� pow, **), !, sin, cos, tg' +
          ' (+arc*, *h, arc*h), ln, lg, log, sqr, sqrt, abs (���  [ ] ), ' +
          'root (��� //)'
        WordWrap = True
      end
      object Edit1: TEdit
        Left = 8
        Top = 24
        Width = 241
        Height = 21
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = '����� ����������'
      ImageIndex = 1
      object Image1: TImage
        Left = 152
        Top = 7
        Width = 81
        Height = 23
      end
      object Button1: TButton
        Left = 8
        Top = 6
        Width = 129
        Height = 25
        Caption = '���� �������...'
        TabOrder = 0
        OnClick = Button1Click
      end
      object CheckBox1: TCheckBox
        Left = 16
        Top = 35
        Width = 129
        Height = 17
        Caption = '���������� ������'
        TabOrder = 1
      end
      object LineStyle: TRadioGroup
        Left = 8
        Top = 56
        Width = 241
        Height = 41
        Caption = '����� ����������'
        Columns = 2
        ItemIndex = 1
        Items.Strings = (
          '�����'
          '�����')
        TabOrder = 2
      end
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 224
    Top = 144
  end
end
