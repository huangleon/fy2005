#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"������ʮ���ơ��𾪰���ɣɣɡ�"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));
				set("value", 500);
                set("no_split",1);
                set("unit", "��");
                set("material", "paper");
                set("required_class","beggar");
                set("teaching", "baili");
				set("required_exp", 4000000);
				set("required_skill", "begging");
                set("required_skill_level",170);
				set("grade",3);
        }
}

