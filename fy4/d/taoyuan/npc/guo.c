#include <ansi.h>

inherit NPC;


void tell_team(object who,string what)
{
	object *team;
	int i; 
	object ob,me=who;
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			tell_object(team[i],what);
		}
	}
	return ;
	
}

int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob==me) return 0;
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}


int fin()
{
	object obj;
	object me=this_player();
	object *inv;
	string a;
	int i,f,j;

	if (!QUESTS_D->verify_quest(me, "�ջ�ļ���"))
	{
		ccommand("say С���Ӳ����±����ʡ�");
		return 1;
	}

	if (me->query("quest/short") != CYN"��ȥ������豨����(end)"NOR)
	{
		ccommand("say �������û��ɰɡ�");
		return 1;
	}
		
	if (me->query_temp("annie_quest/halloween")-me->query_temp("annie_quest/halloween_done")>0)
	{
		ccommand("sigh");									// ������ expire... 300sec - 270 sec
		ccommand("say ԭ�����㶼����Щ�Ϲ���û�취����");
		ccommand("idle");
		return 1;
	}


	ccommand("jump");
	ccommand("bow");

	me->set("quest/difficulty",240);

	if (QUESTS_D->verify_quest(me, "�ջ�ļ���"))
		QUESTS_D->special_reward(me, "�ջ�ļ���");

	return 1;
}


int lic()
{

	object obj,oe;
	object me=this_player();
	object *inv;
	int i,x,y,z;

	if (me->query("quest/short") != "����Դ���������ķ���")
	{
		ccommand("say С���Ӳ����±����ʡ�");
		return 1;
	}

	me->set_temp("annie_quest/halloween",0);
	me->set_temp("annie_quest/halloween_done",0);

	ccommand("say ��Դ��ʲô����û�У�������ֻ�ܿ����Ϲ�����");
	ccommand("say ��˵���Ϲϲ�ֵʲôǮ����峤��������ÿ�쵹Ҳ�������ٰ�ʮ�����������ұ������������");
	ccommand("say ����˵���������Դӽ�ţ��������������");
	ccommand("sigh");
	ccommand("say �۴�ֿ�����ŵ���Щ�Ϲ�ѽ��û��ȥ���ܣ����Ѿ����˾���");
	ccommand("say Ҳ����ʲô���¶��������ϹϾ������ţ����ﵽ���е������ʵ");
	ccommand("say �����������кã�ȥ����Щ�ϹϾ������Ϲϰ�");
	ccommand("say ������Ҳ����������м����ϹϾ�����һ�߿���һ�߶�����תת��������������������ŵ����");

	obj=find_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	if (obj)
	{
		obj->destruct_maze();
		obj=find_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	}
	if (!obj)
		obj=load_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	if (!obj)	
		obj="/obj/dungeon/halloween"->query_maze_room(me->query("id")+"/entry");

	if (obj)
	{
		for (x=0; x<4; x++)
			for (y=0; y<4; y++)
				for (z=0; z<2; z++)
					"/obj/dungeon/halloween"->query_maze_room(me->query("id")+"/"+x+"/"+y+"/"+z);
	}

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);

	me->move(obj);
	me->set("quest/short", CYN"���������ϹϾ�"NOR);
	me->set("quest/duration",270);
	me->set("quest_time",time());

	if (obj)
		tell_team(me,HIY+me->name()+HIY"������ı��ˣ�\n"NOR);

	return 1;
}

void create()
{

	set_name("������", ({ "guo dama", "guo" }) );

	set("gender", "Ů��" );

	set("age", 50);

	set("long",

"û���˼ǵù�������ʲôʱ�������԰�ģ����ֻ�ǵõ������Ǵ���һ�����

�ĺ������ģ�Ҳû����ע�⵽����ʲôʱ�򲻼��ˡ� \n");


	set("inquiry",([
		"����": CYN"��ѽ����·����������͸����ø���͵ġ����ѳ��������������������������ˡ���"NOR,
		"�Ϲ�": (:lic:),
		"pumpkin": (:lic:),
		"����": (:lic:),
		"help": (:lic:),
		"job":	(:lic:),
		"end": (:fin:),
		"���": (:fin:),
    	]) );


	set("combat_exp", 100);

	set("attitude", "friendly");

	set("per",15);

	set("chat_chance", 2);

	

	set("chat_msg", ({

		"������̾��һ����˵������������������һ�뽭�����ɼ���������\n",

		"����������������������Ƕ�����֪����ߵĶ��»���ů�𣿡�\n",

		"������������æµ�š�\n",

	}) );

	setup();

	

    carry_object("/obj/armor/cloth")->wear();

    add_money("coin", 20);

}



int accept_fight(object me)

{

        command("say ����̫�����������Ķ��֣�");

        return 0;

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


