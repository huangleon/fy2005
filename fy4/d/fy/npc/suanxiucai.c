#include <ansi.h>
inherit  NPC;

void  create()
{
	set_name("�����",  ({"suan xiucai","suan","xiucai"}));
//	set("title","С���");
	set("age",  22);
	set("gender",  "����");
	set("long", "���˱������飬��ϧ���Ų����������Űܡ�\n");
	set("attitude",  "peaceful");
	set("NO_KILL",1);
	set("combat_exp",  8000);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

