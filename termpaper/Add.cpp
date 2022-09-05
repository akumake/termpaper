#include "Add.h"
#include "Main.h"
#include "Functions.h"

using namespace System::Runtime::InteropServices;

 Train train;




System::Void termpaper::Add::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{

    if (isBusyTrack(train.trackNumber))
        MessageBox::Show("Track is busy!");
    else if (!isCorrectTime(train.arrivalTime, train.departureTime))
        MessageBox::Show("Incorrect time!");
    else if (isCorrectTrack(train.trackNumber))
        MessageBox::Show("Incorrect track number!");
    else if (isBusyFlight(train.flightNumber))
        MessageBox::Show("Incorrect flight number!");
    else
    {
        writeData(train);
        MessageBox::Show("Data about train was add!");
        textBox1->Text = "";
        textBox2->Text = "";
        textBox3->Text = "";
        textBox4->Text = "";
        textBox5->Text = "";
        textBox6->Text = "";
        textBox7->Text = "";
    }
   
}

System::Void termpaper::Add::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
        Main^ frm = gcnew Main;
        this->Hide();
        frm->Show();
}

System::Void termpaper::Add::textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.trackNumber = atoi(String_to_string(textBox7->Text).c_str());
}

System::Void termpaper::Add::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.flightNumber = atoi(String_to_string(textBox1->Text).c_str());
}

System::Void termpaper::Add::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.arrivalTime = String_to_string(textBox2->Text);

}

System::Void termpaper::Add::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.departureTime = String_to_string(textBox3->Text);
}

System::Void termpaper::Add::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.placeOfDeparture = String_to_string(textBox4->Text);
}

System::Void termpaper::Add::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.placeOfArrival = String_to_string(textBox5->Text);
}

System::Void termpaper::Add::textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    train.conditionOfTheTrain =  String_to_string(textBox6->Text);
}
