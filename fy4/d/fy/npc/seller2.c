// annie 07.2003
// dancing_faery@hotmail.com

#include <combat.h>
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("������ϰ���", ({ "silent wrinkly","wrinkly" }) );
	set("long","һ������Ů�ˣ�����Ϊ�����ƶ����������´����ϡ�\n");
	set("gender", "Ů��" );
	set("age", 35);
	set("no_curse",1);
	set("no_kill",1);
	set("no_arrest",1);
	set("long",
		" ");
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();


        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/specials/food/noodle1"					 : 10,
                "obj/specials/food/spiced1"					 : 10,
        ]) );
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
//        add_action("do_say", "say");
        add_action("do_answer", "answer");
}
/*
int do_say(string arg)
{
	object me = this_object();
	object ob = this_player();
	string a1;
	int a2;
	
	if (!arg)
		return 0;

	// annie; ��more��ʽ�����ʾ
	a1 = arg[0..3];
	if (crypt(a1,"m/ZNhkGgSUjmo") != "m/ZNhkGgSUjmo")
		a2=0;
	else
		a2=4;
	if (crypt(arg[a2..a2+7],"ERALFDGn3JqKM") != "ERALFDGn3JqKM")
		return 0;
	a2+=10;
	if (crypt(arg[a2..a2+7],"pF6DHQq2KAFp6") != "pF6DHQq2KAFp6")
		return 0;
	a2+=10;
	if (crypt(arg[a2..],"SMi3blOT3v18Y") != "SMi3blOT3v18Y")
		return 0;


	if (REWARD_D->riddle_check(ob,"����") || REWARD_D->check_m_success(ob,"����"))
		return 0;
	"/cmds/std/say"->main(ob,arg);
	ccommand("emote ͻȻ������üͷ��");
	ccommand("emote �ʵ������б��³Ե���ȥ?");
	tell_object(ob,HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
    REWARD_D->riddle_set(ob,"����",1);
	return 1;
}
*/

int do_answer(string arg)
{
	object me = this_object();
	object ob = this_player();
	object who;
	object o1,o2,o3;
	string msg;
	int i;
	
	string a1;
	int a2;
	
	if (!arg)
		return notify_fail("��Ҫ�ش�ʲô��\n");
	
	if (REWARD_D->riddle_check(ob,"����")!= 1) {
		// annie; ��more��ʽ�����ʾ
		a1 = arg[0..3];
		if (crypt(a1,"m/ZNhkGgSUjmo") != "m/ZNhkGgSUjmo")
			a2=0;
		else
			a2=4;
		if (crypt(arg[a2..a2+7],"ERALFDGn3JqKM") != "ERALFDGn3JqKM")
		{
			command("say ��˵����˵��");
			return 1;
		}
		a2+=10;
		if (crypt(arg[a2..a2+7],"pF6DHQq2KAFp6") != "pF6DHQq2KAFp6")
		{
			command("say ��˵����˵��");
			return 1;
		}
		a2+=10;
		if (crypt(arg[a2..],"SMi3blOT3v18Y") != "SMi3blOT3v18Y")
		{
			command("say ��˵����˵��");
			return 1;
		}

		if (REWARD_D->check_m_success(ob,"����")
			|| REWARD_D->riddle_check(ob,"����")== 2
			|| REWARD_D->riddle_check(ob,"����")== 3)
		{
			command("say ���Ѿ��Թ������ˡ�");
			return 1;
		}
		ccommand("emote ͻȻ������üͷ��");
		ccommand("emote �ʵ������б��³Ե���ȥ?");
		tell_object(ob,HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
    	REWARD_D->riddle_set(ob,"����",1);
		return 1;
	}
		
	who = present("carotic wrinkly",environment());
	if (ob->is_busy())
		return notify_fail("��������æ��\n");
	
	if (!who)
	{
		command("say ��˵����˵��");
		return 1;
	}
	
	if (REWARD_D->riddle_check(ob,"����")!= 1) 
	{
		command("say ��˵����˵��");
		return 1;
	}
		
	if (arg == "no")
	{
	    REWARD_D->riddle_clear(ob,"����");
		ccommand("hmm");
		return 1;
	}
	else if (arg == "yes")
	{
		ob->ccommand("say �����ԣ������Կ���");
		who->add_temp("combat_no_report",1);
		who->add_temp("no_check_pfm_win",1);

	msg = HIW "\n��Ȼ�亮��һ����$N�Ѿ����߰���֣����߰����������ľګ����̯�ϰ��Ŀڻ�ȥ��\n$N�ĳ��������ȶ��߸��죬������\n\n" NOR;
	message_vision(msg,ob,who);
	COMBAT_D->do_attack(ob,who, TYPE_PERFORM);
		who->add_temp("combat_no_report",-1);
		who->add_temp("no_check_pfm_win",-1);
		if (who->query_temp("damaged_during_attack"))
		{
			msg = HIC "$n����ƽת����һ������Ĵ���굱���˵�Ѩ�б��$N�ļ羮Ѩ��\n" NOR;
			message_vision(msg,ob,who);
			msg = HIY "$N������һ���������Ѵ���$n���Ŀ��ϣ�ȴ�����ˡ�������һ���죬
�ͺ������һ�������ϡ�\n\n" NOR;
			message_vision(msg,ob,who);
			ccommand("emote Ц�ˣ�һ�ű�����ƽ����ª�����ϣ�һЦ������Ȼ��¶���ܶ��˵���̬��");
			msg = CYN "  ���ã��ñ��¡���$N�Ὺ�˷����һ�����ӣ���$n��ǰ����һ�����룺
�����������档��\n\n" NOR;
			message_vision(msg,me,ob);
		    REWARD_D->riddle_set(ob,"����",2);

			o1=new(__DIR__"obj/dawan");
			o2=new(__DIR__"obj/paper");
			o3=new(__DIR__"obj/pearl");
			o3->move(o1);
			o2->move(o1);
			o1->move(ob);
			// ya..

		who->receive_fulling("kee",99999);
		who->receive_fulling("gin",99999);
		who->receive_fulling("sen",99999);

		}
		else
		{
			msg = HIC "$n����һ˫����Ȼ�̳�����˫������֮������$N��˫�ۡ�" NOR;
			message_vision(msg,ob,who);
			msg = HIY "\n$N�Ĺ�����δ��$n���Ŀ�ǰ��$n������Ѵ�����$N��ü�޼䣡\n" NOR;
			message_vision(msg,ob,who);
			i = ob->query("max_kee");
			i = i*9/10+random(i/10)+10;
			ob->receive_wound("kee",i,who);
			COMBAT_D->report_status(ob);
			ccommand("heng");
			ccommand("say ��ô�㱾��Ҳ�����棿");
		    REWARD_D->riddle_clear(ob,"����");
		}
		ob->perform_busy(1);
		return 1;
	}
	
	command("say ��˵����˵��");
	return 1;
//	return notify_fail("��Ҫ�ش�ʲô��\n");
}
//

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		ccommand("say ��λ" + RANK_D->query_respect(ob)+"��Ҫ�������棿ţ���棬��������棿");
    return;
}


void reset()
{
        set("vendor_goods", ([
                "obj/specials/food/noodle1"					 : 10,
                "obj/specials/food/spiced1"					 : 10,
        ]) );
}



// ���p��dancing_faery@hotmail.com

