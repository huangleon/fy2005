// waiter.c
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
    set_name("����", ({ "zhu xiang","zhu","zhuxiang","xiang" }) );
	set("gender", "Ů��" );
	set("age", 21);
	set("price_modifier",500);
	set("per",36);
	set("score",-32);
	set("str",14);
	set("title",WHT"ֻ��ʱӯ������"NOR);
	set("nickname",MAG"ѩ����� �������"NOR);
	set("long","һ�����㶯�˵ĳ�����Ů��б������ˮͤ�ķ�����\n�������Լ������¡�\n");
	set("combat_exp", 5200000);
	set("attitude", "friendly");

	set("no_arrest",1);
	
	set("chat_chance",1);
	set("chat_msg", ({
		CYN"���㳤���Ľ�ë������һ��ˮ������㣬���������⶯�ˡ�\n"NOR,
		CYN"����ҧ���촽�����ḧ���������������˼Һ����㡭��\n"NOR,
		CYN"������������һЦ���ڱ��˵ľ籾�����ɰ����������ȴ������\n�������Ǹ���ǣ���������Ҽҵ������ǲ��Ǻ�ɵ��ɵ��\n"NOR,
		CYN"����͵���ӽ��\n��ҹҹ����ҹ�����������������á�\n���Ͼ�Ȫ����룬��������ձ��䡣\n�������ת�࣬\n����ᣬ�����衣\n������������飬\n�����ϣ�����Υ��\nһ�ﲻ���⣬�Ӿ����������ɡ�\n"NOR,
		CYN"������̾����һ�ﲻ���⣬�Ӿ����������ɣ�����������������\n�ˣ������������ܵ��ģ�ǰ�˶��Ѿ����ҵ����ˡ�\n"NOR,
		CYN"�����������ۣ�һ�ξ�Ө�����黺������Ө�������գ�������\nʯ���ϣ��ɽ����顣\n"NOR,
		CYN"��������ͤ�����ϼ��ã��þò���һ�\n"NOR,
		CYN"�����ͷ�����Լ����֣�������˵�����Ǳ˴���˵�̰���ˣ�ȴ\n���ǵò����˴˵Ļ��ġ������ǣ����ܹ�˭�ء�\n"NOR,
		CYN"����б������������ͷ����������˵�������ǧ�׷Ѱʮһ\n��δ�������ģ�����ֻ����ʮ��֮һ�Ĵ��۱������ˣ������㣬\n���᲻֪�ҵ����飿\n"NOR,
		CYN"�������һЦ������֯�ɣ��ǣ�����֯�ɣ���Զ���ǽ񳯽�Ϧ��\n"NOR,
		CYN"�����ᳶ���Լ��ĳ��������������������������Ҳ����Σ�Ҳ\n��ϣ����û��ϣ������û�о������ܾ���ǰ���Ҿ;������پ����ˡ�\n"NOR,
		CYN"���������ӵס�Լ�������¶���¼ŵı��顣\n"NOR,
		CYN"�������ĵ������ڲ����٣����������꣮�������������꣮����\n"NOR,
		CYN"�����������������⵴����΢΢��Ц�������㻹�ǵã�������\n����Я���������۳���ô���С��ô��\n"NOR,
	}) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

		set("death_msg",CYN"\n$N�����Ŀڣ�������������ҧ�������㡭���ú��ġ���\n"NOR);

		setup();

		carry_object("/d/bashan/npc/obj/stone")->wear();

	
	weapon = carry_object("/d/huashan/npc/obj/qingcong");
	weapon->set_name(WHT"���곤��"NOR, ({ "slippery sleeve" }) );
	weapon->set("unit", "˫");
	weapon->set("long", "\n");
	weapon->set("weapon_wielded","��");
	weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(MAG"��������"NOR, ({ "longskirt" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/boots");
        weapon->set_name("��ɫ��Ь", ({ "shoes" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",150,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);

}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "����̧ͷ������һ�ۣ��촽�䶯�����£��ֵ���ͷȥ��\n");
			break;
		case 1:
			say( "����ĬĬ��������ˮͤ�����ϼ�������Ỻ������������С�\n");
			break;
	}
}


int accept_object(object who, object ob)
{
	object me = this_object();

	if (query("ggyying"))
		return notify_fail(CYN"����������æ����Ȼû�����㡣\n"NOR);
	if (!ob->query("real") || ob->query("id") != "paper boat" 
		|| REWARD_D->riddle_check(who,"��Ϧ����")!=1)
//		|| who->query("annie/void") != 1)
		return 0;
	set("ggyying",1);
	message_vision(CYN"\n$N����ͷ���������е�ֽ��С�����ֿ���$n�����������ҵ�ô��\n"NOR,me,who);
	set("chat_chance",0);
	who->start_busy(9);
	call_out("do_ggyy",3+random(2),me,who,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$N΢΢һЦ����Զ����ȥ����ô���ˣ����ǷŲ���ô������",
"$N��������Щ���ʣ�������˵���ǣ�����������һ���洦�ɼ��������ź�������Ȼ��û���ͻ��ء�
ƴ��һ���ݣ�����һ�ջ��������Ƕ��Ǻܾúܾ���ǰ�����Ҷ������Ѿ���ȥ�����ˡ�",
"\n˵���ף�����һ�������޷����������컣��ģ���Ϸ��������\n$Nңң�ؿ�����������Ϧ�����գ���������һ���ł�һ���ݣ���һ��ֻ��һ������Ҳ�գ�����\n�����������˵��˵��"WHT"��÷�Ѳ����ܻ�ͷ�ˣ�����Ե���Ѿ�"CYN"�������������������������ˡ�",
});

	set("chat_chance",1);

	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	set("chat_chance",0);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",3+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		REWARD_D->riddle_set( target,"��Ϧ����", 2);
//		target->add("annie/void",1);
		set("chat_chance",1);
		return;
	}
	return;
}
