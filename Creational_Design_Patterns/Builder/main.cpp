/*Builder is a creational design pattern that lets
you construct complex objects step by step. 
The pattern allows you to produce different
types and representations of an object using the
same construction code.*/

#include <iostream>
#include <string>
using namespace std;

class ReportBuilder
{
protected:
	string document;
public:
	virtual void CreateTitle() = 0 {};
	virtual void CreateText() = 0 {};
	virtual void CreateSigns() = 0 {};

	virtual void Print()
	{
		cout << document << endl;
	}

	virtual ~ReportBuilder() {};
};

class HtmlReportBuilder :public ReportBuilder
{
	virtual void CreateTitle() override
	{
		document.append("<H1>Title Html report</H1>\n");
	}

	virtual void CreateText() override
	{
		document.append("<Content>Title Html report</Content>\n");
	}

	virtual void CreateSigns()override
	{
		document.append("<footer>Title Html report</footer>\n");
	}
};

class PdfReportBuilder :public ReportBuilder
{
	virtual void CreateTitle() override
	{
		document.append("Title pdf report\n");
	}

	virtual void CreateText() override
	{
		document.append("Text pdf report\n");  //add to document
	}

	virtual void CreateSigns()override
	{
		document.append("Signs pdf report\n");
		document.append("Colonttituls\n");
	}
};

class Director
{
public:
	void CreateReport(ReportBuilder& builder)  //director create report by using builder's interface
	{
		builder.CreateTitle();
		builder.CreateText();
		builder.CreateSigns();
	}
};


int main() {

	HtmlReportBuilder report;

	Director director;
	director.CreateReport(report);
	report.Print();


	PdfReportBuilder report2;
	director.CreateReport(report2);
	report.Print();

	system("pause");
	return 0;
}