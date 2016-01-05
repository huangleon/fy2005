// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
#include <ansi.h>
inherit F_LIQUID;
void create()
{
    set_name(HIB "ҹ�Ɑ" NOR,({"yeguangbei"}));
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ��ʢ�����ʺ���Ѫ���������Ƶ�ҹ�Ɑ��\n");
		set("unit", "��");
        set("value", 0);
        set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
        "type": "alcohol",
        "name": "��������",
		"remaining": 5,
        "drunk_apply": 20,
	]) );
}
