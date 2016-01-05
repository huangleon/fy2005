// bottle.c
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name(HIW"�������«"NOR, ({ "white calabash", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "����һ���������Ƴɵľƺ�«������ɢ����Ѫ��ɫ���������Ƶ�ɫ��\n");
		set("unit", "��");
        set("value", 200);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
        "name": "��������",
		"remaining": 60,
         "drunk_apply": 10,
	]) );
}
