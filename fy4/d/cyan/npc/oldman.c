// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;


int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob==me) return 1;
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}

int lic()
{
	object obj;
	object me=this_player();
	object *inv;
	int i;

	if (me->query("quest/short") != "����ϼɽ����ĺ���˽�һ������Ĺ���")
	{
		ccommand("say С���Ӳ����±����ʡ�");
		return 1;
	}
//goto /d/phoenix/cyan2/peak3;updatep /d/phoenix/cyan2/npc/;update here;l
	set("mud_age",999999);
	ccommand("cemote $ME$�������ֳ���Ȼ��������ɫ��");
	ccommand("chat ��˵���꣮����");

	obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan2/peak3");
	if (!obj)
		obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan2/peak3");

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);

	me->move(obj);
	obj->do_start(me);
	
	me->set("quest/short", "������ϼɽ�t��̨"NOR);
	me->set("quest/duration",1800);
	me->set("quest_time",time());
	message_vision(HIY+me->name()+HIY"������ı��ˣ�\n"NOR,me);

	return 1;

}

void create()
{
		object weapon;
        set_name("��ĺ����", ({ "oldman" }) );
        set("gender", "����" );

		set("chat_chance",1);
		set("chat_msg", ({
			"��ĺ����̾�������갵ת���������ţ��������Ű���\n",
			"��ĺ����������߳��������ֳ�������������ɫ��\n",
			"��ĺ�����������Žڣ���������ǰ�죬����ӡ���һ�������Ҷ���������󡭡�\n",
			"��ĺ���˵͵�̾Ϣ������һ˲�����һ������ɽ����ʱ���ݣ�����б�֡�\n",
		}) );
		set("NO_KILL","���˺ܿ�������ˣ��α��ٻ������أ�\n");
		
		set("age",87);

        set("combat_exp", 7800000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

        set("inquiry",([
 			"����"  : 	(: lic :),
 			"����"  : 	(: lic :),
 			"����Ĺ���"  : (: lic :),
 			"������"  :	 (: lic :),
 			"job"  : (: lic :),
 			"story"  : (: lic :),
        ]) );

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
		set("perform_busy_d","huashan/throwing/tanzhi-shentong/tanzhijinghun");

		setup();

        weapon=carry_object("/obj/weapon/dart");
        weapon->set_name("���ƽ�", ({ "gold" }) );
		weapon->set("unit","");
		weapon->set("base_unit","");
		weapon->set("value",0);
		weapon->set("no_transfer",1);
		weapon->set_amount(16);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ϴ�÷��׵Ļ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
