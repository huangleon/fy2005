// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create()
{
    set_name( "СϺ", ({ "shrimp","small shrimp"  }) );
    set("unit", "��");
    set("value",5);
	set("fish_bait", 1);
    set("long","
һ�����������СϺ��
\n");
    set_weight(1);
	::init_item();
}
