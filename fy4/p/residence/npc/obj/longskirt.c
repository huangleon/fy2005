#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
	string * msg = ({
	CYN"������ɴ",RED"ϼ�Ʋ��",HIR"���ɴ��",HIB"�����ƺ�",HIR BLK"׹����ɴ",HIW"��Ӱ֯��",MAG"�ϵ�ɴ��",HIR"��������",WHT"��˿����",BLU"ʥ�鷨��",HIB"����ҹ��",HIW"Ʈ������",HIG"ӳ�̺���"
	});
	set_name(msg[random(sizeof(msg))]+NOR, ({ "surcoat" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "��");
        set("female_only",1);
		set("long","һ���ɴ��ȹ�������������\n");
	}
	::init_surcoat();
}


int init()
{
	set("armor_worn","����");
}
