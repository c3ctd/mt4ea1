#property copyright "��˹����"
#property link      "��˹����"
extern datetime �ҵ����ص���ʱ��;
extern int �ҵ��۾��뵱ʱ�ּ۵��� = 100;
extern int �ҵ���Ч������ = 10;
extern double �ҵ��µ���;
extern int �ҵ�ֹ����� = 70;
extern int �ҵ�ֹӯ����;
extern int �ҵ��ɽ����ƶ�ֹ�����;
extern int magic = 405215;
datetime dangshi = 0;
int sells = 0;
int buys = 0;
int end = 0;


int kaidanok = 0;
int kaiguan = 0;
int ticket = 0;

int init()
{
	DrawLabel("will1", "sell is better", 2, 13, "����", 9, Aqua, 0);
	dangshi = TimeLocal();
	return(0);
}
int deinit()
{
	return(0);
}
int start()
{


	if (�ҵ����ص���ʱ��<dangshi)
		if (end == 0)
		{
			Alert("����ҵ�ʱ���Ѿ����˻���ô�ҵ�");
			end = 1;
		}






	if (�ҵ����ص���ʱ�� <= TimeLocal())
		if (end != 1)
		{
			sells = OrderSend(Symbol(), OP_SELLSTOP, �ҵ��µ���, Bid - �ҵ��۾��뵱ʱ�ּ۵���*Point, 70, Ask + �ҵ�ֹ�����*Point, 0, 0, magic, TimeLocal() + �ҵ���Ч������ * 60, White);
			buys = OrderSend(Symbol(), OP_BUYSTOP, �ҵ��µ���, Ask + �ҵ��۾��뵱ʱ�ּ۵���*Point, 70, Ask - �ҵ�ֹ�����*Point, 0, 0, magic, TimeLocal() + �ҵ���Ч������ * 60, White);
		}


	for (int i = 0; i<OrdersTotal(); i++)
	{
		if (OrderSelect(i, SELECT_BY_POS, MODE_TRADES) == TRUE)
			end = 1;
	}

	if (sells == -1 && buys == -1)
		end = 0;

	Comment("sells=", sells, "buys=", buys, "end=", end);
	return(0);
}
/*
void yidong()
{
for(int i=0;i<OrdersTotal();i++)//�ƶ�ֹ��ͨ�ô���,�δ�����Զ����buy��sell���������ƶ�ֹ��
{
if(OrderSelect(i,SELECT_BY_POS,MODE_TRADES)==true)
{
if(OrderType()==0 && OrderSymbol()==Symbol() && OrderMagicNumber()==magic)
{
if((Bid-OrderOpenPrice()) >=Point*�ҵ��ɽ����ƶ�ֹ�����)
{
if(OrderStopLoss()<(Bid-Point*�ҵ��ɽ����ƶ�ֹ�����) || (OrderStopLoss()==0))
{
OrderModify(OrderTicket(),OrderOpenPrice(),Bid-Point*�ҵ��ɽ����ƶ�ֹ�����,0,0,Green);
}
}
}
if(OrderType()==1 && OrderSymbol()==Symbol() && OrderMagicNumber()==magic)
{
if((OrderOpenPrice()-Ask)>=(Point*�ҵ��ɽ����ƶ�ֹ�����))
{
if((OrderStopLoss()>(Ask+Point*�ҵ��ɽ����ƶ�ֹ�����)) || (OrderStopLoss()==0))
{
OrderModify(OrderTicket(),OrderOpenPrice(),Ask+Point*�ҵ��ɽ����ƶ�ֹ�����,0,0,Red);
}
}
}
}
}
}
*/
void DrawLabel(string name, string text, int X, int Y, string FontName, int FontSize, color FontColor, int zhongxin)
{
	if (ObjectFind(name) != 0)
	{
		ObjectDelete(name);
		ObjectCreate(name, OBJ_LABEL, 0, 0, 0);
		ObjectSet(name, OBJPROP_CORNER, zhongxin);
		ObjectSet(name, OBJPROP_XDISTANCE, X);
		ObjectSet(name, OBJPROP_YDISTANCE, Y);
	}
	// ObjectSetText(name,text,FontSize,FontName,FontColor);
	WindowRedraw();
}