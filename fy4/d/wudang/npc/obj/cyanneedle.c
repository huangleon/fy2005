#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
    set_name(CYN"��������"NOR, ({ "cyan needle","needle" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ��ϸ�緢˿������Сָ�ĵ���ɫ���룬���մȾ�˺ֺ�ɫ��Ѫ����\n");
		set("value", 1000);
		set("material", "silver");
	}
    ::init_dagger(20);
}
