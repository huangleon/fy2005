// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "�Žر�", ({ "whip" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "skin");
        }
        init_whip(10);

        set("wield_msg", "$N����������һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");

        setup();
}

