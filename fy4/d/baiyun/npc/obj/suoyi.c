// raincoat.c

#include <armor.h>

inherit SURCOAT;

void create()
{
    set_name("��ˮ��մ���ƾ�����", ({ "rain coat","coat" }) );
    set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "plant");
		set("unit", "��");
                set("long", "���۴��ﵽ����ô��,�ⶼ��һ������ͨ�������ƾ���\n��,����ֵ��Ǵ�������������,ŭ�������о���ˮ��մ.\n");
        set("value", 0);
        set("armor_prop/armor", 10);
	}
	::init_surcoat();
}
