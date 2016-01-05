#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("����¥", ({ "hua manlou","hua" }) );
        set("gender", "����");
        set("age", 32);
        set("nickname",WHT"�ʻ���¥"NOR);
        set("title","���ϻ���     ����");
        set("quality","good");
        set("long",
"�ʻ���¥������¥���ʻ���������ǿ�ҵ��Ȱ����������Ȱ����е�����һ����
\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 8000000);
        set("chat_chance", 10);
        set("chat_msg", ({
"����¥˵����ֻҪ���ȥ���ԣ��ͻᷢ���������Ƕ�ô�ɰ���ÿ�������ﶼ��
�ܶ����������������з��յ��������¡�\n",
"����¥���ŵ�����ͻȻһ�᣺½С����С���Ѿ�ʧ���˺�Щ�����ˣ�����ȥ���ˣ�\n", 
"����¥�������кܳ����˯�ߣ��кܺõ�θ�ڣ���������������ӣ���һ��
�����ܺõĹ��٣���Щ�����㹻���ο��һ��и��ܺõ����ѡ�\n",
        }) );
		set("chat_chance_combat",40);
		set("chat_msg_combat", ({
			(:perform_action,"unarmed.xinyoulingxi":)
		})	);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 90);
        set("fle",30);
	set("int",41);
	set("cor",40);
	set("per",40);
        set_skill("force", 80);
        set_skill("unarmed", 200);
        set_skill("dodge", 220);
	set_skill("parry",220);
	set_skill("lingxi-zhi",350);
	set_skill("move", 220);
	set_skill("fall-steps",100);
	map_skill("unarmed","lingxi-zhi");
	map_skill("move","fall-steps");
	map_skill("dodge","fall-steps");
	set("strategy","brave");
	set("hunting",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int universe_busy(object *all_enm)
{
	command("perform xinyoulingxi");
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int myexp,hisexp;
	myexp=me->query("combat_exp");
	hisexp=victim->query("combat_exp");

	if (random(myexp+hisexp)>hisexp&&(!random(2)))
	{
		victim->start_busy(10+random(10));
//		victim->remove_all_killer();
        return HIR "$nֻ����һ�飬ҪѨ���ƣ�һ�������ܶ��ˡ�\n" NOR;
	}
}

int kill_ob(object enemy)
{
	if(enemy->query_busy())
	{
		message_vision(HIC"����¥΢Ц�Ķ�$N�������������޻���֮��������֮Σ���£��Ǿ���֮������\n"NOR,enemy);
		return 0;
	}
	::kill_ob(enemy);
}

int normal_att(object opp)
{
	set("force_factor",50);
	return 1;
}


int alert_att(object opp)
{
	set("force_factor",90);
	return 1;
}


int flee_att(object opp)
{
	set("force_factor",200);
	return 1;
}