// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "����ʯ", ({ "stone"}) );
    set("unit", "��");
    set("value",3000);
    set("long","����һ���ĥ�úܹ�Ĵ���ʯ��\n");
    set_weight(10000);
	::init_item();
}
