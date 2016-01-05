// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("������", ({ "figure" }) );

        set("gender", "����" );
		set("age",47);

        set("long","�����������ͣ����輫�󣬵�ȴ���ݣ�ͷ�����ף�һ������������ϳ�\n�Ŷ������ۣ������׹����䣬��һֱվ��ԶԶ�أ�ע�������ؿ͡�\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform tianwaifeixian") :),
             }) );

            set("inquiry",([
 		"���³���"  : (: jice :),
 		"�˵���"  :"action�����˶���$n��һ��һ�ֵ�������˵������������˵��ˣ�Ī�����˾����㣿\n",
 		"�˼���"  :"action�����˶���$n��һ��һ�ֵ�������˵������������˵��ˣ�Ī�����˾����㣿\n",
           ]) );

        set_skill("sword", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("feixiansword", 200);
        set_skill("13-sword", 220);

        map_skill("sword", "feixiansword");
        map_skill("parry", "feixiansword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(MAG"�ɻ꽣"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɵ���Ʒ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void init()
{
	add_action("do_assassinate","assassinate");
	::init();
}

int jice()
{
	object me;
	me = this_player();
	if (me->is_fighting())
	{
		message_vision("$N�������³��ţ����³��š�������������Ӻܿ��ɡ�\n",this_object(),me);
		return 1;
	}
	if(REWARD_D->riddle_check(me,"̽��׷Դ") != 2)
	{
		message_vision("$N�������³��ţ����³��š�������������Ӻܿ��ɡ�\n",this_object(),me);
		return 1;
	}

	if (query("doing"))
	{
		message_vision("$N�������³��ţ����³��š�������������Ӻܿ��ɡ�\n",this_object(),me);
		return 1;
	}

	message_vision("$N����$n��һ��һ�ֵ�������˵������������˵��ˣ�Ī�����˾����㣿\n",this_object(),me);

	set("doing",1);

	call_out("do_abc",4,me);

	me->start_busy(40);

	return 1;
}

void do_abc(object me)
{
	object gu,jiang,feng,lu;
	object env = environment();
	feng=this_object();
	jiang = present("figure jiang",env);
	gu = present("gu jianqiu",env);
	lu = present("luo jiafei",env);

	if (!feng || !jiang || !gu || !lu || !me)
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}
	if (feng->is_fighting() || jiang->is_fighting() || gu->is_fighting() || lu->is_fighting() || me->is_fighting())
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}
	if (environment(me) != env)
	{
		me->start_busy(3);
		set("doing",0);
		return 0;
	}

	message_vision(CYN"$NӯӯһЦ����$n�������ʱ���������ҵ���ȥ��Ժ������������\n",lu,gu);
	message_vision("$N����������һ��ת���Ժ��\n\n"NOR,lu);
	destruct(lu);

	feng->set("no_kill",1);
	jiang->set("no_kill",1);
	gu->set("no_kill",1);

	me->stop_busy();

	me->set_temp("annie/assassin",1);

	tell_object(me,HIR"ǿ����ȥ���˿����Ǵ�ɱ(assassinate)�˵��˵Ĵ��ʱ����\n"NOR);

	call_out("timeout",20,feng,jiang,gu,me);
}

void timeout(object feng,object jiang,object gu,object me)
{
	remove_action("do_assassinate","assassinate");

	me->set_temp("annie/assassin",0);
	message_vision(CYN"\n$N������üͷ�������˵���������Ļ�û������������ˡ����ʧ��\n",gu);
	message_vision("$Nվ�����ӣ�Ҳ���Ժ��ȥ��\n"NOR,gu);
	feng->set("no_kill",0);
	jiang->set("no_kill",0);
	set("doing",0);
	destruct(gu);
	return;
}

int do_assassinate(string arg)
{
	object me = this_player();
	object gu,jiang,feng,target;
	object env = environment();
	feng=this_object();
	jiang = present("figure jiang",env);
	gu = present("gu jianqiu",env);


	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 2)
		return notify_fail("��Ҫ��ʲô��\n");
	if (!me->query_temp("annie/assassin"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!arg)
		return notify_fail("��Ҫ��ɱ˭��\n");
	if (!target=present(arg,env))
		return notify_fail("��Ҫ��ɱ˭��\n");
	if (target != gu)
		return notify_fail("С�Ŀ���ϸ�ˣ���Ҫɱ�����ˣ���ݾ��ߣ�\n");
	

	me->set_temp("annie/assassin",0);

	message_vision(HIR"\n$N������â���������ְ������䣬��ס$n��\n"NOR,me,gu);
	message_vision("$N�͵ػ�ͷ�������Ŀ��ɨ��������էչ��������$n��ǰ��\n"NOR,feng,me);

	feng->kill_ob(me);
	me->kill_ob(feng);

	remove_call_out("timeout");
	call_out("timeout",20,feng,jiang,gu,me);
	call_out("nexts",16,feng,jiang,gu,me);
	return 1;
}

void nexts(object feng,object jiang,object gu,object me)
{
	string msg;
	if (!feng || !jiang || !gu || !me)
	{
		set("doing",0);
		return ;
	}
	if (environment(me) != environment(feng))
	{
		set("doing",0);
		return ;
	}
	if (!is_fighting())
	{
		ccommand("heng");
		set("doing",0);
		return ;
	}
	remove_call_out("timeout");

	message_vision(CYN"\n$N��$n��ս֮�̣����ؿͶ�Ȼѹ�����Լ��Ķ��ң��ƹ����ǵ�ս�֣��۽��˵�����ǰ��\n\n"NOR,me,feng);

	msg=HIR BLK"���ؿ������Ȼ�������������г�����һ˲����Ȼ���ʣ�����������Ҳ�����ϵ��Ĺ켣��\nֻ�ܼ���һ����ɫ����Ӱ���ŵ���������������ڳ���ն���Ŀռ�������·�ͻȻ��˺\n�飬����ѹ�������������Х�У�һ��ƥ���Ƶļ����������ؿͻ���̤��ǰն�Ķ�������\n�޿��赲֮�ƴ�Խ������\n\n"HIB"�������������������������������󡡺ס��١��١���\n\n"NOR"���ֻ�����˼���һ�����У�"HIB"��ߵ�"NOR"�������Ŀڻ���һ������ǵĿ����˿ڣ���\n( �˼���"RED"�Ѿ���������״̬������ȫʧ������в�����ʱ�����ܶ�����"NOR" )\n\n";
	message_vision(msg,feng,me);
	gu->receive_wound("kee",1,jiang);
	gu->die();

	message_vision(CYN"$Nһ������֮���ٲ���ս�������������ɣ������ͤ����һ�㣬�����ȥ��\n"NOR,jiang);
	message_vision(CYN"\n$Nһ����𣬻������г�����$n������ʽ����϶��հ��������ؿ���ʧ�ķ���׷ȥ��\n\n"NOR,feng,me);

	REWARD_D->riddle_set(me,"̽��׷Դ",3);

	tell_object(me,WHT"����ס�Ų����������µ�ʬ�壬��֪����Ǻá�\n�����˼����������������ҲӦ���˽ᡣ\n"NOR);

	destruct(jiang);
	destruct(this_object());
	return;
	
}

