// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
    	set_name("��Ȫ����", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����ɳ���Ͻ�ʿ����ı�����\n");
        set("value", 1);
		set("material", "steel");
	}
    	init_sword(4);
}
