#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(MAG"��ö��"NOR, ({ "purple flower", "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������˵���õ�塣\n");
                set("unit", "��");
                set("value", 6);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

                set("female_only", 1);

        }
        ::init_head();
		call_out("wither",600);
}
void wither()
{
	if (query("delivery"))
	{
		set("name","��ή��"+name());
		set("long","��ԭ����һ��"+query("long")+"���������Ѿ���ή�ˡ�\n");
		delete("delivery");
	}
}