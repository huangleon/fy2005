// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("��·��", ({ "shanliu yinluren","yinluren","ren" }) );
        set("title","ɽ��");
        set("gender", "����" );

		set("no_kill",1);

		set("age",31);

        set("combat_exp", 3000000);

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���ַ�", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

int hi(object who)
{
	object me = who;
	if (!who)
		return 0;
	if (REWARD_D->riddle_check(who,"̽��׷Դ") != 1)
		return 0;
	
	message_vision("һ����ӰͻȻ�����һ��س���������ǰ��\n",me);
	message_vision(CYN"$NĿ���絶���������µش�����$n��\n",this_object(),me);
	message_vision("$N����ص��ͷ�������ã��ܺá�\n",this_object(),me);
	message_vision("$N˵������ȷ����Ҫ����ɽ����(Accept yes/no)\n"NOR,this_object(),me);
	me->set_temp("annie/shanliu",1);
	add_action("do_accept","accept");
	return 1;
}



int hi2(object who)
{
	object me = who;
	if (!who)
		return 0;
	if (REWARD_D->riddle_check(who,"̽��׷Դ") != 7)
		return 0;
	
	message_vision("һ����ӰͻȻ�����һ��س���������ǰ��\n",me);
	message_vision(CYN"$Nһ��$n�������ܻ��ضٽţ���ɱ�˾��³��ţ���ܺã����������ַ紫��ɱ��
������ʦ���⵽������ô���£�\n",this_object(),me);
	who->start_busy(30);
	call_out("do_ggyy",2,me,this_object(),0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$Nһ��������ѹ���ĵף������������˵����������Ǿ��³��ţ���Ϊ��ƭ�ң�",
"$n���㳤̾�����������������˼ҵ����֮���ˣ�",
"$n����������գ�����ɽ����������ɽׯ��Ǳ����̽�������˻ط罣��֮�¡�",
"$n���������л���ط罣���ģ����˹��ϵ�������ͽ�ܣ�����˭�ˣ�",
"$Nһ�㣬�����ƺ����ڳ������������������ԣ�����",
"$n��ɫ���أ����������������˼ҵ����֮���ˣ�������ɱ�˻�����ʦ������������ô������˽�����",
"$N���������ʦ����ǰ�Ļ����ɻ��������ˣ�",
"$n̾�����㲻֪������������ǻ�����ʦ����ʱ���µ�˽�ӣ�֮�������Ŵ�ң�ֻ��Ϊ�˲��谭������;ǰ�̡�",
"$N��ʧɫ��$n����ԭ��̤�Ų��ӣ��������޷��ա�",
"$n���ֵ������˰��ˣ�����������ֻ��ͽ���鷳���ѣ���֪��ˣ�����������ֱ��ɽ���ˡ�",
"$n����$N���ߣ��ֹ��˼��䡣",
});
	if (!me || !target)
	{
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n"NOR,me,target);

	if (count == sizeof(event_msg)-1)
	{
		tell_object(me,"��·������Ķ�������˵�������������������������\n");
		tell_object(me,"��·������Ķ�������˵������ȥ�����������ǰ˵�����ţ����ܽ���\n");
		tell_object(me,"��·������Ķ�������˵����ɽ���Թ���ȥ���Թ���ͷ�����˽����㡣\n");
		tell_object(me,"��·������Ķ�������˵���������ǣ�"HIC"����������ò�࣬��ˮ�����Ѷ���\n"NOR);
		tell_object(me,"��·������Ķ�������˵�����Թ����߷���"HIY"������һ����̤�ķ���Ϊǰ��\n"NOR);
		tell_object(me,"��·������Ķ�������˵����"HIY"��������������"NOR"��"HIR"��Ī̤��һ��"NOR"������ͻ�\n");
		tell_object(me,"��·������Ķ�������˵����������֮�ݡ�\n");
	}


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		message_vision("$N̾�˿������漴ת����ȥ��\n",this_object(),me);
		set("ggyying",0);
		me->start_busy(1);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"̽��׷Դ",8);
		destruct(target);
		return;
	}
	return;
}



int do_accept(string arg)
{
	object me = this_player();
	object ob = me;
	if (me->query_temp("annie/shanliu")==1 && REWARD_D->riddle_check(me,"̽��׷Դ") == 1)
	{
		if (arg == "yes")
		{
			ccommand("ok");
			message("vision",name()+"��"+me->name()+"����С����˵��Щ����\n",environment(me),ob);
			tell_object(ob,"��·�˸����㣺ɽ������ֻ��Է��ķ����������пɣ�ֻ�������д����顣\n");
			tell_object(ob,"��·�˸����㣺��ɽ"MAG"�˵���"NOR"��������ɽׯ�ϵ������ĸ�����ʦ�������ϵ�Ҳ�й��ᡣ\n");
			tell_object(ob,"��·�˸����㣺��������ħ�������������������ɱ�֡�"WHT"���³���"NOR"����\n");
			tell_object(ob,"��·�˸����㣺Ϊ�����Խ�������ʧ��ר��Ϊ������������Ҫ�������"CYN"�⽣����"NOR"��\n");
			tell_object(ob,"��·�˸����㣺ֻҪ���ܹ���ȥ��ɽ�˵��ˣ�֤���Լ��ı��£��Ҿͱ�������ɽ����\n");
			ccommand("pat "+me->query("id"));
			REWARD_D->riddle_set(me,"̽��׷Դ",2);
			message_vision("$N��$n˵�������ͣ��úøɣ�\n$N�漴ת����ȥ��\n",this_object(),me);
			destruct(this_object());
			return 1;
		}
		else if (arg == "no")
		{
			ccommand("hmm "+me->query("id"));
			message_vision("$Nһ�ﲻ����ת����ȥ��\n",this_object(),me);
			destruct(this_object());
			return 1;
		}
	}

	return 0;
}


