#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"��������ƽǹ�������������ɣɡ�"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 800);
                set("no_split",1);
                set("unit", "��");
                set("material", "paper");
                set("required_class","official");
                set("teaching", "juechufengsheng");
				set("required_exp", 5000000);
				set("required_skill", "yue-spear");
                set("required_skill_level",160);
				set("grade",2);
        }
}

