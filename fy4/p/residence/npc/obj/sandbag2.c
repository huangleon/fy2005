#include <ansi.h>
#include <combat.h>
inherit WALL;

string heal();
void create()
{
	set_name("��ˮ", ({ "sinny","sandbag" }) );
	set("race","Ԫ��");
	set("desc","����һ������С��ɳ���������ɰ�ˮ�����ӡ�\n����������������Ĺ���������������������������\n");
	set("combat_exp",4000000);
	set("max_kee",40000);	// 20k,1% = 400kee
	set_skill("iron-cloth",100);
	set_skill("steelwall",100);
	map_skill("iron-cloth","steelwall");
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        	(: heal() :),
        }) );
	set("item_type","t");
set("tax",15);
set("score_tax",1);
	set("size",1);
	setup();
}

void init()
{
   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
}


string heal()
{
	message_vision(CYN"���Ű�ˮ�Ĵ�ɳ�����˻Σ��ڻ�ԭ����λ�á�\n"NOR,this_object());
	remove_all_killer();
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
}


int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("����#13106��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("��ͥ��Ʒֻ�������ӵ����˲����\n");
	if (!present("dismantle statue",me))
		return notify_fail("��û�к��ʵĹ����Խ��в����\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("����#13108��\n");	// ��֪����ʲô��˼...ppl report��ʱ��search index
	message_vision(CYN"$Nһ�������������ʯ����"+name()+"����ȥ�������¾Ͱ�"+name()+"�ҵ�ϡ�á�\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));

		env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// ��bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// ��bug

	env->save();
	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}


int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
	if (wizardp(this_player()))
		set("long",query("desc")+"��ϸ��ȥ����Լ�ɼ�����С�֣��������졣\n");
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

