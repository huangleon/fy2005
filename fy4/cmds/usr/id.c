// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, j;
        object obj, *inv;
        string *id;

        if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("������ȽϺķ�ϵͳ��Դ��ÿ��ֻ��ִ��һ�Ρ�\n");
	else
		me->set_temp("timer/big_cmd",time());
        
        if( !arg ) {
                inv = all_inventory(me);
                if( !sizeof(inv) )
                        return notify_fail("������û���κζ�����\n");
        write( "������Я����Ʒ�ı������(�ҷ�) :\n");
                for(i=0; i<sizeof(inv); i++) {
                        if( !me->visible(inv[i]) ) continue;
                        printf("%-20s = %s\n", inv[i]->name(),
                                implode(inv[i]->parse_command_id_list(), ", ") 
);
                }
                return 1;
        }

        if( arg=="here" ) {
            if (environment(me)->query("brief_objects"))
            	return notify_fail("�˵��޷�ʹ�ô����\n");
            inv = all_inventory(environment(me));
            if( !sizeof(inv) )
                	return notify_fail("����û���κζ�����\n");
        		write( "�����������, ���Ｐ��Ʒ��(Ӣ��)�������� :\n");
                for(i=0; i<sizeof(inv); i++) {
                    if( !me->visible(inv[i]) ) continue;
					if( (int) inv[i]->query("no_shown") ) 
					if(! wizardp(me))	continue;
                    if (wizardp(me) && inv[i]->query("id")!= inv[i]->get_id())
                    	printf("%-20s = %s ��%s��%s��\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ","), inv[i]->name(1), inv[i]->query("id"));
                    else
                    	printf("%-20s = %s\n", inv[i]->name(),
                    	implode(inv[i]->parse_command_id_list(), ",") ); 
                }
                return 1;
        }
}
int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	id [here][0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ���������֪����Ʒ��Ӣ�����Ƽ�����. ֻ�� id ����ʾ
��������Я����Ʒ������. 'id here' ����ʾ���и�����ͬһ��
��������������.

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );
    return 1;
}
 
 
