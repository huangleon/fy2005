
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIW"��ʬ"NOR, ({ "frozen corpse" , "corpse"}) );
    set_weight(20000+random(30000));
	set_max_encumbrance(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�߱����ⶳס��ʬ��,��Ŀ����,�ƺ��㶼���Ըо�������ʱ�Ŀ־�..\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


