inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("�ײ�", ({ "coffin","�ײ�" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
		set("long","һ��ո�µĹײģ����Ӵ��š�\n");
		set("prep","on");
	}
	
	::init_item();
}


int is_container() { return 1; }

