// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "СԲ����", ({ "mirror","small mirror"  }) );
    set("unit", "��");
    set("value",200);
    set("long","һ��ԲԲ��С���ӣ�һ������Ů���õĶ�����\n");
    set_weight(10);
	::init_item();
}
