// movebook.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"����"NOR, ({ "yu pai", "pai" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ���������ƣ��������һ�������Ů�ˡ�\n");
		set("value", 0);
		set("material", "jade");
		set("skill", ([
			"name": 		"yuxiao",	
			"exp_required":	1000000,				
			"sen_cost":		50,				
			"difficulty":	75,		
			"max_skill":	51,		
		]) );
	}
}
