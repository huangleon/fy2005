#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        int num;
        string name;

        if(!arg)
        	return notify_fail("����help�鿴��ָ���÷���\n");
        
        if(sscanf(arg,"%s %d", name,num)!=2)
        	return notify_fail("����help�鿴��ָ���÷���\n");
                
        ob=find_player(name);
        if(!ob)
			return notify_fail("��ָ��ֻ�ܶ��������ʹ�á�\n");

		if (num>5 || num<0)
			return notify_fail("����help�鿴��ָ���÷���\n");
			
        ob->set("MONITORING", num);
		if (!num)
			ob->delete("MONITORING");
		
		write(sprintf("��ʼ��%s(%s)����%d����¼��\n", ob->name(1),ob->query("id"),num));
		return 1;
		        
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	monitor ID 0/1/2/5 [0m
[0;1;37m����������������������������������������������������������������[0m   

ʹ�����ָ���ĳID����Ϊ����¼����ָ��Ŀ����׷��һЩ������Ϊ��
�ķ�ϵͳ��Դ����ʱ��Ӳ�̿ռ䣩���Ȳ�Ҫ����ʹ�ã�Ҳ��Ҫ����ʹ�á�
��¼�ļ���/log/backup/��

monitor xxx 0	ֹͣ��ĳID�ļ�¼
monitor xxx 1	�Ը�ID����combat_exp/potential/saved_quest
		�Ĳ������Լ�¼
monitor xxx 2	�Ը�ID���ӽ�̸��¼
monitor xxx 3	(undecided)
monitor xxx 4	(undecided)
monitor xxx 5   �Ը�ID���з����ߵ���Ϊ���Լ�¼���㹻Ӳ�̣���

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
