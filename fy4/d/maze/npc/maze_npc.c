#include <ansi.h>
inherit SMART_NPC;

//	mapping damage_list=([]);


//	����maze_npcû�������startroom���á�	
void heart_beat() {
	if (!query("set_room")) {
		set("set_room",1);
		set("startroom",environment());
	}
	:: heart_beat();
}
	
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
	questcheck();
	::die();
}