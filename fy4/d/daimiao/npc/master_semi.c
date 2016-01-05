inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("������", ({ "master shadow", "master"}) );
        set("gender", "����" );
        set("age", 64);
        set("per", 3);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("attitude","friendly");
		set("class","demon");
    
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("long","��������ħ�������Ե�λ���ֽ��ۣ�\nȴ��һ���͵͵Ķ�����ס��Ŀ������\n");
    
        create_family("ħ��", 1, "ִ��ʹ");
        set("rank_nogen",1);
        set("ranks",({"��ͽ","������","����","��̳��","̳��",
                      "������","����","����","�󻤷�",
                      "����","����","������"}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,15000000 }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight(90) :),
        }) );
        
        set_skill("whip", 300);
        set_skill("dragonwhip", 200);
        set_skill("unarmed", 190);
        set_skill("divineforce", 190);
        set_skill("spicyclaw", 170);
		set_skill("perception",160);
		set_skill("magic",160);
		set_skill("sheolmagic",170);
        set_skill("literate", 100);
        set_skill("chanting", 190);
        set_skill("dodge", 180);
        set_skill("move", 170);
        set_skill("parry", 190);

        map_skill("unarmed", "spicyclaw");
        map_skill("force", "divineforce");
        map_skill("whip", "dragonwhip");
        map_skill("magic", "sheolmagic");

        setup();
        carry_object(__DIR__"obj/semiwhip")->wield();
        carry_object(__DIR__"obj/semicloth")->wear();

}


void attempt_apprentice(object me)
{
	if (me->query("gender") == "Ů��")
	{
		ccommand("shake");
		ccommand("say �Ϸ�ֻ����ͽ��");
		return;
	}
	if (me->query("class") != "demon")
	{
	ccommand("emote �Ӷ�����Ƴ����һ�ۡ�");
	ccommand("say Ҫ���ҽ̣�����Ҫ֤��������ġ�");
	ccommand("say ȥ�ѣ��Ƕ������������Ҿ��ϱ�������������̡�");
	REWARD_D->riddle_set(me,"����ħ��",1);
	}
	else
	{
		ccommand("shake");
		ccommand("say ���������У��㰲�Ĵ��¾��ǡ�");
	}
	return;
}


int accept_object(object me, object obj)
{
	if (random(100)+1)			// Not possible in fy2005
	{
		ccommand("shake");
		return 0;
	}
	if (REWARD_D->riddle_check(me,"����ħ��") != 1)
	{
		ccommand("shake");
		return 0;
	}
	REWARD_D->riddle_set(me,"����ħ��",2);
	ccommand("emote �Զ����·����͵͵�Ц����");
	ccommand("say �ã��������̡�");
	ccommand("recruit "+me->query("id"));
	return 1;
}
