inherit NPC;
#include <ansi.h>


void create()
{
	object armor;
	set_name("�ϻ���", ({ "old gardener","gardener"}) );
	set("gender", "����" );
	set("age", 60+random(10));
	set("long",
		"һ����̬���ӵĻ��������ڸ�����Ļ�����ľ��ˮ��֦��\n");
	set("attitude", "friendly");
	set("class","wudang");	
	set("combat_exp", 2700000);
 	
 	set_temp("xinyoulingxi", 1);
 	set("marks/�����Ϭ",1);       
        
        set_skill("dodge",160);
	set_skill("move",150);
	set_skill("force",120);
	set_skill("lingxi-zhi",160);
	set_skill("sword",150);
	set_skill("taiji-sword",160);
	set_skill("parry",170);
	set_skill("five-steps",150);
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge","five-steps");
	map_skill("sword", "taiji-sword");
	map_skill("parry","taiji-sword");
	map_skill("move","five-steps");
	
	setup();
	
        armor=new("/obj/armor/cloth");
	armor->set_name(RED"���۷�"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
        carry_object(__DIR__"obj/b_scissor")->wield();
}
