// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("������ĵ�ͷ��", ({ "gangster" }) );
	set("gender", "����" );
	set("age", 27);
	set("long", "�������ר���ڳ���������ҵ�����ط��ߵġ�\n");
	set("combat_exp", 10000);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		"������ĵ�ͷ�ߺȵ������Ӿ��ǿ��㲻˳�ۣ�����ô�ţ�\n",
		(: random_move :)
	}) );
	
	set("leave_msg", "���տ���");
	
	setup();
	
	carry_object("/obj/armor/cloth")->wear();

}
