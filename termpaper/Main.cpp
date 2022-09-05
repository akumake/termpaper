#include "Main.h"
#include "Add.h"
#include "Change.h"
#include "Delete.h"
#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;

std::vector<Train> check;
Train t;

[STAThreadAttribute]


int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);


	termpaper::Main form;
	Application::Run(% form);
 }

System::Void termpaper::Main::Main_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void termpaper::Main::groupBox1_Enter(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void termpaper::Main::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	Add^ frm = gcnew Add;
	this->Hide();
	frm->Show();
}

System::Void termpaper::Main::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
	Change^ frm = gcnew Change;
	this->Hide();
	frm->Show();
}

System::Void termpaper::Main::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	Delete^ frm = gcnew Delete;
	this->Hide();
	frm->Show();
}

System::Void termpaper::Main::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
		
}

System::Void termpaper::Main::buttonShow_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	
	if (init() == 0)
		MessageBox::Show("Non element");
	else
	{

		dataGridView1->RowCount = init();
		dataGridView1->ColumnCount = 7;

		check = readAll();
		for (size_t i = 0; i < init(); i++)
		{
			dataGridView1->Rows[i]->Cells[0]->Value = string_to_String(std::to_string(check[i].trackNumber));
			dataGridView1->Rows[i]->Cells[1]->Value = string_to_String(std::to_string(check[i].flightNumber));
			dataGridView1->Rows[i]->Cells[2]->Value = string_to_String(check[i].arrivalTime);
			dataGridView1->Rows[i]->Cells[3]->Value = string_to_String(check[i].placeOfDeparture);
			dataGridView1->Rows[i]->Cells[4]->Value = string_to_String(check[i].placeOfArrival);
			dataGridView1->Rows[i]->Cells[5]->Value = string_to_String(check[i].departureTime);
			dataGridView1->Rows[i]->Cells[6]->Value = string_to_String(check[i].conditionOfTheTrain);
		}
	}

}

