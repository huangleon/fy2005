// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("����", ({ "die chai", "chai" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ͨ����̵������Ͼ��������һ������������С�۵���\n");
		set("unit", "��");
		set("value", 1000);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

		set("female_only", 1);

	}
	::init_head();
}

