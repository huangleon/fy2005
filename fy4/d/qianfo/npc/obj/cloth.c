// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"�ֲ�", "�޲�", "����", "ϴ�÷��׵�",
"�಼","�ϲ�","�ڲ�","�ײ�"});
        set_name((order[random(8)]) +"ɮ��", ({ "monk cloth", "cloth"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("value",20);
        }
        ::init_cloth();
}
