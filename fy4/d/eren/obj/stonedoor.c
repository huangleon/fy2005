// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name( "ʯ��", ({ "door"  }) );
	set("unit", "��");
	set("no_get",1);
	set("value",20);
	set("long","
����һ�ȳ��ص�ʯ�ţ�������һ����״��ȱ��(Hole)��
\n");
	set_weight(5000);
	::init_item();
}
