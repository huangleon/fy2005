// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "����", ({ "freshfish","fish"  }) );
    set("unit", "��");
    set("value",8);
    set("long","
һ���Ϻõ�����
\n");
    set_weight(5);
	::init_item();
}
