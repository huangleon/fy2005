#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"��˪�����ᡤ��һ��"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

				set("value", 1000);
                set("unit", "��");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "shuanghuaningjie");
				set("required_exp", 1000000);
				set("required_skill", "snowforce");
                set("required_skill_level",60);
				set("grade",1);
        }
}

