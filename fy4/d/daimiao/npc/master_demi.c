inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("����Ů��", ({ "master figure", "master"}) );
        set("gender", "Ů��" );
        set("age", 64);
        set("per", 3);
        set("group", "demon");
        set("vendetta_mark","demon");
        set("attitude","friendly");
		set("class","demon");
    
        set("combat_exp", 10000000);
        set("score", 200000);
        set("long","��������ħ�������Ե�λ���ֽ��ۣ�\nȴ��һ���͵͵���ɴ��ס��Ŀ������\n");
    
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
        
        set_skill("blade", 300);
        set_skill("heavendance", 200);
        set_skill("unarmed", 180);
        set_skill("divineforce", 160);
        set_skill("kaleidostrike", 140);
		set_skill("perception",190);
		set_skill("magic",200);
		set_skill("sheolmagic",200);
        set_skill("literate", 100);
        set_skill("chanting", 160);
        set_skill("dodge", 180);
        set_skill("move", 190);
        set_skill("parry", 170);

        map_skill("unarmed", "kaleidostrike");
        map_skill("force", "divineforce");
        map_skill("blade", "heavendance");
        map_skill("magic", "sheolmagic");

        setup();
        carry_object(__DIR__"obj/demiblade")->wield();
        carry_object(__DIR__"obj/semicloth")->wear();

}


void attempt_apprentice(object me)
{
	if (me->query("gender") == "����")
	{
		ccommand("shake");
		ccommand("say ����ֻ��Ůͽ��");
		return;
	}
	if (me->query("class") != "demon")
	{
		ccommand("emote ����ɴ��Ƴ����һ�ۡ�");
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
//	if (crypt(obj->query("name"),"pbpRubOoY/Q/A") != "pbpRubOoY/Q/A" || me->query("gender") == "����")		// disabled upon further investigation
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
	ccommand("emote ����ɴ�·����͵͵�Ц����");
	ccommand("say �ã��������̡�");
	ccommand("recruit "+me->query("id"));
	return 1;
}
