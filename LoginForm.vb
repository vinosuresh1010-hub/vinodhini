
Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        If TextBox1.Text = "" Then
            MessageBox.Show("Please enter username")
            TextBox1.Focus()
            Exit Sub

        ElseIf TextBox2.Text = "" Then
            MessageBox.Show("Please enter password")
            TextBox2.Focus()
            Exit Sub
        End If

        If TextBox1.Text = "admin" And TextBox2.Text = "admin" Then
            MessageBox.Show("Welcome admin")
        Else
            MessageBox.Show("Incorrect username or password")
        End If

    End Sub

    Private Sub CheckBox1_CheckedChanged(sender As Object, e As EventArgs) Handles CheckBox1.CheckedChanged

        If CheckBox1.Checked = True Then
            TextBox2.PasswordChar = ChrW(0)
        Else
            TextBox2.PasswordChar = "*"c
        End If

    End Sub

End Class
