// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// �˲���֮ҹ���� ǧ�꼯�� ���� 
// EXP 8M KEE 40K GIN/SEN 24K RESIST/ALL 60
// STR 40 DMG 25 ATTACK 46K DODGE 45K PARRY 150K
// PETMASTER

// A/D/P��Զ���ڱ�׼8M��PARRY��ֵ�ߣ����˲���TK��
// ����Ⱥ��6M EXP����ȫBUFF֮��50-81K ATTACK,32K D/P.

inherit NPC;
#include <ansi.h>
#include <combat.h>
int kill_him();

void kick_out(object me)
{
	message_vision(CYN"\n����һ���֣�һ������ɫ�ķ�ֽ������$N���ϣ�$N����Ӱ���ڿ�����ģ������\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n����ǰ�Ŀ�����Ȼ��ʼ���󲨶���һ��ģ�������������Ĵ���������ֳ���������\n\n"NOR,me);
}

void create()
{
	object armor,weapon;
	set_name("����", ({ "xin wang","xin"}) );
	set("gender", "����" );
	set("title",YEL"�ɷ����"NOR);
	set("age", 60+random(10));
	set("attitude","friendly");

        set("inquiry", ([
                "�������":  (: kill_him :),
        ]) );

	set("long",
		"�������°׷������糤�룬�ֳ�ֽ�����������ۣ�������һ��\n�����ɷ硣\n"
		);
	set("class","demon");
    set("score", 10000);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",40000);
	set("max_gin",24000);
	set("max_sen",24000);
	
	set("NO_KILL","����������վ������ǰ�ĳ�֮��������̶̵��ĳ߾���������޷���Խ��\n");

	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//               (: smart_fight() :),
        }) );


	setup();

	carry_object(__DIR__"obj/taopao")->wear();
	carry_object(__DIR__"obj/papersword")->wield();

}

int kill_him()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"��������") != 5)
	{
		ccommand("heng");
		kick_out(me);
		return 1;
	}
	ccommand("hmm");
	ccommand("say �Ǳ����ϵ����֣��Ϸ��ѹ������졣");
	ccommand("say ����Ի��㣬�����Ϸ��и���������֪��𲻴�Ӧ��\n"HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
	me->set_temp("annie/riddle_ask_xin",1);
	return 1;
}


int do_answer(string arg)
{
	object me = this_player();
	if (!me->query_temp("annie/riddle_ask_xin"))
		return 0;
	me->set_temp("annie/riddle_ask_xin",0);
	if (arg == "no")
	{
		ccommand("hmm");
		return 1;
	}
	me->ccommand("ok");
	ccommand("nod");
	ccommand("say ��Ȼˬ�졣");
	ccommand("say ��ȥ���������������Ⱥ��ͷ�����ң��ұ������㡣");
	REWARD_D->riddle_set(me,"��������",6);
	kick_out(me);
	return 1;
}

void init()
{
	object me;
	::init();
	me = this_player();
	if (userp(me) && environment(me)->query("short") == "��������"  && REWARD_D->riddle_check(me,"��������") != 6)
		call_out("do_greeting",1,me,environment(this_object()));
	if (userp(me) && environment(me)->query("short") == "��������"  && REWARD_D->riddle_check(me,"��������") == 6)
		call_out("do_greeting",6,me,environment(this_object()));
	add_action("do_answer","answer");
}



void do_testppl(object me,int count,object room)
{
	string msg;
	string *event_msg = ({
"\n$N����$n�߽�����̧��̧üë������¶��һ˿����֮ɫ��\n",
"$NЦ������ô����Ѿ�������Ը��������������ô��\n",
"$N���ͷ�������Ǳ���Թ��������ɱ�����Ⱥ������˵�ҵ���л����ǡ�\n",
"$N����һ�٣��ֵ���ֻ��������վ�ڶ�������һ�ߣ����������õ����ѣ��������ǵĵ��ˡ�\n",
"$Nͻ��΢Ц������ת��֮����ȱ�Ķ����������ҳ����ˣ��Ǿ��ǣ�ɱ������������������ٰ���һ�Σ�\n",
"$N����$n����Сָ��һ��Ũ�ܵĺ������$n�������ڶ���ת�۾ͽ�$n��û��\n\n"});
	if (!me || environment(me) != room)
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+NOR,this_object(),me);
	if (count < sizeof(event_msg)-1)
		call_out("do_testppl",1+random(2),me,count+1,room);
	else
	{
		set("ggyy",0);
		me->set_temp("annie/demon_xin_1",1) ;
		me->move(load_object("/d/taoguan/fog"));
	}
	return;
}


void do_greeting(object me,object room)
{
	object book;
	if (!me || environment(me) != room)
		return;

	if (REWARD_D->check_m_success(me,"��������") == 1)
	{
		if (query("ggyy"))
		{
			kick_out(me);
			return;
		}
		// ת��ս���׶Ρ�
		set("ggyy",1);
		do_testppl(me,0,room);
		return ;
	}

	if (REWARD_D->riddle_check(me,"��������") != 5)
	{
		kick_out(me);
		return;
	}
	ccommand("pat xin wang");
	ccommand("say ���ѳɣ�ý����ۣ���ʱ��˳������δΥ������������ת��֮�������׻�ȱ��ʲô��");
	ccommand("consider");
}


int accept_object(object who, object ob)
{
	object me = this_player(), book;
	int i = REWARD_D->riddle_check(who,"��������");
	if (!i)
		return 0;
	if (i != 6)
		return 0;
	if (!ob->query("real"))
		return 0;

	if (ob->query("name")=="���Ⱥ��ͷ")
	{
		// consider...annnnie
		ccommand("haha");
		ccommand("emote ���Ű��룬��ͷ�����ã��ã�");
		ccommand("say �Ϸ��Ե����ţ����������ȥ���������ơ�");
		ccommand("say ����֮�£�����������δ��ɵ���Ը���������Ұɡ�");
		book=new(__DIR__"obj/necbook");
		if (!book->move(me))
			book->move(environment(me));
		REWARD_D->riddle_set(me,"��������",8);
		tell_object(me,HIY"��õ�һ����"HIW"�������"HIY"����\n"NOR);
		kick_out(me);
		return 1;
	}
	else if (ob->query("name")=="����ѩ��ͷ")
	{
		ccommand("emote ��Ȼ��ɫ����Ц�����ã��ܺá�");
		ccommand("emote һ���֣���һ����װ�鶪��$n����������������ȥ������Ը���ٹ��������ɣ�");
		book=new(__DIR__"obj/necbook");
		if (!book->move(me))
			book->move(environment(me));
		REWARD_D->riddle_set(me,"��������",8);
		tell_object(me,HIY"��õ�һ����"HIW"�������"HIY"����\n"NOR);
		kick_out(me);
		return 1;
	}
	return 0;

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

