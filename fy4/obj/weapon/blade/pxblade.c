// blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit LONG_BLADE;

void create() {
        set_name(HIY"��ɽ��"NOR, ({ "blade" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("level_required",120);
                set("material", "iron");
        }
        ::init_blade(105);
}

