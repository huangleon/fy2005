#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
        set_name(CYN"����ѩ��ᰡ���Ҫ��"NOR, ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: description() :));

				set("value", 1000);
                set("unit", "��");
                set("material", "paper");

                set("required_class","moon");

                set("teaching", "hanxueliulan");
				set("required_exp", 6400000);
				set("required_skill", "stormdance");
                set("required_skill_level",200);
				set("grade",4);
        }
}

