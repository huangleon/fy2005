inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
	set_name("���޸���", ({ "bo luo"}) );
	set("gender", "����" );
	set("title",HIY"�������"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long","���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n");
	set("class","lama");
    set("combat_exp", 4300000);
    set("score", 900);
    set("reward_npc", 1);
	set("difficulty",5);
	set("no_busy",6);

	
	set("inquiry", 	([
		"�ϻ�����":	"ʲô�ϲ��ϵģ����Ƕ�����ʦ�ֵġ�\n",
		"��ʦ��":	"��ʦ�־������Ǻ�������е��̵��ڶ���\n",		
		]));
			
		
	set("chat_chance", 1);
    set("chat_msg", ({
                "���޸���˵���ٺ٣���ʵ���ֻ����С�ӣ������ֵ����������ܸĳɡ��ƺ�����
�ǿ�������˼��\n",
                }) );
        
    set_skill("perception",180);
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("lingxi-zhi", 160);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("jin-gang",150);
	set_skill("move",400);
	set_skill("nodust-steps",200);
	set_skill("dodge",200);
	map_skill("dodge","nodust-steps");	
	map_skill("iron-cloth","jin-gang");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	
	setup();
    carry_object(__DIR__"obj/lamacloth1")->wear();
    carry_object(__DIR__"obj/ring3")->wear();
        
}

void win_enemy(object loser)
{
	say("���޸������һЦ˵������˵����˵��\n");

}
