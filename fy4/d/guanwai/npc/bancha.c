#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "bancha bana","bancha" }) );
        set("gender", "����" );
        set("long",
                "����������������������������ͬ�����Ӣ�����䡣\n"
                );
        set("title", "ʥĸ���� ��һ��ʿ");
        set("nickname", HIY "�廨����"NOR);
        set("attitude", "peaceful");
        set("reward_npc", 1);
	set("difficulty", 5);
	set("age", 38);
        set("per", 40);
        set("combat_exp", 1500000);
        
        set_temp("apply/damage", 100);

        set("chat_chance", 2);
        set("chat_msg", ({
                "�����ǰ�Ȼ������ӥ�������Ұ����Ǿ���ʥĸ���µ�һ��ʿ��\n",
                }) );
    	
    	set_skill("perception", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("throwing", 300);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/arrow")->wield();
}

int accept_fight(object me)
{
        if(me->query("combat_exp") > 500000)
        {
            command("say ��,�����ƺ��е�����,��,���ҹ�����!\n");
        	return 1;
        }
        else
        {
            command("say ����?�޶�Ū�����ҵ��廨���!\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
	command("say ����Ҷ����㻹���Զ�أ�\n");
}
void lose_enemy(object winner)
{
	command("say �㱾�²����ҿڷ��ķ���\n");
	winner->set_temp("marks/won_bancha",1);
}
