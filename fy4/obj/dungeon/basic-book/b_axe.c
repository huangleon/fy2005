#include <ansi.h>
inherit "/obj/dungeon/draft.c";

void create()
{
        set_name("��������", ({ "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","С���ӻ�������趯���ӵ�С�ˣ����������ȥ����������master��\n");
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
                set("material", "paper");
                
                set("teaching", "axe");
		set("teaching_limit", 120);
		set("required_exp", 5000000);
        }
}
