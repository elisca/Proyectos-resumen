VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Calculadora de Divisor de Tensión Resistivo"
   ClientHeight    =   3525
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   5625
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3525
   ScaleWidth      =   5625
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Calcular"
      Default         =   -1  'True
      Height          =   375
      Left            =   4200
      TabIndex        =   8
      Top             =   2160
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Appearance      =   0  'Flat
      Height          =   285
      Index           =   3
      Left            =   4080
      TabIndex        =   7
      Top             =   1680
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Appearance      =   0  'Flat
      Height          =   285
      Index           =   2
      Left            =   4080
      TabIndex        =   6
      Top             =   1080
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Appearance      =   0  'Flat
      Height          =   285
      Index           =   1
      Left            =   4080
      TabIndex        =   5
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Appearance      =   0  'Flat
      Height          =   285
      Index           =   0
      Left            =   4080
      TabIndex        =   4
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Paulo_17"
      ForeColor       =   &H8000000C&
      Height          =   195
      Left            =   4200
      TabIndex        =   9
      Top             =   3240
      Width           =   675
   End
   Begin VB.Line Line2 
      X1              =   120
      X2              =   5520
      Y1              =   3120
      Y2              =   3120
   End
   Begin VB.Line Line1 
      X1              =   3240
      X2              =   5280
      Y1              =   1560
      Y2              =   1560
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "V. Out:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   3
      Left            =   3150
      TabIndex        =   3
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "R2:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   2
      Left            =   3300
      TabIndex        =   2
      Top             =   1080
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "R1:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   1
      Left            =   3330
      TabIndex        =   1
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "V. In:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   0
      Left            =   3240
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
   Begin VB.Image Image1 
      Height          =   2670
      Left            =   240
      Picture         =   "Form1.frx":0000
      Top             =   240
      Width           =   2670
   End
   Begin VB.Shape Shape1 
      BackStyle       =   1  'Opaque
      Height          =   2655
      Left            =   120
      Top             =   240
      Width           =   2895
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Text1(3).Text = Div_Ten_Res_Calc(CSng(Text1(0).Text), CSng(Text1(1).Text), CSng(Text1(2).Text))
End Sub

Private Function Div_Ten_Res_Calc(Vin As Single, Resistor1 As Single, Resistor2 As Single) As Single
    Dim Error As Boolean
    
    Error = False
    
    If Vin < 0 Then
        MsgBox "El voltaje de entrada es negativo. Por favor, ingrese una tensión de entrada positiva e intente de nuevo.", vbExclamation, "Error: Vin negativo"
        Error = True
    ElseIf Vin = 0 Then
        MsgBox "El voltaje de entrada es neutro. Por favor, ingrese una tensión de entrada positiva e intente de nuevo.", vbExclamation, "Error: Vin neutro"
        Error = True
    End If
    
    If Resistor1 < 0 Then
        MsgBox "La resistencia 1 tiene valor negativo. Por favor, ingrese una resistencia eléctrica positiva e intente de nuevo.", vbExclamation, "Error: Resistencia 1 negativa"
        Error = True
    ElseIf Resistor1 = 0 Then
        MsgBox "La resistencia 1 tiene valor neutro. Por favor, ingrese una resistencia eléctrica positiva e intente de nuevo.", vbExclamation, "Error: Resistencia 1 neutra"
        Error = True
    End If
    
    If Resistor2 < 0 Then
        MsgBox "La resistencia 2 tiene valor negativo. Por favor, ingrese una resistencia eléctrica positiva e intente de nuevo.", vbExclamation, "Error: Resistencia 2 negativa"
        Error = True
    ElseIf Resistor2 = 0 Then
        MsgBox "La resistencia 2 tiene valor neutro. Por favor, ingrese una resistencia eléctrica positiva e intente de nuevo.", vbExclamation, "Error: Resistencia 2 neutra"
        Error = True
    End If
    
    If Error = False Then
        Div_Ten_Res_Calc = Resistor2 / (Resistor2 + Resistor1) * Vin
    Else
        Div_Ten_Res_Calc = 0
        Beep
    End If
End Function
