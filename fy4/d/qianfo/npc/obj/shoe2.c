// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
        string *order=({"�ֲ�", "�޲�", "����", "ϴ�÷��׵�",
"�಼","�ϲ�","�ڲ�","�ײ�"});
        set_name((order[random(8)]) +"ɮЬ", ({ "monk shoes", "shoes"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("material", "cloth");
				set("value",10);
        }
	::init_boots();
}
