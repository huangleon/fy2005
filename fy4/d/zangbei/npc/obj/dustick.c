#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(WHT"����"NOR , ({ "jade stick", "stick" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "һ����ף���Ө��͸�ı��ȣ������Ǳ���������һ�����\n"NOR);
        set("value", 100);
		set("class","beggar");
		set("agility",24);
		set("material", "jade");
        	set("wield_msg", "$N���һ��$n�����������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	::init_stick(20);
}
