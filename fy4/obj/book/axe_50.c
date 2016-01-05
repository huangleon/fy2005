// spear_book.c

inherit ITEM;

void create()
{
	set_name("�������", ({ "axebook","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long",
			"���Ǳ���ֽ�Ƶ��飬��������Լ�ɼ���������顱�ĸ�ӬͷС����\n"
			);
		set("value", 50);
		set("no_drop",1);
		set("material", "paper");
		set("skill", ([
			"name": 	"axe",		
			"exp_required":	0,			
			"sen_cost":		2,				
			"difficulty":	10,				
			"max_skill":	49				
		]) );
	}
	::init_item();
}
