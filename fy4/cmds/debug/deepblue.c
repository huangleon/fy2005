// cat.c
#include <ansi.h>

inherit F_CLEAN_UP;

object env;
int damage;

int destroying(object me,object room,int n,int damage)
{
	object *inv;
	int i;	
	mapping exits;
	string *dirs, dest;
	object next_room;
	
	if(room!=env)
	{
		tell_room(room,HIB"\n�����Ĺ�â����������ӹ�������\n"NOR);
		tell_room(room,HIW"�ڳ���һ�ж���Ť�������𣬷·������������һ�㣡����\n"NOR);
	}
	room->set("destroying",1);
	room->destroy_room();
	inv=all_inventory(room);
	for(i=0;i<sizeof(inv);i++)
	{
		if(!objectp(inv[i]))
			continue;
		if(inv[i]==me)
			continue;
		if(inv[i]->is_character())
		{
			message_vision(HIB"\n$Nȫ��Ϊ�����Ĺ�â�����ţ���\n"NOR,inv[i]);
			inv[i]->delete("resistance");
			inv[i]->receive_wound("kee",damage*(n+1));
			COMBAT_D->report_status(inv[i]);
			inv[i]->set_temp("last_damage_from",me);
		}
	}
        if( mapp(exits = room->query("exits")) ) 
	{
		dirs=keys(exits);
		for(i=0;i<sizeof(dirs);i++)
		{
			dest=room->query("exits/"+dirs[i]);
			if(!next_room=find_object(dest))
				next_room=load_object(dest);
			if(!objectp(next_room)) continue;
			if(next_room->query("destroying"))
				continue;
			if(!n) continue;
			destroying(me,next_room,n-1,damage);
		}
	}
	room->delete("destroying");
	return 1;
}
	
			
int begin_perform(object me)
{
	int n;

	
	message_vision(HIG"ҫ�۵Ĺ�â�������ǧ���������ʯ��Ź�ʣ�˲�佫��Χ������룬
�ƻ�ʵ����������ţ��д�ǿ����Դ�ĹⲨ�������������һ�У���\n"NOR,me);
	n=me->query("deepblue_range");
	damage=me->query("sen");
//	if(n>10)
//		n=10;
	me->delete_temp("in_deepblue");
	me->set("gin",1);
	me->set("kee",1);
	me->set("sen",1);
	me->set("eff_gin",1);
	me->set("eff_kee",1);
	me->set("eff_sen",1);
	destroying(me,env,n,damage);
}
	
	
string *spelling_msg=({
 HIB"�ȴ󺣸���������ˣ� \n"NOR,
 HIB"����ո���������Զ��\n"NOR,
 HIB"�Ծ��ĵ�Ԩ֮�׸��֣� \n"NOR,
HIB"����������ѪΪ�ģ� \n"NOR,
HIB"���б��İ�֮���� \n"NOR,
HIB"�������ܴ�����һ�У� \n"NOR,
HIB"��֮�о��� \n"NOR,
        });


int spelling(object me,int n)
{
	if(environment(me)!=env)
	{
		me->delete_temp("in_deepblue");
		return 0;
	}
	if(n<sizeof(spelling_msg))
	{
		message_vision(spelling_msg[n],me);
		call_out("spelling",1,me,n+1);
	}
	else
		begin_perform(me);
	return 1;
}

int main(object me)
{

	
	if(!objectp(env=environment(me)))
	{
		me->delete_temp("in_deepblue");
		return 0;
	}
	if(me->query_temp("in_deepblue"))
		return notify_fail("������ʹ�á�����֮�о����С�\n");
		
	message_vision(HIR"$N˫��΢�գ����ֿ��ٵؽ�����ӡ������רע�����������\n"NOR,me);
	me->start_busy(10);
	me->set_temp("in_deepblue",1);
	call_out("spelling",1,me,0);
	

	return 1;
}
