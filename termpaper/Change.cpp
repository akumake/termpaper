#include "Change.h"
#include "Main.h"
#include "Functions.h"
#include "MyForm.h"


unsigned int track;


System::Void termpaper::Change::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    track = atoi(String_to_string(textBox1->Text).c_str());
    
}

System::Void termpaper::Change::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!isBusyTrack(track))
        MessageBox::Show("There is no such track!");
    else
    {
        changeDataInFile(track);

        MyForm^ frm = gcnew MyForm;

        this->Hide();
        frm->Show();
    }
}

System::Void termpaper::Change::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
    Main^ frm = gcnew Main;
    this->Hide();
    frm->Show();
}
