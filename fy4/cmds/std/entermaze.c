
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,room2,who,*mem;
	int pwd, i, j,mm,count, max_exp, combatexp;
	string name; 
	object *dungeon_list;
	
	seteuid(getuid());
	
	// �������ǲ���ʵ�ʣң��������Ǻţ����н���������������˽���
	// This is the primary quest owner 
	if (me->query("private_maze/destination") == base_name(environment(me))+".c"
		 && me->query("quest/quest")== "������ɮ������" ) {
		
		if (me->query("quest_time")+ me->query("quest/duration")< time()) {
			tell_object(me,"̫���ˣ������Ѿ��ŷ�ת�ƣ��������ʧ���ˡ�\n");
			return 1;
		}
		
		if (!arg)
			who = me;
			else who = present(arg, environment(me));
		if (!who)
			return notify_fail("�����Χû������ˡ�\n");
		
		if (!userp(who))
			return notify_fail("���˲�Ը���Ϊ��Ļ�顣\n");
				
		// If it's the first time, prepare the instance parameters for other people's entry.
		if (me->query("private_maze/create"))	{
			
		// ��ԭ����Dungeon����
			dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
			mm = sizeof(dungeon_list);
			for (i=0;i<mm;i++){
				if (dungeon_list[i]->query_owner()== me->query("id")) {
					dungeon_list[i]->refresh_maze();
				}
			}
						
			room2=load_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");			
			if (!room2)	
				room2="/obj/dungeon/standardmaze"->query_maze_room(me->query("id")+"/entry");
			if (!room2) 
				return notify_fail("Oops.Please report to wizards. \n");	
		
			me->set("private_maze/create",0);	// ��Ϊ�����٣�����ʱ��������owner�˳������Ա�������create�Ĵ�����
						
			// Maze_exp �����ڶ�������ߵľ���ֵ�����������е��˿϶��ܰ�æ
			mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
    		j = sizeof (mem);
    		while (j--)	{
				if (mem[j]) {
		    		max_exp = mem[j]->query("combat_exp");
		    		if (max_exp > 15000000) max_exp = 15000000;
		    		combatexp = (max_exp>combatexp) ? max_exp : combatexp;
				}
    		}
			room2->set("maze/exp", 	combatexp); 			

			room2->set("maze/type", me->query("private_maze/type"));
			room2->set("maze/exit", me->query("private_maze/destination"));
			room2->set("maze/name", me->query("private_maze/orig_name"));
			room2->set("maze/sig",	me->query("private_maze/maze"));
			room2->set("maze/npc_killed",me->query("private_maze/carried_npc"));
				me->delete("private_maze/carried_npc");
			
					room2->query("maze/sig")->set_link_exit_room(room2->query("maze/exit"));
					room2->query("maze/sig")->set_link_entry_room(room2->query("maze/exit"));

			room2->set("maze/boss",		"/obj/dungeon/boss");	
			room2->set("maze/blocker",	"/obj/dungeon/blocker");	
			room2->set("maze/npc_pfm_chance", me->query("private_maze/difficulty"));
			
			tell_object(me,sprintf("��������%s�����ɹ������������ߵȼ�Ϊ%s���������%s�ˡ�\n",
						me->query("private_maze/orig_name"),
						chinese_number(F_LEVEL->get_level(room2->query("maze/exp")) +5),
						chinese_number(room2->query("maze/type"))));
							
		}
		
		room2 = find_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");
		if (!room2 && !me->query("private_maze/create"))
			return notify_fail("��������Ѿ��������߹�ʱ���޷��ٽ��룯�����µ�����\n");
	
		if (F_LEVEL->get_level(who->query("combat_exp")) > F_LEVEL->get_level(room2->query("maze/exp")) +5)
			return notify_fail("���������������ߵȼ����ܳ���"+ (F_LEVEL->get_level(room2->query("maze/exp"))+5)+"��\n");
		
		count = sizeof(room2->get_players());
		if (count >= room2->query("maze/type"))
			return notify_fail("��������Ϊ���ܣ������˶࣬�Ѳ����ٽ����ˡ�\n");
		
//		me->set_temp("maze_entry",environment(me));	
		
		if (who->is_busy()|| who->is_fighting())
			return notify_fail("����������æ���У��޷��ƶ���\n");
					
		who->move(room2);
		tell_object(who, WHT"\n����"+me->name()+"������" + me->query("private_maze/orig_name")+ "����������ǳ��״ݻ����\n"NOR);
		if (who!=me)
			tell_object(me,WHT+who->name()+"�ѽ��������������\n"NOR);
		
//		tell_object(me,"file name is " + base_name(room2));		
		return 1;	
	}
	
	return 0;	
	
}

int help (object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[1;36m		entermaze [name] 	
[0;1;37m����������������������������������������������������������������[0m   
 
������ɽ�������Լ������˵��������������ɴ������˸�����
�ӵ������Ѱ�ҵ���صص㣬ʹ�ø��������ܽ���һ������������

���ڳ�����������˵��ֻ������ entermaze ���ܽ���

��ͬ�������������в�ͬ���������ƣ��ڸ�������ʱ�������˵����
�������޸ߵģ��ѶȾͻ��һЩ����Ȼ����Ҳ���ߡ�

������������̫�ѣ������Щ���������󣬿�������ڴ�ִ��ָ��
entermaze id	����id�����ѵ�Ӣ������

������û��������ƣ��������̫�ѣ�������ʱ������������æ����
��ڴ�ִ��ָ��
entermaze id	����id�����ѵ�Ӣ������
��Ȼ�����ѵľ���ȼ����ܱ��������Ҫ���̫�ࡣ
�������󣬽������ɵ�ʱ���ڸ��������������˷������ǵ�����
��Ҳ�������˰�æ����Ȼ�����Լ��͵ò��������ˡ�

������һ����ڣ������������ӣ�ʱ�䵽������ɺ��Զ����٣�����
�������ˡ�ʬ���ƶ�����ڷ��䡣


[0;1;37m����������������������������������������������������������������[0m    
HELP
	);
	return 1;
}

