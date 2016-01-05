// summon command..

# include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������?\n");
	
	if (environment(ob)== environment(me))
		return notify_fail("����˾��������ǰ��\n");
	
	// moving
	message_vision("\n\n��Ȼ$N�������һ�˽е��������������˹��ϴ���$N�����Ļ�Ķ�Ҫ��
˵�վ�����$N�����ƶ�һ���̵���ʧ�ˡ���\n\n", ob);
	tell_object(ob,"������Լ�������һ�ᣬ���������ط������죬һ׼����λ����ȥ�˰ɣ�\n\n");
	
	ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ת�Ƶ������ǰ.\n");
	tell_object(ob,"....ԭ����"+(string)me->query("name")+"�����м��¶���\n");
	tell_room(environment(ob),(string)ob->query("name")+"�Ӱ����ƮƮ���Ƶص������ϡ�\n",({me,ob}));
	
	 if( !wizardp(ob) ) 
     /*	log_file("static/SUMMON", sprintf("%s(%s) summoned %s(%s) to %s at %s��\n", me->name(1),
              me->query("id"), ob->name(1), ob->query("id"), base_name(environment(me)), ctime(time()) ) );*/
	
	return 1;
}

int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	summon <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ������㽫ĳ���Ƶ�����ǰ��

ע�⣺��ָ����������ҵĽ����жϣ��򶷷������˳��ȣ�
��no_fly, no_move, busy�ȵȵȵȣ�
���Խ���ʹ�ã����������ʹ�ô�ָ��ǰ������������


[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
