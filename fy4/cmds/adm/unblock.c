#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;

        if(!arg)
                return notify_fail("����help�鿴��ָ���÷���\n");
        ob=find_player(arg);
        if(ob)
			return notify_fail("��ָ��ֻ�ܶ��������ʹ�á�\n");

		ob = FINGER_D->acquire_login_ob(arg);
    	
        if(!ob)
             return notify_fail("û�������ҡ�\n");
			
		if (!ob->query("blocked"))
             return notify_fail("�����Ҳ���Ҫִ�н���������\n");
	
		ob->delete("blocked");
		ob->save();
		destruct(ob);
		write("UNBLOCK ��� Ok.\n");
		
        return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	unblock ID[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�����Խ����ϵͳ���õ�����ʺš�

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
