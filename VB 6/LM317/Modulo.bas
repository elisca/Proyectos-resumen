Attribute VB_Name = "Modulo"

Public Sub Error_Interno_Programa()
    MsgBox "Error interno en el programa. Por favor, no utilice esta calculadora para evitar posibles errores en los cálculos. Disculpe la molestia." + Chr(13) + Chr(13) + "El programa procederá a cerrarse automáticamente.", vbCritical, "Error interno"
    End
End Sub

Public Function Dominio_Definicion(Vout As Double, R1 As Double, R2 As Double, Opcion As Byte) As Double
    Select Case Opcion
        Case 0:
            'Dominio para despejar valor de Vout
            Call Textboxes_Fondo_Blanco
            
            If R2 >= 0 And R1 > 0 Then
                Dominio_Definicion = 1.25 * (1 + R2 / R1)
            Else
                Dominio_Definicion = 0
                Beep
            End If
        
            If Not R2 >= 0 Then
                Form1.Text1(2).BackColor = RGB(255, 0, 0)
            Else
                Form1.Text1(2).BackColor = RGB(255, 255, 255)
            End If
                
            If Not R1 > 0 Then
                Form1.Text1(1).BackColor = RGB(255, 0, 0)
            Else
                Form1.Text1(1).BackColor = RGB(255, 255, 255)
            End If
        
        Case 1:
            'Dominio para despejar valor de R1
            Call Textboxes_Fondo_Blanco
            
            If R2 > 0 And Vout > 1.25 And Vout <= 37 Then
                Dominio_Definicion = R2 / (Vout / 1.25 - 1)
                Form1.Text1(0).BackColor = RGB(255, 255, 255)
                Form1.Text1(2).BackColor = RGB(255, 255, 255)
            Else
                Dominio_Definicion = 0
                Beep
            
                If Not R2 > 0 Then
                    Form1.Text1(2).BackColor = RGB(255, 0, 0)
                Else
                    Form1.Text1(2).BackColor = RGB(255, 255, 255)
                End If
                
                If Vout <= 1.25 Or Vout > 37 Then
                    Form1.Text1(0).BackColor = RGB(255, 0, 0)
                Else
                    Form1.Text1(0).BackColor = RGB(255, 255, 255)
                End If
            End If
        Case 2:
            'Dominio para despejar valor de R2
            Call Textboxes_Fondo_Blanco
            
            If Vout >= 1.25 And Vout <= 37 And R1 > 0 Then
                Dominio_Definicion = (Vout / 1.25 - 1) * R1
            Else
                Dominio_Definicion = 0
                Beep
            
                If Vout < 1.25 Or Vout > 37 Then
                    Form1.Text1(0).BackColor = RGB(255, 0, 0)
                Else
                    Form1.Text1(0).BackColor = RGB(255, 255, 255)
                End If
                
                If Not R1 > 0 Then
                    Form1.Text1(1).BackColor = RGB(255, 0, 0)
                Else
                    Form1.Text1(1).BackColor = RGB(255, 255, 255)
                End If
            End If
        Case Else
            Call Error_Interno_Programa
    End Select
End Function

Sub Textboxes_Fondo_Blanco()
    Form1.Text1(0).BackColor = RGB(255, 255, 255)
    Form1.Text1(1).BackColor = RGB(255, 255, 255)
    Form1.Text1(2).BackColor = RGB(255, 255, 255)
End Sub
