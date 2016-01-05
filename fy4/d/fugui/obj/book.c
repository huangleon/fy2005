// spear_book.c

inherit ITEM;

void create()
{
	set_name("ǹ�����", ({ "spearbook","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long",
			"���Ǳ���ֽ�Ƶ��飬��������Լ�ɼ���ǹ����顱�ĸ�ӬͷС����\n"
			);
		set("value", 1);
		set("material", "paper");
		set("skill", ([
			"name": 	"spear",		
			"exp_required":	0,			
			"sen_cost":	10,				
			"difficulty":	10,				
			"max_skill":	50				
		]) );
	}
	::init_item();
}
