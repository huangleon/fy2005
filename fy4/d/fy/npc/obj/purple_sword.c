#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��ڤ���齣", ({ "hell sword", "sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "stone");
		set("long", "һ�ѷǽ�����ı������ƺ�͸����ɫ�Ĺ�â��\n");
		set("wield_msg", "$N���һ��͸����ɫ�Ĺ�â�Ľ����������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	::init_sword(1);
}

/*
int query_autoload() { 
	return 1; 
}*/