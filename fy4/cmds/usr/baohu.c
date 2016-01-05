// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string id, id2;
	object obj, old_obj,*pros,*pros_real;
	int i, remove_me;
	
	if (!arg)
		return notify_fail("ָ���ʽ : baohu <����>\n");
	
	if (userp(me))
	{
		if(!stringp(id=me->query("marry")))
			return notify_fail("�����û�н�飡\n");
		if(me->query("jiebai"))
			return notify_fail("�����û�н�飡\n");
			
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("������������\n");
		if(id!= arg)
			return notify_fail(obj->name()+"���󲢲������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+"��\n");
		id2 = obj->query("marry");
		if( id2 != me->query("id"))
			return notify_fail(obj->name()+"���󲢲������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+"��\n");
		
		if (obj->query("divorced"))
			return notify_fail("������һ��������"+obj->name(1)+"����֮���£���������������\n");
			
		pros = obj->query_temp("protectors");
		remove_me =0;
		for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
			 pros -= ({ me });
			 remove_me =1;
			}
		if (remove_me) {
			me->delete_temp("protecting");
			obj->set_temp("protectors",pros);
			return notify_fail("��ֹͣ�������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+obj->name()+"�ˣ�\n");	
		}
	
		if(sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		obj->set_temp("protectors",pros);
		write("�㿪ʼ�������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+obj->name()+"��\n");
		me->set_temp("protecting",obj);
		return 1;
	} else
	{
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("������������\n");	
		if (!userp(obj))
			return notify_fail("��ֻ�ܱ�����ҡ�\n");
		if (obj == me)
			return notify_fail("�����Լ��������⣡\n");
		
		// ȥ���ɵı�������	
		if (objectp(old_obj = me->query_temp("protecting")))
		{
			if (old_obj == obj)
				return notify_fail("���Ѿ��ڱ���"+ obj->name()+ "�ˡ�\n");
			pros = old_obj->query_temp("protectors");
			remove_me =0;
			for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
		 		pros -= ({ me });
		 		remove_me =1;
			}	
			old_obj->set_temp("protectors",pros);
		}
		
		// Clean up a bit.lazy to count :D
		pros = obj->query_temp("protectors");
		for(i=0;i<sizeof(pros);i++)	
		{
			if(pros[i] == me) 
				pros -= ({ me });
		}
		
		if (sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		
		pros_real = ({});
		for(i=0;i<sizeof(pros);i++)	
		{
			if (pros[i])
				pros_real += ({ pros[i] });
		}
		
		me->set_temp("protecting", obj);
		obj->set_temp("protectors",pros_real);
	
		write("�㿪ʼ����"+obj->name()+"��\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	baohu <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

�����ѻ�����������Է������ӣ��ɷ򣩵�ָ��
�����Ϊ������ʱ����������Լ��߳��Ĳ��м���������
�Լ���ͬ�飬��Է���ܵ��˵Ĺ�����

ע�⣺
��������������ʱ������Ҳ�����ڱ���ս���С�
����������ٻ���л�ʷ��һ���������ܴ��Żݡ�

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
