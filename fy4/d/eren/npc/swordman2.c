#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("��ƽ",({"yang ping","yang"}));
    	set("title","���а���");
	set("long", "���а���֮�ף�������⣬����������\n");
	set("age",30+random(20));
	set("combat_exp", 4800000);
	
	set("reward_npc", 1);
    set("difficulty", 3);

	set("inquiry", ([
        	"������" : "������ǵ�һ���Ҵ�����˹ȵ��������ˡ�\n",
        	"���˹�" : "ʮ�����ɢ��ɢ�������������˹�����̫ƽ���ˡ�\n",
      	]));
	
	
	set("chat_chance", 1);
    set("chat_msg", ({
        	"��ƽ������������书��ߣ����������壬С����������������ĸ���
��������Ȼ���壬����������ɷ����\n",
        }) );
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: auto_smart_fight(20) :),    
       }) );
	
	auto_npc_setup("guardian",200,170,0,"obj/weapon/none","fighter_u","dragonstrike",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/hat")->wear();
	
}
