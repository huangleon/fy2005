#include <ansi.h>
inherit NPC;

void create()
{
		object weapon;
        set_name("����", ({ "ou hao","oho" }) );
        set("gender", "����" );
		set("title",YEL"һ��ʮ����"NOR);
		set("nickname",RED"�������"NOR);
        set("age", 24);
		set("per",1);
        set("long","һ����üб�ۣ����������С������\n");
        set("attitude", "heroism");
        set("combat_exp", 20000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������Ҹ������һֻʭ���׽����ҧ�ø�֨���졣\n",
                "����������һ�۵�����ɶ����û����Ӣ�����������˫ȫ�����ꣿ\n",
                "�����ٺ���Ц���������Ҿ��������������ˡ�\n",
                "������Ц��������ȥ���Ұ���ֻҪ�㲻����XXX��\n",
                "����һ����ͷ����Ĩ��ˮ��һ�ߵ�������ظ���������˧������Ҫ��������������Ҫ��ù������\n",

        }) );

        setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("������", ({"iron stick","stick" }) );
		weapon->set("long","����һ�ѽ���С��쳣�õĴ�������\n");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ζ���ı���", ({ "pungent cloth","cloth" }) );
		weapon->set("long","һ��ɢ������ζ�ı��ġ�\n");
		weapon->set("value",0);
		weapon->wear();

		carry_object(__DIR__"obj/coconut");

}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("����Ŀǰ��ѧ�����ּ��ܣ�\n\n͵������֮�� (stealing)                  - "HIW"��ɲ�"NOR" 200/    0\n�Դ�����֮�� (blowing)                   - "HIW"��ɲ�"NOR" 200/    0\n��ҥ����֮�� (rumour)                    - "HIW"��ɲ�"NOR" 200/    0\n��������֮�� (cheating)                  - "HIW"��ɲ�"NOR" 200/    0\n\n");
	return 1;
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_enjoy","enjoy");
	add_action("do_listskill","skills");
	add_action("do_listskill","betaskills");
	add_action("do_accept","accept");
}

void greeting(object ob)
{
	object me = this_object();
	object * tar;
	int i;
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query_temp("marks/oho") == 2  && ob->query("combat_exp") >= 1000000)
	{
		message_vision(CYN"$N����$n���������ۣ�����������\n"NOR,me,ob);
		message("vision",name()+"��"+ob->name()+"����С����˵��Щ����\n",environment(me),ob);
		tell_object(ob,"��������Ķ�������˵�����ֵ���ʶ���������ѣ������и���֯����\n");
		if (ob->query("gender") == "����")
			tell_object(ob,"��������Ķ�������˵����ɽ������������ɽ����ү��Ҫ�Ǵ����\n");
		else
			tell_object(ob,"��������Ķ�������˵����ɽ������������ɽ����������Ҫ�����\n");
		tell_object(ob,"��������Ķ�������˵�����룬�ֵܿ�����������(accept yes/no)\n");
		ob->set_temp("marks/oho",3);
	}
	if (ob->query("gender") == "����")
	{
		if (!ob->query_temp("marks/oho"))
		{
			message_vision(CYN"$N����$n���������������˹��������Ƕ������ӹ��ò�������������\nǮ�����ֵܻ����ɣ�\n"NOR,me,ob);
			ob->set_temp("marks/oho",1);
			return;
		}
		if (ob->query_temp("marks/oho") == 1)
		{
			message_vision(CYN"$N����$n���ٺ���Ц�žʹ�����ȥ��������$n�ı���\n$N˵������������Ƕ�������ͦ��İ����ֵ������Ǯ�����裿\n$N����������һ�ڣ�̧�����б������$n���㲻�������ӻ���ϡ���ء�\n$Ņ��üë���߿������⵽һ�ߡ�\n"NOR,me,ob);
			tell_object(ob,RED"��ֻ����һ����ʹ�Ա��Ĵ�����ԭ���ѱ�����͵͵����һ����\n"NOR);
            ob->receive_wound("kee",ob->query("kee")/100-1,this_object());
			return;
		}
		if (ob->query_temp("marks/oho") == 2)
		{
			message_vision(CYN"$NԶԶ�ļ���$n��ӭ����ȥ����ͷ����������ү���������զ�пչ�������\n"NOR,me,ob);
			return;
		}
	}
	if (ob->query("gender") == "Ů��")
	{
		if (!ob->query_temp("marks/oho"))
		{
			message_vision(CYN"$N����$n���۽�������һ����Ц����$n����֣������벻���㱾����\n�����(enjoy)��\n"NOR,me,ob);
			ob->set_temp("marks/oho",1);
			return;
		}
		if (ob->query_temp("marks/oho") == 1)
		{
			message_vision(CYN"$N���´���������$n����Ц����Ӵ���ⲻ���ϻصĻ�������\n$Nб�������˹�������������$n��ȴ��$nһ�������\n$N���˸�ûȤ���ٺٸ�Ц������ڨڨ���ߵ�һ�ԡ�\n"NOR,me,ob);
			tar = all_inventory(ob);
			i=sizeof(tar);
			if (i)
				for (i=0;i<sizeof(tar) ; i++)
					if (tar[i]->query("armor_type") == "cloth" && !tar[i]->query("no_get") && !tar[i]->query("no_drop"))
						tar[i]->move(this_object());
			return;
		}
		if (ob->query_temp("marks/oho") == 2)
		{
			message_vision(CYN"$NԶԶ�ļ���$n��ӭ����ȥ����ͷ�������������̣��������զ�пչ�������\n"NOR,me,ob);
			return;
		}
	}
}

int do_accept(string arg)
{
	object me = this_player();
	object ob = me;
	if (me->query_temp("marks/oho")==3)
	{
		if (arg == "yes")
		{
			ccommand("nod");
			message("vision",name()+"��"+me->name()+"����С����˵��Щ����\n",environment(me),ob);
			tell_object(ob,"��������Ķ�������˵����Ҫ��ɽ������ʵʮ�ּ򵥡�\n");
			tell_object(ob,"��������Ķ�������˵�����㵽"MAG"�Ǹ����Կ���һ�еĺ�"NOR"�ߴ������ڣ��ͻ����˽�Ӧ��\n");
			ccommand("grin "+me->query("id"));
			REWARD_D->riddle_set(me,"̽��׷Դ",1);
/*
			tell_object(ob,"��������Ķ�������˵�������������������������\n");
			tell_object(ob,"��������Ķ�������˵������ȥ�����������ǰ˵�����ţ����ܽ���\n");
			tell_object(ob,"��������Ķ�������˵����ɽ���Թ���ȥ���Թ���ͷ�����˽����㡣\n");
			tell_object(ob,"��������Ķ�������˵���������ǣ�"HIC"����������ò�࣬��ˮ�����Ѷ���\n"NOR);
			tell_object(ob,"��������Ķ�������˵�����Թ����߷���"HIY"������һ����̤�ķ���Ϊǰ��\n"NOR);
			tell_object(ob,"��������Ķ�������˵����"HIY"��������������"NOR"��"HIR"��Ī̤��һ��"NOR"������ͻ�\n");
			tell_object(ob,"��������Ķ�������˵����������֮�ݡ�\n");
*/
//			me->set("annie/demon_feng",1);
			return 1;
		}
		else if (arg == "no")
		{
			ccommand("fool");
			return 1;
		}
	}

	return 0;
}


void die()
{
	object who = query_temp("last_damage_from");
	if (!who)
	{
		::die();
		return;
	}
	who->set_temp("marks/oho",2);
	ccommand("slap");
	message_vision(CYN"\n$N��е������ˣ�������С�İɣ�С�������������Ǯ��Т�����ϣ�\n"NOR,this_object(),who);
	::die();
	return;
}

int accept_object(object me, object obj)
{
	if (me->query_temp("marks/oho") == 2)
	{
	    command("say ����ô�ң�����ô�ҡ�");
		command("lick "+me->query("id"));
	    command("say С��С�����ƣ���������ū�ŵ���˼����������ʹ����");
        return 1;
	}

	if (me->query_temp("marks/oho") == 1 && me->query("gender") == "����")
	{
		command(":)) "+me->query("id"));
		if (obj->query("value") < 10000)
		{
			command("say ��ô�����ô����");
			command("fangpi");
			command("say ��������Ҫ��Сү���Ĳ����㣡");
			return 1;
		}
		command("say ����ô�㣿");
		command("tnndx");
		command("say ���ˣ����ӽ������鲻�����ɡ�");
		me->set_temp("marks/oho",0);
        return 1;
	}
	command("heihei "+me->query("id"));
    return 1;
}

int do_enjoy()
{
	object me,room,ob;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	ob = this_player();
	if (ob->query("gender") != "Ů��")
		return 0;
	if (ob->query_temp("marks/oho") != 1)
		return 0;
	ob->set_temp("marks/oho",0);

	message_vision("\n$N������ķ�צ��$n���˹�ȥ��\n",this_object(),me);
	
    inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		destruct(inv[i]);
	}
	message_vision("$Nֻ����һ�ɼ������ŵ����֮����$n���ϴ���������\n", me,this_object());
	me->unconcious();
	ccommand("grin");
	message_vision("$n������$N���ɿ���뿪�ˡ�\n\nƬ�̣�$n��������Ŀ��Ŷ������˻�����\n", me,this_object());
	room = find_object("/d/qianjin/troom");
	if (!room)
		room = load_object("/d/qianjin/troom");
	me->apply_condition("hualiu_poison",100);
	me->move(room);
	room = new("/d/qianjin/obj/broken_cloth");
	room->move(me);
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

