// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create() {
    	set_name(YEL"��˿����"NOR, ({ "golden gloves","gloves"}));
    	set_weight(5);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
        	set("long", "һ˫��˿��ɵ����ף��ʵ���������Ȼ�۸�Ҳ���ơ���\n");
        	set("value", 90000);
		set("material", "cloth");
	}
    	::init_hands();
}

