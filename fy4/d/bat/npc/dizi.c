// dizi.c

#include <ansi.h>

inherit NPC;
void create()
{

    	set_name("���𵺵���", ({ "dizi"}) );
	set("long", "����һλ����ר�ŵ��α���֮��ĵ��ӡ�\n");
	set("attitude", "friendly");

	set("combat_exp", 500000+random(500000));
	set_skill("sword", 70+random(70));
	set_skill("parry", 70+random(70));
	set_skill("dodge", 70+random(70));
	set_skill("move", 70+random(70));

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{
 	::init();
 	if( interactive(this_player()) && !is_fighting() && !random(4)&& this_player()->query("class")!="bat") {
  		message_vision("\n$N��Ȼ��$n���һ����ʲô�˾����ڴ��Ҵ���������\n",this_object(),this_player());
  		this_object()->kill_ob(this_player());
 	}
}
