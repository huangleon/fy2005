inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT"�����"NOR, ({ "jade statue", "statue"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"һ�����Ϻõİ����ɵķ���\n");
		set("value", 500000);
		set("material", "steel");
		set("skill", ([
			"name": 	"buddhism",	
			"exp_required":	1000000,		
			"sen_cost":	50,	
			"difficulty":	50,	
			"max_skill":	49		
		]) );
	}
	::init_item();
}
