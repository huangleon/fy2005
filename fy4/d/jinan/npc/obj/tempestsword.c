#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("���潣", ({ "myst sword","sword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��׺�ŵ������գ�ӳ�չ⺮�ĳ�����\n");
  				set("no_stack",1);
				set("no_drop",1);
              set("value", 0);
                set("material", "steel");
        }
        ::init_sword(73);
}
