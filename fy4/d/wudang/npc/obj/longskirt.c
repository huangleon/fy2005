#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
//ϼ녲ʾc ��缆�� �����ƺ� ׹����ɴ
void create()
{
	set_name(CYN"����ҹ��"NOR, ({ "longskirt" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "��");
        set("female_only",1);
		set("long","һ��ˮ��ɫ���ɴ��ȹ�������������\n");
	}
	::init_surcoat();
}


int init()
{
//	::init();
	set("armor_worn","����");
}