#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"��Ѫսǹ���������ʯ�ɣɣɡ�"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "��");
                set("material", "paper");
                set("required_class","fugui");
                set("teaching", "liguangsheshi");
				set("required_exp", 5100000);
				set("required_skill", "xuezhan-spear");
                set("required_skill_level",230);
				set("grade",3);
        }
}

