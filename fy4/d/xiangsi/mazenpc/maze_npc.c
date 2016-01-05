// Po һ��
// Pe ����
// Shade ѩ������
// Mistfolk ��Ӱ
// Gaseous Phantom ��а
// Glacial Efreet ��ħ��
// ����	  Ephemeron
// ѩ���� Snowy Kirin
// �׺�	  White Fox
// ������ Icecream

#include <ansi.h>
inherit SMART_NPC;

//	Here, due to annie_quest count, we check and call give_reward directly.

void questcheck()
{
	object enemy,owner,me, *mem;
	string a,b;
    int i, num;
    
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
			enemy = owner;
	
	if (!enemy)
	{
		return;
	}
	else
		me=enemy;
	
	// Check self first, we reward ppl who does the killing first.
	if (!query("target_name") || query("target_name")=="")	return;
			
	if (query("target_name") == me->query("annie_quest/target")) 			
	{	
		// All annie_quest should be deleted/reset when getting new quests
		// Here we only need to check time.
		if (time()-me->query("quest_time") < me->query("quest/duration"))
		{
			me->add("annie_quest/number",-1);
			if (me->query("annie_quest/number")>0)
			{
				tell_team(me,WHT+me->name()+"ɱ����һ��"+query("name")+"����"+me->name()+"����������ֽ���һ����\n"NOR);
				a= me->query("annie_quest/short");
				b = replace_string(a,"XXX",""+ me->query("annie_quest/number"));
				me->set("quest/short", b);
			} else
			{
				tell_team(me,WHT+me->name()+"ɱ����һ��"+query("name")+"�������"+me->name()+"������\n"NOR);
				me ->delete("annie_quest");	// the next step should delete the quest. 
				QUESTS_D->give_reward(me,me, me->query("quest"));				
			}
			return;
		}
	}
		
	// Team time;
		
	mem = me->query_team();
	num = sizeof(mem);
	
	if (!mem || num <2)	return;
		
	for (i = 0; i< num;i++)	{
		if ( mem[i] == me)	continue;
		if (query("target_name"))
		if (query("target_name")!= mem[i]->query("annie_quest/target"))	continue;
		if (time()- mem[i]->query("quest_time") > mem[i]->query("quest/duration")) continue;
		
		mem[i]->add("annie_quest/number",-1);
		if (mem[i]->query("annie_quest/number")>0)
		{
			tell_team(me,WHT+me->name()+"ɱ����һ��"+query("name")+"����"+mem[i]->name()+"����������ֽ���һ����\n"NOR);
			a= mem[i]->query("annie_quest/short");
			b = replace_string(a,"XXX",""+ mem[i]->query("annie_quest/number"));
			mem[i]->set("quest/short", b);
		} else
		{
			tell_team(me,WHT+me->name()+"ɱ����һ��"+query("name")+"�������"+mem[i]->name()+"������\n"NOR);
			mem[i] ->delete("annie_quest");	// the next step should delete the quest. 
			QUESTS_D->give_reward(mem[i],me, mem[i]->query("quest"));				
		}
		return;	
	}
	
	return;
}



void die()
{
	object me=this_object(),item;
	object who ;
	string * list;
	mapping drop;
	int cd,rd,bg,seed,amount,i;

	questcheck();

	drop = query("drop");
	if (!drop || !mapp(drop))
	{
		::die();
		return;
	}
	cd = drop["common"];
	rd = drop["rare"];
	bg = drop["bg"];

	if (query_temp("last_damage_from"))
		who = query_temp("last_damage_from");
	if (!who)
		who = this_object();

	amount = drop["amount"];
	amount = random(random(amount)+1)+1;

	seed = random(100)+1;
	if (seed <= bg)							// BG
	{
		ccommand("say BG lah��");
		::die();
		return;
	}

	for (i=0; i<amount; i++)
	{
		seed = random(cd+rd)+1;
		if (seed > rd)						// Common drop
		{
			list = drop["common_drop"];	
			cd = random(sizeof(list));
//			ccommand("say ����һ"+list[cd]+"��");
			item = new(list[cd]);
			item->move(me);
			ccommand("say ����һ"+item->query("unit")+item->name()+"��");
		}
		if (seed <= rd)						// Rare Drop
		{
			list = drop["rare_drop"];	
			cd = random(sizeof(list));
//			ccommand("say ����һ"+list[cd]+"��");
			item = new(list[cd]);
			ccommand("say "+HIY+"����һ"+item->query("unit")+item->name()+HIY+"��"+NOR);
			item->move(me);
		}
		if (query("real_ph") || query("real_boss"))
		{
		CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)�ڱ�ѩ�Թ���ɱ����%s(%s)���õ���%s��\n",
	                who->query("name"),who->query("id"),query("name"),query("id"),item->query("name")));

		log_file("riddle/annie_log", sprintf("[%s] %s(%s)�ڱ�ѩ�Թ���ɱ����%s(%s)���õ���%s��\n",
			ctime(time()), who->query("name"),who->query("id"),query("name"),query("id"),item->query("name")));
		}
	}

	::die();
}



void heart_beat()
{
	if (!query("set_room"))
	{
		set("set_room",1);
		set("startroom",environment());
	}
	::heart_beat();
}
	

/* ������ maze drops

��Ʒ������:

����/�м�: ��

�߼�
/d/xiangsi/mazenpc/obj/fakemoveupdrug.c
/d/xiangsi/mazenpc/obj/hastedrug.c
/d/xiangsi/mazenpc/obj/snowball.c
/d/xiangsi/mazenpc/obj/arcticwind.c
/d/xiangsi/mazenpc/obj/statdrug.c
/d/xiangsi/mazenpc/obj/lockupdrug.c
/d/xiangsi/mazenpc/obj/moveupdrug.c
/d/xiangsi/mazenpc/obj/seal.c
/d/xiangsi/mazenpc/obj/snowball2.c
/d/xiangsi/mazenpc/obj/glacialcrevasses.c
/d/xiangsi/mazenpc/obj/cash.c
/d/xiangsi/mazenpc/obj/herb.c

����
/d/xiangsi/mazenpc/obj/boots.c
/d/xiangsi/mazenpc/obj/flask.c
/d/xiangsi/mazenpc/obj/panacea.c


����
/d/xiangsi/mazenpc/obj/incense.c

����NPC
/d/xiangsi/mazenpc/obj/kirinheart.c
/d/xiangsi/mazenpc/obj/nacrissus_boot.c
/d/xiangsi/mazenpc/obj/nail.c



����

# ��Ч����

��7��������Ҫ�������
/d/xiangsi/mazenpc/obj/scroll.c

������:

// !M ����	
// Po һ��
// Pe ����
/d/xiangsi/mazenpc/obj/binglunyinjing_1.c
/d/xiangsi/mazenpc/obj/bingpojingbi_1.c

// Shade ѩ������  2M
// Mistfolk ��Ӱ  3.5M
// Gaseous Phantom ��а
/d/xiangsi/mazenpc/obj/hanxueliulan_1.c
/d/xiangsi/mazenpc/obj/mingyue_1.c
/d/xiangsi/mazenpc/obj/qinghui_1.c

// Glacial Efreet ��ħ�� 5M
// ����	  Ephemeron		 6M
// ѩ���� Snowy Kirin	 7M
/d/xiangsi/mazenpc/obj/bingpojingbi_2.c
/d/xiangsi/mazenpc/obj/hanxueliulan_2.c
/d/xiangsi/mazenpc/obj/mingyue_2.c
/d/xiangsi/mazenpc/obj/qinghui_2.c
/d/xiangsi/mazenpc/obj/qixingbanyue_1.c
/d/xiangsi/mazenpc/obj/shuanghuaningjie_1.c
/d/xiangsi/mazenpc/obj/zhaoyuwanqing_1.c

// �׺�	  White Fox		8M
// ������ Icecream		9.5M
/d/xiangsi/mazenpc/obj/hanxueliulan_3.c
/d/xiangsi/mazenpc/obj/mingyue_3.c
/d/xiangsi/mazenpc/obj/qinghui_3.c
/d/xiangsi/mazenpc/obj/shuanghuaningjie_3.c
/d/xiangsi/mazenpc/obj/qixingbanyue_2.c
/d/xiangsi/mazenpc/obj/shuanghuaningjie_2.c
/d/xiangsi/mazenpc/obj/zhaoyuwanqing_2.c

# �����Ƶ��������һ��BOSS����
/d/xiangsi/mazenpc/obj/bingpojingbi_3.c
/d/xiangsi/mazenpc/obj/hanxueliulan_4.c
/d/xiangsi/mazenpc/obj/zhaoyuwanqing_3.c


# ��Ч����
/d/xiangsi/mazenpc/obj/bingpojingbi_4.c
/d/xiangsi/mazenpc/obj/binglunyinjing_2.c
/d/xiangsi/mazenpc/obj/budongzhijie_1.c
/d/xiangsi/mazenpc/obj/hanlingluoxue_1.c
/d/xiangsi/mazenpc/obj/hanlingluoxue_2.c
/d/xiangsi/mazenpc/obj/hanlingluoxue_3.c
/d/xiangsi/mazenpc/obj/hanlingluoxue_4.c
/d/xiangsi/mazenpc/obj/liulongbingjia_1.c
/d/xiangsi/mazenpc/obj/liulongbingjia_2.c
/d/xiangsi/mazenpc/obj/liulongbingjia_3.c

/d/xiangsi/mazenpc/obj/tianheyixian_1.c
/d/xiangsi/mazenpc/obj/tianheyixian_2.c
/d/xiangsi/mazenpc/obj/wufangbianhuan_1.c
/d/xiangsi/mazenpc/obj/wufangbianhuan_2.c
/d/xiangsi/mazenpc/obj/wufangbianhuan_3.c



*/	