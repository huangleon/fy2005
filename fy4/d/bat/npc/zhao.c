// zhao.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("�Ը�", ({ "zhao", "zhao gang" }) );
	set("title", HIY "���ƿ���" NOR);
	set("long","
���������ƿ����Ըգ��书֮ǿ���ѿ����ǽ����е�һ������,
����Ӳ������ǿ�Ĵ�ˤ���֡�
\n" );

	set("gender", "����" );
	set("class", "wudang");
	set("age", 42);
	set("reward_npc", 1);
	set("difficulty", 3);
	
	set("attitude", "peaceful");
	set_skill("unarmed", 300);
	set_skill("shuaibei", 200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("five-steps",200);
	set_skill("move",200);
	
 	map_skill("unarmed", "shuaibei");
 	map_skill("dodge","five-steps");
 	map_skill("move","five-steps");
	map_skill("parry", "shuaibei");
	 	
 	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
  		(: perform_action, "dodge.bazhentu" :),
  		}) ); 
 	 	 	
	set("combat_exp", 4800000);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	if (!random(10)) carry_object(BOOKS"unarmed_75");
}
