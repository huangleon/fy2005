#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"�������ķ���������Ϣ�ɣɡ�"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 1000);
                set("no_split",1);
                set("unit", "��");
                set("material", "paper");
                set("required_class","taoist");
                set("teaching", "heal");
				set("required_exp", 3000000);
				set("required_skill", "gouyee");
                set("required_skill_level",120);
				set("grade",2);
        }
}

