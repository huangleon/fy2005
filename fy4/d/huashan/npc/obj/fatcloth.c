// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(BLU"�����"NOR, ({"silk cloth", "cloth"}) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long", "
һ���޴�ĳ�����ӣ��Ϻõĳ���������Щ���µĻ��ݡ�һ����֪��
�ۼ۲�������ȴ�������������Ρ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",1000);
    }
    ::init_cloth();
}
