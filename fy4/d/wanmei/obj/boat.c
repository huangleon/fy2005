// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ITEM;
void create() 
{
    set_name( "Сľ��", ({ "boat","little boat"  }) );
    set("unit", "��");
    set("value",20);
    set("floating",1);
    set("long","һ��СС��Сľ����\n");
    set_weight(150000);
    ::init_item();
}
