// necklace.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#include <armor.h>
inherit NECK;

void create() {
	set_name("�춹����", ({ "hongdou necklace", "necklace"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú춹��ɵ�������\n");
		set("unit", "��");
		set("value", 850);
		set("wear_msg", "$N����ذ�$n���ھ��ϡ�\n");
		set("unwield_msg", "$N����ذ�$n�Ӿ��ϳ���������\n");
		set("holiday", "������");
	}
	::init_neck();
}

