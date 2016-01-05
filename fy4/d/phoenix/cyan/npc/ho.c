// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void create()
{
	object weapon;
	set_name("����ƽ", ({ "hao zhongping","hao","zhongping","haozhongping" }) );
	set("class","beggar");
	set("gender", "����" );
	set("age", 16);

	set("nickname",MAG"С���"NOR);
	set("title","ؤ������"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("long","�����������ֳ���С�����һ˫������Ĵ���ȴ�޶��鶯��\n");

	set("inquiry",([
		"��Ѫƽ��": (: look_stone :),
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"����ƽ���ڵ���ƫͷ���㣺��λ��ү�β�ʩ��һЩ��\n",
		"����ƽ������СС���������£�ʩ�ữ��һ�뷹��\n",
	}) );

	set("combat_exp", 6000000);

	set_skill("staff", 200);
	set_skill("dagou-stick", 220);
	map_skill("staff","dagou-stick");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "staff.banzijue" :),
	}) );

	setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name(YEL"������"NOR, ({ "stick" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("�Ʋ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}



int accept_object(object who, object ob)
{
	message_vision(CYN"����ƽǷǷ���ӵ�����ү���Ķ������кñ���\n"NOR,who);
	return 1;
}

int do_ans(string arg)
{
	object me = this_player();
	if (arg != "yes" && arg != "no")
		return notify_fail("��Ҫ�ش�ʲô��\n");
	if (me->query("annie/b") || REWARD_D->riddle_check(me,"�ع�����") != 5)
		return notify_fail("��ô��\n");

	if (arg == "no")
	{
		ccommand("duh");
		me->set("annie/b",1);
		return 1;
	}
	if (REWARD_D->riddle_check(me,"�ع�����") == 5) 
		REWARD_D->riddle_set(me,"�ع�����",6);
	ccommand("ok");

	
	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"ȥ"CYN"���ƶ�"WHT"�μ���Ѫƽ�ܴ��"NOR);
	me->set("quest/location", "somewhere");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


	return 1;
}

int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();

	if (me->query("annie/b") || REWARD_D->check_m_success(me,"���"))
	{
		message_vision(CYN"����ƽ��$N�����۾�������˵�ǻ��Ͽ�Σ�յĺܣ��㣮����\n"NOR,me);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"�ع�����") == 6) 
	{
		if (me->query("annie/a") && !REWARD_D->check_m_success(me,"���ȥ"))
		{
			message_vision(CYN"����ƽ������ɣ�������û�����\n"NOR,me);
			message_vision(CYN"����ƽ���������ţ���ʵû�����Ҳ������ν�����������пɴ�֦��Ҷ�úܣ�\nֻ���������ӣ����������"WHT"���ȥ"CYN"�ͺá�"NOR,me);
			REWARD_D->riddle_done(me,"���ȥ",0,1);


			return 1;
		}
		message_vision(CYN"����ƽգ�۵��������Ǳ�����Ѫƽ�ܴ���ϼ��ˡ�\n"NOR,me);
		return 1;
	}


	if (REWARD_D->riddle_check(me,"�ع�����") == 4 || REWARD_D->riddle_check(me,"�ع�����") == 5) 
	{
		message_vision(CYN"����ƽƫ��ͷ���´���$N��¶��һЦ����λ������������С���һͬ�ڴ���ϣ�������\n"HIW"("HIY"Answer "HIY"yes"HIW"/"HIY"no"HIW")\n"NOR,me);
		add_action("do_ans","answer");
		REWARD_D->riddle_set(me,"�ع�����",5);
		return 1;
	}

	message_vision(CYN"����ƽ˵���������㻹��������ʲô���춯����\n"NOR,me);
	return 1;

}

