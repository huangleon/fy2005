
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIR"�����ƶǵĲ�ȱʬ��"NOR, ({ "slayed corpse"}) );
    set_weight(20000+random(30000));
	set_max_encumbrance(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ�߻�ð�Ų�֪��������Ѫ����ʬ�壬�����ƶǣ��ǽ�һƬ����\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


