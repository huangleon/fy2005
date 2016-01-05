// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj,obj1;
	string msg;

	if( !arg ) return notify_fail("��Ҫȥ���\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if (wiz_level(me)<4 && goto_inventory)
		return notify_fail("��Ĺ���Ȩ���޷����������ڲ���\n");
			
	if( !arg ) return notify_fail("��Ҫȥ���\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}
	
	if (wiz_level(me)<4 && !environment(obj) && obj->query("id"))
		return notify_fail("��Ĺ���Ȩ���޷�����������ڲ�����\n"); 
		
	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("������û�л������� goto��\n");
	
	if( stringp(msg = me->query("env/msg_mout")) ) {
	        if (msg!="none") message_vision(msg+"\n",me);		
	} else	{
			message("vision","����ǰһ����"+me->name()+"����Ӱ�Ѿ������ˡ�\n",environment(me),me);
			if (environment(me)->query("name"))
				tell_object(me,"���뿪��"+environment(me)->query("name")+"��\n");
			else tell_object(me,"���뿪��"+environment(me)->query("short")+"��\n");
	}
						
	if(me->move(obj)) {
		if ( obj->name(1))
		/*log_file("static/GOTO_LOG",
			sprintf("%s(%s) goto -i %s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj),
				ctime(time()) ) );*/
		
		if( stringp(msg = me->query("env/msg_min")) ) {
	        	if (msg!="none") message_vision(msg+"\n",me);
		} else	{
			message("vision","����ǰһ����"+me->name()+"����Ӱ��������ǰ��\n",environment(me),me);
			if (goto_inventory || !environment(me)->query("short")) tell_object(me,YEL"����Ӱһ����������"+obj->name()+NOR+YEL"�����ڡ�\n"NOR);
				else tell_object(me,YEL"����Ӱһ����������"+environment(me)->query("short")+"��\n"NOR, me);	
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	goto [-i] <Ŀ��>[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.

set msg_min/msg_mout <����> �ɹ����Լ�ѡ�����/�뿪�����������
set msg_min/msg_mout none ������ʾ����/�뿪�������Ϣ��

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
