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

	if (me->query("quest/short") != "����ϼɽ��Ϲ��ƽ�ߴ������")
	{
		ccommand("say С���Ӳ����±����ʡ�");
		return 1;
	}

	set("mud_age",999999);
	ccommand("emote ����һЦ���Ҹ�����������");
	message_vision(CYN"\n������ƽ���ڴ�������ת��ת��һ��������˷���\n\n"NOR,this_object());

	obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan4/peak3");
	if (!obj)
		obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan4/peak3");

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);


	me->move(obj);

	tell_object(me, CYN"ƽ��ͣס�Ų�������˵���������ˣ���������������һ��ʱ��������·����
��һ��ɱһ��������һ�������̻�����

ƽ�߷���һ˫�������İ��ۣ���Ц����ɱԽ�࣬ǮԽ�࣬��Ҫ���ʣ���Ҫ��˵��֪����\n"NOR);

	i=6+random(3);
	me->set("quest/short", "��ɱ����·���˴�֮�ˣ�����"+CHINESE_D->chinese_number(i)+"����"NOR);
	me->set("quest/duration",3600);
	me->set("quest_time",time());
	me->set_temp("annie_quest/cyan43",i);
	tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);

	obj->do_start(me);

	return 1;

}

int lcic()
{
	object obj;
	object me=this_player();
	object *inv;
	string a;
	int i,f,j;

	if (me->query("quest/short") != WHT"��ȥ��ƽ�ߴ���"CYN"�������"NOR)
	{
		ccommand("say С���Ӳ����±����ʡ�");
		return 1;
	}

	set("mud_age",999999);
	i=me->query_temp("annie_quest/cyan4");
	ccommand("hmm");
	f=1;
	a="��ɱ��"+CHINESE_D->chinese_number(i)+"���ˣ�";
	j=me->query_temp("annie_quest/cyan43");
	if (i<j)
	{
		a+="ʵ����̫��ˡ�";
		f=2;
	}
	if (i>= j && i<j+3)
	{
		a+="�������й��оذɡ�";
		f=3;
	}
	if (i>= j+3 && i<j+20)
	{
		a+="ʵ�ڸɵò���";
		f=4;
	}
	if (i>= j+20)
	{
		a+="���ã��ã��Ϸ��Ѿ��кܶ���û����������ô���ڵĸ����ˣ�";
		f=6;
	}

	ccommand("say "+a);
	if (f==2)
	{
		ccommand("emote ҡͷ����ȥ�ٺú��������հɡ�");
		return 1;
	}
	me->set("quest/difficulty",f*80);
	if (QUESTS_D->verify_quest(me, "Ϲ��ƽ��"))
		QUESTS_D->special_reward(me, "Ϲ��ƽ��");



	return 1;

}

//update d/phoenix/cyan4/peak3;updatep /d/phoenix/cyan4/npc/;update d/cyan/npc/ping;update here;
void create()
{
	object weapon;
        set_name("ƽ��", ({ "ping qi","pingqi","ping" }) );
		set("nickname",HIR BLK"Ϲ��"NOR);
        set("title",BLK"����֮��"NOR);
        set("gender", "����" );
		set("class","huashan");

		set("age",57);

        set("long","���㵴ɽһսϹ��ƽ�߳����������Ѿ�������ꡣ�����\n���ｭ�����˲ű�����Ȼ��ȴ�����˸���ƽ����ս����Ϊ��ô\n���Ľ�������Ǹ�������ս����������һ����\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"ƽ��ִ��ä�ȣ��������ɽ�����ô�\n",
			"ƽ��߶�������ط�û��������\n",
		}) );

        set("combat_exp", 7500000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


        set("inquiry",([
 		"help"  : (: lic :),
 		"�������"  : (: lcic :),
 		"job":		(: lic :),
 		"����":		(: lic :),
        "����":		(: lic :),
              ]) );


		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("ä��", ({ "guide staff","staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dart");
        weapon->set_name("����֮��", ({ "iron star","star" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ϴ�÷��Ƶİ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);

		set_skill("staff",220);
		set_skill("dagou-stick",200);
		map_skill("parry","dagou-stick");
		set("perform_weapon_attack3","begger/staff/dagou-stick/tianxiawugou");
}
