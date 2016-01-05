// ; annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();
int look_stone();

void create()
{
	object weapon;
    set_name("Ѧ����", ({ "master xue", "master", "xue" }) );
    set("nickname", YEL"����"NOR);
	set("gender", "Ů��");
    set("age",19);
    set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ��
�ƿ������֣��¹⵭������������ǡ�������������ϡ��԰׵Ĺɣ��԰���
�¡�\n"
        );

	set("combat_exp", 90000000);
    set("score", -10000);
    set("class", "moon");
    set("reward_npc", 1);
    set("difficulty", 10);

	set("no_fly",1);
	set("no_arrest",1);

	set("guard_msg",CYN"$N��ü�����۸�����¹����ˣ��۸������������ˣ�\n"NOR);

	set("inquiry",([
		"�": (: look_stone :),
    	]) );

    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000);

    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",70);
	
    set("inquiry", ([
		"�": (: look_stone :),
         ]) );

    set("apprentice_available", 1);

    create_family("��¹�", 3, "����");
	set("title","��¹�");

    set("rank_nogen",1);

    set_skill("literate", 100);
	set_skill("starrain", 200);
	set_skill("force", 160);
	set_skill("chanting",160);
	set_skill("snowforce", 170);
	set_skill("blade", 250);
	set_skill("chillblade", 190);
	set_skill("throwing", 250);
	set_skill("parry", 160);
	set_skill("dodge", 200);
	set_skill("move", 170);
	set_skill("stormdance", 200);
	set_skill("perception",160);
	set_skill("foreknowledge",100);

	map_skill("throwing","starrain");
    map_skill("parry", "chillblade");
    map_skill("blade", "chillblade");
    map_skill("move", "stormdance");
    map_skill("dodge", "stormdance");
    map_skill("force", "snowforce");

    setup();

	weapon = carry_object("/obj/armor/cloth");
	weapon->set("name",WHT"��ѩ��ɴ"NOR);
	weapon->set("long","һ�����л��޵��ذ�ɴ�¡�");
	weapon->wear();
	weapon=carry_object("/questnpc/obj/leaf");
    weapon->set_name(HIW"���հ���"NOR, ({ "white feather" }) );
	weapon->set("long","һ�ؽ�׵���ë�����Ƽ�����������ʵ��Ӳ�ޱȡ�\n");
	weapon->set("base_unit","��");
	weapon->set("value",0);
	weapon->set_amount(909);
	weapon->set("volumn",909);
	weapon->wield();

}

void reset()
{
	set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("flook");
        }
}

void do_recruit(object me)
{
	if( (string)me->query("class") != "moon" )
	{
		command("flook" );
	}
	else
	{
		if (REWARD_D->check_m_success(me,"������Թ") >0 && me->query("imbue/moon_xue"))
		{
			command("sigh");
			command("recruit " + me->query("id") );
			command("flook");
		}
		else
			command("flook" );
	}
}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}


void init()
{
	::init();
	add_action("do_killing", "kill");
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N������ɨ��$nһ�ۡ�\n"NOR, this_object(),this_player());
	message_vision(CYN"$N˵����Ȼ��һ��Ҫ�ߣ���Ҳ������ǿ��\n"NOR,this_object(),this_player());
	message_vision(CYN"$N˵��ֻ�����и��յľ��裬���Ƕ��޷����õ��ˡ�\n"NOR,this_object(),this_player());
    return 1;
}

int look_stone()
{
	object me;
	me=this_player();
	if (REWARD_D->check_m_success(me,"������Թ") >0)
	{
		ccommand("say ������");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 10 )
	{
	ccommand("emote ��Ѷ��ȻһЦ��������������������Ҫ�ټ���ô��");
	ccommand("emote ����˫��������̾�˿�����");
	ccommand("nod");
	REWARD_D->riddle_set(me,"������Թ",11);
	return 1;
	}

	if (random(2))
	{
		message_vision("$N����̾Ϣ����˵Ϊʲô�����Ͼͻ��������еĹ������ء���\n"NOR,this_object(),this_player());
	}
	else
	{
		message_vision("$N����Զ������գ����ĵ�����֪�����ڿɺã��ǲ��ǻ�ϲ��\n�ڳ�ѩ�������ﳪ�衭��\n"NOR,this_object(),this_player());
	}
    return 1;
}


int accept_object(object me, object obj)
{
	if (obj->query("name") == "Сֽ��" && obj->query("real") == 3)
	{
		if (REWARD_D->riddle_check(me,"������Թ") == 2 && me->query_temp("annie/xiangsi_master") == 4)
		{
			ccommand("say ��Ϊ���ˣ������������˳�����");
			ccommand("say ֻ����Щ�����������˺ܶ࡭�����Ƕ���Ե����������Ҫ��������\nΪ�У��ӵ���һʱ��Ҳ�Ӳ���һ���ġ�");
			ccommand("say �Ҳ�����ȥ�ı�ʲô�����������ģ��������ɡ�");
			REWARD_D->riddle_set(me,"������Թ",3);
			return 0;
		}

	}
	command("smile");
	command("shake");
	return 0;
}

/*

Ѧ����Ŀǰ��ѧ��ʮ���ּ��ܣ�

  �������� (blade)                         - �����뻯 150/    0
�������߾� (chillblade)                    - �����뻯 150/    0
  ��Ծ����֮�� (dodge)                     - ��ɲ� 200/    0
  �ڹ��ķ� (force)                         - һ����ʦ 180/    0
  ����ʶ�� (literate)                      - ��Ȼ��ͨ 150/    0
  �����Ṧ (move)                          - ��ɲ� 200/    0
  ����ж��֮�� (parry)                     - �Ƿ��켫 170/    0
  �������֮�� (perception)                - ��ɲ� 300/    0
����ѩ�ľ� (snowforce)                     - �����뻯 140/    0
���������� (starrain)                      - ��ɲ� 200/    0
��������� (stormdance)                    - ��ɲ� 200/    0
  ����ʹ�� (throwing)                      - ��ɲ� 300/    0

��������Ŀǰʹ���е����⼼�ܡ�
��������������������������������������������������������������������
  ���� (blade)            �� �����߾�         ��Ч�ȼ���300     
  ������ (dodge)          �� �������         ��Ч�ȼ���570     
  �ڹ� (force)            �� ��ѩ�ľ�         ��Ч�ȼ���300     
  ��д (literate)         �� ��               ��Ч�ȼ��� 75     
  �Ṧ (move)             �� �������         ��Ч�ȼ���570     
  �м� (parry)            �� �����߾�         ��Ч�ȼ���310     
  ������ (perception)     �� ��               ��Ч�ȼ���300     
  ���� (throwing)         �� ��������         ��Ч�ȼ���390     
 
��Ч�ȼ� = ��������/2 + ���⼼��*�书ϵ��
����ɫ���ɫ�����ֱ�ʾ������������Perform����Advanced-skill������ֵ��
 
��������������������������������������������������������������������

*/
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
