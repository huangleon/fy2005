// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(MAG"嫺�����"NOR, ({ "yunblade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
            	set("long", "����һ������ѩ���ĳ��������м�������Ѫ��������
������ƥ��ӳ��������\n");
//		set("value", 0);
		set("material", "iron");
		set("agility",30);
		set("wield_msg", "ֻ�������һ����嫺��������ʷɳ�������Ծ��$N
���С�˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n");
        	set("unwield_msg", "嫺������������ԣ�৵�һ���ɻ����ڡ�\n");
	}
	::init_blade(1);
}
