#include <ansi.h>
inherit NPC;
int leave();

void create()
{
    	set_name("С���", ({ "xiao linger", "linger" }));
    	set("long", "����Ľ�С����ڵĳ������һ�Դ��٣��������Ĵ����г������档\n" );
	set("title", "��ɽ�� ��ʮ�ߴ�����");
 	set("gender", "Ů��");
	set("age", 13);
	set("per", 27);
	set("agi", 20);
	set("class","huashan");
	set("combat_exp", 280000+random(50000));
	set("attitude", "friendly");

	set("chat_chance", 3);
	set("chat_msg", ({
	 	"С���С��˵����ʦ������������һ�Ѿ�ץ��������Ү�� \n",
		"С��������������������ʦ������ڽ�ʦ�������������ѽ��\n", 
		"С������������Ǹ�ɽ���������"YEL"��"NOR"Ү������\n", 
	}) );
    		
    	set("inquiry", ([
 	 	"��" : (: leave :),
         ]) );

 	set_skill("unarmed", 100);
	set_skill("move", 150);
	set_skill("dodge", 145);
	set_skill("parry", 135);
	set_skill("force", 149);
	set_skill("sword", 130);
	set_skill("qingfeng-sword", 100);
	set_skill("zhaixin-claw",100);
	set_skill("anxiang-steps", 100);
	set_skill("hanmei-force",100);
	
	map_skill("force", "hanmei-force");
        map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps");
        map_skill("unarmed","zhaixin-claw");

	setup();
    	carry_object(__DIR__"obj/gcloth",
    		([ 	"name" 	:	"����",
    			"long"	:	"����ɫ��С�ӡ�"		])
    		)->wear();
    	carry_object("/obj/weapon/sword_short")->wield();

}


int leave() {
	object who = this_player();

	if (REWARD_D->riddle_check(who,"����ëŮ��") != 2)
	{
		message_vision(CYN"$N�������������������ŵ����Ҳ���˵���������ҵġ�\n"NOR, this_object(),this_player());
		return 1;
	}

	REWARD_D->riddle_set(who,"����ëŮ��",3);
	message_vision(CYN"$N����һ�£�һ�����ŵĶ�$n˵��ÿ����ҹ��������е��ٵ��������ÿ��£�����\n"NOR, this_object(),this_player());
	return 1;
}