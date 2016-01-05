inherit SMART_NPC;
#include <ansi.h>


int do_exp(string arg);

string *first_name = ({ 
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","����","����","����","����",	});
string *name_words = ({ "��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��", });

void create()
{
	set_name("�հ�����", ({ "boss" }) );
	set("long", "һ�����ϻ��Ÿ������ʺŵġ�û����Ŀ���ˡ�\n");
//	set("drop_rate",15);
	
	set("dd",1);	// default difficulty
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	   	(: auto_smart_fight(100) :),    
    }) );
	set("attitude", "friendly");	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void die(){
	
	object room2,book;
	int n,i;
	
	environment(this_object())->set("cleared",1);
	
	room2 = find_object("/obj/dungeon/standardmaze/"+ environment(this_object())->query("mark_ob")+"/entry");
	if (room2) {
		room2->add("maze/leader_killed",1);	// Boss ������
		room2->set("maze/cleared",1);
		n = room2->query("maze/type");
		if (room2->query("maze/exp")>= 6100000)
		for (i=0;i<n;i++){
			book=new("/obj/item/treasurebook");
			book->move(this_object());
		}		
//		room2->check_quest();
	}
	::die();
}


int invocation(int exp)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, name;
    int loop;
	string tmp1,tmp2;
	int flag,best_basic_skill=1,best_adv_skill=1;
	mapping skl,map;
	string *sname,*mapped;
	
	if (!exp)
		exp = 10000000;

	set("combat_exp",exp);

	auto_npc_setup("bandit",200,200,1,"/obj/weapon/","random","random",query("dd"));

	do_exp(query("combat_exp")+"");
	set("title",WHT+query("maze/name")+ " ����"NOR);

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
	
	set_name(name, ({ "bandit leader","leader" }) );
	set("long", "���˿�������������죬���ݺݵص����㡣\n");
	set("group","standardmaze_bandit");
	return 1;
}


int do_exp(string arg)
{
	// exp calc inherited from my in ^^
	int exp;
	int pow_exp;
    int loop;
	int a_skill, b_skill;
	mapping skl,map;
	string *sname,*mapped;

	int flag,enforce,best_force=1;

	if (!arg)
		return notify_fail("[Usage]: Exp <NPC-EXP>\n");
	exp = atoi(arg);
	set("combat_exp",exp);

	b_skill = 250;

	pow_exp = to_int(pow(to_float(exp*10),0.3334));

	skl = query_skills();
	if (sizeof(skl))	// ����skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		map = query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
		{
			
			if (sname[loop] == "xuezhan-spear") a_skill = 250;
				else 	a_skill = 200; 
				 
			// Basic skill : cap @ 300 | ��ϵ��1.6����.
			if (SKILL_D(sname[loop])->effective_level() == 50)
//				if (skl[sname[loop]] > 300 || skl[sname[loop]] > pow_exp*100/160)
				set_skill(sname[loop],b_skill >pow_exp*100/160?pow_exp*100/160: b_skill);	// 

			// Advance skill : cap @ 200.
			if (SKILL_D(sname[loop])->effective_level() != 50)
				set_skill(sname[loop],a_skill>pow_exp*100/SKILL_D(sname[loop])->effective_level()?pow_exp*100/SKILL_D(sname[loop])->effective_level():a_skill);	 

			if (SKILL_D(sname[loop])->valid_enable("force"))
				if (SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force)
					best_force = skl[sname[loop]];

		}
	}

	"/feature/nada.c"->reset_npc(this_object());
	full_me();
	message_vision("\n",this_object());

	return 1;
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
