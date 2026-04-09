#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "clsDate.h"

using namespace std;

class clsQueueLine
{
	short _TotalTickets;
	short _AverageServeTime;
	string _Prefix;

	class clsTicket
	{
		string _FullNumber;
		string _TicketTime;
		short _WaitingClients;
		short _ExpectedServeTime;

	public:

		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_FullNumber = Prefix + to_string(Number);
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_ExpectedServeTime = AverageServeTime * WaitingClients;
		}

		string FullNumber()
		{
			return _FullNumber;
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		short ExpectedServeTime()
		{
			return _ExpectedServeTime;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << TicketTime();
			cout << "\n\t\t\t    Wating Clients = " << WaitingClients();
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}
	};

public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0;
	}

	short WaitingClients()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.\n";
		else
			return QueueLine.front().FullNumber();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\t\tTickets : ";

		if (QueueLine.empty())
		{
			cout << "No Tickets.\n";
			return;
		}

		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			cout << " " << TempQueueLine.front().FullNumber() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\t\tTickets : ";

		if (QueueLine.empty())
		{
			cout << "No Tickets.\n";
			return;
		}

		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());

			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			cout << " " << TempStackLine.top().FullNumber() << " --> ";

			TempStackLine.pop();
		}

		cout << "\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
		{
			cout << "\n\n\t\t\t     ---No Tickets---\n";
			return;
		}

		queue <clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();

			TempQueueLine.pop();
		}
	}
};