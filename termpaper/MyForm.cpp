#include "MyForm.h"
#include "Main.h"
#include "Change.h"
#include "Functions.h"

Train train1;

System::Void termpaper::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e){}

System::Void termpaper::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
 
    train1.flightNumber = atoi(String_to_string(textBox1->Text).c_str());
    train1.arrivalTime = String_to_string(textBox2->Text);
    train1.departureTime = String_to_string(textBox3->Text);
    train1.placeOfDeparture = String_to_string(textBox4->Text);
    train1.placeOfArrival = String_to_string(textBox5->Text);
    train1.conditionOfTheTrain = String_to_string(textBox6->Text);
    train1.trackNumber = atoi(String_to_string(textBox7->Text).c_str());

    if (isBusyTrack(train1.trackNumber))
        MessageBox::Show("Track is busy!");
    else if (!isCorrectTime(train1.arrivalTime, train1.departureTime))
        MessageBox::Show("Incorrect time!");
    else if (isCorrectTrack(train1.trackNumber))
        MessageBox::Show("Incorrect track number!");
    else if (isBusyFlight(train1.flightNumber))
        MessageBox::Show("Incorrect flight number!");
    else
    {
        writeData(train1);
        MessageBox::Show("Data was changed");
        Change^ frm = gcnew Change;
        this->Hide();
        frm->Show();
    }
}

System::Void termpaper::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
        readForChange(train1);
        writeData(train1);
        Main^ frm = gcnew Main;
        this->Hide();
        frm->Show();
}

System::Void termpaper::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    readForChange(train1);
    textBox1->Text = string_to_String(std::to_string(train1.flightNumber));
    textBox2->Text = string_to_String(train1.arrivalTime);
    textBox3->Text = string_to_String(train1.departureTime);
    textBox4->Text = string_to_String(train1.placeOfDeparture);
    textBox5->Text = string_to_String(train1.placeOfArrival);
    textBox6->Text = string_to_String(train1.conditionOfTheTrain);
    textBox7->Text = string_to_String(std::to_string(train1.trackNumber));
}
