#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name("������", ({ "basket", "flower basket" }) );
	set_weight(500);
    if( clonep() )
		set_default_object(__FILE__);
  	else {
		set("long", "һ��ʢ���ʻ���С������\n");
		set("prep", "in");
        set("unit", "��");
        set("value", 20);
        set("material", "wood");
    }
	::init_hammer(1);
}

