// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "С��ݵĵ���", ({ "diqi","qi"  }) );
    set("unit", "��");
    set("value",200);
    set("long","
С��ݵ���
		----------------
		|�������ظ���ӡ|
		----------------
\n");
    set_weight(1);
	::init_item();
}
