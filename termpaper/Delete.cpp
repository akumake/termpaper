#include "Delete.h"
#include "Main.h"
#include "Functions.h"

unsigned int flight;

System::Void termpaper::Delete::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
   
    flight = atoi(String_to_string(textBox1->Text).c_str());
}

System::Void termpaper::Delete::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!isBusyFlight(flight))
        MessageBox::Show("There is no such flight!");
    else
    {
        deleteFromFile(flight);
        textBox1->Text = "";
    }
}

System::Void termpaper::Delete::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
    Main^ frm = gcnew Main;
    this->Hide();
    frm->Show();
}
