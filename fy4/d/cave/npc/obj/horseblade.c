#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(RED"ն��"NOR, ({ "zhanma blade","blade" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��˵�����ĳ����糤��ն�����Զ�季������쳣��\n");
                set("value", 100);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}
