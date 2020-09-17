object net: Tnet
  Left = 337
  Top = 344
  Width = 568
  Height = 404
  Caption = 'Game networking connection'
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PortServer: TLabel
    Left = 80
    Top = 120
    Width = 48
    Height = 24
    Caption = 'Port'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Cooper Black'
    Font.Style = []
    ParentFont = False
  end
  object PortClient: TLabel
    Left = 296
    Top = 120
    Width = 48
    Height = 24
    Caption = 'Port'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Cooper Black'
    Font.Style = []
    ParentFont = False
  end
  object IPclient: TLabel
    Left = 296
    Top = 184
    Width = 115
    Height = 24
    Caption = 'IP Address'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Cooper Black'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 80
    Top = 48
    Width = 117
    Height = 22
    Caption = 'SERVER'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Goudy Stout'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 312
    Top = 48
    Width = 110
    Height = 22
    Caption = 'CLIENT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Goudy Stout'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 80
    Top = 144
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '2002'
  end
  object Edit2: TEdit
    Left = 296
    Top = 144
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '2002'
  end
  object Edit3: TEdit
    Left = 296
    Top = 208
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '127.0.0.1'
  end
  object Button1: TButton
    Left = 80
    Top = 192
    Width = 81
    Height = 25
    Caption = 'Create'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 296
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 4
    OnClick = Button2Click
  end
end
