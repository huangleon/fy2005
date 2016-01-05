// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
int look_stone();

void create()
{
	set_name("������ʤ", ({ "gongsun wusheng","gongsun","wusheng" }) );
	set("class","huashan");
	set("gender", "����" );
	set("age", 75);

	set("title",YEL"ƽ����ʤ"NOR);

	set("attitude", "friendly");

	set("long",CYN"������ʤ������һ�ۡ�\n\n"NOR);
	set("chat_chance", 1);
	set("chat_msg", ({
	CYN"������ʤ��Ȼ�����Ϸ���ܣ����ǽ�����ʮ�꣬���˽��֣�����һʤ�����\n��������ܣ�������ʤ��\n"NOR,
	}) );

	set("death_msg",CYN"\n������ʤ��Ц�����Ϸ����㽻�֣����Ͳ���һʤ��\n"NOR);

	set("inquiry",([
       	"����": 	"�������ǵ��¼۸���ߵ�ɱ�֣���ϧ�Ϸ��ò��ã����������������һ�ܡ�\n",
       	"������": "���϶������ׯ�Ĵ��ܹܡ�\n",
       	"���ׯ": "���ǵ�����Ѱ�����˵�ׯ԰�ˡ�\n",
		"�": (: look_stone :),
    	]) );


	set("combat_exp", 1500000);

	set("reward_npc",1);
	set("difficulty",1);

	set_skill("move", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("shuaijiao",140);
	set_skill("13-sword",1);
	map_skill("dodge","13-sword");
	map_skill("unarmed","shuaijiao");
	set_skill("force",200);
	set_skill("liangyi-force",200);
	set_skill("hanmei-force",200);
	map_skill("force","liangyi-force");
	

		set("perform_busy_d", "npc/dodge/13-sword/rufengsibi");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	setup();

	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/wine");

}

void die()
{
	object me;
	object wine;
	me = query_temp("last_damage_from");
	if (me )
	{
		if (REWARD_D->riddle_check(me,"������Թ") == 7 && me->query_temp("annie/riddle/moonmaster") == 10)
		{
			message_vision(CYN"\n������ʤ�ƺ�һ������ס���Ρ�\n"NOR,me);
			ccommand("say �ã��ñ��£�����⣬���ǵ�һ��������֮�ˡ�");
			ccommand("say �������һս������������ŵ��ֻҪִ�������«�������������һ�¡�");
			ccommand("say ���«�������Ѿ����꣬���ھ�������ɡ�");
			wine=new(__DIR__"obj/wine");
			wine->move(me);
			message_vision(CYN"\n������ʤ����«�ݸ�$N�����Ƴ��裬ƮȻ��ȥ��ɽ����ֻʣ����Խ�ĸ������죺\n��������ܼ躮��Ϊ�������Զ��ѡ�������֪��Զ�����������������\n�����ž������Σ�ҹ��ƫ�й��¡��ϵó�Ե���뾡���������նȷ�������\n\n"NOR,me);
			REWARD_D->riddle_set(me,"������Թ",8);
			destruct(this_object());
			return;
		}
	}
	::die();
}

int look_stone()
{
	object me;
	me=this_player();

	if (REWARD_D->riddle_check(me,"������Թ") == 7 		// to get lots of winepots ...
		|| REWARD_D->riddle_check(me,"������Թ") == 8)
	{
		ccommand("hmm");
		ccommand("say ���������ó���ı�����˵��");
		me->set_temp("annie/riddle/moonmaster",10);
		kill_ob(me);
		return 1;
	}
	message_vision("$N˵�������С��ɵ����ˣ��������϶����������\n"NOR,this_object(),this_player());
    return 1;
}

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
