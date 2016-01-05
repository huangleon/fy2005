// gloves.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>

#include <armor.h>
inherit HANDS;

void create() {
    set_name(HIC"ժ����"NOR, ({ "zhaixin-shou"}));

    set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
        set("material", "��˿");
        set("wear_msg", "$N˫��С������ذ�һ˫�����˿���$n�������ϡ�\n");
        set("unwield_msg", "$NС������ذ�$n�����ϳ����������������뻳�С�\n");
        set("long", HIW
"һ˫��ɫ��˿֯���ף�ƽƽ�����������ر�֮��������ֻ�����Ϸֱ�����һ������ŤŤ��ʫ��
����Ϊ�������ǣ������ǣ���������ժ������Ϊ�����н����н����������ͣ��Ա�����
�����µ�һ͵  ˾��ժ�ǡ��ݴ������ױ�Ϊ��ɽ��֮�����������˾��֮���䣬��˾
��ժ�Ǿ�̽��ɽɯ��ƺ�����á�\n"NOR);
        set("value", 0);
        set("armor_prop/armor", 2);
		set("material", "cloth");
	}
	::init_hands();
}

