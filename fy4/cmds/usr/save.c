// save.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;

				if ( !wizardp(me) && me->query_temp("timer/big_cmd")+60 > time())
					return notify_fail("��������ȽϺķ�ϵͳ��Դ��ÿ��ʮ�����ִ��һ�Ρ�\n");
				else
					me->set_temp("timer/big_cmd",time());

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("�㲻�����������߽��룬���ܴ��档\n");
  
        if( environment(me)->query("valid_startroom") ) {
                me->set("startroom", base_name(environment(me)));
                write("�����´�����ʱ�����������롣\n");
        } 
                	
// change save to fake
// for decrease harddisk operate
// 2002-11-1 
// akuma

      	if( (int)link_ob->save() && (int)me->save() ) {
        write("����������ϡ�\n");
                return 1;
       	} else {
                write("����ʧ�ܡ�\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	save[0m
[0;1;37m����������������������������������������������������������������[0m   

�洢�����Լ��趨����һ�����߽���ĵص㡣

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
        return 1;
}
