VERSION 5.00
Begin VB.Form Form1 
   AutoRedraw      =   -1  'True
   BackColor       =   &H00FFFFFF&
   Caption         =   "Screenshot"
   ClientHeight    =   1890
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   3780
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1890
   ScaleWidth      =   3780
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer Timer1 
      Interval        =   1
      Left            =   120
      Top             =   1320
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "?"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   3120
      TabIndex        =   3
      Top             =   1320
      Width           =   495
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Use la captura pegando con (Ctrl + V) la imagen"
      Height          =   195
      Index           =   2
      Left            =   0
      TabIndex        =   2
      Top             =   960
      Width           =   3855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Presione (W) para capturar la ventana activa"
      Height          =   195
      Index           =   1
      Left            =   0
      TabIndex        =   1
      Top             =   600
      Width           =   3855
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Presione (Q) para capturar la pantalla completa"
      Height          =   195
      Index           =   0
      Left            =   0
      TabIndex        =   0
      Top             =   240
      Width           =   3855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Sub keybd_event Lib "user32" (ByVal bVk As Byte, ByVal bScan As Byte, ByVal dwFlags As Long, ByVal dwExtraInfo As Long)
Private Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Long) As Integer

Private Sub Form_Resize()
    If Me.WindowState = 0 Then
        Me.Width = 4020
        Me.Height = 2460
    End If
End Sub

Private Sub Label2_Click()
    MsgBox "Use este programa para capturar el estado de las ventanas que desee. Presione la tecla ""Q"" para capturar una imagen de la pantalla completa, o la tecla ""W"" para capturar sólo la ventana abierta que usted haya seleccionado, sin tener necesidad de que la ventana que esta activa sea la de este programa (este programa puede estar minimizado mientras lo usa)." & Chr(13) & Chr(13) & "Cuando haya realizado la captura de la imagen, puede editarla o guardarla pegándola en algún editor de imágenes, como el Paint por ejemplo. Para esto, presiona simultáneamente las teclas ""Ctrl"" y ""V"", o haga clic en el menú ""Edición"" y cliquee en ""Pegar""." & Chr(13) & Chr(13) & "Creado por Ezequiel Lisca." & Chr(13) & Chr(13) & "Mayo de 2011", vbInformation, "Acerca de este programa"
End Sub

Private Sub Timer1_Timer()
    On Error Resume Next
    If GetAsyncKeyState(vbKeyQ) Then
        'Captura toda la pantalla
        keybd_event 44, 0, 0&, 0&
    ElseIf GetAsyncKeyState(vbKeyW) Then
        'Captura la ventana activa
        keybd_event 44, 1, 0&, 0&
    End If
End Sub
