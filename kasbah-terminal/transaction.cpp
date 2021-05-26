#include"transaction.h"

Transaction::Transaction(unsigned Idmarchand)
{
	Time tm;
	dateS_ = tm.getDateString();
	date_ = tm.getdate();
	idMarchand_ = Idmarchand;
}
