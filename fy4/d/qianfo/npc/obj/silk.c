// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
    set_name(HIR"��"+HIY"��"+HIG"˿�д�"NOR, ({ "silk", "rainbow silk" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("long","�����߲�˿�д���������������ֹ�â��һ�����ǲ���֮Ʒ��\n");
		set("material", "silk");
		set("realsilk",1);
		set("value",150);
		set("armor_prop/spirituality",3);
    }
    ::init_waist();
}
