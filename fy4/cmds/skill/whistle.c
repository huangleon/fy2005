
#include <ansi.h>
inherit F_CLEAN_UP;
#define DEATH_PERIOD 1200
int main(object me, string arg)
{
	object pet;
	object *ob_list;
	int i;
	string id,name;
	string file;
	if(me->is_busy() || me->is_ghost() || me->query("sen") <= 50)
            	return notify_fail("�����ڲ����Դ����ڡ�\n");
        if (me->query("timer/whistle")+10>time())
        	return notify_fail("�㲻�����������ڣ����ټ��10�룩��\n");
        me->set("timer/whistle",time());
        write("������ش��������ڡ�����\n");
	if(environment(me)->query("NONPC")) return notify_fail("���ʲô����Ҳû�С�\n");
	file = me->query_save_file();
	file += ".pet.o";
	ob_list = children("/obj/npc/pet");
	for(i=0; i<sizeof(ob_list); i++) 
		if(ob_list[i]->query("possessed") == me)
			pet = ob_list[i];
	if(!pet && file_size(file) > 0 )
	{
		seteuid(getuid());
		pet = new("/obj/npc/pet");
		pet->set("owner",me->query("id"));
		pet->restore();
		id = pet->query("id");
		name = pet->query("name");
		pet->set("id",id);
		pet->set_name(name,({id}));
		pet->set("possessed",me);
		pet->setup();

	}
	me->add("sen",-50);
	if(pet && environment(pet) != environment(me) 
		&& time() - (int)pet->query("deathstamp") > 1200
		&& !pet->is_fighting())
	{
		pet->move(environment(me));
		pet->reset_action();
		message_vision("$N��֪������ܵ�$n��ǰ��\n",pet,me);	
// let pet be our protector
		if(me->is_fighting())
		{
			object *enemy;
			enemy = me->query_enemy();
        		i = sizeof(enemy);
        		while(i--) {
                		if( enemy[i] && living(enemy[i]) ) {
                        		pet->kill_ob(enemy[i]);
                        		if( userp(enemy[i]) ) enemy[i]->fight_ob(pet);
                        		else enemy[i]->kill_ob(pet);
			    	}
			}
        		me->remove_all_killer();
		}
		pet->add("sen",-10);
		pet->set_leader(me);
		if (pet->query("gin")<0 || pet->query("kee")<0 ||pet->query("sen")<0)
			pet->die();
		return 1;
	}else	if (pet) 
			{
			pet->save();
        		message_vision("$Nһ���Ͳ����ˡ�\n",pet);
			destruct(pet);
			return 1;
	}
	return notify_fail("���ʲô����Ҳû�С�\n");
}



int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	whistle <������>[0m
[0;1;37m����������������������������������������������������������������[0m   

����뿴�����ļ��еġ�����ƪ�� 

[0;1;37m����������������������������������������������������������������[0m 
HELP
        );
        return 1;
}
