// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();
int look_stone2();
int look_stone3();

void create()
{
	set_name("����", ({ "jian fanxing", "fanxing","jian" }) );
	set("class","moon");
	set("gender", "Ů��" );
	set("age", 25);

	set("nickname",HIW"���ƺ�ɽѩ��֦����ʿ��"NOR);
	set("title","��¹�"NOR);

	set("per",80);

	set("attitude", "friendly");

	set("long","��һ�������ѩ����������ķ��ټ仹����һ��С�׻���\n");

	set("inquiry",([
		"�": (: look_stone :),
		"����": (: look_stone :),
		"ָ��": (: look_stone2 :),
		"ҩ": (: look_stone3 :),
		"ʧ����Ӱ":	"ʧ�ٵ��������ϣ�������û��һ���˽���ҩ����\n������͵�ģ�Ī�ǻ�����è��֮����\n",
       	"ʧ��": 	"ʧ�ٵ��������ϣ�������û��һ���˽���"WHT"ҩ��"CYN"��\n������͵�ģ�Ī�ǻ�����è��֮����\n",
       	"�����һ���": 	"�һ������"WHT"����"CYN"�����²ɣ��Ҳ���մ�˵���֮�����������ҩ����\n",
       	"��ɽ����": 	WHT"��ɽ"CYN"����ǰ����ף�ڣ���ɽ���յý��ˣ�����ѰѰ���ٺþò��ҵ�һЩ�ɻ������������Ѱȥ��\n",
       	"��ɽǧ��": 	"�⻨��˼���Ͼ��У�ϲ������"WHT"�״�ʯ"CYN"��������ϡ�\n",
       	"���ź�Ȫˮ": 	"Ȫˮ���ǹ����ǿڣ�ֻ����Ҫ"WHT"������"CYN"�Ĳ��С�\n",
       	"�������": 	"���⵹Ҳ�ð죬"WHT"ѩ��"CYN"�ж���ǡ�\n",
       	"�񾱽���": 	"�������Ǵ�ҵ�ʱ��һ��"WHT"�Ŷ�����"CYN"������ã���֪���������ںη�����\n",
       	"������¼": 	"�Ǳ��黹��"WHT"���"CYN"֮�У���ֻ��Ѱ��ǰ��ζҩ�ģ���ʱ�������졣\n",
		"����":			"�����Ƕ�ʮ�Ľ�֮һ������������\n",
		"��ɽ":			"�˴����ɺ��⣬�д�ʮ���죬����Ե���ɽ�ˡ�\n",
		"�״�ʯ":		"Ī������ɽʱ����·����\n",
		"ѩ��":			"�������Ǳ߹�ȥ�Ǹ������ˡ�\n",
		"�Ŷ�����":		"�ǹŶ�������һ��Ԫ����ӣ�ͷ�ϴ��˶��廨����ڣ��Գ���������ʿ��\n",
		"���":			"�����޸������Ƶ�����ˡ�\n",
		"ҩ��":			"����������ݵ��Ա��ˣ��ԴӶ���ҩ���޸���Ͱ���������˲���ĵط���\n",
		"����":			"ͬ�Ķ���ӣ����������ϣ�����\n",
		"����֮��":		"�Ǳ������������������ĵط��ˡ�\n",
		"������":		"���ź�������������ⶼ��֪����Ҳ�Ͳ����ٰ׷���˼�ˡ�\n",
		"С��":			(: look_stone :),
		"Ѧ���":		"һ����ѩѦ���������С��ĸ��ס�\n",
		]) );

	set("death_msg",CYN"\n������������С�㣮���������󣮣����ܣ������Ŋ��ˣ�������Ҫ�����ౣ�أ���
���ǵ��������������Ѫ������������ȥ��\n"NOR);

	set("chat_chance", 1);
	set("chat_msg", ({
		"��������Ц����֪��ѩԭ�β�Ļ�����ʲô��\n",
		"��������Զ��ɽ�ͣ����Ƶ�������������֮������������飬Ӧ�Ǻεȵ���ů��\n",
		"����˵������˵����Ϧ�����ϣ������������������ĵط�ȥ���ͻ��ռ���֯Ů����ˮ��\n",
	}) );

	set("combat_exp", 400000);

	set_skill("blade", 1);
	set_skill("chillblade", 100);
	map_skill("blade","chillblade");

	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("stormdance", 100);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.shuangtianxuewu" :),
	}) );

	setup();

	carry_object(__DIR__"obj/iceblade")->wield();
	carry_object(__DIR__"obj/wcloth2")->wear();
	carry_object(__DIR__"obj/flower")->wear();

}

int kill_ob(object who)
{
    command("loveme "+who->query("id"));
	ccommand("perform dodge.shuangtianxuewu");
	::kill_ob(who);
	return 1;
}

void killed_enemy(object who)
{
    command("admire2 "+who->query("id"));
}


int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();
	me->add_temp("annie/riddle/moonmaster",1);
	i=me->query_temp("annie/riddle/moonmaster");

	if (me->query("combat_exp") < 2600000)	// ��1.2M�������Ϳ���ȥleh
	{
		ccommand("emote ҡͷ�����㻹С������˵��������Ҳ��û���õģ�������60����");
		return 1;
	}


	if (REWARD_D->riddle_check(me,"������Թ") == 3)
	{
		ccommand("say ʲô��");
		ccommand("say С�㡭��С������ô��ô˵��");
		ccommand("say �������ˡ��������ˣ������ô��źá���");
		ccommand("emote ��ɫ�ұ䣬ҧ���´���˼��");
		REWARD_D->riddle_set(me,"������Թ",4);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"������Թ") == 2)
	{
		ccommand("say ���ҩ��ȥ��С��ɡ�");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 99 || REWARD_D->check_m_success(me,"������Թ") >0)
	{
		ccommand("say ������");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 4)
	{
		ccommand("emote ͻ��һ���ֵ������ˣ�������ȥ�������ܽ�ա�");
		return 1;
	}

	if (i >= 6)
		me->set_temp("annie/riddle/moonmaster",5);
	msg="���ˣ����ˣ�ԭ������Щ"WHT"ָ��"CYN"�����ȴֻ������������";
	switch (i)
	{
	case 1:
		msg="���ɱ��С����ȱ�����ծ�ӳ���С�������������쾭���塣";
		break;
	case 2:
		msg="ֻ�ǣ�ֻ�ǡ���������";
		break;
	case 3:
		msg="����С�����ԭ����һ����ˣ����ȴ�ߵ�������ز��������������ϣ�����Ū�ˡ�";
		break;
	case 4:
		msg="ԩ����ԩ����������ǰ���Ķ�Թ��ȴ���������ľ�����";
		break;
	}
	message_vision(CYN"$N˵����"+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}

int look_stone2()
{
	object me;
	int i;
	string msg;
	me=this_player();
	if (REWARD_D->riddle_check(me,"������Թ") == 2)
	{
		ccommand("say ���ҩ��ȥ��С��ɡ�");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 99 || REWARD_D->check_m_success(me,"������Թ") >0)
	{
		ccommand("say ������");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 4)
	{
		ccommand("emote ͻ��һ���ֵ������ˣ�������ȥ�������ܽ�ա�");
		return 1;
	}
	i=me->query_temp("annie/riddle/moonmaster");
	if (i < 5)
		return 0;

	me->set_temp("annie/riddle/moonmaster",6);
	REWARD_D->riddle_set(me,"������Թ",1);
	msg="���������������"WHT"ҩ"CYN"����û����С�㣬��Ī�������"WHT"ʧ����Ӱ"CYN"��";
	message_vision(CYN"$N˵����"+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}

int look_stone3()
{
	object me;
	int i;
	string msg;
	me=this_player();

	if (REWARD_D->riddle_check(me,"������Թ") == 2)
	{
		ccommand("say ���ҩ��ȥ��С��ɡ�");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 99 || REWARD_D->check_m_success(me,"������Թ") >0)
	{
		ccommand("say ������");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"������Թ") == 4)
	{
		ccommand("emote ͻ��һ���ֵ������ˣ�������ȥ�������ܽ�ա�");
		return 1;
	}

	i=me->query_temp("annie/riddle/moonmaster");
	if (i < 6)
		return 0;

	me->set_temp("annie/riddle/moonmaster",7);
	msg="������"WHT"�����һ���"CYN"��"WHT"��ɽ����"CYN"��"WHT"��ɽǧ��"CYN"����"WHT"���ź�Ȫˮ"CYN"��\n"WHT"�������"CYN"������"WHT"�񾱽���"CYN"Ϊ����"WHT"������¼"CYN"Ϊ�����Ƴɵ�һ����ҩ�����ú�һ\n��������Ϣȫ�ޣ�������һ�����졣";
	message_vision(CYN"$N˵����"+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}


int accept_object(object me, object obj)
{
	if (obj->query("name") == "Сֽ��" && obj->query("real") == 3)
	{
		if (REWARD_D->riddle_check(me,"������Թ") == 1 && me->query_temp("annie/xiangsi_master") == 4)
		{
			ccommand("say �ף��⡭���⡭����������������Ƴ���������ҩ������������Ѱ�ã�");
			ccommand("say �죬����ȥ��С�㡣");
			ccommand("say �������ۣ����¿��о��ˡ�");
			REWARD_D->riddle_set(me,"������Թ",2);
			return 0;
		}
		return 0;
	}
	command("smile");
	command("say ��л����л��");
	return 1;
}

