inherit NPC;
#include <ansi.h>
void smart_fight();

void create()
{
	set_name("��ʤ��", ({ "jin bo"}) );
	set("gender", "����" );
	set("title",HIY"�������"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long",
		"���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
		);
	set("class","lama");
    set("combat_exp", 4000000);
    set("score", 900);
    set("reward_npc", 1);
	set("difficulty",5);
		
	set("no_busy",4);

	set("chat_chance", 1);
        set("chat_msg", ({
                "��ʤ��˵���ٺ٣���ʵ���ֻ����С�ӣ������ֵ����������ܸĳɡ��ƺ�����
�ǿ�������˼��\n",
                }) );
     
	set("inquiry", 	([
		"�ϻ�����":	"ʲô�ϲ��ϵģ����Ƕ�����ʦ�ֵġ�\n",
		"��ʦ��":	"��ʦ�־������Ǻ�������е��̵��ڶ���\n",		
		]));
		  
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("yue-strike", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("jin-gang",200);
	set_skill("perception",180);
	set_skill("nodust-steps",200);
	set_skill("dodge",200);
	map_skill("dodge","nodust-steps");
	map_skill("iron-cloth","jin-gang");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "yue-strike");
	map_skill("force", "bolomiduo");
    	
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/

	setup();
    carry_object(__DIR__"obj/lamacloth1")->wear();
    carry_object(__DIR__"obj/ring2")->wear();
        
}

void win_enemy(object loser)
{
	say("��ʤ�Ĺ���һЦ˵������˵����˵��\n");

}
