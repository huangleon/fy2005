inherit NPC;
#include <ansi.h>

void create()
{
	set_name(WHT"���ι���"NOR, ({ "wolf man"}) );
	set("gender", "����" );
	set("age", 30+random(20));
	set("long",
		"һ������Ұ�ɫ�ĳ�ë����֮�������εĹ��������ȻҲ�����㣬����
Χ��һ�鱪Ƥ�����ֳֻ�����ȴ����һֻѪ���ܵĵ�ɽ�ǣ�\n");
	set("attitude", "aggressive");
	set("bellicosity",300000);
	
	set("reward_npc", 1);
	set("difficulty",5);
	set("toughness",160);
	
	set("combat_exp", 4500000);
        
    set_skill("dodge",200);
	set_skill("move",200);
	set_skill("force",200);
	set_skill("lingxi-zhi",160);
	set_skill("hammer",200);
	set_skill("assassin-hammer",180);
	set_skill("parry",200);
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge","hawk-steps");
	map_skill("hammer", "assassin-hammer");
	map_skill("parry","assassin-hammer");
	
	set("no_busy",10);
	setup();
	
	carry_object(__DIR__"obj/wolf_hammer")->wield();
    carry_object(__DIR__"obj/raw_cloth")->wear();
    if (!random(10)) carry_object(BOOKS"hammer_75");
}
