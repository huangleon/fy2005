inherit SMART_NPC;
#include <ansi.h> 

void create()
{
        set_name("����", ({"wu qing", "wu", "qing"}));
        set("long", "һ�������ܸɣ��书��ǿ���ͷ���������\n");
        set("gender","����");
		set("title",  "��Ǯ��"HIR" �ͷ�������"NOR);
        set("class", "legend");
        
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("combat_exp", 5000000);
	
		set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("force", 150);
        set_skill("qidaoforce", 170);
        set_skill("fall-steps", 200);
        set_skill("move",200);

		set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		map_skill("parry", "qidaoforce");
        map_skill("unarmed", "qidaoforce");
        map_skill("dodge", "fall-steps");
		map_skill("force","qidaoforce");
		map_skill("move","fall-steps");

        setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  HIY"���ƽ���"NOR,
    						"long": "һ���ƶг��ۣ������Ƿ���\n",
    						 ]))->wear();    
}
 
 
int accept_object(object who, object ob)
{
            command("grin");
            command("say Ϲ���۵Ĺ��ţ����һ�¸�ң���");
	    kill_ob(who);
            return 0;
}
 
